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

	/** AST includes*/
	#include "../ast/AbstractSyntaxTree.hpp"
	#include "../ast/nodes/ASTNode.hpp"
	#include "../ast/nodes/NodeLocation.hpp"

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

	using namespace std;
	using namespace ast;

	extern "C" int yylex();

	static void yyerror(const char*);
	static string curr_line_row();

	// will store a pointer to the abstract syntax tree constructed by the parser
	extern AbstractSyntaxTree* syntax_tree;

#line 104 "parser/sushipp.tab.c" /* yacc.c:339  */

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
#line 43 "parser/spp_parser.y" /* yacc.c:355  */

	std::string* vstring;
	void* vnode;

#line 213 "parser/sushipp.tab.c" /* yacc.c:355  */
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

#line 242 "parser/sushipp.tab.c" /* yacc.c:358  */

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
#define YYFINAL  92
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1511

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
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
       0,   161,   161,   162,   167,   175,   180,   186,   193,   202,
     207,   212,   223,   229,   239,   244,   251,   262,   270,   280,
     285,   294,   313,   317,   327,   332,   351,   365,   369,   380,
     388,   393,   400,   405,   410,   415,   425,   440,   447,   453,
     461,   466,   472,   483,   493,   510,   515,   522,   529,   534,
     539,   544,   549,   554,   559,   566,   573,   580,   587,   594,
     601,   607,   614,   621,   628,   634,   641,   648,   654,   661,
     668,   675,   682,   689,   696,   703,   710,   720,   726,   732,
     738,   747,   754,   761,   768,   775,   782,   789,   796,   803,
     810,   817,   831,   836,   841,   846,   857,   864,   872,   886,
     891,   904,   911,   918,   925,   932,   945,   950,   955,   960,
     968,   974,   984,   990,  1000,  1006,  1019,  1024,  1032,  1042,
    1053,  1066,  1071,  1076,  1081,  1086,  1091,  1100,  1105,  1115,
    1127,  1133,  1139,  1149,  1160,  1172,  1177,  1182,  1193,  1208,
    1231,  1253,  1257,  1265,  1269,  1278,  1287,  1298,  1308,  1323,
    1331
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
  "CONST_CHAR", "IDENTIFIER", "$accept", "program", "scope", "scope-body",
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

#define YYPACT_NINF -175

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-175)))

