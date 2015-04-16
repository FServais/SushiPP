/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser/spp_parser.y" /* yacc.c:339  */

	#include <iostream>
	#include <string>
	#include <sstream>
	#include <cstddef>

	/** Compiler and AST includes */
	#include "../SppCompiler.hpp"
	#include "../ast/AbstractSyntaxTree.hpp"

	#include "../ast/nodes/ASTNode.hpp"
	#include "../ast/nodes/NodeLocation.hpp"
	#include "../ast/nodes/ErrorNode.hpp"

	#include "../ast/nodes/tokens/Token.hpp"
	#include "../ast/nodes/tokens/Operator.hpp"
	#include "../ast/nodes/tokens/ConstantToken.hpp"
	#include "../ast/nodes/tokens/Delimiter.hpp"
	#include "../ast/nodes/tokens/Keyword.hpp"

	#include "../ast/nodes/nonterminal/NonTerminal.hpp"
	#include "../ast/nodes/nonterminal/NT_Constant.hpp"
	#include "../ast/nodes/nonterminal/NT_Datastructure.hpp"
	#include "../ast/nodes/nonterminal/NT_Declaration.hpp"
	#include "../ast/nodes/nonterminal/NT_Expression.hpp"
	#include "../ast/nodes/nonterminal/NT_FunctionCall.hpp"
	#include "../ast/nodes/nonterminal/NT_Program.hpp"
	#include "../ast/nodes/nonterminal/NT_Statement.hpp"

	/* Macro for getting the children of a ast::ASTNode* of type void* */
	#define children(node) ((ast::ASTNode*)node)->delete_children()


	extern "C" int yylex();

	static void yyerror(const char*);
	static std::string curr_line_row();

	// pointer to 
	extern compiler::SppCompiler* g_compiler;
	// true if an error occurred -> used for exiting yyparse with correct code if the parser
	// reaches the end of file after error recovery
	bool error_occurred;

#line 111 "parser/sushipp.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "sushipp.tab.h".  */
#ifndef YY_YY_PARSER_SUSHIPP_TAB_H_INCLUDED
# define YY_YY_PARSER_SUSHIPP_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    KEYWORD_MAKI = 258,
    KEYWORD_TO = 259,
    KEYWORD_SOY = 260,
    KEYWORD_NORI = 261,
    KEYWORD_MENU = 262,
    KEYWORD_FOR = 263,
    KEYWORD_ROLL = 264,
    KEYWORD_BREAK = 265,
    KEYWORD_CONTINUE = 266,
    KEYWORD_FOREACH = 267,
    KEYWORD_AS = 268,
    KEYWORD_IF = 269,
    KEYWORD_ELSEIF = 270,
    KEYWORD_ELSE = 271,
    TYPE_INT = 272,
    TYPE_FLOAT = 273,
    TYPE_BOOL = 274,
    TYPE_CHAR = 275,
    TYPE_STRING = 276,
    TYPE_ARRAY = 277,
    TYPE_LIST = 278,
    TYPE_TUPLE = 279,
    OP_ARITH_INCR = 280,
    OP_ARITH_DECR = 281,
    OP_ARITH_EXPO = 282,
    OP_LOGIC_OR = 283,
    OP_LOGIC_AND = 284,
    OP_COMP_LEQ = 285,
    OP_COMP_GEQ = 286,
    OP_COMP_EQ = 287,
    OP_COMP_NEQ = 288,
    OP_RSHIFT = 289,
    OP_LSHIFT = 290,
    OP_ASSIGN_PLUS = 291,
    OP_ASSIGN_MINUS = 292,
    OP_ASSIGN_MULT = 293,
    OP_ASSIGN_DIV = 294,
    OP_ASSIGN_EXPO = 295,
    OP_ASSIGN_MOD = 296,
    OP_ASSIGN_OR = 297,
    OP_ASSIGN_AND = 298,
    OP_ASSIGN_XOR = 299,
    OP_ASSIGN_CONCAT = 300,
    UNARY_MINUS = 301,
    PREFIX_INCR = 302,
    PREFIX_DECR = 303,
    SUFFIX_INCR = 304,
    SUFFIX_DECR = 305,
    DELIM_EOL = 306,
    DELIM_EOS = 307,
    DELIM_TUPLE_BEG = 308,
    DELIM_TUPLE_END = 309,
    DELIM_ARRAY_BEG = 310,
    DELIM_ARRAY_END = 311,
    DELIM_ARROW = 312,
    CONST_STRING = 313,
    CONST_INT = 314,
    CONST_FLOAT = 315,
    CONST_BOOL = 316,
    CONST_CHAR = 317,
    IDENTIFIER = 318
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 55 "parser/spp_parser.y" /* yacc.c:355  */

	std::string* vstring;
	void* vnode;

#line 220 "parser/sushipp.tab.c" /* yacc.c:355  */
};
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

