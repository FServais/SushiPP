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

	/** print the current location data */
	static std::string curr_line_row();
	/** Return a pointer to the type node for the given string*/
	static ast::ASTNode* get_type_node(const std::string&);

	// pointer to 
	extern compiler::SppCompiler* g_compiler;
	// true if an error occurred -> used for exiting yyparse with correct code if the parser
	// reaches the end of file after error recovery
	bool error_occurred;

#line 113 "parser/sushipp.tab.c" /* yacc.c:339  */

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
    OP_ARITH_INCR = 279,
    OP_ARITH_DECR = 280,
    OP_ARITH_EXPO = 281,
    OP_LOGIC_OR = 282,
    OP_LOGIC_AND = 283,
    OP_COMP_LEQ = 284,
    OP_COMP_GEQ = 285,
    OP_COMP_EQ = 286,
    OP_COMP_NEQ = 287,
    OP_RSHIFT = 288,
    OP_LSHIFT = 289,
    OP_ASSIGN_PLUS = 290,
    OP_ASSIGN_MINUS = 291,
    OP_ASSIGN_MULT = 292,
    OP_ASSIGN_DIV = 293,
    OP_ASSIGN_EXPO = 294,
    OP_ASSIGN_MOD = 295,
    OP_ASSIGN_OR = 296,
    OP_ASSIGN_AND = 297,
    OP_ASSIGN_XOR = 298,
    OP_ASSIGN_CONCAT = 299,
    UNARY_MINUS = 300,
    PREFIX_INCR = 301,
    PREFIX_DECR = 302,
    SUFFIX_INCR = 303,
    SUFFIX_DECR = 304,
    DELIM_EOL = 305,
    DELIM_EOS = 306,
    DELIM_ARRAY_BEG = 307,
    DELIM_ARRAY_END = 308,
    DELIM_ARROW = 309,
    CONST_STRING = 310,
    CONST_INT = 311,
    CONST_FLOAT = 312,
    CONST_BOOL = 313,
    CONST_CHAR = 314,
    IDENTIFIER = 315
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 57 "parser/spp_parser.y" /* yacc.c:355  */

	std::string* vstring;
	void* vnode;

#line 219 "parser/sushipp.tab.c" /* yacc.c:355  */
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

#line 248 "parser/sushipp.tab.c" /* yacc.c:358  */

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
#define YYFINAL  91
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1517

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  148
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  268

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,     2,     2,    56,    49,     2,
      71,    72,    54,    52,    70,    53,    60,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    25,     2,
      50,    24,    51,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    73,     2,    74,    48,    77,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,    47,    76,    57,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      59,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      78,    79,    80,    81,    82,    83
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   175,   175,   176,   193,   199,   205,   215,   227,   228,
     229,   236,   237,   242,   248,   258,   271,   280,   296,   303,
     315,   333,   337,   354,   363,   401,   416,   422,   439,   448,
     454,   460,   470,   476,   482,   488,   499,   508,   518,   525,
     535,   541,   551,   565,   569,   584,   585,   586,   593,   594,
     595,   596,   597,   598,   599,   606,   613,   620,   627,   634,
     641,   647,   654,   661,   668,   674,   681,   688,   694,   701,
     708,   715,   722,   729,   736,   743,   750,   760,   766,   772,
     778,   787,   794,   801,   808,   815,   822,   829,   836,   843,
     850,   857,   871,   877,   883,   889,   901,   908,   912,   929,
     938,   957,   966,   975,   984,   993,  1008,  1014,  1020,  1029,
    1033,  1042,  1046,  1057,  1063,  1072,  1081,  1091,  1111,  1117,
    1123,  1129,  1135,  1141,  1151,  1155,  1168,  1182,  1188,  1195,
    1208,  1222,  1232,  1238,  1244,  1256,  1273,  1299,  1319,  1323,
    1332,  1336,  1346,  1357,  1368,  1383,  1403,  1413,  1430
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
  "\"array\"", "\"list\"", "'='", "':'", "\"++\"", "\"--\"", "\"**\"",
  "\"||\"", "\"&&\"", "\"<=\"", "\">=\"", "\"==\"", "\"!=\"", "\">>\"",
  "\"<<\"", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"**=\"", "\"%=\"",
  "\"|=\"", "\"&=\"", "\"^=\"", "\".=\"", "'|'", "'^'", "'&'", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'~'", "'!'", "UNARY_MINUS",
  "'.'", "PREFIX_INCR", "PREFIX_DECR", "SUFFIX_INCR", "SUFFIX_DECR",
  "DELIM_EOL", "\";;\"", "\"#[\"", "\"]#\"", "\"->\"", "','", "'('", "')'",
  "'['", "']'", "'{'", "'}'", "'_'", "CONST_STRING", "CONST_INT",
  "CONST_FLOAT", "CONST_BOOL", "CONST_CHAR", "IDENTIFIER", "$accept",
  "program", "scope", "program-element", "declaration", "decl-vars",
  "decl-var", "decl-func", "param-list", "param", "func-call", "arg-list",
  "argument", "braced-func-call", "func-call-eol", "arg-list-eol",
  "soy-expression", "soy-func", "expression", "incr-expression",
  "assignment", "modifying-expression", "assignable-expression",
  "datastructure-access", "expression-list", "constant", "datastructure",
  "array", "list", "make-sequence", "make-sequence-list",
  "make-sequence-array", "seq-expression", "statement", "return", "menu",
  "menu-body", "menu-case", "menu-def", "loop", "roll", "foreach", "for",
  "for-initializer", "for-update", "conditional", "elseif", "else", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    61,    58,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   124,    94,    38,
      60,    62,    43,    45,    42,    47,    37,   126,    33,   300,
      46,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      44,    40,    41,    91,    93,   123,   125,    95,   310,   311,
     312,   313,   314,   315
};
# endif

