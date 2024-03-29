/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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


#line 127 "obj/parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 174 "obj/parser.c"

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

#line 246 "obj/parser.c"

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



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

#define YYUNDEFTOK  2
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    97,    97,   117,   122,   129,   138,   141,   142,   148,
     149,   150,   153,   155,   159,   169,   181,   182,   185,   194,
     205,   206,   209,   218,   224,   231,   233,   235,   237,   247,
     256,   259,   263,   264,   267,   269,   273,   275,   279,   281,
     283,   288,   290,   294,   296,   300,   302,   306,   308,   310,
     312,   318,   320,   322,   326,   327,   330,   331,   334,   335,
     336,   337,   338,   339,   342,   347,   352
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "LITERALSTR", "REALNUMBER",
  "SCIENTIFIC", "INTEGERNUM", "PROGRAM", "VAR", "ARRAY", "OF", "INTEGER",
  "REAL", "STRING", "FUNCTION", "PROCEDURE", "PBEGIN", "END", "IF", "THEN",
  "ELSE", "WHILE", "DO", "NOT", "AND", "OR", "LPAREN", "RPAREN",
  "SEMICOLON", "DOT", "COMMA", "COLON", "LBRACE", "RBRACE", "DOTDOT",
  "ASSIGNMENT", "ADDOP", "SUBOP", "MULOP", "DIVOP", "LTOP", "GTOP", "EQOP",
  "GETOP", "LETOP", "NEQOP", "$accept", "prog", "identifier_list",
  "declarations", "type", "standard_type", "subprogram_declarations",
  "subprogram_declaration", "arguments", "parameter_list", "optional_var",
  "compound_statement", "statement_list", "statement", "variable", "tail",
  "procedure_statement", "expression_list", "expression", "boolexpression",
  "simple_expression", "term", "factor", "addop", "mulop", "relop", "num", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF (-83)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-34)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      13,    20,    62,    17,   -83,    67,    42,    37,    67,    45,
     -83,    72,    67,    56,    51,    81,    82,    69,    58,    44,
      61,    61,    33,    59,    56,    57,   -83,   -83,   -83,    63,
     -83,    84,    64,    65,   -14,    11,    11,   -83,    73,    66,
      68,   -83,   -83,   -83,    35,    72,   -83,    70,    67,    55,
      72,    11,    11,   -83,    10,   -83,   -83,   -83,   -83,    11,
      11,    11,   -83,    77,    34,   -13,    36,   -83,   -83,    76,
     -83,    33,    11,    74,   -83,   -83,    71,    79,    69,    83,
      85,    78,    11,   -83,    86,   -83,    33,    11,    11,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,    11,    11,   -83,
     -83,    11,    33,   -83,   -83,    35,    44,    72,   -83,   -83,
      11,    80,    87,   -83,    89,   -83,   -83,    36,    40,   -83,
     -83,    88,    90,    69,   -83,   -83,   -83,    33,    91,    84,
     -83,   -83,    44,   -83,   -83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     3,     0,     0,     0,
       4,     6,     0,    13,     0,     0,     0,     0,     0,     0,
      17,    17,    30,     0,    13,     0,     9,    10,    11,     0,
       7,    21,     0,     0,    34,     0,     0,    27,     0,    23,
       0,    26,     2,    12,     0,     6,    20,     0,     0,     0,
       6,     0,     0,    31,    33,    50,    65,    66,    64,     0,
       0,     0,    47,     0,    38,    41,    43,    45,    49,     0,
      22,    30,     0,     0,     5,    16,     0,     0,     0,     0,
      36,     0,     0,    52,     0,    53,    30,     0,     0,    54,
      55,    58,    59,    60,    62,    61,    63,     0,     0,    56,
      57,     0,    30,    24,    25,     0,     0,     6,    15,    35,
       0,    33,     0,    51,     0,    39,    40,    44,    42,    46,
      29,     0,    18,     0,    37,    32,    48,    30,     0,    21,
      14,    28,     0,    19,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -83,   -83,     0,   -44,   -79,    52,    93,   -83,    97,   -29,
     -83,   -17,    49,   -82,   -20,    -6,   -83,   -71,   -26,    -8,
      23,    26,   -54,   -83,   -83,   -83,   -41
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    13,    29,    30,    17,    18,    32,    47,
      48,    37,    38,    39,    62,    53,    41,    79,    80,    64,
      65,    66,    67,    97,   101,    98,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    74,    40,    73,   114,    83,    78,    85,    10,    63,
      69,   112,    14,    51,    54,    55,    56,    57,    58,    52,
     120,     1,   -33,     3,    89,    90,    81,   122,    91,    92,
      93,    94,    95,    96,    84,    59,    34,    82,    60,   124,
      56,    57,    58,    52,     5,   131,   104,   119,    76,    61,
      22,    40,    35,   134,    25,    36,    26,    27,    28,    87,
      88,   108,     4,   123,   121,     9,    40,    26,    27,    28,
       6,    15,    16,     8,    11,    99,   100,    89,    90,   115,
     116,    12,    40,    19,    20,    21,    22,    24,    31,    42,
      44,    70,    45,    46,    50,    71,    49,    86,    75,   102,
     133,    77,   132,   106,    72,   125,   130,    40,   107,   105,
     127,   109,   111,    52,   113,   126,   110,    43,    33,   129,
     103,   118,   128,   117
};