#endif /* !YY_YY_PARSER_SUSHIPP_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 249 "parser/sushipp.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  93
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1528

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  273

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,     2,     2,    57,    50,     2,
      74,    75,    55,    53,    73,    54,    61,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    26,     2,
      51,    25,    52,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    76,     2,    77,    49,    80,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,    48,    79,    58,     2,     2,     2,
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
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    60,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    81,    82,    83,    84,    85,    86
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   176,   176,   177,   201,   213,   225,   241,   259,   271,
     283,   301,   314,   331,   343,   360,   380,   395,   412,   418,
     430,   456,   460,   483,   498,   524,   545,   551,   574,   589,
     601,   613,   627,   639,   651,   663,   674,   696,   712,   725,
     734,   746,   762,   782,   799,   823,   835,   849,   864,   876,
     888,   900,   912,   924,   936,   949,   962,   975,   988,  1001,
    1014,  1026,  1039,  1052,  1065,  1077,  1090,  1103,  1115,  1128,
    1141,  1154,  1167,  1180,  1193,  1206,  1219,  1235,  1247,  1259,
    1271,  1286,  1299,  1312,  1325,  1338,  1351,  1364,  1377,  1390,
    1403,  1416,  1436,  1448,  1460,  1472,  1490,  1505,  1520,  1542,
    1554,  1577,  1592,  1607,  1622,  1637,  1658,  1670,  1682,  1694,
    1709,  1722,  1739,  1752,  1769,  1782,  1802,  1814,  1829,  1846,
    1864,  1884,  1896,  1908,  1920,  1932,  1944,  1960,  1972,  1989,
    2007,  2019,  2032,  2051,  2069,  2088,  2100,  2112,  2130,  2151,
    2182,  2210,  2214,  2229,  2233,  2249,  2266,  2284,  2301,  2323,
    2338
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"maki\"", "\"to\"", "\"soy\"",
  "\"nori\"", "\"menu\"", "\"for\"", "\"roll\"", "\"break\"",
  "\"continue\"", "\"foreach\"", "\"as\"", "\"if\"", "\"elseif\"",
  "\"else\"", "\"int\"", "\"float\"", "\"bool\"", "\"char\"", "\"string\"",
  "\"array\"", "\"list\"", "\"tuple\"", "'='", "':'", "\"++\"", "\"--\"",
  "\"**\"", "\"||\"", "\"&&\"", "\"<=\"", "\">=\"", "\"==\"", "\"!=\"",
  "\">>\"", "\"<<\"", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"**=\"",
  "\"%=\"", "\"|=\"", "\"&=\"", "\"^=\"", "\".=\"", "'|'", "'^'", "'&'",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'~'", "'!'",
  "UNARY_MINUS", "'.'", "PREFIX_INCR", "PREFIX_DECR", "SUFFIX_INCR",
  "SUFFIX_DECR", "DELIM_EOL", "\";;\"", "\"#{\"", "\"}#\"", "\"#[\"",
  "\"]#\"", "\"->\"", "','", "'('", "')'", "'['", "']'", "'{'", "'}'",
  "'_'", "CONST_STRING", "CONST_INT", "CONST_FLOAT", "CONST_BOOL",
  "CONST_CHAR", "IDENTIFIER", "$accept", "program", "scope",
  "program-element", "declaration", "decl-vars", "decl-var", "decl-func",
  "param-list", "param", "func-call", "arg-list", "argument",
  "braced-func-call", "func-call-eol", "arg-list-eol", "soy-expression",
  "soy-func", "expression", "incr-expression", "assignment",
  "modifying-expression", "assignable-expression", "datastructure-access",
  "expression-list", "constant", "datastructure", "array", "list", "tuple",
  "make-sequence", "make-sequence-list", "make-sequence-array",
  "seq-expression", "statement", "return", "menu", "menu-body",
  "menu-case", "menu-def", "loop", "roll", "foreach", "for",
  "for-initializer", "for-update", "conditional", "elseif", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    61,    58,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   124,    94,
      38,    60,    62,    43,    45,    42,    47,    37,   126,    33,
     301,    46,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,    44,    40,    41,    91,    93,   123,   125,
      95,   313,   314,   315,   316,   317,   318
};
# endif

#define YYPACT_NINF -92

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-92)))