#define YYTABLE_NINF -98

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     441,    21,   804,   804,   -69,   804,  -175,  -175,   804,   804,
     -69,   -69,   441,    17,   456,    24,  -175,   -33,  -175,  -175,
    -175,  -175,  -175,  -175,  1441,  -175,  -175,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,     9,    11,  -175,   -32,  -175,   804,
     804,   804,   678,   699,   146,   738,  -175,  -175,  -175,  -175,
    -175,   856,  -175,  -175,  1274,  -175,  -175,  1464,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  1122,   -34,  -175,   420,
     -30,  1160,   891,  1198,  -175,  -175,  -175,   236,    40,   236,
     -31,   236,  -175,   146,   804,   -34,  -175,   489,  -175,  -175,
    -175,  -175,  -175,   441,   804,  -175,  -175,   804,   804,   804,
     804,   804,   804,   804,   804,   804,   804,   804,   279,    -3,
      47,   -10,    18,    -8,    -8,    -8,  -175,  1023,   -17,  -175,
     667,    14,    15,   -10,   551,   609,   -21,   957,  -175,    20,
      42,   804,   804,   804,   804,   804,   804,   804,   804,   804,
     804,   804,   804,   804,   804,   804,   804,   804,   804,   804,
     804,   771,   804,   441,    19,   441,   101,  -175,  -175,  -175,
    -175,   990,   924,  -175,  -175,  1274,  1274,  1274,  1274,  1274,
    1274,  1274,  1274,  1274,  1274,  1274,  1274,  -175,  1274,    36,
     441,  -175,    28,    63,  -175,   804,  -175,   804,  -175,  -175,
      75,  -175,  -175,  -175,  -175,    -8,  1305,  1335,   104,   104,
     350,   350,     2,     2,  1365,  1395,  1406,   104,   104,    54,
      54,    -8,    -8,    -8,    -8,    51,  1089,    61,    64,    65,
    1056,    62,  -175,    68,    31,   236,  -175,  -175,  -175,    83,
      69,  -175,  -175,  1274,   441,   441,   441,  -175,   771,  -175,
      22,  -175,   441,   804,   441,  -175,    -1,  -175,  -175,  -175,
    -175,    72,    76,  -175,  -175,    80,    81,  1236,    85,   441,
    -175,  -175,  -175,   441,  -175,   441,  -175,    87,    95,   127,
    -175,  -175,  -175
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,   127,     0,   141,     0,   125,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     5,    11,    95,
      94,    93,    92,    10,     0,    97,     9,   121,   122,   123,
     137,   135,   136,   126,     0,    17,    13,    14,    12,     0,
       0,     0,     0,     0,     0,     0,   103,   101,   102,   104,
     105,    47,    53,    49,   128,    51,    52,    50,    45,    48,
     106,   107,   108,   109,   116,   117,     0,    96,   142,     0,
       0,     0,     0,     0,    77,    78,     8,     0,     0,     0,
       0,     0,    35,     0,     0,    29,    26,     0,    34,    32,
      33,    30,     1,     6,     0,    79,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
       0,    22,     0,    60,    64,    67,   114,    99,     0,   110,
      99,     0,     0,    22,     0,     0,     0,     0,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,    37,    36,
      38,     0,     0,    28,     7,    81,    82,    83,    84,    85,
      86,    87,    89,    88,    90,    91,    19,    20,    18,     0,
       0,    23,     0,    17,    15,     0,   115,     0,   111,   119,
       0,    43,    46,   113,   118,    59,    65,    66,    70,    71,
      72,    73,    75,    74,    61,    63,    62,    68,    69,    54,
      55,    56,    57,    58,    76,     0,     0,     0,     0,     0,
       0,     0,     4,     0,     0,     0,    41,    31,    98,     0,
       0,    16,   100,   120,     0,     0,     0,   129,   131,   130,
     143,   138,     0,     0,     0,   145,     0,    42,    25,    21,
      44,     0,     0,   132,   144,     0,     0,     0,     0,     0,
     147,   134,   133,     0,   139,     0,   146,     0,     0,   149,
     148,   140,   150
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -175,  -175,  -174,    23,  -175,  -175,  -104,  -175,  -175,   -83,
    -175,  -175,    84,    -5,    13,  -175,   -61,   -12,  -175,   291,
      39,    26,   -90,   116,     0,   -40,    -7,  -175,  -175,  -175,
    -175,  -175,  -175,  -175,   118,  -175,  -175,  -175,   -68,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,   -97
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,   221,   222,    17,    18,    36,    37,    38,   110,
     111,    19,    86,   156,    52,    80,   158,    53,   126,   117,
      55,    56,    23,    24,    57,   118,    58,    59,    60,    61,
      62,    63,    64,    65,   122,    26,    27,    28,   217,   218,
     219,    29,    30,    31,    32,    70,   255,    33,   246
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    81,    89,   121,    25,   129,   230,    91,   184,    87,
      25,    25,    25,    20,    90,   259,   157,    67,    77,    34,
     160,   131,    34,    16,    92,    20,    22,    88,   181,    34,
      68,   131,   125,    93,   107,    76,   108,   -22,    22,    21,
     190,   112,    84,   152,   159,   123,   243,   244,   179,    10,
      11,    21,   186,   150,   191,   145,   146,   147,   148,   149,
     250,   251,   252,   150,   160,    89,   260,    89,   256,    89,
      91,   125,    91,   180,    91,    89,   109,    90,   231,    90,
      91,    90,    87,   131,   182,   188,   189,    90,   108,   268,
      88,    78,    88,    25,    88,   226,    13,   109,   245,   193,
      88,   234,    82,    79,   183,   223,    20,    35,    14,   147,
     148,   149,    89,    89,   183,   150,   164,    91,    91,    22,
      69,   194,   229,   235,    90,    90,    74,    75,   237,   241,
     238,   239,    21,   131,   242,   248,   249,    88,    88,   261,
     138,   139,   243,   262,    89,   232,   263,    77,   264,    91,
     254,   123,   266,    25,   270,    25,    90,   145,   146,   147,
     148,   149,   271,   130,   247,   150,    20,   225,    20,    88,
     253,   163,   272,    10,    11,    83,   -40,     0,   224,    22,
      25,    22,    46,    47,    48,    49,    50,    85,     0,     0,
       0,     0,    21,    20,    21,     0,     0,     0,     0,     0,
      39,     0,     0,     0,    40,    41,    22,     0,     0,     0,
       0,     0,     0,    89,    42,     0,    43,     0,    91,    21,
      44,     0,     0,     0,    45,    90,     0,    46,    47,    48,
      49,    50,   124,     0,    25,    25,    25,    82,    88,     0,
      25,     0,    25,     0,    25,     0,     0,    20,    20,    20,
       0,     0,     0,    20,     0,    20,     0,    20,     0,    25,
      22,    22,    22,    25,     0,    25,    22,   258,    22,     0,
      22,     0,    20,    21,    21,    21,    20,     0,    20,    21,
     177,    21,   267,    21,     0,    22,     0,     0,   269,    22,
       0,    22,     0,    54,    66,     0,    71,     0,    21,    72,
      73,     0,    21,     0,    21,     0,    10,    11,     0,     0,
      83,     0,     0,     0,     0,     0,     0,    46,    47,    48,
      49,    50,    85,     0,     0,     0,     0,     0,     0,     0,
     113,   114,   115,    39,   120,   127,   120,    40,    41,     0,
       0,     0,     0,     0,     0,     0,     0,    42,     0,    43,
       0,     0,     0,    44,     0,     0,     0,    45,     0,     0,
      46,    47,    48,    49,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,   161,   162,     0,     0,     0,   131,
       0,     0,   134,   135,     0,   165,   138,   139,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   178,
       0,   143,   144,   145,   146,   147,   148,   149,     0,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   216,   220,     1,    94,     0,     2,     3,     4,
       5,     6,     7,     8,     0,     9,   -27,    82,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    10,    11,
       0,   -27,   -27,     0,     0,     0,     0,     0,   233,     0,
       0,   -96,     0,   -96,   -96,     0,     0,     0,     0,   -27,
      82,     0,     0,     0,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -27,   -27,     0,    12,     0,     0,
       0,     0,     0,     0,     0,    13,     0,     0,     0,     0,
       0,     0,   -27,   -27,     0,     0,     0,    14,     0,   216,
      83,   -27,    84,     0,   257,     0,     0,    46,    47,    48,
      49,    50,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,   -27,   -27,     0,     0,     0,
       0,     0,     0,    83,   -27,     0,     0,     0,     0,     0,
      46,    47,    48,    49,    50,    85,   -96,     0,   -96,   -96,
     -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,     0,
      82,     0,   -47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83,   -47,    84,     0,     0,
       0,     0,    46,    47,    48,    49,    50,    85,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,     0,
     -49,   187,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,   -49,     0,     0,     0,     0,     0,
      46,    47,    48,    49,    50,    85,   131,   132,   133,   134,
     135,   136,   137,   138,   139,    10,    11,     0,     0,     0,
       0,     0,     0,     0,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,    10,    11,   150,     0,
       0,     0,    39,     0,     0,     0,    40,    41,     0,     0,
     185,     0,     0,     0,     0,     0,    42,   116,    43,     0,
       0,     0,    44,    39,     0,     0,    45,    40,    41,    46,
      47,    48,    49,    50,    51,    10,    11,    42,     0,    43,
     119,     0,     0,    44,     0,     0,     0,    45,     0,     0,
      46,    47,    48,    49,    50,    51,     0,     0,     0,     0,
       0,     0,    39,     0,     0,     0,    40,    41,    10,    11,
       0,     0,     0,     0,     0,     0,    42,     0,    43,     0,
       0,     0,    44,     0,     0,     0,    45,   128,     0,    46,
      47,    48,    49,    50,    51,    39,     0,     0,     0,    40,
      41,    10,    11,     0,     0,     0,     0,     0,     0,    42,
       0,    43,     0,     0,     0,    44,     0,     0,     0,    45,
       0,   215,    46,    47,    48,    49,    50,    51,    39,     0,
       0,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,    43,     0,     0,     0,    44,     0,
       0,   -96,    45,   -96,   -96,    46,    47,    48,    49,    50,
      51,     0,     0,     0,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   154,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,     0,
       0,     0,   150,   131,   132,   133,   134,   135,   136,   137,
     138,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,     0,     0,     0,   150,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,     0,     0,     0,
       0,   228,     0,     0,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,     0,   150,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,     0,   192,     0,     0,     0,     0,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,     0,
       0,   150,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,     0,     0,     0,   227,     0,     0,     0,     0,
       0,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,     0,     0,     0,   150,   131,   132,   133,   134,   135,
     136,   137,   138,   139,     0,     0,   185,     0,     0,     0,
       0,     0,     0,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,     0,     0,     0,   150,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,     0,   240,
       0,     0,     0,     0,     0,     0,     0,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,     0,
     150,   131,   132,   133,   134,   135,   136,   137,   138,   139,
       0,   236,     0,     0,     0,     0,     0,     0,     0,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,     0,   150,     0,     0,     0,     0,   151,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,     0,
       0,   150,     0,     0,     0,     0,   153,   131,   132,   133,
     134,   135,   136,   137,   138,   139,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,     0,     0,     0,   150,
       0,     0,     0,     0,   155,   131,   132,   133,   134,   135,
     136,   137,   138,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,     0,     0,     0,   150,     0,     0,
       0,     0,   265,   131,   132,   133,   134,   135,   136,   137,
     138,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,     0,     0,   131,   150,   133,   134,   135,   136,
     137,   138,   139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,   131,     0,   150,   134,   135,   136,
     137,   138,   139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,   131,     0,   150,   134,   135,   136,
     137,   138,   139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,   131,     0,   150,   134,   135,   136,
     137,   138,   139,     0,     0,   131,     0,     0,   134,   135,
     136,   137,   138,   139,     0,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,     0,   150,   143,   144,   145,
     146,   147,   148,   149,     0,     0,    94,   150,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   -97,
       0,   -97,   -97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97
};

