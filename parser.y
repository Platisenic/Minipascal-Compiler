%{
#include "Nodes/assignment.hpp"
#include "Nodes/ast.hpp"
#include "Nodes/binary_operator.hpp"
#include "Nodes/compound_statement.hpp"
#include "Nodes/constant.hpp"
#include "Nodes/declartion.hpp"
#include "Nodes/if.hpp"
#include "Nodes/program.hpp"
#include "Nodes/subprogram_invoc.hpp"
#include "Nodes/subprogram.hpp"
#include "Nodes/unary_operator.hpp"
#include "Nodes/variable_ref.hpp"
#include "Nodes/variable.hpp"
#include "Nodes/while.hpp"
#include "Nodes/AstDumper.hpp"
#include "Sema/SemanticAnalyzer.hpp"
#include "Sema/SymbolTable.hpp"
#include "Codegen/CodeGenerator.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <algorithm>
#include <ctype.h>
#include <unistd.h>
#include "loc.h"
#include "error.h"

#define YYLTYPE yyltype

typedef struct YYLTYPE {
    uint32_t first_line;
    uint32_t first_column;
    uint32_t last_line;
    uint32_t last_column;
} yyltype;

#define MAX_LINE_LENG      256
extern int line_no, col_no, opt_list;
extern char buffer[MAX_LINE_LENG];
extern FILE *yyin;        /* declared by lex */
extern char *yytext;      /* declared by lex */
extern int yyleng;
char *output = NULL;

static Node root = NULL;

extern
#ifdef __cplusplus
"C"
#endif
int yylex(void);
static void yyerror(const char *msg);
extern int yylex_destroy(void);

%}
%code requires{
    #include "Nodes/ast.hpp"
}

%union {
  int val;
  char* text;
  double dval;
  
  Node node;
  NodeList* node_list;
  type_inf* typeinfo;
  enum enumOperator op_type;
  enum enumType val_Type;
  std::vector<id_info *>* id_list_ptr;
  num_const *num_value;
}

%locations
%token <text> IDENTIFIER 
%token <text> LITERALSTR
%token <dval> REALNUMBER
%token <dval> SCIENTIFIC
%token <val> INTEGERNUM

%token PROGRAM VAR ARRAY OF INTEGER REAL STRING FUNCTION PROCEDURE PBEGIN END IF THEN ELSE WHILE DO NOT AND OR

%token LPAREN RPAREN SEMICOLON DOT COMMA COLON LBRACE RBRACE DOTDOT ASSIGNMENT ADDOP SUBOP MULOP DIVOP LTOP GTOP EQOP GETOP LETOP NEQOP


%type <node> prog  subprogram_declaration compound_statement statement variable procedure_statement expression boolexpression simple_expression term factor
%type <node_list> declarations subprogram_declarations arguments parameter_list statement_list tail expression_list
%type <typeinfo> type
%type <op_type> addop mulop relop
%type <val_Type> standard_type
%type <id_list_ptr> identifier_list
%type <num_value> num
%%

    
prog : PROGRAM IDENTIFIER LPAREN identifier_list RPAREN SEMICOLON
     declarations
     subprogram_declarations
     compound_statement
     DOT 
     {
         root = new ProgramNode(
             @1.first_line,
             @1.first_column,
             string($2),
             Type_void,
             $4,
             $7,
             $8,
             $9
         );
         //free($2);
     }
     ;
     

identifier_list : IDENTIFIER
                { 
                    $$ = new vector<id_info *>();
                    $$->push_back(new id_info(std::string($1), @1.first_line, @1.first_column));
                    //free($1);
                }
                | IDENTIFIER COMMA identifier_list
                { 
                    $3->push_back(new id_info(std::string($1), @1.first_line, @1.first_column)); 
                    $$ = $3;
                    //free($1);
                }
                ;
//1210
declarations : VAR identifier_list COLON type SEMICOLON declarations
             {
                auto vars = new NodeList();
                //std::reverse($4->dimensions.begin(), $4->dimensions.end()); !!!!!!!!!!!!!!!!!!!!!
                for(auto& id : *$2)
                    vars->push_back(new VariableNode(id->line_number, id->col_number, id->name, $4));
                auto decl = new DeclarationNode(@2.first_line, @2.first_column, vars);
                $$ = $6;
                $$->push_back(decl);
             }
             | {$$ = new NodeList(); }
             ;