static const yytype_uint8 yycheck[] =
{
      17,    45,    22,    44,    86,    59,    50,    61,     8,    35,
      36,    82,    12,    27,     3,     4,     5,     6,     7,    33,
     102,     8,    36,     3,    37,    38,    52,   106,    41,    42,
      43,    44,    45,    46,    60,    24,     3,    27,    27,   110,
       5,     6,     7,    33,    27,   127,    72,   101,    48,    38,
      17,    71,    19,   132,    10,    22,    12,    13,    14,    25,
      26,    78,     0,   107,   105,    28,    86,    12,    13,    14,
       3,    15,    16,    31,    29,    39,    40,    37,    38,    87,
      88,     9,   102,    32,     3,     3,    17,    29,    27,    30,
      33,    18,    29,     9,    29,    29,    32,    20,    28,    23,
     129,    49,    11,    32,    36,   111,   123,   127,    29,    35,
      21,    28,    34,    33,    28,    28,    31,    24,    21,    29,
      71,    98,    34,    97
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    48,     3,     0,    27,     3,    49,    31,    28,
      49,    29,     9,    50,    49,    15,    16,    53,    54,    32,
       3,     3,    17,    58,    29,    10,    12,    13,    14,    51,
      52,    27,    55,    55,     3,    19,    22,    58,    59,    60,
      61,    63,    30,    53,    33,    29,     9,    56,    57,    32,
      29,    27,    33,    62,     3,     4,     5,     6,     7,    24,
      27,    38,    61,    65,    66,    67,    68,    69,    73,    65,
      18,    29,    36,    73,    50,    28,    49,    52,    50,    64,
      65,    65,    27,    69,    65,    69,    20,    25,    26,    37,
      38,    41,    42,    43,    44,    45,    46,    70,    72,    39,
      40,    71,    23,    59,    65,    35,    32,    29,    58,    28,
      31,    34,    64,    28,    60,    66,    66,    68,    67,    69,
      60,    73,    51,    50,    64,    62,    28,    21,    34,    29,
      58,    60,    11,    56,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    51,    52,
      52,    52,    53,    53,    54,    54,    55,    55,    56,    56,
      57,    57,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    61,    62,    62,    63,    63,    64,    64,    65,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    69,
      69,    69,    69,    69,    70,    70,    71,    71,    72,    72,
      72,    72,    72,    72,    73,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,    10,     1,     3,     6,     0,     1,     8,     1,
       1,     1,     3,     0,     8,     6,     3,     0,     4,     6,
       1,     0,     3,     1,     3,     3,     1,     1,     6,     4,
       0,     2,     4,     0,     1,     4,     1,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     4,     1,
       1,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 102 "parser.y"
     {
         root = new ProgramNode(
             (yylsp[-9]).first_line,
             (yylsp[-9]).first_column,
             string((yyvsp[-8].text)),
             Type_void,
             (yyvsp[-6].id_list_ptr),
             (yyvsp[-3].node_list),
             (yyvsp[-2].node_list),
             (yyvsp[-1].node)
         );
     }
#line 1635 "obj/parser.c"
    break;

  case 3:
#line 118 "parser.y"
                { 
                    (yyval.id_list_ptr) = new vector<id_info *>();
                    (yyval.id_list_ptr)->push_back(new id_info(std::string((yyvsp[0].text)), (yylsp[0]).first_line, (yylsp[0]).first_column));
                }
#line 1644 "obj/parser.c"
    break;

  case 4:
#line 123 "parser.y"
                { 
                    (yyvsp[0].id_list_ptr)->push_back(new id_info(std::string((yyvsp[-2].text)), (yylsp[-2]).first_line, (yylsp[-2]).first_column)); 
                    (yyval.id_list_ptr) = (yyvsp[0].id_list_ptr);          
                }
#line 1653 "obj/parser.c"
    break;

  case 5:
#line 130 "parser.y"
             {
                auto vars = new NodeList();
                for(auto& id : *(yyvsp[-4].id_list_ptr))
                    vars->push_back(new VariableNode(id->line_number, id->col_number, id->name, (yyvsp[-2].typeinfo)));
                auto decl = new DeclarationNode((yylsp[-4]).first_line, (yylsp[-4]).first_column, vars);
                (yyval.node_list) = (yyvsp[0].node_list);
                (yyval.node_list)->push_back(decl);
             }
#line 1666 "obj/parser.c"
    break;

  case 6:
#line 138 "parser.y"
               {(yyval.node_list) = new NodeList(); }
#line 1672 "obj/parser.c"
    break;

  case 7:
#line 141 "parser.y"
                     { (yyval.typeinfo) = new type_inf((yyvsp[0].val_Type)); }
#line 1678 "obj/parser.c"
    break;

  case 8:
#line 143 "parser.y"
     {  (yyvsp[0].typeinfo)->dimensions.push_back(std::make_pair((yyvsp[-5].num_value)->value.val, (yyvsp[-3].num_value)->value.val));
        (yyval.typeinfo) = (yyvsp[0].typeinfo);
     }
#line 1686 "obj/parser.c"
    break;

  case 9:
#line 148 "parser.y"
                        { (yyval.val_Type) = Type_int; }
#line 1692 "obj/parser.c"
    break;

  case 10:
#line 149 "parser.y"
                        { (yyval.val_Type) = Type_real; }
#line 1698 "obj/parser.c"
    break;

  case 11:
#line 150 "parser.y"
                        { (yyval.val_Type) = Type_string; }
#line 1704 "obj/parser.c"
    break;

  case 12:
#line 154 "parser.y"
                        { (yyvsp[0].node_list)->push_back((yyvsp[-2].node)); (yyval.node_list) = (yyvsp[0].node_list); }
#line 1710 "obj/parser.c"
    break;

  case 13:
#line 155 "parser.y"
                          { (yyval.node_list) = new NodeList(); }
#line 1716 "obj/parser.c"
    break;

  case 14:
#line 160 "parser.y"
                {   std::reverse((yyvsp[-5].node_list)->begin(), (yyvsp[-5].node_list)->end());
                    (yyval.node) = new SubProgramNode(
                         (yylsp[-7]).first_line,
                         (yylsp[-7]).first_column,
                         std::string((yyvsp[-6].text)),
                         (yyvsp[-5].node_list),
                         (yyvsp[-3].val_Type),
                         (yyvsp[-1].node_list),
                         (yyvsp[0].node) ); }
#line 1730 "obj/parser.c"
    break;

  case 15:
#line 170 "parser.y"
                {   std::reverse((yyvsp[-3].node_list)->begin(), (yyvsp[-3].node_list)->end());
                    (yyval.node) = new SubProgramNode(
                         (yylsp[-5]).first_line,
                         (yylsp[-5]).first_column,
                         std::string((yyvsp[-4].text)),
                         (yyvsp[-3].node_list),
                         Type_void,
                         (yyvsp[-1].node_list),
                         (yyvsp[0].node) ); }
#line 1744 "obj/parser.c"
    break;

  case 16:
#line 181 "parser.y"
                                         { (yyval.node_list) = (yyvsp[-1].node_list); }
#line 1750 "obj/parser.c"
    break;

  case 17:
#line 182 "parser.y"
            { (yyval.node_list) = new NodeList(); }
#line 1756 "obj/parser.c"
    break;

  case 18:
#line 186 "parser.y"
                { 
                    auto vars = new NodeList();
                    for(auto& id : *(yyvsp[-2].id_list_ptr))
                        vars->push_back(new VariableNode(id->line_number, id->col_number, id->name, (yyvsp[0].typeinfo)));
                    auto decl = new DeclarationNode((yylsp[-2]).first_line, (yylsp[-2]).first_column, vars);
                    (yyval.node_list) = new NodeList();
                    (yyval.node_list)->push_back(decl);
                }
#line 1769 "obj/parser.c"
    break;

  case 19:
#line 195 "parser.y"
                {   
                    auto vars = new NodeList();
                    for(auto& id : *(yyvsp[-4].id_list_ptr))
                        vars->push_back(new VariableNode(id->line_number, id->col_number, id->name, (yyvsp[-2].typeinfo)));
                    auto decl = new DeclarationNode((yylsp[-4]).first_line, (yylsp[-4]).first_column, vars);
                    (yyval.node_list) = (yyvsp[0].node_list);
                    (yyval.node_list)->push_back(decl);
                }
#line 1782 "obj/parser.c"
    break;

  case 22:
#line 210 "parser.y"
                   {
                       (yyval.node) = new CompoundStatementNode(
                            (yylsp[-2]).first_line,
                            (yylsp[-2]).first_column,
                            (yyvsp[-1].node_list)
                        );
                   }
#line 1794 "obj/parser.c"
    break;

  case 23:
#line 219 "parser.y"
               { 
                   (yyval.node_list) = new NodeList();
                   if((yyvsp[0].node))
                    (yyval.node_list)->push_back((yyvsp[0].node)); 
               }
#line 1804 "obj/parser.c"
    break;

  case 24:
#line 225 "parser.y"
               { 
                   (yyvsp[0].node_list)->push_back((yyvsp[-2].node));
                   (yyval.node_list) = (yyvsp[0].node_list);
               }
#line 1813 "obj/parser.c"
    break;

  case 25:
#line 232 "parser.y"
          { (yyval.node) = new AssignmentNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1819 "obj/parser.c"
    break;

  case 26:
#line 234 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1825 "obj/parser.c"
    break;

  case 27:
#line 236 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1831 "obj/parser.c"
    break;

  case 28:
#line 238 "parser.y"
          { 
              (yyval.node) = new IfNode(
                  (yylsp[-5]).first_line,
                  (yylsp[-5]).first_column,
                  (yyvsp[-4].node),
                  (yyvsp[-2].node),
                  (yyvsp[0].node)
              ); 
          }
#line 1845 "obj/parser.c"
    break;

  case 29:
#line 248 "parser.y"
          { 
              (yyval.node) = new WhileNode(
                  (yylsp[-3]).first_line,
                  (yylsp[-3]).first_column,
                  (yyvsp[-2].node),
                  (yyvsp[0].node)
              ); 
          }
#line 1858 "obj/parser.c"
    break;

  case 30:
#line 256 "parser.y"
            { (yyval.node) = nullptr; }
#line 1864 "obj/parser.c"
    break;

  case 31:
#line 259 "parser.y"
                           { 
        (yyval.node) = new VariableRefNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, std::string((yyvsp[-1].text)), (yyvsp[0].node_list));
    }
#line 1872 "obj/parser.c"
    break;

  case 32:
#line 263 "parser.y"
                                     { (yyval.node_list) = (yyvsp[0].node_list); (yyval.node_list)->push_back((yyvsp[-2].node));}
#line 1878 "obj/parser.c"
    break;

  case 33:
#line 264 "parser.y"
       { (yyval.node_list) = new NodeList(); }
#line 1884 "obj/parser.c"
    break;

  case 34:
#line 268 "parser.y"
                    { (yyval.node) = new SubProgramInvocationNode((yylsp[0]).first_line, (yylsp[0]).first_column, std::string((yyvsp[0].text))); }
#line 1890 "obj/parser.c"
    break;

  case 35:
#line 270 "parser.y"
                    { (yyval.node) = new SubProgramInvocationNode((yylsp[-3]).first_line, (yylsp[-3]).first_column, std::string((yyvsp[-3].text)), (yyvsp[-1].node_list)); }
#line 1896 "obj/parser.c"
    break;

  case 36:
#line 274 "parser.y"
                { (yyval.node_list) = new NodeList(); if((yyvsp[0].node)) (yyval.node_list)->push_back((yyvsp[0].node));}
#line 1902 "obj/parser.c"
    break;

  case 37:
#line 276 "parser.y"
                { (yyval.node_list) = (yyvsp[0].node_list); (yyval.node_list)->push_back((yyvsp[-2].node));}
#line 1908 "obj/parser.c"
    break;

  case 38:
#line 280 "parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1914 "obj/parser.c"
    break;

  case 39:
#line 282 "parser.y"
           { (yyval.node) = new BinaryOperatorNode((yylsp[-2]).first_line, (yylsp[-2]).first_column, OP_AND, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1920 "obj/parser.c"
    break;

  case 40:
#line 284 "parser.y"
           { (yyval.node) = new BinaryOperatorNode((yylsp[-2]).first_line, (yylsp[-2]).first_column, OP_OR, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1926 "obj/parser.c"
    break;

  case 41:
#line 289 "parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1932 "obj/parser.c"
    break;

  case 42:
#line 291 "parser.y"
               { (yyval.node) = new BinaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].op_type), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1938 "obj/parser.c"
    break;

  case 43:
#line 295 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1944 "obj/parser.c"
    break;

  case 44:
#line 297 "parser.y"
                  { (yyval.node) = new BinaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].op_type), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1950 "obj/parser.c"
    break;

  case 45:
#line 301 "parser.y"
     { (yyval.node) = (yyvsp[0].node); }
#line 1956 "obj/parser.c"
    break;

  case 46:
#line 303 "parser.y"
     { (yyval.node) = new BinaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].op_type), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1962 "obj/parser.c"
    break;

  case 47:
#line 307 "parser.y"
       { (yyval.node) = (yyvsp[0].node); }
#line 1968 "obj/parser.c"
    break;

  case 48:
#line 309 "parser.y"
       { (yyval.node) = new SubProgramInvocationNode((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].text), (yyvsp[-1].node_list)); }
#line 1974 "obj/parser.c"
    break;

  case 49:
#line 311 "parser.y"
       { (yyval.node) = new ConstantNode((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].num_value)->type, (yyvsp[0].num_value)->value); }