static const yytype_int16 yycheck[] =
{
       0,    13,    14,    43,     4,    45,   180,    14,   112,    14,
      10,    11,    12,     0,    14,    16,    77,    86,     1,     1,
      81,    29,     1,     0,     0,    12,     0,    14,   111,     1,
       4,    29,    44,    66,    25,    12,    25,    26,    12,     0,
     123,    73,    76,    73,    75,     5,    15,    16,    51,    27,
      28,    12,    69,    61,    75,    53,    54,    55,    56,    57,
     234,   235,   236,    61,   125,    77,    67,    79,   242,    81,
      77,    83,    79,    26,    81,    87,    86,    77,   182,    79,
      87,    81,    87,    29,    66,    71,    71,    87,    25,   263,
      77,    74,    79,    93,    81,   156,    74,    86,    67,    79,
      87,    26,     1,    86,    86,    86,    93,    86,    86,    55,
      56,    57,   124,   125,    86,    61,    93,   124,   125,    93,
       4,    79,    86,    72,   124,   125,    10,    11,    67,    67,
      66,    66,    93,    29,    66,    52,    67,   124,   125,    67,
      36,    37,    15,    67,   156,   185,    66,     1,    67,   156,
     240,     5,    67,   153,    67,   155,   156,    53,    54,    55,
      56,    57,    67,    45,   225,    61,   153,    66,   155,   156,
     238,    87,   269,    27,    28,    74,    75,    -1,   155,   153,
     180,   155,    81,    82,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,   153,   180,   155,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    58,    59,   180,    -1,    -1,    -1,
      -1,    -1,    -1,   225,    68,    -1,    70,    -1,   225,   180,
      74,    -1,    -1,    -1,    78,   225,    -1,    81,    82,    83,
      84,    85,    86,    -1,   234,   235,   236,     1,   225,    -1,
     240,    -1,   242,    -1,   244,    -1,    -1,   234,   235,   236,
      -1,    -1,    -1,   240,    -1,   242,    -1,   244,    -1,   259,
     234,   235,   236,   263,    -1,   265,   240,   244,   242,    -1,
     244,    -1,   259,   234,   235,   236,   263,    -1,   265,   240,
       1,   242,   259,   244,    -1,   259,    -1,    -1,   265,   263,
      -1,   265,    -1,     2,     3,    -1,     5,    -1,   259,     8,
       9,    -1,   263,    -1,   265,    -1,    27,    28,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    54,    43,    44,    45,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,
      81,    82,    83,    84,    85,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    29,
      -1,    -1,    32,    33,    -1,    94,    36,    37,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     3,    25,    -1,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,     0,     1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    27,    28,
      -1,    15,    16,    -1,    -1,    -1,    -1,    -1,   187,    -1,
      -1,    25,    -1,    27,    28,    -1,    -1,    -1,    -1,     0,
       1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    15,    16,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    -1,    -1,    -1,    86,    -1,   238,
      74,    75,    76,    -1,   243,    -1,    -1,    81,    82,    83,
      84,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    86,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
       1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    86,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      61,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    86,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    27,    28,    61,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    58,    59,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,
      -1,    -1,    74,    54,    -1,    -1,    78,    58,    59,    81,
      82,    83,    84,    85,    86,    27,    28,    68,    -1,    70,
      71,    -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,
      81,    82,    83,    84,    85,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    58,    59,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    70,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    78,    79,    -1,    81,
      82,    83,    84,    85,    86,    54,    -1,    -1,    -1,    58,
      59,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    70,    -1,    -1,    -1,    74,    -1,    -1,    -1,    78,
      -1,    80,    81,    82,    83,    84,    85,    86,    54,    -1,
      -1,    -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,
      -1,    25,    78,    27,    28,    81,    82,    83,    84,    85,
      86,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    48,
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
      54,    55,    56,    57,    -1,    -1,    25,    61,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    25,
      -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,     8,     9,    10,    11,    12,    14,
      27,    28,    66,    74,    86,    88,    90,    91,    92,    98,
     101,   107,   108,   109,   110,   111,   122,   123,   124,   128,
     129,   130,   131,   134,     1,    86,    93,    94,    95,    54,
      58,    59,    68,    70,    74,    78,    81,    82,    83,    84,
      85,    86,   101,   104,   106,   107,   108,   111,   113,   114,
     115,   116,   117,   118,   119,   120,   106,    86,   108,   110,
     132,   106,   106,   106,   110,   110,    90,     1,    74,    86,
     102,   104,     1,    74,    76,    86,    99,   100,   101,   104,
     111,   113,     0,    66,    25,    27,    28,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    25,    25,    86,
      96,    97,    73,   106,   106,   106,    69,   106,   112,    71,
     106,   112,   121,     5,    86,   104,   105,   106,    79,   112,
     121,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      61,    66,    73,    66,    13,    66,   100,   103,   103,    75,
     103,   106,   106,    99,    90,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,     1,   106,    51,
      26,    96,    66,    86,    93,    73,    69,     4,    71,    71,
      96,    75,    75,    79,    79,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,    80,   106,   125,   126,   127,
     106,    89,    90,    86,    90,    66,   103,    75,    77,    86,
      89,    93,   112,   106,    26,    72,    72,    67,    66,    66,
      73,    67,    66,    15,    16,    67,   135,   103,    52,    67,
      89,    89,    89,   125,   109,   133,    89,   106,    90,    16,
      67,    67,    67,    66,    67,    66,    67,    90,    89,    90,
      67,    67,   135
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    89,    90,    90,    90,    90,    91,
      91,    91,    92,    92,    93,    93,    93,    94,    94,    94,
      94,    95,    96,    96,    97,    97,    98,    99,    99,   100,
     100,   100,   100,   100,   100,   100,   101,   102,   102,   102,
     103,   103,   103,   104,   105,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   107,   107,   107,
     107,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   109,   109,   109,   109,   110,   110,   111,   112,
     112,   113,   113,   113,   113,   113,   114,   114,   114,   114,
     115,   115,   116,   116,   117,   117,   118,   118,   119,   120,
     121,   122,   122,   122,   122,   122,   122,   123,   123,   124,
     125,   125,   125,   126,   127,   128,   128,   128,   129,   130,
     131,   132,   132,   133,   133,   134,   134,   134,   134,   135,
     135
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     1,     2,     3,     2,     1,
       1,     1,     2,     2,     1,     3,     4,     1,     3,     3,
       3,     5,     0,     2,     1,     4,     2,     0,     2,     1,
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
#line 161 "parser/spp_parser.y" /* yacc.c:1646  */
    { syntax_tree = new AbstractSyntaxTree; }
#line 1874 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 162 "parser/spp_parser.y" /* yacc.c:1646  */
    { syntax_tree = new AbstractSyntaxTree((ASTNode*)(yyval.vnode)); }
#line 1880 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 168 "parser/spp_parser.y" /* yacc.c:1646  */
    { 
		(yyval.vnode) = (void*) (new Scope);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode)); 
	}