#define YYTABLE_NINF -98

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     152,    19,   843,   843,   -62,   843,   -92,   -92,   843,   843,
     -62,   -62,   152,    14,   425,    47,   -92,   -18,   -92,   -92,
     -92,   -92,   -92,   -92,   389,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,    26,    10,   -92,   -20,   -92,   843,
     843,   843,   717,   738,   615,   777,   -92,   -92,   -92,   -92,
     -92,   293,   -92,   -92,  1284,   -92,   -92,  1481,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,  1132,   -21,   -92,   437,
     -17,  1170,   901,  1208,   -92,   -92,   -92,   304,    55,   304,
     -13,   304,   -92,   615,   843,   -21,   -92,   458,   -92,   -92,
     -92,   -92,   -92,   -92,   152,   843,   -92,   -92,   843,   843,
     843,   843,   843,   843,   843,   843,   843,   843,   843,   648,
      25,    54,     4,    18,     5,     5,     5,   -92,  1033,    17,
     -92,   706,    27,    28,     4,   520,   578,    33,   967,   -92,
      12,    23,   843,   843,   843,   843,   843,   843,   843,   843,
     843,   843,   843,   843,   843,   843,   843,   843,   843,   843,
     843,   843,   810,   843,   152,    15,   152,    53,   -92,   -92,
     -92,   -92,  1000,   934,   -92,   -92,  1284,  1284,  1284,  1284,
    1284,  1284,  1284,  1284,  1284,  1284,  1284,  1284,   -92,  1284,
      32,   152,   -92,    20,    84,   -92,   843,   -92,   843,   -92,
     -92,    86,   -92,   -92,   -92,   -92,     5,  1315,  1345,   658,
     658,  1446,  1446,   -11,   -11,  1375,  1405,  1416,   658,   658,
       2,     2,     5,     5,     5,     5,    43,  1099,    57,    56,
      63,  1066,    65,    64,    22,   304,   -92,   -92,   -92,    68,
      66,   -92,   -92,  1284,   152,   152,   152,   -92,   810,   -92,
      -1,   -92,   152,   843,   152,   -92,     7,   -92,   -92,   -92,
     -92,    73,    77,   -92,   -92,    81,    83,  1246,    85,   152,
     -92,   -92,   -92,   152,   -92,   152,   -92,    98,   101,   138,
     -92,   -92,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,   127,     0,   141,     0,   125,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     4,    10,    95,
      94,    93,    92,     9,     0,    97,     8,   121,   122,   123,
     137,   135,   136,   126,     0,    16,    12,    13,    11,     0,
       0,     0,     0,     0,     0,     0,   103,   101,   102,   104,
     105,    47,    53,    49,   128,    51,    52,    50,    45,    48,
     106,   107,   108,   109,   116,   117,     0,    96,   142,     0,
       0,     0,     0,     0,    77,    78,     7,     0,     0,     0,
       0,     0,    35,     0,     0,    28,    25,     0,    34,    32,
      33,    29,    30,     1,     5,     0,    79,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,     0,    21,     0,    60,    64,    67,   114,    99,     0,
     110,    99,     0,     0,    21,     0,     0,     0,     0,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    39,    37,
      36,    38,     0,     0,    27,     6,    81,    82,    83,    84,
      85,    86,    87,    89,    88,    90,    91,    18,    19,    17,
       0,     0,    22,     0,    16,    14,     0,   115,     0,   111,
     119,     0,    43,    46,   113,   118,    59,    65,    66,    70,
      71,    72,    73,    75,    74,    61,    63,    62,    68,    69,
      54,    55,    56,    57,    58,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,    31,    98,     0,
       0,    15,   100,   120,     0,     0,     0,   129,   131,   130,
     143,   138,     0,     0,     0,   145,     0,    42,    24,    20,
      44,     0,     0,   132,   144,     0,     0,     0,     0,     0,
     147,   134,   133,     0,   139,     0,   146,     0,     0,   149,
     148,   140,   150
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,    52,   -92,   -92,   -91,   -92,   -92,   -83,   -92,
     -92,    88,    -5,    16,   -92,   -74,   -12,   -92,   259,    49,
      13,   -69,    29,     0,   -37,    -9,    97,   -92,   -92,   -92,
     -92,   -92,   -92,   132,   -92,   -92,   -92,   -56,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -86
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,    17,    18,    36,    37,    38,   111,   112,
      19,    86,   157,    52,    80,   159,    53,   127,   118,    55,
      56,    23,    24,    57,   119,    58,    59,    60,    61,    62,
      63,    64,    65,   123,    26,    27,    28,   218,   219,   220,
      29,    30,    31,    32,    70,   255,    33,   246
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    81,    89,   158,    25,    91,   122,   161,   130,    87,
      25,    25,    25,    22,    90,    77,    20,    68,   132,    34,
      34,    34,   185,   259,    67,    22,    10,    11,    20,   182,
      88,   132,   126,    69,   132,   109,   -21,   243,   244,    74,
      75,   191,   146,   147,   148,   149,   150,    93,    94,    21,
     151,   108,   161,   113,    82,    84,   153,   148,   149,   150,
     124,    21,   160,   151,    76,    89,   151,    89,    91,    89,
      91,   126,    91,    13,   260,    89,   180,    90,    91,    90,
     181,    90,    87,   226,   183,    14,   187,    90,    78,   245,
     110,   194,   231,    88,    25,    88,   110,    88,   189,   190,
      79,   223,   195,    88,   184,    35,   184,    22,   192,   109,
      20,    92,   234,    89,    89,   235,    91,    91,   229,   225,
     248,    42,   238,    43,   237,    90,    90,    83,   -40,   239,
     242,    45,   241,   249,    46,    47,    48,    49,    50,    85,
     261,    88,    88,    21,   262,    89,   165,   263,    91,   232,
     264,   247,   266,   243,    25,     1,    25,    90,     2,     3,
       4,     5,     6,     7,     8,   270,     9,    22,   271,    22,
      20,   254,    20,    88,    92,   164,    92,   131,    92,    10,
      11,    25,   253,   272,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     0,    20,     0,     0,
       0,     0,     0,    21,     0,    21,   222,     0,   224,     0,
       0,     0,     0,    89,     0,     0,    91,     0,    12,     0,
       0,     0,    92,    92,     0,    90,    13,     0,     0,     0,
      21,     0,     0,   230,    25,    25,    25,     0,    14,     0,
      25,    88,    25,     0,    25,     0,     0,    22,    22,    22,
      20,    20,    20,    22,    92,    22,    20,    22,    20,    25,
      20,    54,    66,    25,    71,    25,     0,    72,    73,     0,
       0,     0,    22,     0,     0,    20,    22,     0,    22,    20,
       0,    20,     0,    21,    21,    21,   250,   251,   252,    21,
       0,    21,     0,    21,   256,     0,   258,     0,   114,   115,
     116,     0,   121,   128,   121,    82,     0,     0,    21,     0,
       0,   267,    21,     0,    21,   268,     0,   269,   -96,     0,
     -96,   -96,    92,     0,     0,     0,     0,     0,     0,     0,
       0,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,     0,   162,   163,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   166,     0,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   179,    84,
       0,     0,    42,     0,    43,     0,     0,     0,    83,     0,
       0,     0,    45,     0,     0,    46,    47,    48,    49,    50,
      85,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   217,   221,     0,    95,     0,    96,    97,     0,     0,
       0,     0,     0,     0,     0,   -26,    82,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,     0,     0,     0,
     -26,   -26,     0,     0,     0,     0,     0,   233,     0,     0,
     -96,     0,   -96,   -96,     0,     0,     0,     0,   -26,    82,
       0,     0,    95,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -26,   -26,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   -26,   -26,    42,     0,    43,     0,   217,     0,    83,
     -26,    84,   257,    45,     0,     0,    46,    47,    48,    49,
      50,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     0,     0,   -26,   -26,    42,     0,    43,     0,
       0,     0,    83,   -26,     0,     0,    45,     0,     0,    46,
      47,    48,    49,    50,    85,   -96,     0,   -96,   -96,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -47,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,     0,    82,
       0,   -47,     0,     0,     0,     0,     0,     0,    42,     0,
      43,     0,     0,     0,    83,   -47,    84,     0,    45,     0,
       0,    46,    47,    48,    49,    50,    85,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,    77,     0,     0,     0,
     124,     0,     0,     0,     0,     0,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,     0,     0,     0,   -49,
       0,     0,    10,    11,     0,     0,    42,     0,    43,   178,
       0,     0,    83,   -49,     0,     0,    45,     0,     0,    46,
      47,    48,    49,    50,    85,     0,     0,     0,     0,    39,
       0,     0,     0,    40,    41,    10,    11,     0,     0,     0,
       0,     0,     0,    42,     0,    43,     0,   132,     0,    44,
       0,     0,     0,    45,   139,   140,    46,    47,    48,    49,
      50,   125,    39,     0,     0,     0,    40,    41,     0,     0,
     188,   146,   147,   148,   149,   150,    42,     0,    43,   151,
       0,     0,    44,     0,     0,     0,    45,     0,     0,    46,
      47,    48,    49,    50,    51,   132,   133,   134,   135,   136,
     137,   138,   139,   140,    10,    11,     0,     0,     0,     0,
       0,     0,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,    10,    11,   151,     0,     0,
       0,    39,     0,     0,     0,    40,    41,     0,     0,   186,
       0,     0,     0,     0,     0,    42,   117,    43,     0,     0,
       0,    44,    39,     0,     0,    45,    40,    41,    46,    47,
      48,    49,    50,    51,    10,    11,    42,     0,    43,   120,
       0,     0,    44,     0,     0,     0,    45,     0,     0,    46,
      47,    48,    49,    50,    51,     0,     0,     0,     0,     0,
       0,    39,     0,     0,     0,    40,    41,    10,    11,     0,
       0,     0,     0,     0,     0,    42,     0,    43,     0,     0,
       0,    44,     0,     0,     0,    45,   129,     0,    46,    47,
      48,    49,    50,    51,    39,     0,     0,     0,    40,    41,
      10,    11,     0,     0,     0,     0,     0,     0,    42,     0,
      43,     0,     0,     0,    44,     0,     0,     0,    45,     0,
     216,    46,    47,    48,    49,    50,    51,    39,     0,     0,
       0,    40,    41,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,    43,   155,     0,     0,    44,     0,     0,
       0,    45,     0,     0,    46,    47,    48,    49,    50,    51,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,     0,   151,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,     0,     0,     0,   151,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,   228,     0,     0,     0,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,     0,     0,     0,   151,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,   193,     0,     0,     0,     0,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,     0,
       0,   151,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,   227,     0,     0,     0,     0,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,     0,   151,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   186,     0,     0,     0,
       0,     0,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,     0,   151,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   240,
       0,     0,     0,     0,     0,     0,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,     0,     0,     0,
     151,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,   236,     0,     0,     0,     0,     0,     0,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,     0,   151,     0,     0,     0,     0,   152,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,     0,
       0,   151,     0,     0,     0,     0,   154,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,     0,   151,
       0,     0,     0,     0,   156,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,     0,   151,     0,     0,
       0,     0,   265,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,     0,     0,   132,   151,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,     0,   132,     0,   151,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,     0,   132,     0,   151,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,   144,   145,   146,   147,
     148,   149,   150,     0,   132,     0,   151,   135,   136,   137,
     138,   139,   140,     0,     0,   132,     0,     0,   135,   136,
     137,   138,   139,   140,     0,   143,   144,   145,   146,   147,
     148,   149,   150,     0,     0,     0,   151,   144,   145,   146,
     147,   148,   149,   150,     0,   132,     0,   151,   135,   136,
       0,     0,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   -97,   151,   -97,   -97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97
};