#define YYPACT_NINF -102

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-102)))

#define YYTABLE_NINF -98

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     323,     7,   775,   775,   -68,   775,  -102,  -102,   775,   775,
     -68,   -68,   323,    12,   429,    37,  -102,   -27,  -102,  -102,
    -102,  -102,  -102,  -102,  1448,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,    15,    -2,  -102,   -43,  -102,   775,
     775,   775,   675,   285,   709,  -102,  -102,  -102,  -102,  -102,
     825,  -102,  -102,  1251,  -102,  -102,  1471,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  1099,   -33,  -102,   439,   -29,  1137,
     859,  1175,  -102,  -102,  -102,   220,    47,   220,   -18,   220,
    -102,   285,   775,   -33,  -102,   449,  -102,  -102,  -102,  -102,
    -102,  -102,   323,   775,  -102,  -102,   775,   775,   775,   775,
     775,   775,   775,   775,   775,   775,   775,   608,    -5,    30,
     -23,     4,     2,     2,     2,  -102,   664,   -12,    -1,   -23,
     516,   572,     1,   925,  -102,   -15,     8,   775,   775,   775,
     775,   775,   775,   775,   775,   775,   775,   775,   775,   775,
     775,   775,   775,   775,   775,   775,   775,   742,   775,   323,
     -20,   323,   134,  -102,  -102,  -102,  -102,   958,   892,  -102,
    -102,  1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,  1251,
    1251,  1251,  1251,  -102,  1251,    23,   323,  -102,    17,    41,
    -102,   775,   775,  -102,  -102,    51,  -102,  -102,  -102,  -102,
       2,  1282,  1312,    77,    77,  1413,  1413,   106,   106,  1342,
    1372,  1383,    77,    77,    -7,    -7,     2,     2,     2,     2,
      45,  1057,    20,    52,    53,   991,    50,    54,    27,   220,
    -102,  -102,  -102,    71,    59,  -102,  1251,  1024,  -102,   323,
     323,   323,  -102,   742,  -102,    32,  -102,   323,   775,   323,
    -102,    -9,    61,  -102,  -102,  -102,  -102,    62,    70,  -102,
    -102,    73,    79,  1213,  -102,  -102,    81,  -102,  -102,  -102,
     323,  -102,   323,  -102,    84,   138,  -102,  -102
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,   124,     0,   138,     0,   122,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     4,    10,    95,
      94,    93,    92,     9,     0,    97,     8,   118,   119,   120,
     134,   132,   133,   123,     0,    16,    12,    13,    11,     0,
       0,     0,     0,     0,     0,   103,   101,   102,   104,   105,
      47,    53,    49,   125,    51,    52,    50,    45,    48,   106,
     107,   108,   113,   114,     0,    96,   139,     0,     0,     0,
       0,     0,    77,    78,     7,     0,     0,     0,     0,     0,
      35,     0,     0,    28,    25,     0,    34,    32,    33,    29,
      30,     1,     5,     0,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
      21,     0,    60,    64,    67,   109,    99,     0,     0,    21,
       0,     0,     0,     0,   111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    37,    36,    38,     0,     0,    27,
       6,    81,    82,    83,    84,    85,    86,    87,    89,    88,
      90,    91,    18,    19,    17,     0,     0,    22,     0,    16,
      14,     0,     0,   110,   116,     0,    43,    46,   112,   115,
      59,    65,    66,    70,    71,    72,    73,    75,    74,    61,
      63,    62,    68,    69,    54,    55,    56,    57,    58,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,    31,    98,     0,     0,    15,   117,    99,   100,     0,
       0,     0,   126,   128,   127,   140,   135,     0,     0,     0,
     142,     0,     0,    42,    24,    20,    44,     0,     0,   129,
     141,     0,     0,     0,   148,   144,     0,   143,   131,   130,
       0,   136,     0,   145,     0,   146,   137,   147
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,    -3,  -102,  -102,   -87,  -102,  -102,   -84,  -102,
    -102,    69,   -13,    19,  -102,   -50,   -11,  -102,   280,    34,
      16,   -79,    40,     0,   -38,     3,    22,  -102,  -102,  -102,
    -102,  -102,   113,  -102,  -102,  -102,   -70,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,  -101,   -69
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,    17,    18,    36,    37,    38,   109,   110,
      19,    84,   152,    51,    78,   154,    52,   122,   116,    54,
      55,    23,    24,    56,   117,    57,    58,    59,    60,    61,
      62,    63,   118,    26,    27,    28,   212,   213,   214,    29,
      30,    31,    32,    68,   251,    33,   241,   242
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    85,    79,    87,    25,    34,   125,   239,    34,    74,
      25,    25,    25,    75,    88,    65,    22,    89,    34,    20,
      66,   127,   107,   -21,   180,   153,   177,   111,    22,   156,
     127,    20,   121,    86,    21,   185,    90,    91,    92,   106,
      82,   148,   238,   239,    67,   175,    21,   143,   144,   145,
      72,    73,   119,   146,   155,   176,   183,   255,    10,    11,
     108,   188,   146,   217,    87,   107,    87,   184,    87,   178,
     121,   156,    85,   186,    87,    88,   229,    88,    89,    88,
      89,   108,    89,    76,   189,    88,   232,   179,    89,   160,
      35,   225,    25,   240,    86,    77,    86,    90,    86,    90,
     179,    90,   220,    13,    86,   127,   223,    90,    22,    87,
      87,    20,   134,   135,   230,    14,   236,   233,   234,   237,
      88,    88,   244,    89,    89,   245,    21,   257,   258,   141,
     142,   143,   144,   145,   127,    80,   259,   146,   260,    86,
      86,    87,    90,    90,   228,   261,   216,   263,   218,    25,
     266,    25,    88,   238,   159,    89,   250,   126,   141,   142,
     143,   144,   145,   249,   267,    22,   146,    22,    20,   243,
      20,    86,   256,   224,    90,     0,    25,     0,     0,     0,
       0,     0,     0,    21,     0,    21,     0,     0,     0,     0,
       0,     0,    22,     0,     0,    20,     0,     0,     0,   219,
       0,    42,     0,     0,     0,    81,   -40,     0,    87,    44,
      21,     0,    45,    46,    47,    48,    49,    83,     0,    88,
       0,    80,    89,     0,     0,     0,   246,   247,   248,    25,
      25,    25,     0,     0,   252,    25,   254,    25,    86,    25,
       0,    90,     0,     0,     0,    22,    22,    22,    20,    20,
      20,    22,     0,    22,    20,    22,    20,   264,    20,   265,
      25,     0,    25,    21,    21,    21,     0,     0,     0,    21,
       0,    21,     0,    21,     0,     0,    22,     0,    22,    20,
       0,    20,    53,    64,     0,    69,    75,    42,    70,    71,
     119,    81,     0,     0,    21,    44,    21,     0,    45,    46,
      47,    48,    49,    83,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,     0,     0,   112,
     113,   114,     0,   123,     0,     0,     1,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     0,     9,    39,     0,
       0,     0,    40,    41,     0,     0,     0,     0,     0,    10,
      11,     0,    42,     0,     0,     0,    43,     0,     0,     0,
      44,   157,   158,    45,    46,    47,    48,    49,   120,     0,
       0,     0,     0,   161,     0,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   174,    12,     0,
       0,     0,     0,     0,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   211,   215,   -26,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -26,   -26,     0,     0,     0,   -26,
      80,     0,     0,   -96,     0,   -96,   -96,     0,     0,     0,
       0,   226,   227,    93,   -26,   -26,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,     0,
       0,     0,     0,     0,   -26,   -26,    42,     0,     0,     0,
      81,   -26,    82,     0,    44,     0,     0,    45,    46,    47,
      48,    49,    83,   211,   -26,   -26,    42,    80,   253,     0,
      81,   -26,     0,     0,    44,     0,     0,    45,    46,    47,
      48,    49,    83,     0,     0,     0,     0,     0,     0,     0,
     -96,     0,   -96,   -96,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,    80,     0,     0,   -47,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,    81,   -47,    82,
       0,    44,     0,     0,    45,    46,    47,    48,    49,    83,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   173,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,     0,
       0,     0,   -49,     0,    10,    11,     0,     0,     0,    42,
       0,     0,     0,    81,   -49,     0,     0,    44,     0,     0,
      45,    46,    47,    48,    49,    83,     0,     0,     0,     0,
       0,    39,     0,     0,     0,    40,    41,     0,   181,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,    43,
       0,     0,     0,    44,     0,     0,    45,    46,    47,    48,
      49,    50,   127,   128,   129,   130,   131,   132,   133,   134,
     135,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,     0,     0,   146,     0,     0,     0,    39,     0,
       0,     0,    40,    41,   182,    10,    11,     0,     0,     0,
       0,     0,    42,   115,     0,     0,    43,     0,     0,     0,
      44,     0,     0,    45,    46,    47,    48,    49,    50,     0,
       0,     0,    39,     0,     0,     0,    40,    41,    10,    11,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
      43,     0,     0,     0,    44,   124,     0,    45,    46,    47,
      48,    49,    50,     0,     0,    39,     0,     0,     0,    40,
      41,    10,    11,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,    43,     0,     0,     0,    44,     0,   210,
      45,    46,    47,    48,    49,    50,     0,     0,    39,     0,
       0,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,    43,     0,     0,   -96,
      44,   -96,   -96,    45,    46,    47,    48,    49,    50,     0,
       0,     0,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   150,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,     0,   146,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
       0,     0,   146,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,     0,     0,   222,     0,     0,     0,
       0,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,     0,   146,   127,   128,   129,   130,
     131,   132,   133,   134,   135,     0,     0,   187,     0,     0,
       0,     0,     0,     0,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,     0,     0,   146,   127,
     128,   129,   130,   131,   132,   133,   134,   135,     0,     0,
     221,     0,     0,     0,     0,     0,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
       0,   146,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   235,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,     0,     0,   146,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,     0,   146,     0,     0,
       0,     0,     0,     0,     0,     0,   231,   127,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,     0,   146,
       0,     0,     0,     0,   147,   127,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,     0,   146,     0,     0,
       0,     0,   149,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,     0,   146,     0,     0,     0,     0,
     151,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,     0,   146,     0,     0,     0,     0,   262,   127,
     128,   129,   130,   131,   132,   133,   134,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
     127,   146,   129,   130,   131,   132,   133,   134,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
     127,     0,   146,   130,   131,   132,   133,   134,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
     127,     0,   146,   130,   131,   132,   133,   134,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
     127,     0,   146,   130,   131,   132,   133,   134,   135,     0,
       0,   127,     0,     0,   130,   131,   132,   133,   134,   135,
       0,   138,   139,   140,   141,   142,   143,   144,   145,     0,
       0,     0,   146,   139,   140,   141,   142,   143,   144,   145,
       0,   127,     0,   146,   130,   131,     0,     0,   134,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   139,   140,   141,   142,   143,   144,   145,
       0,     0,    93,   146,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   -97,     0,   -97,   -97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97
};