#line 1889 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 176 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ScopeBody);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 1898 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 181 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ScopeBody);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new DelimEol);
	}
#line 1908 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 187 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ScopeBody);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new DelimEol);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 1919 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 194 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ScopeBody);
		((ASTNode*)(yyval.vnode))->add_child(new DelimEol);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 1929 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 203 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ProgramElement);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 1938 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 208 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ProgramElement);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 1947 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 213 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ProgramElement);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 1956 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 224 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Declaration);
		((ASTNode*)(yyval.vnode))->add_child(new K_Maki);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 1966 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 230 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Declaration);
		((ASTNode*)(yyval.vnode))->add_child(new K_Maki);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 1976 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 240 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new DeclVars);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 1985 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 245 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new DeclVars);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Virg);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 1996 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 252 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new DeclVars);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-3].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Virg);
		((ASTNode*)(yyval.vnode))->add_child(new DelimEol);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2008 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 263 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new DeclVar);
		((ASTNode*)(yyval.vnode))->add_child(new Identifier(*(yyvsp[0].vstring)));
		
		// free semantic type of identifier
		//delete ((ASTNode*) $1);
	}
#line 2020 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 271 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new DeclVar);
		((ASTNode*)(yyval.vnode))->add_child(new Identifier(*(yyvsp[-2].vstring)));
		((ASTNode*)(yyval.vnode))->add_child(new Op_Assignment);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));

		// free semantic type of identifier
		//delete ((ASTNode*) $1);
	}