static const yytype_int16 yycheck[] =
{
       0,    13,    14,    77,     4,    14,    43,    81,    45,    14,
      10,    11,    12,     0,    14,     1,     0,     4,    29,     1,
       1,     1,   113,    16,    86,    12,    27,    28,    12,   112,
      14,    29,    44,     4,    29,    25,    26,    15,    16,    10,
      11,   124,    53,    54,    55,    56,    57,     0,    66,     0,
      61,    25,   126,    73,     1,    76,    73,    55,    56,    57,
       5,    12,    75,    61,    12,    77,    61,    79,    77,    81,
      79,    83,    81,    74,    67,    87,    51,    77,    87,    79,
      26,    81,    87,   157,    66,    86,    69,    87,    74,    67,
      86,    79,   183,    77,    94,    79,    86,    81,    71,    71,
      86,    86,    79,    87,    86,    86,    86,    94,    75,    25,
      94,    14,    26,   125,   126,    72,   125,   126,    86,    66,
      52,    68,    66,    70,    67,   125,   126,    74,    75,    66,
      66,    78,    67,    67,    81,    82,    83,    84,    85,    86,
      67,   125,   126,    94,    67,   157,    94,    66,   157,   186,
      67,   225,    67,    15,   154,     3,   156,   157,     6,     7,
       8,     9,    10,    11,    12,    67,    14,   154,    67,   156,
     154,   240,   156,   157,    77,    87,    79,    45,    81,    27,
      28,   181,   238,   269,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,    -1,    -1,   181,    -1,    -1,
      -1,    -1,    -1,   154,    -1,   156,   154,    -1,   156,    -1,
      -1,    -1,    -1,   225,    -1,    -1,   225,    -1,    66,    -1,
      -1,    -1,   125,   126,    -1,   225,    74,    -1,    -1,    -1,
     181,    -1,    -1,   181,   234,   235,   236,    -1,    86,    -1,
     240,   225,   242,    -1,   244,    -1,    -1,   234,   235,   236,
     234,   235,   236,   240,   157,   242,   240,   244,   242,   259,
     244,     2,     3,   263,     5,   265,    -1,     8,     9,    -1,
      -1,    -1,   259,    -1,    -1,   259,   263,    -1,   265,   263,
      -1,   265,    -1,   234,   235,   236,   234,   235,   236,   240,
      -1,   242,    -1,   244,   242,    -1,   244,    -1,    39,    40,
      41,    -1,    43,    44,    45,     1,    -1,    -1,   259,    -1,
      -1,   259,   263,    -1,   265,   263,    -1,   265,    25,    -1,
      27,    28,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,    76,
      -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    78,    -1,    -1,    81,    82,    83,    84,    85,
      86,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    25,    -1,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,     1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      15,    16,    -1,    -1,    -1,    -1,    -1,   188,    -1,    -1,
      25,    -1,    27,    28,    -1,    -1,    -1,    -1,     0,     1,
      -1,    -1,    25,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    15,    16,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    -1,    70,    -1,   238,    -1,    74,
      75,    76,   243,    78,    -1,    -1,    81,    82,    83,    84,
      85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    66,    67,    68,    -1,    70,    -1,
      -1,    -1,    74,    75,    -1,    -1,    78,    -1,    -1,    81,
      82,    83,    84,    85,    86,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,     1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      70,    -1,    -1,    -1,    74,    75,    76,    -1,    78,    -1,
      -1,    81,    82,    83,    84,    85,    86,    29,    30,    31,
      32,    33,    34,    35,    36,    37,     1,    -1,    -1,    -1,
       5,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    61,
      -1,    -1,    27,    28,    -1,    -1,    68,    -1,    70,     1,
      -1,    -1,    74,    75,    -1,    -1,    78,    -1,    -1,    81,
      82,    83,    84,    85,    86,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    58,    59,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    -1,    29,    -1,    74,
      -1,    -1,    -1,    78,    36,    37,    81,    82,    83,    84,
      85,    86,    54,    -1,    -1,    -1,    58,    59,    -1,    -1,
       4,    53,    54,    55,    56,    57,    68,    -1,    70,    61,
      -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,
      82,    83,    84,    85,    86,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    27,    28,    61,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    58,    59,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,
      -1,    74,    54,    -1,    -1,    78,    58,    59,    81,    82,
      83,    84,    85,    86,    27,    28,    68,    -1,    70,    71,
      -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,
      82,    83,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    58,    59,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    54,    -1,    -1,    -1,    58,    59,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    -1,
      80,    81,    82,    83,    84,    85,    86,    54,    -1,    -1,
      -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,    13,    -1,    -1,    74,    -1,    -1,
      -1,    78,    -1,    -1,    81,    82,    83,    84,    85,    86,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    61,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    61,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    61,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    61,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    61,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    61,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      61,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    66,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    66,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    66,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    66,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    29,    61,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    29,    -1,    61,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    29,    -1,    61,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    29,    -1,    61,    32,    33,    34,
      35,    36,    37,    -1,    -1,    29,    -1,    -1,    32,    33,
      34,    35,    36,    37,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    61,    51,    52,    53,
      54,    55,    56,    57,    -1,    29,    -1,    61,    32,    33,
      -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    25,    61,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,     8,     9,    10,    11,    12,    14,
      27,    28,    66,    74,    86,    88,    89,    90,    91,    97,
     100,   106,   107,   108,   109,   110,   121,   122,   123,   127,
     128,   129,   130,   133,     1,    86,    92,    93,    94,    54,
      58,    59,    68,    70,    74,    78,    81,    82,    83,    84,
      85,    86,   100,   103,   105,   106,   107,   110,   112,   113,
     114,   115,   116,   117,   118,   119,   105,    86,   107,   109,
     131,   105,   105,   105,   109,   109,    89,     1,    74,    86,
     101,   103,     1,    74,    76,    86,    98,    99,   100,   103,
     110,   112,   113,     0,    66,    25,    27,    28,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    25,    25,
      86,    95,    96,    73,   105,   105,   105,    69,   105,   111,
      71,   105,   111,   120,     5,    86,   103,   104,   105,    79,
     111,   120,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    61,    66,    73,    66,    13,    66,    99,   102,   102,
      75,   102,   105,   105,    98,    89,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,     1,   105,
      51,    26,    95,    66,    86,    92,    73,    69,     4,    71,
      71,    95,    75,    75,    79,    79,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,    80,   105,   124,   125,
     126,   105,    89,    86,    89,    66,   102,    75,    77,    86,
      89,    92,   111,   105,    26,    72,    72,    67,    66,    66,
      73,    67,    66,    15,    16,    67,   134,   102,    52,    67,
      89,    89,    89,   124,   108,   132,    89,   105,    89,    16,
      67,    67,    67,    66,    67,    66,    67,    89,    89,    89,
      67,    67,   134
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    89,    89,    89,    89,    90,    90,
      90,    91,    91,    92,    92,    92,    93,    93,    93,    93,
      94,    95,    95,    96,    96,    97,    98,    98,    99,    99,
      99,    99,    99,    99,    99,    99,   100,   101,   101,   101,
     102,   102,   102,   103,   104,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   106,   106,   106,
     106,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   108,   108,   108,   108,   109,   109,   110,   111,
     111,   112,   112,   112,   112,   112,   113,   113,   113,   113,
     114,   114,   115,   115,   116,   116,   117,   117,   118,   119,
     120,   121,   121,   121,   121,   121,   121,   122,   122,   123,
     124,   124,   124,   125,   126,   127,   127,   127,   128,   129,
     130,   131,   131,   132,   132,   133,   133,   133,   133,   134,
     134
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     3,     2,     1,     1,
       1,     2,     2,     1,     3,     4,     1,     3,     3,     3,
       5,     0,     2,     1,     4,     2,     0,     2,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     2,     2,     2,
       1,     2,     3,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     2,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     2,     3,     2,     3,     1,     1,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     5,
       2,     2,     3,     4,     4,     1,     1,     1,     5,     7,
       9,     0,     1,     0,     1,     5,     7,     6,     8,     4,
       5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
  switch (yytype)
    {
          case 81: /* CONST_STRING  */
#line 60 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).vstring); }
#line 1606 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 82: /* CONST_INT  */
#line 60 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).vstring); }
#line 1612 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 83: /* CONST_FLOAT  */
#line 60 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).vstring); }
#line 1618 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 84: /* CONST_BOOL  */
#line 60 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).vstring); }
#line 1624 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 85: /* CONST_CHAR  */
#line 60 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).vstring); }
#line 1630 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 86: /* IDENTIFIER  */
#line 60 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).vstring); }
#line 1636 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 89: /* scope  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1642 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 90: /* program-element  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1648 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 91: /* declaration  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1654 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 92: /* decl-vars  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1660 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 93: /* decl-var  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1666 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 94: /* decl-func  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1672 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 95: /* param-list  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1678 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 96: /* param  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1684 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 97: /* func-call  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1690 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 98: /* arg-list  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1696 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 99: /* argument  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1702 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 100: /* braced-func-call  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1708 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 101: /* func-call-eol  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1714 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 102: /* arg-list-eol  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1720 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 103: /* soy-expression  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1726 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 104: /* soy-func  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1732 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 105: /* expression  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1738 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 106: /* incr-expression  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1744 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 107: /* assignment  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1750 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 108: /* modifying-expression  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1756 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 109: /* assignable-expression  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1762 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 110: /* datastructure-access  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1768 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 111: /* expression-list  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1774 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 112: /* constant  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1780 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 113: /* datastructure  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1786 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 114: /* array  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1792 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 115: /* list  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1798 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 116: /* tuple  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1804 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 117: /* make-sequence  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1810 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 118: /* make-sequence-list  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1816 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 119: /* make-sequence-array  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1822 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 120: /* seq-expression  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1828 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 121: /* statement  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1834 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 122: /* return  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1840 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 123: /* menu  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1846 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 124: /* menu-body  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1852 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 125: /* menu-case  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1858 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 126: /* menu-def  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1864 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 127: /* loop  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1870 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 128: /* roll  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1876 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 129: /* foreach  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1882 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 130: /* for  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1888 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 131: /* for-initializer  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1894 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 132: /* for-update  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1900 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 133: /* conditional  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1906 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 134: /* elseif  */
#line 61 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1912 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;


      default:
        break;
    }
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

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

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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

/* User initialization code.  */
#line 50 "parser/spp_parser.y" /* yacc.c:1429  */
{
	error_occurred = false;
}

#line 2019 "parser/sushipp.tab.c" /* yacc.c:1429  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 176 "parser/spp_parser.y" /* yacc.c:1646  */
    { g_compiler->set_syntax_tree_root(new ast::Program); }
#line 2208 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 178 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		if(error_occurred)
		{
			delete ((ast::ASTNode*) (yyvsp[0].vnode));
			YYABORT;
		}

		ast::ASTNode* prog = new ast::Program;

		if(prog == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		prog->add_child((ast::ASTNode*)(yyvsp[0].vnode));
		g_compiler->set_syntax_tree_root(prog); 
	}
#line 2231 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 202 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Scope);
		
		if((yyval.vnode) == nullptr)
		{	
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2247 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 214 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Scope);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
	}
