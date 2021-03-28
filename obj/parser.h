/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_OBJ_PARSER_H_INCLUDED
# define YY_YY_OBJ_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 57 "parser.y"

    #include "Nodes/ast.hpp"

#line 52 "obj/parser.h"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    LITERALSTR = 259,
    REALNUMBER = 260,
    SCIENTIFIC = 261,
    INTEGERNUM = 262,
    PROGRAM = 263,
    VAR = 264,
    ARRAY = 265,
    OF = 266,
    INTEGER = 267,
    REAL = 268,
    STRING = 269,
    FUNCTION = 270,
    PROCEDURE = 271,
    PBEGIN = 272,
    END = 273,
    IF = 274,
    THEN = 275,
    ELSE = 276,
    WHILE = 277,
    DO = 278,
    NOT = 279,
    AND = 280,
    OR = 281,
    LPAREN = 282,
    RPAREN = 283,
    SEMICOLON = 284,
    DOT = 285,
    COMMA = 286,
    COLON = 287,
    LBRACE = 288,
    RBRACE = 289,
    DOTDOT = 290,
    ASSIGNMENT = 291,
    ADDOP = 292,
    SUBOP = 293,
    MULOP = 294,
    DIVOP = 295,
    LTOP = 296,
    GTOP = 297,
    EQOP = 298,
    GETOP = 299,
    LETOP = 300,
    NEQOP = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 61 "parser.y"

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

#line 124 "obj/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_OBJ_PARSER_H_INCLUDED  */