static const yytype_int16 yycheck[] =
{
       0,    14,    13,    14,     4,     1,    44,    16,     1,    12,
      10,    11,    12,     1,    14,    83,     0,    14,     1,     0,
       4,    28,    24,    25,   111,    75,   110,    70,    12,    79,
      28,    12,    43,    14,     0,   119,    14,     0,    65,    24,
      73,    70,    15,    16,     4,    50,    12,    54,    55,    56,
      10,    11,     5,    60,    72,    25,    68,    66,    26,    27,
      83,    76,    60,    83,    75,    24,    77,    68,    79,    65,
      81,   121,    85,    72,    85,    75,    25,    77,    75,    79,
      77,    83,    79,    71,    76,    85,    66,    83,    85,    92,
      83,   178,    92,    66,    75,    83,    77,    75,    79,    77,
      83,    79,   152,    71,    85,    28,    83,    85,    92,   120,
     121,    92,    35,    36,    69,    83,    66,    65,    65,    65,
     120,   121,    51,   120,   121,    66,    92,    66,    66,    52,
      53,    54,    55,    56,    28,     1,    66,    60,    65,   120,
     121,   152,   120,   121,   182,    66,   149,    66,   151,   149,
      66,   151,   152,    15,    85,   152,   235,    44,    52,    53,
      54,    55,    56,   233,   265,   149,    60,   151,   149,   219,
     151,   152,   241,   176,   152,    -1,   176,    -1,    -1,    -1,
      -1,    -1,    -1,   149,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,   176,    -1,    -1,   176,    -1,    -1,    -1,    65,
      -1,    67,    -1,    -1,    -1,    71,    72,    -1,   219,    75,
     176,    -1,    78,    79,    80,    81,    82,    83,    -1,   219,
      -1,     1,   219,    -1,    -1,    -1,   229,   230,   231,   229,
     230,   231,    -1,    -1,   237,   235,   239,   237,   219,   239,
      -1,   219,    -1,    -1,    -1,   229,   230,   231,   229,   230,
     231,   235,    -1,   237,   235,   239,   237,   260,   239,   262,
     260,    -1,   262,   229,   230,   231,    -1,    -1,    -1,   235,
      -1,   237,    -1,   239,    -1,    -1,   260,    -1,   262,   260,
      -1,   262,     2,     3,    -1,     5,     1,    67,     8,     9,
       5,    71,    -1,    -1,   260,    75,   262,    -1,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    -1,    43,    -1,    -1,     3,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    53,    -1,
      -1,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,    26,
      27,    -1,    67,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      75,    81,    82,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    65,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,     0,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,     0,
       1,    -1,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,
      -1,   181,   182,    24,    15,    16,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    -1,    75,    -1,    -1,    78,    79,    80,
      81,    82,    83,   233,    65,    66,    67,     1,   238,    -1,
      71,    72,    -1,    -1,    75,    -1,    -1,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    71,    72,    73,
      -1,    75,    -1,    -1,    78,    79,    80,    81,    82,    83,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    60,    -1,    26,    27,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    71,    72,    -1,    -1,    75,    -1,    -1,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    57,    58,    -1,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,
      -1,    -1,    -1,    75,    -1,    -1,    78,    79,    80,    81,
      82,    83,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    60,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    57,    58,    70,    26,    27,    -1,    -1,    -1,
      -1,    -1,    67,    68,    -1,    -1,    71,    -1,    -1,    -1,
      75,    -1,    -1,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    58,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    -1,    -1,    53,    -1,    -1,    -1,    57,
      58,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    75,    -1,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,    53,    -1,
      -1,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    71,    -1,    -1,    24,
      75,    26,    27,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    60,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    60,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    60,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    60,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    60,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    60,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    65,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    65,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      65,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    65,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      28,    60,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      28,    -1,    60,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      28,    -1,    60,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      28,    -1,    60,    31,    32,    33,    34,    35,    36,    -1,
      -1,    28,    -1,    -1,    31,    32,    33,    34,    35,    36,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    60,    50,    51,    52,    53,    54,    55,    56,
      -1,    28,    -1,    60,    31,    32,    -1,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    24,    60,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    24,    -1,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,     8,     9,    10,    11,    12,    14,
      26,    27,    65,    71,    83,    85,    86,    87,    88,    94,
      97,   103,   104,   105,   106,   107,   117,   118,   119,   123,
     124,   125,   126,   129,     1,    83,    89,    90,    91,    53,
      57,    58,    67,    71,    75,    78,    79,    80,    81,    82,
      83,    97,   100,   102,   103,   104,   107,   109,   110,   111,
     112,   113,   114,   115,   102,    83,   104,   106,   127,   102,
     102,   102,   106,   106,    86,     1,    71,    83,    98,   100,
       1,    71,    73,    83,    95,    96,    97,   100,   107,   109,
     110,     0,    65,    24,    26,    27,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    24,    24,    83,    92,
      93,    70,   102,   102,   102,    68,   102,   108,   116,     5,
      83,   100,   101,   102,    76,   108,   116,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    60,    65,    70,    65,
      13,    65,    96,    99,    99,    72,    99,   102,   102,    95,
      86,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,     1,   102,    50,    25,    92,    65,    83,
      89,     4,    70,    68,    68,    92,    72,    72,    76,    76,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
      77,   102,   120,   121,   122,   102,    86,    83,    86,    65,
      99,    72,    74,    83,    86,    89,   102,   102,   108,    25,
      69,    69,    66,    65,    65,    70,    66,    65,    15,    16,
      66,   130,   131,    99,    51,    66,    86,    86,    86,   120,
     105,   128,    86,   102,    86,    66,   131,    66,    66,    66,
      65,    66,    65,    66,    86,    86,    66,   130
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    85,    86,    86,    86,    86,    87,    87,
      87,    88,    88,    89,    89,    89,    90,    90,    90,    90,
      91,    92,    92,    93,    93,    94,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    96,    97,    98,    98,    98,
      99,    99,    99,   100,   101,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   103,   103,   103,
     103,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   105,   105,   105,   105,   106,   106,   107,   108,
     108,   109,   109,   109,   109,   109,   110,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   115,   116,   117,   117,
     117,   117,   117,   117,   118,   118,   119,   120,   120,   120,
     121,   122,   123,   123,   123,   124,   125,   126,   127,   127,
     128,   128,   129,   129,   129,   129,   130,   130,   131
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
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     2,     3,     1,     1,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     5,     2,     2,     3,
       4,     4,     1,     1,     1,     5,     7,     9,     0,     1,
       0,     1,     5,     6,     6,     7,     4,     5,     2
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
          case 78: /* CONST_STRING  */
#line 62 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).vstring); }
#line 1596 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 79: /* CONST_INT  */
#line 62 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).vstring); }
#line 1602 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 80: /* CONST_FLOAT  */
#line 62 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).vstring); }
#line 1608 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 81: /* CONST_BOOL  */
#line 62 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).vstring); }
#line 1614 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 82: /* CONST_CHAR  */
#line 62 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).vstring); }
#line 1620 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 83: /* IDENTIFIER  */
#line 62 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).vstring); }
#line 1626 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 86: /* scope  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1632 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 87: /* program-element  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1638 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 88: /* declaration  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1644 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 89: /* decl-vars  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1650 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 90: /* decl-var  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1656 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 91: /* decl-func  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1662 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 92: /* param-list  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1668 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 93: /* param  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1674 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 94: /* func-call  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1680 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 95: /* arg-list  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1686 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 96: /* argument  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1692 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 97: /* braced-func-call  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1698 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 98: /* func-call-eol  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1704 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 99: /* arg-list-eol  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1710 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 100: /* soy-expression  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1716 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 101: /* soy-func  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1722 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 102: /* expression  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1728 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 103: /* incr-expression  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1734 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 104: /* assignment  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1740 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 105: /* modifying-expression  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1746 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 106: /* assignable-expression  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1752 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 107: /* datastructure-access  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1758 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 108: /* expression-list  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1764 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 109: /* constant  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1770 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 110: /* datastructure  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1776 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 111: /* array  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1782 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 112: /* list  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1788 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 113: /* make-sequence  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1794 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 114: /* make-sequence-list  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1800 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 115: /* make-sequence-array  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1806 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 116: /* seq-expression  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1812 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 117: /* statement  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1818 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 118: /* return  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1824 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 119: /* menu  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1830 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 120: /* menu-body  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1836 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 121: /* menu-case  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1842 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 122: /* menu-def  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1848 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 123: /* loop  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1854 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 124: /* roll  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1860 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 125: /* foreach  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1866 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 126: /* for  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1872 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 127: /* for-initializer  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1878 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 128: /* for-update  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1884 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 129: /* conditional  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1890 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 130: /* elseif  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1896 "parser/sushipp.tab.c" /* yacc.c:1257  */
        break;

    case 131: /* else  */
#line 63 "parser/spp_parser.y" /* yacc.c:1257  */
      { delete ((ast::ASTNode*)((*yyvaluep).vnode)); }
#line 1902 "parser/sushipp.tab.c" /* yacc.c:1257  */
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
#line 52 "parser/spp_parser.y" /* yacc.c:1429  */
{
	error_occurred = false;
}

#line 2009 "parser/sushipp.tab.c" /* yacc.c:1429  */
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
#line 175 "parser/spp_parser.y" /* yacc.c:1646  */
    { g_compiler->set_syntax_tree_root(new ast::Program); }
#line 2198 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 177 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		if(error_occurred)
		{
			delete ((ast::ASTNode*) (yyvsp[0].vnode));
			YYABORT;
		}

		ast::ASTNode* prog = new ast::Program;
		prog->add_child((ast::ASTNode*)(yyvsp[0].vnode));
		g_compiler->set_syntax_tree_root(prog); 
	}