#line 2263 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 226 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Scope);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));

		// delete remaining node (which has no children)
		delete ((ast::Scope*)(yyvsp[0].vnode));
	}
#line 2283 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 242 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Scope);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));

		// delete remaining node (which has no children)
		delete ((ast::Scope*)(yyvsp[0].vnode));
	}
#line 2302 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 260 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ProgramElement);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2318 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 272 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ProgramElement);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2334 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 284 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ProgramElement);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2350 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 302 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Declaration);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_Maki);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2367 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 315 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Declaration);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_Maki);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2384 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 332 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::DeclVars);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2400 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 344 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::DeclVars);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Virg);
		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));

		// delete remaining node (which has no children)
		delete ((ast::DeclVars*)(yyvsp[0].vnode));
	}
#line 2421 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 361 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::DeclVars);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-3].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Virg);
		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));

		// delete remaining node (which has no children)
		delete ((ast::DeclVars*)(yyvsp[0].vnode));
	}
#line 2442 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 381 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::DeclVar);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[0].vstring)));
		
		// delete the memory allocated for the string
		delete (yyvsp[0].vstring);
	}
#line 2461 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 396 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::DeclVar);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[-2].vstring)));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Op_Assignment);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));

		// delete the memory allocated for the string
		delete (yyvsp[-2].vstring);
	}
