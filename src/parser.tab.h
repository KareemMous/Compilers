
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     OCBRACKET = 258,
     CCBRACKET = 259,
     ORBRACKET = 260,
     CRBRACKET = 261,
     SEMICOLON = 262,
     COLON = 263,
     COMMA = 264,
     INCREMENT = 265,
     DECREMENT = 266,
     PLUSEQUAL = 267,
     MINUSEQUAL = 268,
     MULTIPLYEQUAL = 269,
     DIVIDEEQUAL = 270,
     GREATERTHAN = 271,
     LESSTHAN = 272,
     GREATERTHANOREQUAL = 273,
     LESSTHANOREQUAL = 274,
     EQUALEQUAL = 275,
     NOTEQUAL = 276,
     PLUS = 277,
     MINUS = 278,
     MULTIPLY = 279,
     DIVIDE = 280,
     POWER = 281,
     ASSIGN = 282,
     REM = 283,
     REMEQUAL = 284,
     AND = 285,
     OR = 286,
     NOT = 287,
     WHILE = 288,
     DO = 289,
     FOR = 290,
     IF = 291,
     ELSE = 292,
     INT = 293,
     CHAR = 294,
     FLOAT = 295,
     BOOL = 296,
     STRING = 297,
     ENUM = 298,
     CONST = 299,
     VOID = 300,
     BREAK = 301,
     CONTINUE = 302,
     IDENTIFIER = 303,
     SWITCH = 304,
     CASE = 305,
     FALSE = 306,
     TRUE = 307,
     RET = 308,
     DEFAULT = 309,
     IFX = 310,
     UMINUS = 311
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 4 "parser.y"
  
    int intValue;
    float floatValue;
	char charValue;                
    char* stringValue;
	int boolValue;
    char* variableName;
	struct lexemeInfo * information;
	struct argument_info * argument_info;



/* Line 1676 of yacc.c  */
#line 121 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