#line 2214 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 194 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Scope);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2224 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 200 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Scope);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
	}
#line 2234 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 206 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Scope);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));

		// delete remaining node (which has no children)
		delete ((ast::Scope*)(yyvsp[0].vnode));
	}
#line 2248 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 216 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Scope);

		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));

		// delete remaining node (which has no children)
		delete ((ast::Scope*)(yyvsp[0].vnode));
	}
#line 2261 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 227 "parser/spp_parser.y" /* yacc.c:1646  */
    { (yyval.vnode) = (yyvsp[0].vnode); }
#line 2267 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 228 "parser/spp_parser.y" /* yacc.c:1646  */
    { (yyval.vnode) = (yyvsp[0].vnode); }
#line 2273 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 229 "parser/spp_parser.y" /* yacc.c:1646  */
    { (yyval.vnode) = (yyvsp[0].vnode); }
#line 2279 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 236 "parser/spp_parser.y" /* yacc.c:1646  */
    { (yyval.vnode) = (yyvsp[0].vnode); }
#line 2285 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 237 "parser/spp_parser.y" /* yacc.c:1646  */
    { (yyval.vnode) = (yyvsp[0].vnode); }
#line 2291 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 243 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::DeclVars);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2301 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 249 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::DeclVars);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));

		// delete remaining node (which has no children)
		delete ((ast::DeclVars*)(yyvsp[0].vnode));
	}