#line 2482 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 413 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ErrorNode);
		//cerr << " Details : a valid identifier name was exptected as left-hand-side item." << endl;
		yyerrok;
	}
#line 2492 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 419 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ErrorNode);
		// delete the memory allocated for the string
		delete (yyvsp[-2].vstring);
		//cerr << " Details : a valid expression was exptected as right-hand-side item." << endl;
		yyerrok;
	}
#line 2504 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 431 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::DeclFunc);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[-4].vstring)));

		if((yyvsp[-3].vnode) != nullptr) // if no parameters
			((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-3].vnode));

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Op_AssignFunc);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		//((ast::ASTNode*)$$)->add_child(new ast::DelimEos);

		// delete the memory allocated for the string
		delete (yyvsp[-4].vstring);
	}
#line 2530 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 457 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = nullptr;
	}
#line 2538 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 461 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ParamList);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));

		if((yyvsp[0].vnode) != nullptr)
		{
			((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));
			
			// delete remaining node (which has no children)
			delete ((ast::ParamList*)(yyvsp[0].vnode));
		}
	}
#line 2562 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 484 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Param);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[0].vstring)));

		// delete the memory allocated for the string
		delete (yyvsp[0].vstring);
	}
#line 2581 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 499 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Param);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[-3].vstring)));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::OpenChevr);
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[-1].vstring))); /** Discriminate identifier for type */
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::ClosingChevr);

		// delete the memory allocated for the string
		delete (yyvsp[-3].vstring);
		delete (yyvsp[-1].vstring);
	}