type : standard_type { $$ = new type_inf($1); }
     | ARRAY LBRACE num DOTDOT num RBRACE OF type
     {  $8->dimensions.push_back(std::make_pair($3->value.val, $5->value.val));
        $$ = $8;
     }
     ;

standard_type : INTEGER { $$ = Type_int; }
              | REAL    { $$ = Type_real; }
              | STRING  { $$ = Type_string; }
              ;

subprogram_declarations : subprogram_declaration SEMICOLON subprogram_declarations
                        { $3->push_back($1); $$ = $3; }
                        | { $$ = new NodeList(); }
                        ;

//1210
subprogram_declaration : FUNCTION IDENTIFIER arguments COLON standard_type SEMICOLON declarations compound_statement
                {   std::reverse($3->begin(), $3->end());
                    $$ = new SubProgramNode(
                         @1.first_line,
                         @1.first_column,
                         std::string($2),
                         $3,
                         $5,
                         $7,
                         $8 ); }
                | PROCEDURE IDENTIFIER arguments SEMICOLON declarations compound_statement
                {   std::reverse($3->begin(), $3->end());
                    $$ = new SubProgramNode(
                         @1.first_line,
                         @1.first_column,
                         std::string($2),
                         $3,
                         Type_void,
                         $5,
                         $6 ); }
                ;

arguments : LPAREN parameter_list RPAREN { $$ = $2; }
          | { $$ = new NodeList(); }
          ;

parameter_list : optional_var identifier_list COLON type
                { 
                    auto vars = new NodeList();
                    //std::reverse($4->dimensions.begin(), $4->dimensions.end());
                    for(auto& id : *$2)
                        vars->push_back(new VariableNode(id->line_number, id->col_number, id->name, $4));
                    auto decl = new DeclarationNode(@2.first_line, @2.first_column, vars);
                    $$ = new NodeList();
                    $$->push_back(decl);
                    // free($4);
                    // NODELIST_PTR_DELETE($2);
                }
               | optional_var identifier_list COLON type SEMICOLON parameter_list
                {   
                    auto vars = new NodeList();
                    //std::reverse($4->dimensions.begin(), $4->dimensions.end());
                    for(auto& id : *$2)
                        vars->push_back(new VariableNode(id->line_number, id->col_number, id->name, $4));
                    auto decl = new DeclarationNode(@2.first_line, @2.first_column, vars);
                    $$ = $6;
                    $$->push_back(decl);
                    // free($4);
                    // NODELIST_PTR_DELETE($2);
                }
               ;

optional_var : VAR
             | 
             ;

compound_statement : PBEGIN statement_list END 
                   {
                       $$ = new CompoundStatementNode(
                            @1.first_line,
                            @1.first_column,
                            $2
                        );
                   }

statement_list : statement 
               { 
                   $$ = new NodeList();
                   if($1)
                    $$->push_back($1); 
               }
               | statement SEMICOLON statement_list 
               { 
                   $3->push_back($1);
                   $$ = $3;
               }
               ;

statement : variable ASSIGNMENT expression
          { $$ = new AssignmentNode(@2.first_line, @2.first_column, $1, $3); }
          | procedure_statement
          { $$ = $1; }
          | compound_statement
          { $$ = $1; }
          | IF expression THEN statement ELSE statement
          { 
              $$ = new IfNode(
                  @1.first_line,
                  @1.first_column,
                  $2,
                  $4,
                  $6
              ); 
          }
          | WHILE expression DO statement
          { 
              $$ = new WhileNode(
                  @1.first_line,
                  @1.first_column,
                  $2,
                  $4
              ); 
          }
          | { $$ = nullptr; }
          ;

variable : IDENTIFIER tail { 
        $$ = new VariableRefNode(@1.first_line, @1.first_column, std::string($1), $2);
    }

tail : LBRACE expression RBRACE tail { $$ = $4; $$->push_back($2);}
     | { $$ = new NodeList(); }
     ;

procedure_statement : IDENTIFIER
                    { $$ = new SubProgramInvocationNode(@1.first_line, @1.first_column, std::string($1)); }
                    | IDENTIFIER LPAREN expression_list RPAREN
                    { $$ = new SubProgramInvocationNode(@1.first_line, @1.first_column, std::string($1), $3); }
                    ;

