#ifndef __Codegen_CodeGenerator_H
#define __Codegen_CodeGenerator_H

#include "Visitor/AstNodeVisitor.hpp"
#include "Sema/SymbolTable.hpp"

#include <vector>
#include <cstdio>


class CodeGenerator : public AstNodeVisitor {
  public:
    CodeGenerator(char *_filename, SymbolTable * _Scope0Symbol) : filename(_filename), Scope0Symbol(_Scope0Symbol)
    {
      //printf("Filename:%s\n", filename);
      
    }
    ~CodeGenerator()
    {
      
    }
  
    void visit(AssignmentNode &p_assignment) override;
    void visit(BinaryOperatorNode &p_binaryoperator) override;
    void visit(CompoundStatementNode &p_compound_statement) override;
    void visit(ConstantNode &p_constant) override;
    void visit(DeclarationNode &p_declaration) override;
    void visit(IfNode &p_if) override;
    void visit(ProgramNode &p_program) override;
    void visit(SubProgramInvocationNode &p_subprogram_invoc) override;
    void visit(SubProgramNode &p_subprogram) override;
    void visit(UnaryOperatorNode &p_unaryoperator) override;
    void visit(VariableRefNode &p_variable_ref) override;
    void visit(VariableNode &p_variable) override;
    void visit(WhileNode &p_while) override;

    void filecreate();
    void fileclose();
    void pushtable();
    void pushentry(SymbolEntry entry);
    void poptable();
    bool TypeEqual(type_inf left, type_inf right);

  public:
    char *filename;
    FILE *fp;
    std::string classname;
    std::vector<SymbolTable> tablelist;
    SymbolTable * Scope0Symbol;
    int current_scope = -1;
    int label = 1;
    int StringBufferinit = 0;
    int Stringjava = 0;
    int funcDecl = 0; // 0-> no 1->yes
    int functionDeclName = 0;
    int funcinv = 0; // 1->subpro inv
    int needreturn = 1;
};

#endif