#line 2034 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 281 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		//cerr << " Details : a valid identifier name was exptected as left-hand-side item." << endl;
		yyerrok;
	}
#line 2043 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 286 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		//cerr << " Details : a valid expression was exptected as right-hand-side item." << endl;
		yyerrok;
	}
#line 2052 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 295 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new DeclFunc);
		((ASTNode*)(yyval.vnode))->add_child(new Identifier(*(yyvsp[-4].vstring)));

		if((ASTNode*)(yyvsp[-3].vnode) != nullptr) // if no parameters
			((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-3].vnode));

		((ASTNode*)(yyval.vnode))->add_child(new Op_AssignFunc);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new DelimEos);

		// free semantic type of identifier
		//delete ((ASTNode*) $1);
	}
#line 2071 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 314 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = nullptr;
	}
#line 2079 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 318 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ParamList);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		if((yyvsp[0].vnode) != nullptr)
			((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2090 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 328 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Param);
		((ASTNode*)(yyval.vnode))->add_child(new Identifier(*(yyvsp[0].vstring)));
	}
#line 2099 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 333 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Param);
		((ASTNode*)(yyval.vnode))->add_child(new Identifier(*(yyvsp[-3].vstring)));
		((ASTNode*)(yyval.vnode))->add_child(new OpenChevr);
		((ASTNode*)(yyval.vnode))->add_child(new Identifier(*(yyvsp[-1].vstring))); /** Discriminate identifier for type */
		((ASTNode*)(yyval.vnode))->add_child(new ClosingChevr);

		// free semantic type of identifier
		//delete ((ASTNode*) $1);
		//delete ((ASTNode*) $3);
	}