expression_list : expression
                { $$ = new NodeList(); if($1) $$->push_back($1);}
                | expression COMMA expression_list
                { $$ = $3; $$->push_back($1);}
                ;

expression : boolexpression
           { $$ = $1; }
           | boolexpression AND boolexpression
           { $$ = new BinaryOperatorNode(@1.first_line, @1.first_column, OP_AND, $1, $3); }
           | boolexpression OR boolexpression
           { $$ = new BinaryOperatorNode(@1.first_line, @1.first_column, OP_OR, $1, $3); }
           ;


boolexpression : simple_expression
               { $$ = $1; }
               | simple_expression relop simple_expression
               { $$ = new BinaryOperatorNode(@2.first_line, @2.first_column, $2, $1, $3); }
               ;

simple_expression : term
                  { $$ = $1; }
                  | simple_expression addop term
                  { $$ = new BinaryOperatorNode(@2.first_line, @2.first_column, $2, $1, $3); }
                  ;

term : factor
     { $$ = $1; }
     | term mulop factor
     { $$ = new BinaryOperatorNode(@2.first_line, @2.first_column, $2, $1, $3); }
     ;

factor : variable
       { $$ = $1; }
       | IDENTIFIER LPAREN expression_list RPAREN
       { $$ = new SubProgramInvocationNode(@1.first_line, @1.first_column, $1, $3); }
       | num
       { $$ = new ConstantNode(@1.first_line, @1.first_column, $1->type, $1->value); }
       | LITERALSTR
       {    
           const_union constant;
           constant.text = $1;
           $$ = new ConstantNode(@1.first_line, @1.first_column, Type_string, constant);
       }
       | LPAREN expression RPAREN
       { $$ = $2; }
       | NOT factor
       { $$ = new UnaryOperatorNode(@1.first_line, @1.first_column, OP_NOT, $2); }
       | SUBOP factor
       { $$ = new UnaryOperatorNode(@1.first_line, @1.first_column, OP_SUB, $2); }
       ;

addop : ADDOP { $$ = OP_ADD; }
      | SUBOP { $$ = OP_SUB; }
      ;

mulop : MULOP { $$ = OP_MUL; }
      | DIVOP { $$ = OP_DIV; }
      ;

relop : LTOP  { $$ = OP_LT; }
      | GTOP  { $$ = OP_GT; }
      | EQOP  { $$ = OP_EQ; }
      | LETOP { $$ = OP_LET; }
      | GETOP { $$ = OP_GET; }
      | NEQOP { $$ = OP_NEQ; }
      ;

num : INTEGERNUM { 
        const_union num;
        num.val = $1;
        $$ = new num_const(Type_int, num);
    }
    | REALNUMBER { 
        const_union num;
        num.dval = $1;
        $$ = new num_const(Type_real, num);
    }
    | SCIENTIFIC { 
        const_union num;
        num.dval = $1;
        $$ = new num_const(Type_real, num);
    }
    ;

%%

void yyerror(const char *msg) {
    fprintf(stderr,
            "[ERROR] line %4d:%3d %s, Unmatched token: %s\n",
            line_no, col_no-(int)yyleng+1, buffer, yytext);
}

int main(int argc, char *argv[]) {

    char c;
    while((c=getopt(argc, argv, "o:")) != -1){
      switch(c){
        case 'o':
          output = optarg;
          break;
        case '?':
            fprintf(stderr, "Illegal option:-%c\n", isprint(optopt)?optopt:'#');
            break;
        default:
            fprintf( stderr, "Usage: %s [-o output] filename\n", argv[0]), exit(0);
            break;
      }
    }

    FILE *fp = argc == 1 ? stdin : fopen(argv[optind], "r");

    if(fp == NULL)
        fprintf( stderr, "Open file error\n" ), exit(-1);

    yyin = fp;
    yyparse();
    if(root){
        //AstDumper dump;
        //dump.visit(*(ProgramNode *)root);
        
        SemanticAnalyzer sema;
        sema.visit(*(ProgramNode *)root);
        SymbolTable* S0Stmbol = sema.getS0Stmbol();
        CodeGenerator gene(output, S0Stmbol);
        gene.visit(*(ProgramNode *)root);
        

    }
    return 0;
}
