/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 43 "parser/spp_parser.y" /* yacc.c:1909  */

	std::string* vstring;
	void* vnode;

#line 123 "parser/sushipp.tab.h" /* yacc.c:1909  */
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