#line 2115 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 352 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Param);
		((ASTNode*)(yyval.vnode))->add_child(new Identifier(*(yyvsp[-1].vstring)));

		if((yyvsp[0].vnode) != nullptr)
			((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));

		// free semantic type of identifier
		//delete ((ASTNode*) $1);
	}
#line 2130 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 366 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = nullptr;
	}
#line 2138 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 370 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ArgList);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));

		if((yyvsp[0].vnode) != nullptr)
			((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2150 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 381 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Argument);
		((ASTNode*)(yyval.vnode))->add_child(new Identifier(*(yyvsp[0].vstring)));

		// free semantic type of identifier
		//delete ((ASTNode*) $1);
	}
#line 2162 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 389 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Argument);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2171 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 394 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Argument);
		((ASTNode*)(yyval.vnode))->add_child(new OpenPar);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new ClosingPar);
	}
#line 2182 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 401 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Argument);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2191 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 406 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Argument);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2200 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 411 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Argument);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2209 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 416 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		/*cerr << " Details : the argument is invalid. It should be either " << endl
			 << "    a constant, a braced expression, an anonymous soy function, " << endl
			 << "    a datastructure access or a variable." << endl; */
		yyclearin;
	}
#line 2220 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 426 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new BracedFuncCall);
		((ASTNode*)(yyval.vnode))->add_child(new OpenPar);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new ClosingPar);
	}
#line 2231 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 441 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new FuncCallEol);
		((ASTNode*)(yyval.vnode))->add_child(new Identifier(*(yyvsp[-1].vstring)));
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
		//delete ((ASTNode*) $1);
	}
#line 2242 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 448 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new FuncCallEol);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2252 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 454 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		//cerr << " Details : either an identifier or a soy anonymous function was expected" << endl;
		yyclearin;
	}
#line 2261 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 462 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ArgListEol);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2270 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 467 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ArgListEol);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2280 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 473 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ArgListEol);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new DelimEol);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2291 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 484 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new SoyExpression);
		((ASTNode*)(yyval.vnode))->add_child(new OpenPar);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new ClosingPar);
	}
#line 2302 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 494 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new SoyFunc);
		((ASTNode*)(yyval.vnode))->add_child(new K_Soy);

		if((ASTNode*)(yyvsp[-2].vnode) != nullptr)
			((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));

		((ASTNode*)(yyval.vnode))->add_child(new Op_AssignFunc);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2317 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 511 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2326 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 516 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child(new OpenPar);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new ClosingPar);
	}
#line 2337 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 523 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child(new Identifier(*(yyvsp[0].vstring)));

		//delete ((ASTNode*) $1);
	}
#line 2348 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 530 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2357 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 535 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2366 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 540 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2375 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 545 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2384 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 550 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2393 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 555 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2402 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 560 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_Plus);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2413 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 567 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_Minus);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2424 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 574 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_Mult);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2435 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 581 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_Div);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2446 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 588 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_Modulo);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2457 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 595 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_Exponentiation);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2468 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 602 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child(new Op_UnaryMinus);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2478 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 608 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_BitwiseOr);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2489 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 615 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_BitwiseAnd);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2500 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 622 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_BitwiseXor);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2511 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 629 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child(new Op_BitwiseNot);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2521 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 635 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_LogicalOr);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2532 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 642 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_LogicalAnd);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2543 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 649 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child(new Op_LogicalNot);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2553 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 655 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_CompLessThan);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2564 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 662 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_CompGreaterThan);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2575 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 669 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_CompLessEqual);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2586 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 676 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_CompGreaterEqual);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2597 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 683 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_CompEqual);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2608 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 690 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_CompNotEqual);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2619 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 697 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_RightShift);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2630 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 704 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_LeftShift);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2641 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 711 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Expression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_StringConcat);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2652 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 721 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new IncrExpression);
		((ASTNode*)(yyval.vnode))->add_child(new Op_PrefixIncrement);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2662 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 727 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new IncrExpression);
		((ASTNode*)(yyval.vnode))->add_child(new Op_PrefixDecrement);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2672 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 733 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new IncrExpression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_PostfixIncrement);
	}
#line 2682 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 739 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new IncrExpression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_PostfixDecrement);
	}
#line 2692 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 748 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Assignment);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_Assignment);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2703 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 755 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Assignment);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_AssignPlus);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2714 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 762 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Assignment);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_AssignMinus);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2725 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 769 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Assignment);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_AssignMult);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2736 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 776 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Assignment);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_AssignDiv);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2747 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 783 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Assignment);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_AssignExpo);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2758 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 790 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Assignment);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_AssignMod);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2769 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 797 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Assignment);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_AssignAnd);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2780 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 804 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Assignment);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_AssignOr);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2791 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 811 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Assignment);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_AssignXor);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2802 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 818 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Assignment);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Op_AssignConcat);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2813 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 832 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ModifyingExpression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2822 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 837 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ModifyingExpression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2831 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 842 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ModifyingExpression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2840 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 847 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ModifyingExpression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2849 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 858 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new AssignableExpression);
		((ASTNode*)(yyval.vnode))->add_child(new Identifier(*(yyvsp[0].vstring)));

		//delete ((ASTNode*) $1);
	}