#line 2315 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 259 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::DeclVars);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-3].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));

		// delete remaining node (which has no children)
		delete ((ast::DeclVars*)(yyvsp[0].vnode));
	}
#line 2329 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 272 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::DeclVar);

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[0].vstring)));
		
		// delete the memory allocated for the string
		delete (yyvsp[0].vstring);
	}
#line 2342 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 281 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::DeclVar);

		// as the expression rule does not return an expression but the actual expression tree,
		// we create the expression node here
		ast::Expression* expr = new ast::Expression;

		expr->add_child((ast::ASTNode*)(yyvsp[0].vnode));
		
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[-2].vstring)));
		((ast::ASTNode*)(yyval.vnode))->add_child(expr);

		// delete the memory allocated for the string
		delete (yyvsp[-2].vstring);
	}
#line 2362 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 297 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ErrorNode);
		//cerr << " Details : a valid identifier name was exptected as left-hand-side item." << endl;
		delete ((ast::ASTNode*)(yyvsp[0].vnode));
		yyerrok;
	}
#line 2373 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 304 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ErrorNode);
		// delete the memory allocated for the string
		delete (yyvsp[-2].vstring);
		//cerr << " Details : a valid expression was exptected as right-hand-side item." << endl;
		yyerrok;
	}
#line 2385 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 316 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::DeclFunc);

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[-4].vstring)));

		if((yyvsp[-3].vnode) != nullptr) // if no parameters
			((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-3].vnode));

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		
		// delete the memory allocated for the string
		delete (yyvsp[-4].vstring);
	}