#line 2604 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 525 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::FuncCall);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[-1].vstring)));

		if((yyvsp[0].vnode) != nullptr)
			((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));

		// delete the memory allocated for the string
		delete (yyvsp[-1].vstring);
	}
#line 2626 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 546 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = nullptr;
	}
#line 2634 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 552 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ArgList);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));

		if((yyvsp[0].vnode) != nullptr)
		{
			((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));
			
			// delete remaining node (which has no children)
			delete ((ast::ArgList*)(yyvsp[0].vnode));
		}
	}
#line 2658 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 575 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Argument);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[0].vstring)));

		// delete the memory allocated for the string
		delete (yyvsp[0].vstring);
	}
#line 2677 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 590 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Argument);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2693 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 602 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Argument);

		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2709 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 614 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Argument);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::OpenPar);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::ClosingPar);
	}
#line 2727 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 628 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Argument);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2743 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 640 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Argument);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2759 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 652 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Argument);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2775 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 664 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ErrorNode);
		/*cerr << " Details : the argument is invalid. It should be either " << endl
			 << "    a constant, a braced expression, an anonymous soy function, " << endl
			 << "    a datastructure access or a variable." << endl; */
		yyclearin;
	}
#line 2787 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 675 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::BracedFuncCall);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::OpenPar);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::ClosingPar);
	}
#line 2805 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 697 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::FuncCallEol);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[-1].vstring)));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));

		// delete the memory allocated for the string
		delete (yyvsp[-1].vstring);
	}
#line 2825 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 713 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::FuncCallEol);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2842 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 726 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ErrorNode);
		//cerr << " Details : either an identifier or a soy anonymous function was expected" << endl;
		yyerrok;
	}
#line 2852 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 735 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ArgListEol);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2868 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 747 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ArgListEol);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));

		// delete remaining node (which has no children)
		delete ((ast::ArgListEol*)(yyvsp[0].vnode));
	}
#line 2888 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 763 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ArgListEol);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));

		// delete remaining node (which has no children)
		delete ((ast::ArgListEol*)(yyvsp[0].vnode));
	}
#line 2908 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 783 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::SoyExpression);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::OpenPar);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::ClosingPar);
	}
#line 2926 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 800 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::SoyFunc);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_Soy);

		if((ast::ASTNode*)(yyvsp[-2].vnode) != nullptr)
			((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Op_AssignFunc);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2948 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 824 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Expression);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2964 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 836 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Expression);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::OpenPar);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::ClosingPar);
	}
#line 2982 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 850 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Expression);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[0].vstring)));

		// delete the memory allocated for the string
		delete (yyvsp[0].vstring);
	}
#line 3001 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 865 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Expression);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3017 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 877 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Expression);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3033 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 889 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Expression);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3049 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 901 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Expression);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3065 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 913 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Expression);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3081 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 925 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Expression);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3097 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 937 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_Plus);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3114 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 950 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_Minus);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3131 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 963 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_Mult);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3148 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 976 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_Div);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3165 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 989 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_Modulo);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3182 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1002 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_Exponentiation);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3199 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1015 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_UnaryMinus);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3215 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1027 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_BitwiseOr);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3232 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1040 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_BitwiseAnd);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3249 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1053 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_BitwiseXor);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3266 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1066 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_BitwiseNot);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3282 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1078 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_LogicalOr);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3299 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1091 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_LogicalAnd);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3316 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1104 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_LogicalNot);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3332 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1116 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_CompLessThan);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3349 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1129 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_CompGreaterThan);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3366 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1142 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_CompLessEqual);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3383 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1155 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_CompGreaterEqual);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3400 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1168 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_CompEqual);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3417 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1181 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_CompNotEqual);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3434 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1194 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_RightShift);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3451 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1207 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_LeftShift);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3468 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1220 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_StringConcat);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3485 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1236 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_PrefixIncrement);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3501 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1248 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_PrefixDecrement);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3517 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1260 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_PostfixIncrement);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
	}
#line 3533 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1272 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_PostfixDecrement);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
	}
#line 3549 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1287 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_Assignment);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3566 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1300 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignPlus);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3583 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1313 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignMinus);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3600 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1326 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignMult);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3617 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1339 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignDiv);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3634 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1352 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignExpo);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3651 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1365 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignMod);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3668 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1378 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignAnd);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3685 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1391 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignOr);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3702 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1404 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignXor);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3719 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1417 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignConcat);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3736 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1437 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ModifyingExpression);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3752 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1449 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ModifyingExpression);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3768 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1461 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ModifyingExpression);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3784 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1473 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ModifyingExpression);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3800 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1491 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::AssignableExpression);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[0].vstring)));

		// delete the memory allocated for the string
		delete (yyvsp[0].vstring);
	}
#line 3819 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1506 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::AssignableExpression);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3835 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1521 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::DatastructureAccess);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[-3].vstring)));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::OpenBrace);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::ClosingBrace);

		// delete allocated string
		delete (yyvsp[-3].vstring);
	}
#line 3857 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1543 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ExpressionList);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3873 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1555 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ExpressionList);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Virg);
		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));

		// delete remaining node (which has no children)
		delete ((ast::ExpressionList*)(yyvsp[0].vnode));
	}
#line 3894 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1578 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::NT_Constant);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Integer(*(yyvsp[0].vstring)));
		
		// delete allocated string
		delete (yyvsp[0].vstring);
	}
#line 3913 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1593 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::NT_Constant);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Float(*(yyvsp[0].vstring)));
		
		// delete allocated string
		delete (yyvsp[0].vstring);
	}