#line 2860 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 865 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new AssignableExpression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2869 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 873 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new DatastructureAccess);
		((ASTNode*)(yyval.vnode))->add_child(new Identifier(*(yyvsp[-3].vstring)));
		((ASTNode*)(yyval.vnode))->add_child(new OpenBrace);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new ClosingBrace);

		//delete ((ASTNode*) $1);
	}
#line 2883 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 887 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ExpressionList);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2892 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 892 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ExpressionList);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Virg);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2903 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 905 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new NT_Constant);
		((ASTNode*)(yyval.vnode))->add_child(new Integer(*(yyvsp[0].vstring)));
		
		//delete ((ASTNode*) $1);
	}
#line 2914 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 912 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new NT_Constant);
		((ASTNode*)(yyval.vnode))->add_child(new Float(*(yyvsp[0].vstring)));
		
		//delete ((ASTNode*) $1);
	}
#line 2925 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 919 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new NT_Constant);
		((ASTNode*)(yyval.vnode))->add_child(new String(*(yyvsp[0].vstring)));
		
		//delete ((ASTNode*) $1);
	}
#line 2936 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 926 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new NT_Constant);
		((ASTNode*)(yyval.vnode))->add_child(new Bool(*(yyvsp[0].vstring)));
		
		//delete ((ASTNode*) $1);
	}
#line 2947 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 933 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new NT_Constant);
		((ASTNode*)(yyval.vnode))->add_child(new Character(*(yyvsp[0].vstring)));
		
		//delete ((ASTNode*) $1);
	}
#line 2958 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 946 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Datastructure);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2967 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 951 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Datastructure);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2976 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 956 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Datastructure);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2985 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 961 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Datastructure);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 2994 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 969 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Array);
		((ASTNode*)(yyval.vnode))->add_child(new ArrayBeg);
		((ASTNode*)(yyval.vnode))->add_child(new ArrayEnd);
	}
#line 3004 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 975 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Array);
		((ASTNode*)(yyval.vnode))->add_child(new ArrayBeg);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new ArrayEnd);
	}
#line 3015 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 985 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Array);
		((ASTNode*)(yyval.vnode))->add_child(new OpenAcc);
		((ASTNode*)(yyval.vnode))->add_child(new ClosingAcc);
	}
#line 3025 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 991 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Array);
		((ASTNode*)(yyval.vnode))->add_child(new OpenAcc);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new ClosingAcc);
	}
#line 3036 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1001 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Tuple);
		((ASTNode*)(yyval.vnode))->add_child(new TupleBeg);
		((ASTNode*)(yyval.vnode))->add_child(new TupleEnd);
	}
#line 3046 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1007 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Tuple);
		((ASTNode*)(yyval.vnode))->add_child(new TupleBeg);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new TupleEnd);
	}
#line 3057 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1020 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new MakeSequence);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 3066 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1025 "parser/spp_parser.y" /* yacc.c:1646  */
    {
	 	(yyval.vnode) = (void*) (new MakeSequence);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	 }
#line 3075 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1033 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new MakeSequenceList);
		((ASTNode*)(yyval.vnode))->add_child(new OpenAcc());
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new ClosingAcc());
	}
#line 3086 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1043 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new MakeSequenceArray);
		((ASTNode*)(yyval.vnode))->add_child(new ArrayBeg());
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new ArrayEnd());

	}
#line 3098 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1054 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new SeqExpression);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new K_To());
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 3109 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1067 "parser/spp_parser.y" /* yacc.c:1646  */
    {
  		(yyval.vnode) = (void*) (new Statement);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
  	}
#line 3118 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1072 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Statement);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 3127 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1077 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Statement);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 3136 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1082 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Statement);
  		((ASTNode*)(yyval.vnode))->add_child(new K_Continue);
	}
#line 3145 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1087 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Statement);
  		((ASTNode*)(yyval.vnode))->add_child(new K_Break);
	}
#line 3154 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1092 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Statement);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 3163 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1101 "parser/spp_parser.y" /* yacc.c:1646  */
    {
  		(yyval.vnode) = (void*) (new Return);
  		((ASTNode*)(yyval.vnode))->add_child(new K_Nori);
  	}
#line 3172 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1106 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Return);
  		((ASTNode*)(yyval.vnode))->add_child(new K_Nori);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 3182 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1116 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Menu);
		((ASTNode*)(yyval.vnode))->add_child(new K_Menu);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-3].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new DelimEol);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new DelimEos);
	}
#line 3195 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1128 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new MenuBody);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new DelimEol);
	}
#line 3205 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1134 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new MenuBody);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
  		((ASTNode*)(yyval.vnode))->add_child(new DelimEol);
	}