#line 2403 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 334 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = nullptr;
	}
#line 2411 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 338 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ParamList);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));

		if((yyvsp[0].vnode) != nullptr)
		{
			((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));
			
			// delete remaining node (which has no children)
			delete ((ast::ParamList*)(yyvsp[0].vnode));
		}
	}
#line 2429 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 355 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Param);

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[0].vstring)));

		// delete the memory allocated for the string
		delete (yyvsp[0].vstring);
	}
#line 2442 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 364 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		

		(yyval.vnode) = (void*) (new ast::Param);

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[-3].vstring)));

		// get the type 
		ast::ASTNode* type = get_type_node(*(yyvsp[-1].vstring));

		if(!type)
		{
			// print the error
			std::stringstream ss;
			ss << "Invalid type string : given '" << *(yyvsp[-1].vstring) << "', actual type expected";
			yyerror(ss.str().c_str());

			YYERROR; // signal a parsing error
			yyerrok; // mark the error as ok, to continue parsing

			((ast::ASTNode*)(yyval.vnode))->add_child(new ast::ErrorNode);
		}
		else
			((ast::ASTNode*)(yyval.vnode))->add_child(type);


		// delete the memory allocated for the string
		delete (yyvsp[-3].vstring);
		delete (yyvsp[-1].vstring);
	}
#line 2477 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 402 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::FuncCall);

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[-1].vstring)));

		if((yyvsp[0].vnode) != nullptr)
			((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));

		// delete the memory allocated for the string
		delete (yyvsp[-1].vstring);
	}
#line 2493 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 417 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = nullptr;
	}
#line 2501 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 423 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ArgList);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));

		if((yyvsp[0].vnode) != nullptr)
		{
			((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));
			
			// delete remaining node (which has no children)
			delete ((ast::ArgList*)(yyvsp[0].vnode));
		}
	}
#line 2519 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 440 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Argument);

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[0].vstring)));

		// delete the memory allocated for the string
		delete (yyvsp[0].vstring);
	}
#line 2532 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 449 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Argument);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2542 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 455 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Argument);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2552 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 461 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Argument);
		// as the expression rule does not return an expression but the actual expression tree,
		// we create the expression node here
		ast::Expression* expr = new ast::Expression;

		expr->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(expr);
	}
#line 2566 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 471 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Argument);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2576 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 477 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Argument);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2586 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 483 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Argument);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2596 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 489 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ErrorNode);
		/*cerr << " Details : the argument is invalid. It should be either " << endl
			 << "    a constant, a braced expression, an anonymous soy function, " << endl
			 << "    a datastructure access or a variable." << endl; */
		yyclearin;
	}
#line 2608 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 499 "parser/spp_parser.y" /* yacc.c:1646  */
    { (yyval.vnode) = (yyvsp[-1].vnode); }
#line 2614 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 509 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::FuncCall);

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[-1].vstring)));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));

		// delete the memory allocated for the string
		delete (yyvsp[-1].vstring);
	}
#line 2628 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 519 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::FuncCall);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2639 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 526 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ErrorNode);
		//cerr << " Details : either an identifier or a soy anonymous function was expected" << endl;
		delete ((ast::ASTNode*)(yyvsp[0].vnode));
		yyerrok;
	}
#line 2650 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 536 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ArgList);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2660 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 542 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ArgList);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));

		// delete remaining node (which has no children)
		delete ((ast::ArgList*)(yyvsp[0].vnode));
	}
#line 2674 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 552 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ArgList);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));

		// delete remaining node (which has no children)
		delete ((ast::ArgList*)(yyvsp[0].vnode));
	}
#line 2688 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 565 "parser/spp_parser.y" /* yacc.c:1646  */
    { (yyval.vnode) = (yyvsp[-1].vnode); }