#line 3932 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1608 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::NT_Constant);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::String(*(yyvsp[0].vstring)));
		
		// delete allocated string
		delete (yyvsp[0].vstring);
	}
#line 3951 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1623 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::NT_Constant);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Bool(*(yyvsp[0].vstring)));
		
		// delete allocated string
		delete (yyvsp[0].vstring);
	}
#line 3970 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1638 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::NT_Constant);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Character(*(yyvsp[0].vstring)));
		
		// delete allocated string
		delete (yyvsp[0].vstring);
	}
#line 3989 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1659 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Datastructure);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 4005 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1671 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Datastructure);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 4021 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1683 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Datastructure);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 4037 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1695 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Datastructure);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 4053 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1710 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Array);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::ArrayBeg);
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::ArrayEnd);
	}
#line 4070 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1723 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Array);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::ArrayBeg);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::ArrayEnd);
	}
#line 4088 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1740 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::List);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::OpenAcc);
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::ClosingAcc);
	}
#line 4105 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1753 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::List);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::OpenAcc);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::ClosingAcc);
	}
#line 4123 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1770 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Tuple);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::TupleBeg);
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::TupleEnd);
	}
#line 4140 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1783 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Tuple);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::TupleBeg);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::TupleEnd);
	}
#line 4158 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1803 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::MakeSequence);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 4174 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1815 "parser/spp_parser.y" /* yacc.c:1646  */
    {	
		(yyval.vnode) = (void*) (new ast::MakeSequence);

		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	 }
#line 4190 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1830 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::MakeSequenceList);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::OpenAcc());
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::ClosingAcc());
	}
#line 4208 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1847 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::MakeSequenceArray);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::ArrayBeg());
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::ArrayEnd());

	}
#line 4227 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1865 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::SeqExpression);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_To());
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 4245 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1885 "parser/spp_parser.y" /* yacc.c:1646  */
    {	
		(yyval.vnode) = (void*) (new ast::Statement);

		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 4261 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1897 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Statement);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 4277 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1909 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Statement);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 4293 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1921 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Statement);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_Continue);
	}
#line 4309 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1933 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Statement);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_Break);
	}
#line 4325 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1945 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Statement);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 4341 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1961 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Return);

		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_Nori);
	}
#line 4357 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1973 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Return);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_Nori);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 4374 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1990 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Menu);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_Menu);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-3].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		//((ast::ASTNode*)$$)->add_child(new ast::DelimEos);
	}
#line 4393 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 2008 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::MenuBody);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
	}
#line 4409 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 2020 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::MenuBody);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
 
	}
#line 4426 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 2033 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::MenuBody);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));

		// delete remaining node (which has no children)
		delete ((ast::MenuBody*)(yyvsp[0].vnode));
	}
#line 4446 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 2052 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::MenuCase);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-3].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Arrow);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		//((ast::ASTNode*)$$)->add_child(new ast::DelimEos);
	}
#line 4465 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 2070 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::MenuDef);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Underscore);
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Arrow);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		//((ast::ASTNode*)$$)->add_child(new ast::DelimEos);
	}
#line 4484 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 2089 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Loop);

		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 4500 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 2101 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Loop);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 4516 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 2113 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Loop);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 4532 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 2131 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Roll);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_Roll);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-3].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		//((ast::ASTNode*)$$)->add_child(new ast::DelimEos);
	}
#line 4551 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 2152 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Foreach);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_Foreach);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-5].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_As);
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[-3].vstring)));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		//((ast::ASTNode*)$$)->add_child(new ast::DelimEos);

		// delete the memory allocated for the string
		delete (yyvsp[-3].vstring);
	}
#line 4575 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 2183 "parser/spp_parser.y" /* yacc.c:1646  */
    {	
		(yyval.vnode) = (void*) (new ast::For);

		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_For);

		if((ast::ASTNode*)(yyvsp[-7].vnode) != nullptr)
			((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-7].vnode));

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Virg);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-5].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Virg);

		if((ast::ASTNode*)(yyvsp[-7].vnode) != nullptr)
			((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-3].vnode));

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		//((ast::ASTNode*)$$)->add_child(new ast::DelimEos);
	}
#line 4604 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 2211 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = nullptr;
	}
#line 4612 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 2215 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ForInitializer);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 4628 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 2230 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = nullptr;
	}
#line 4636 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 2234 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ForUpdate);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 4652 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 2250 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		
		(yyval.vnode) = (void*) (new ast::Conditional);

		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_If);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-3].vnode));
 
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		//((ast::ASTNode*)$$)->add_child(new ast::DelimEos);
	}
#line 4673 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 2267 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Conditional);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_If);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-5].vnode));
 
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-3].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_Else);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		//((ast::ASTNode*)$$)->add_child(new ast::DelimEos);
	}
#line 4695 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 2285 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Conditional);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_If);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-4].vnode));
 
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		//((ast::ASTNode*)$$)->add_child(new ast::DelimEos);
	}
#line 4716 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 2302 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Conditional);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("cannot allocate a new node");
			return 1;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_If);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-6].vnode));
 
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-4].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-3].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_Else);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		//((ast::ASTNode*)$$)->add_child(new ast::DelimEos);
	}
#line 4739 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 2324 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Elseif);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_Elseif);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
 
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 4758 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 2339 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Elseif);
		
		if((yyval.vnode) == nullptr)
		{
			yyerror("Cannot allocate a new node");
			return 2;
		}

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_Elseif);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-3].vnode));
 
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 4778 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;


#line 4782 "parser/sushipp.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 2356 "parser/spp_parser.y" /* yacc.c:1906  */


static void yyerror(const char *s)
{
	error_occurred = true;
	std::cerr << "[Error] " << s << curr_line_row() << std::endl;
}

static std::string curr_line_row()
{
	std::stringstream ss;
	ss << " at line " << yylloc.first_line << " (column " << yylloc.first_column << ")";
	return ss.str();
}