#line 1980 "obj/parser.c"
    break;

  case 50:
#line 313 "parser.y"
       {    
           const_union constant;
           constant.text = (yyvsp[0].text);
           (yyval.node) = new ConstantNode((yylsp[0]).first_line, (yylsp[0]).first_column, Type_string, constant);
       }
#line 1990 "obj/parser.c"
    break;

  case 51:
#line 319 "parser.y"
       { (yyval.node) = (yyvsp[-1].node); }
#line 1996 "obj/parser.c"
    break;

  case 52:
#line 321 "parser.y"
       { (yyval.node) = new UnaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, OP_NOT, (yyvsp[0].node)); }
#line 2002 "obj/parser.c"
    break;

  case 53:
#line 323 "parser.y"
       { (yyval.node) = new UnaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, OP_SUB, (yyvsp[0].node)); }
#line 2008 "obj/parser.c"
    break;

  case 54:
#line 326 "parser.y"
              { (yyval.op_type) = OP_ADD; }
#line 2014 "obj/parser.c"
    break;

  case 55:
#line 327 "parser.y"
              { (yyval.op_type) = OP_SUB; }
#line 2020 "obj/parser.c"
    break;

  case 56:
#line 330 "parser.y"
              { (yyval.op_type) = OP_MUL; }
#line 2026 "obj/parser.c"
    break;

  case 57:
#line 331 "parser.y"
              { (yyval.op_type) = OP_DIV; }
#line 2032 "obj/parser.c"
    break;

  case 58:
#line 334 "parser.y"
              { (yyval.op_type) = OP_LT; }
#line 2038 "obj/parser.c"
    break;

  case 59:
#line 335 "parser.y"
              { (yyval.op_type) = OP_GT; }
#line 2044 "obj/parser.c"
    break;

  case 60:
#line 336 "parser.y"
              { (yyval.op_type) = OP_EQ; }
#line 2050 "obj/parser.c"
    break;

  case 61:
#line 337 "parser.y"
              { (yyval.op_type) = OP_LET; }
#line 2056 "obj/parser.c"
    break;

  case 62:
#line 338 "parser.y"
              { (yyval.op_type) = OP_GET; }
#line 2062 "obj/parser.c"
    break;

  case 63:
#line 339 "parser.y"
              { (yyval.op_type) = OP_NEQ; }
#line 2068 "obj/parser.c"
    break;

  case 64:
#line 342 "parser.y"
                 { 
        const_union num;
        num.val = (yyvsp[0].val);
        (yyval.num_value) = new num_const(Type_int, num);
    }
#line 2078 "obj/parser.c"
    break;

  case 65:
#line 347 "parser.y"
                 { 
        const_union num;
        num.dval = (yyvsp[0].dval);
        (yyval.num_value) = new num_const(Type_real, num);
    }
#line 2088 "obj/parser.c"
    break;

  case 66:
#line 352 "parser.y"
                 { 
        const_union num;
        num.dval = (yyvsp[0].dval);
        (yyval.num_value) = new num_const(Type_real, num);
    }
#line 2098 "obj/parser.c"
    break;


#line 2102 "obj/parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 359 "parser.y"


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
        SemanticAnalyzer sema;
        sema.visit(*(ProgramNode *)root);
        SymbolTable* S0Stmbol = sema.getS0Stmbol();
        CodeGenerator gene(output, S0Stmbol);
        gene.visit(*(ProgramNode *)root);
    }
    return 0;
}