#line 2694 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 570 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::SoyFunc);

		if((ast::ASTNode*)(yyvsp[-2].vnode) != nullptr)
			((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2707 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 584 "parser/spp_parser.y" /* yacc.c:1646  */
    { (yyval.vnode) = (yyvsp[0].vnode); }
#line 2713 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 585 "parser/spp_parser.y" /* yacc.c:1646  */
    { (yyval.vnode) = (yyvsp[-1].vnode); }
#line 2719 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 587 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = new ast::Identifier(*(yyvsp[0].vstring));

		// delete the memory allocated for the string
		delete (yyvsp[0].vstring);
	}
#line 2730 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 593 "parser/spp_parser.y" /* yacc.c:1646  */
    { (yyval.vnode) = (yyvsp[0].vnode); }
#line 2736 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 594 "parser/spp_parser.y" /* yacc.c:1646  */
    { (yyval.vnode) = (yyvsp[0].vnode); }
#line 2742 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 595 "parser/spp_parser.y" /* yacc.c:1646  */
    { (yyval.vnode) = (yyvsp[0].vnode); }
#line 2748 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 596 "parser/spp_parser.y" /* yacc.c:1646  */
    { (yyval.vnode) = (yyvsp[0].vnode); }
#line 2754 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 597 "parser/spp_parser.y" /* yacc.c:1646  */
    { (yyval.vnode) = (yyvsp[0].vnode); }
#line 2760 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 598 "parser/spp_parser.y" /* yacc.c:1646  */
    { (yyval.vnode) = (yyvsp[0].vnode); }
#line 2766 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 600 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_Plus);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2777 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 607 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_Minus);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2788 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 614 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_Mult);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2799 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 621 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_Div);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2810 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 628 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_Modulo);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2821 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 635 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_Exponentiation);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2832 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 642 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_UnaryMinus);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2842 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 648 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_BitwiseOr);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2853 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 655 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_BitwiseAnd);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2864 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 662 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_BitwiseXor);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2875 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 669 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_BitwiseNot);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2885 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 675 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_LogicalOr);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2896 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 682 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_LogicalAnd);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2907 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 689 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_LogicalNot);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2917 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 695 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_CompLessThan);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2928 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 702 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_CompGreaterThan);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2939 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 709 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_CompLessEqual);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2950 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 716 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_CompGreaterEqual);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2961 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 723 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_CompEqual);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2972 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 730 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_CompNotEqual);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2983 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 737 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_RightShift);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 2994 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 744 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_LeftShift);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3005 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 751 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_StringConcat);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3016 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 761 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_PrefixIncrement);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3026 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 767 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_PrefixDecrement);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3036 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 773 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_PostfixIncrement);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
	}
#line 3046 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 779 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_PostfixDecrement);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
	}
#line 3056 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 788 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_Assignment);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3067 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 795 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignPlus);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3078 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 802 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignMinus);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3089 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 809 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignMult);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3100 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 816 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignDiv);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3111 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 823 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignExpo);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3122 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 830 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignMod);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3133 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 837 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignAnd);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3144 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 844 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignOr);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3155 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 851 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignXor);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3166 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 858 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Op_AssignConcat);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3177 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 872 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ModifyingExpression);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3187 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 878 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ModifyingExpression);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3197 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 884 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ModifyingExpression);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3207 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 890 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ModifyingExpression);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3217 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 902 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = new ast::Identifier(*(yyvsp[0].vstring));

		// delete the memory allocated for the string
		delete (yyvsp[0].vstring);
	}
#line 3228 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 908 "parser/spp_parser.y" /* yacc.c:1646  */
    { (yyval.vnode) = (yyvsp[0].vnode); }
#line 3234 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 913 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::DatastructureAccess);

		ast::Expression* expr = new ast::Expression;

		expr->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[-3].vstring)));
		((ast::ASTNode*)(yyval.vnode))->add_child(expr);
		
		// delete allocated string
		delete (yyvsp[-3].vstring);
	}
#line 3251 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 930 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ExpressionList);

		ast::Expression* expr = new ast::Expression;

		expr->add_child((ast::ASTNode*)(yyvsp[0].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(expr);
	}
#line 3264 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 939 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ExpressionList);

		ast::Expression* expr = new ast::Expression;

		expr->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(expr);
		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));

		// delete remaining node (which has no children)
		delete ((ast::ExpressionList*)(yyvsp[0].vnode));
	}
#line 3281 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 958 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::NT_Constant);

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Integer(*(yyvsp[0].vstring)));
		
		// delete allocated string
		delete (yyvsp[0].vstring);
	}
#line 3294 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 967 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::NT_Constant);

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Float(*(yyvsp[0].vstring)));
		
		// delete allocated string
		delete (yyvsp[0].vstring);
	}
#line 3307 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 976 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::NT_Constant);

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::String(*(yyvsp[0].vstring)));
		
		// delete allocated string
		delete (yyvsp[0].vstring);
	}
#line 3320 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 985 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::NT_Constant);

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Bool(*(yyvsp[0].vstring)));
		
		// delete allocated string
		delete (yyvsp[0].vstring);
	}
#line 3333 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 994 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::NT_Constant);

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Character(*(yyvsp[0].vstring)));
		
		// delete allocated string
		delete (yyvsp[0].vstring);
	}
#line 3346 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1009 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Datastructure);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3356 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1015 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Datastructure);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3366 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1021 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Datastructure);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3376 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1030 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Array);
	}
#line 3384 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1034 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Array);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
	}
#line 3394 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1043 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::List);
	}
#line 3402 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1047 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::List);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
	}
#line 3411 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1058 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::MakeSequence);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3421 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1064 "parser/spp_parser.y" /* yacc.c:1646  */
    {	
		(yyval.vnode) = (void*) (new ast::MakeSequence);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	 }
#line 3431 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1073 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::MakeSequenceList);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
	}
#line 3441 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1082 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::MakeSequenceArray);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));

	}
#line 3452 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1092 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::SeqExpression);

		ast::Expression* expr1 = new ast::Expression, *expr2;

		expr2 = new ast::Expression;

		expr1->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		expr2->add_child((ast::ASTNode*)(yyvsp[0].vnode));

		((ast::ASTNode*)(yyval.vnode))->add_child(expr1);
		((ast::ASTNode*)(yyval.vnode))->add_child(expr2);
	}
#line 3470 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1112 "parser/spp_parser.y" /* yacc.c:1646  */
    {	
		(yyval.vnode) = (void*) (new ast::Statement);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3480 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1118 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Statement);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3490 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1124 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Statement);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3500 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1130 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Statement);

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_Continue);
	}
#line 3510 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1136 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Statement);

		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::K_Break);
	}