#line 3215 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1140 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new MenuBody);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new DelimEol);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 3226 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1150 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new MenuCase);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-3].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new Arrow);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new DelimEos);
	}
#line 3238 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1161 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new MenuDef);
		((ASTNode*)(yyval.vnode))->add_child(new Underscore);
		((ASTNode*)(yyval.vnode))->add_child(new Arrow);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new DelimEos);
	}
#line 3250 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1173 "parser/spp_parser.y" /* yacc.c:1646  */
    {
  		(yyval.vnode) = (void*) (new Loop);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
  	}
#line 3259 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1178 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Loop);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 3268 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1183 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Loop);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 3277 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1194 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Roll);
		((ASTNode*)(yyval.vnode))->add_child(new K_Roll);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-3].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new DelimEol);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new DelimEos);
	}
#line 3290 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1209 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Foreach);
		((ASTNode*)(yyval.vnode))->add_child(new K_Foreach);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-5].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new K_As);
		((ASTNode*)(yyval.vnode))->add_child(new Identifier(*(yyvsp[-3].vstring)));
		((ASTNode*)(yyval.vnode))->add_child(new DelimEol);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
		((ASTNode*)(yyval.vnode))->add_child(new DelimEos);
		//delete ((ASTNode*) $2);
	}
#line 3306 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1232 "parser/spp_parser.y" /* yacc.c:1646  */
    {
			(yyval.vnode) = (void*) (new For);
			((ASTNode*)(yyval.vnode))->add_child(new K_For);

			if((ASTNode*)(yyvsp[-7].vnode) != nullptr)
				((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-7].vnode));

			((ASTNode*)(yyval.vnode))->add_child(new Virg);
			((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-5].vnode));
			((ASTNode*)(yyval.vnode))->add_child(new Virg);

			if((ASTNode*)(yyvsp[-7].vnode) != nullptr)
				((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-3].vnode));

			((ASTNode*)(yyval.vnode))->add_child(new DelimEol);
			((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
			((ASTNode*)(yyval.vnode))->add_child(new DelimEos);
		}
#line 3329 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1254 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = nullptr;
	}
#line 3337 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1258 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ForInitializer);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 3346 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1266 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = nullptr;
	}
#line 3354 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1270 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ForUpdate);
		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 3363 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1279 "parser/spp_parser.y" /* yacc.c:1646  */
    {
  		(yyval.vnode) = (void*) (new Conditional);
  		((ASTNode*)(yyval.vnode))->add_child(new K_If);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-3].vnode));
  		((ASTNode*)(yyval.vnode))->add_child(new DelimEol);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
  		((ASTNode*)(yyval.vnode))->add_child(new DelimEos);
  	}
#line 3376 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1288 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Conditional);
		((ASTNode*)(yyval.vnode))->add_child(new K_If);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-5].vnode));
  		((ASTNode*)(yyval.vnode))->add_child(new DelimEol);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-3].vnode));
  		((ASTNode*)(yyval.vnode))->add_child(new K_Else);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
  		((ASTNode*)(yyval.vnode))->add_child(new DelimEos);
	}
#line 3391 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1299 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Conditional);
		((ASTNode*)(yyval.vnode))->add_child(new K_If);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-4].vnode));
  		((ASTNode*)(yyval.vnode))->add_child(new DelimEol);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
  		((ASTNode*)(yyval.vnode))->add_child(new DelimEos);
	}
#line 3405 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1309 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Conditional);
		((ASTNode*)(yyval.vnode))->add_child(new K_If);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-6].vnode));
  		((ASTNode*)(yyval.vnode))->add_child(new DelimEol);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-4].vnode));
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-3].vnode));
  		((ASTNode*)(yyval.vnode))->add_child(new K_Else);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
  		((ASTNode*)(yyval.vnode))->add_child(new DelimEos);
	}
#line 3421 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1324 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Elseif);
		((ASTNode*)(yyval.vnode))->add_child(new K_Elseif);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-2].vnode));
  		((ASTNode*)(yyval.vnode))->add_child(new DelimEol);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
  	}
#line 3433 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1332 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new Elseif);
		((ASTNode*)(yyval.vnode))->add_child(new K_Elseif);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-3].vnode));
  		((ASTNode*)(yyval.vnode))->add_child(new DelimEol);
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[-1].vnode));
  		((ASTNode*)(yyval.vnode))->add_child((ASTNode*)(yyvsp[0].vnode));
	}
#line 3446 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;


#line 3450 "parser/sushipp.tab.c" /* yacc.c:1646  */
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
#line 1342 "parser/spp_parser.y" /* yacc.c:1906  */


static void yyerror(const char *s)
{
	cerr << "[Error] " << s << curr_line_row() << endl;
}

static string curr_line_row()
{
	stringstream ss;
	ss << " at line " << yylloc.first_line << " (column " << yylloc.first_column << ")";
	return ss.str();
}