#line 3520 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1142 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Statement);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3530 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1152 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Return);
	}
#line 3538 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1156 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Return);

		ast::Expression* expr = new ast::Expression;

		expr->add_child((ast::ASTNode*)(yyvsp[0].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(expr);
	}
#line 3551 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1169 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Menu);

		ast::Expression* expr = new ast::Expression;

		expr->add_child((ast::ASTNode*)(yyvsp[-3].vnode));

		((ast::ASTNode*)(yyval.vnode))->add_child(expr);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
	}
#line 3566 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1183 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::MenuBody);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
	}
#line 3576 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1189 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::MenuBody);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
 
	}
#line 3587 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1196 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::MenuBody);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));

		// delete remaining node (which has no children)
		delete ((ast::MenuBody*)(yyvsp[0].vnode));
	}
#line 3601 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1209 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::MenuCase);

		ast::Expression* expr = new ast::Expression;

		expr->add_child((ast::ASTNode*)(yyvsp[-3].vnode));

		((ast::ASTNode*)(yyval.vnode))->add_child(expr);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
	}
#line 3616 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1223 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::MenuDef);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
	}
#line 3626 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1233 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Loop);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3636 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1239 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Loop);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3646 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1245 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Loop);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3656 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1257 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Roll);

		ast::Expression* expr = new ast::Expression;

		expr->add_child((ast::ASTNode*)(yyvsp[-3].vnode));

		((ast::ASTNode*)(yyval.vnode))->add_child(expr);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
	}
#line 3671 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1274 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Foreach);

		ast::Expression* expr = new ast::Expression;

		expr->add_child((ast::ASTNode*)(yyvsp[-5].vnode));

		((ast::ASTNode*)(yyval.vnode))->add_child(expr);
		((ast::ASTNode*)(yyval.vnode))->add_child(new ast::Identifier(*(yyvsp[-3].vstring)));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));

		// delete the memory allocated for the string
		delete (yyvsp[-3].vstring);
	}
#line 3690 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1300 "parser/spp_parser.y" /* yacc.c:1646  */
    {	
		(yyval.vnode) = (void*) (new ast::For);

		ast::Expression* expr = new ast::Expression;

		if((ast::ASTNode*)(yyvsp[-7].vnode) != nullptr)
			((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-7].vnode));

		expr->add_child((ast::ASTNode*)(yyvsp[-5].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(expr);

		if((ast::ASTNode*)(yyvsp[-7].vnode) != nullptr)
			((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-3].vnode));

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
	}
#line 3711 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1320 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = nullptr;
	}
#line 3719 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1324 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ForInitializer);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3729 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1333 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = nullptr;
	}
#line 3737 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1337 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::ForUpdate);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3747 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1347 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		
		(yyval.vnode) = (void*) (new ast::Conditional);

		ast::Expression* expr = new ast::Expression;

		expr->add_child((ast::ASTNode*)(yyvsp[-3].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(expr);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
	}
#line 3762 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1358 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Conditional);

		ast::Expression* expr = new ast::Expression;

		expr->add_child((ast::ASTNode*)(yyvsp[-4].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(expr);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
	}
#line 3777 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1369 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Conditional);

		ast::Expression* expr = new ast::Expression;

		expr->add_child((ast::ASTNode*)(yyvsp[-4].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(expr);
 
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[-1].vnode)));

		// delete the unused node
		delete ((ast::ASTNode*) (yyvsp[-1].vnode));
	}
#line 3796 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1384 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Conditional);

		ast::Expression* expr = new ast::Expression;

		expr->add_child((ast::ASTNode*)(yyvsp[-5].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(expr);

		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-3].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[-2].vnode)));
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[-1].vnode));

		// delete the unused node
		delete ((ast::ASTNode*) (yyvsp[-2].vnode));
	}
#line 3816 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1404 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Elseif);
		ast::ASTNode* sub = new ast::Elseif;
		ast::Expression* expr = new ast::Expression;
		expr->add_child((ast::ASTNode*)(yyvsp[-2].vnode));
		sub->add_child(expr);
		sub->add_child((ast::ASTNode*)(yyvsp[0].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(sub);
	}
#line 3830 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1414 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Elseif);
		ast::ASTNode* sub = new ast::Elseif;
		ast::Expression* expr = new ast::Expression;
		expr->add_child((ast::ASTNode*)(yyvsp[-3].vnode));
		sub->add_child(expr);
		sub->add_child((ast::ASTNode*)(yyvsp[-1].vnode));
		((ast::ASTNode*)(yyval.vnode))->add_child(sub);
		((ast::ASTNode*)(yyval.vnode))->add_children(children((yyvsp[0].vnode)));

		//delete the unused node
		delete ((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3848 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1431 "parser/spp_parser.y" /* yacc.c:1646  */
    {
		(yyval.vnode) = (void*) (new ast::Else);
		((ast::ASTNode*)(yyval.vnode))->add_child((ast::ASTNode*)(yyvsp[0].vnode));
	}
#line 3857 "parser/sushipp.tab.c" /* yacc.c:1646  */
    break;


#line 3861 "parser/sushipp.tab.c" /* yacc.c:1646  */
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
#line 1437 "parser/spp_parser.y" /* yacc.c:1906  */


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

static ast::ASTNode* get_type_node(const std::string& type_string)
{
	if(!type_string.compare("int"))
		return new ast::Type_Int;
	else if(!type_string.compare("bool"))
		return new ast::Type_Bool;
	else if(!type_string.compare("float"))
		return new ast::Type_Float;
	else if(!type_string.compare("string"))
		return new ast::Type_String;
	else if(!type_string.compare("list"))
		return new ast::Type_List;
	else if(!type_string.compare("array"))
		return new ast::Type_Array;
	else return nullptr;
}
