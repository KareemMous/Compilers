
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */


/* Line 189 of yacc.c  */
#line 73 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 4 "parser.y"
  
    int intValue;
    float floatValue;
	char charValue;                
    char* stringValue;
	int boolValue;
    char* variableName;
	struct lexemeInfo * information;
	struct argument_info * argument_info;



/* Line 214 of yacc.c  */
#line 178 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */

/* Line 264 of yacc.c  */
#line 104 "parser.y"
  
	#include <stdio.h>
	#include <stdlib.h>   
	#include <string.h>
	#include <math.h>
	#include "DataStructures/scope.h"
	#include "DataStructures/quadruple.h"
	#include "DataStructures/typeConversion.h"
	#include "DataStructures/conversion.h"


	int yyerror(char *);
	int yyerror_with_variable(char*, char*);
	int yylex(void);
	extern int yylineno ;
  	extern char* yytext;
	FILE * f1;
	FILE * symbolTableFile;
	FILE * quadraplesFile;

	extern FILE * yyin;
	struct scope* current_scope ;
	struct scope* parent_scope ;
	
	// Functions Declaration
	void enter_new_scope();
	void exit_a_scope();
	DataType* get_parameters_of_array(struct argument_info*,int*);
	void add_parameters_to_function_symbol_table(DataType*, struct argument_info*);
	void assigning_operation_with_conversion(char* , struct lexemeInfo **,char*);
	void check_Type_Conversion(DataType ,struct argument_info*);

	// variables to use through the code to check semantics
	struct variableEntry * current_identifier;
	ReturnCode current_return_code;
	OperationsToDo operation;

	struct Stack * quad_stack;


/* Line 264 of yacc.c  */
#line 231 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   447

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNRULES -- Number of states.  */
#define YYNSTATES  216

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    13,    19,    24,    27,
      29,    30,    33,    35,    37,    40,    42,    44,    51,    55,
      59,    65,    67,    71,    73,    75,    77,    79,    81,    83,
      87,    91,    95,    99,   103,   107,   111,   114,   116,   118,
     120,   122,   126,   130,   133,   137,   141,   145,   149,   153,
     157,   161,   165,   169,   173,   177,   181,   184,   187,   191,
     194,   198,   202,   203,   207,   208,   218,   219,   224,   225,
     226,   234,   236,   238,   240,   242,   244,   247,   250,   253,
     256,   259,   260,   268,   269,   277,   284,   286,   292,   297,
     300,   301,   305,   307,   308,   312,   317,   323,   326,   330,
     331,   332,   333,   341,   342,   347,   348,   349,   350,   351,
     361,   362,   363
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    59,    -1,    59,    60,    -1,    -1,    76,
      48,     7,    -1,    76,    48,    27,    64,     7,    -1,    48,
      27,    64,     7,    -1,    67,     7,    -1,    91,    -1,    -1,
      61,    68,    -1,    71,    -1,    77,    -1,    84,     7,    -1,
      85,    -1,    62,    -1,    43,    48,     3,    63,     4,     7,
      -1,    43,    48,     7,    -1,    63,     9,    48,    -1,    63,
       9,    48,    27,    64,    -1,    48,    -1,    48,    27,    64,
      -1,    65,    -1,    66,    -1,    84,    -1,    40,    -1,    38,
      -1,    48,    -1,    65,    22,    65,    -1,    65,    23,    65,
      -1,    65,    25,    65,    -1,    65,    24,    65,    -1,    65,
      28,    65,    -1,    65,    26,    65,    -1,     5,    65,     6,
      -1,    23,    65,    -1,    52,    -1,    51,    -1,    39,    -1,
      42,    -1,    64,    30,    64,    -1,    64,    31,    64,    -1,
      32,    64,    -1,    64,    16,    64,    -1,    64,    18,    64,
      -1,    64,    17,    64,    -1,    64,    19,    64,    -1,    64,
      20,    64,    -1,    64,    21,    64,    -1,     5,    66,     6,
      -1,    48,    12,    65,    -1,    48,    13,    65,    -1,    48,
      14,    65,    -1,    48,    15,    65,    -1,    48,    29,    65,
      -1,    48,    10,    -1,    48,    11,    -1,     3,    59,     4,
      -1,    69,    60,    -1,    69,    46,     7,    -1,    69,    47,
       7,    -1,    -1,     3,    69,     4,    -1,    -1,    35,    72,
       5,    60,    64,     7,    67,     6,    70,    -1,    -1,    33,
      64,    73,    70,    -1,    -1,    -1,    34,    74,    70,    75,
      33,    64,     7,    -1,    38,    -1,    40,    -1,    39,    -1,
      42,    -1,    41,    -1,    44,    38,    -1,    44,    40,    -1,
      44,    39,    -1,    44,    42,    -1,    44,    41,    -1,    -1,
      76,    48,     5,    82,     6,    78,    80,    -1,    -1,    45,
      48,     5,    82,     6,    79,    81,    -1,     3,    59,    53,
      64,     7,     4,    -1,    68,    -1,     3,    59,    53,     7,
       4,    -1,    76,    48,     9,    82,    -1,    76,    48,    -1,
      -1,    64,     9,    83,    -1,    64,    -1,    -1,     5,    84,
       6,    -1,    48,     5,    83,     6,    -1,    49,    64,     3,
      87,     4,    -1,    86,    60,    -1,    86,    46,     7,    -1,
      -1,    -1,    -1,    50,    38,     8,    88,    86,    89,    87,
      -1,    -1,    54,     8,    90,    86,    -1,    -1,    -1,    -1,
      -1,    36,     5,    64,    92,     6,    93,    60,    94,    95,
      -1,    -1,    -1,    37,    96,    60,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   147,   147,   150,   151,   154,   161,   197,   237,   238,
     239,   239,   240,   241,   242,   243,   244,   247,   248,   251,
     252,   253,   254,   257,   258,   259,   262,   269,   275,   289,
     305,   320,   337,   352,   367,   382,   383,   399,   400,   401,
     402,   409,   413,   417,   421,   425,   429,   433,   437,   441,
     445,   449,   450,   451,   452,   453,   454,   464,   476,   480,
     481,   482,   483,   486,   489,   489,   490,   490,   491,   491,
     491,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   513,   513,   527,   527,   542,   544,   545,   548,   553,
     557,   560,   566,   570,   573,   574,   632,   635,   636,   637,
     640,   640,   640,   641,   641,   642,   646,   646,   646,   646,
     649,   649,   649
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OCBRACKET", "CCBRACKET", "ORBRACKET",
  "CRBRACKET", "SEMICOLON", "COLON", "COMMA", "INCREMENT", "DECREMENT",
  "PLUSEQUAL", "MINUSEQUAL", "MULTIPLYEQUAL", "DIVIDEEQUAL", "GREATERTHAN",
  "LESSTHAN", "GREATERTHANOREQUAL", "LESSTHANOREQUAL", "EQUALEQUAL",
  "NOTEQUAL", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "POWER", "ASSIGN",
  "REM", "REMEQUAL", "AND", "OR", "NOT", "WHILE", "DO", "FOR", "IF",
  "ELSE", "INT", "CHAR", "FLOAT", "BOOL", "STRING", "ENUM", "CONST",
  "VOID", "BREAK", "CONTINUE", "IDENTIFIER", "SWITCH", "CASE", "FALSE",
  "TRUE", "RET", "DEFAULT", "IFX", "UMINUS", "$accept", "program",
  "statements", "stmt", "$@1", "Enum_Declaration", "ENUM_LIST",
  "EXPRESSION", "Number_Declaration", "Boolean_Expression",
  "Mathematical_Statement", "Scope", "Loop_statements", "Loop_Scope",
  "LOOPS", "$@2", "$@3", "$@4", "$@5", "Type_Identifier", "FUNCTIONS",
  "$@6", "$@7", "Function_Scope", "Void_Function_Scope", "ARGUMENTS",
  "Arguments_Call", "Function_Calls", "Switch_Case",
  "Switch_Case_Statements", "Case_Expressions", "$@8", "$@9", "$@10",
  "IF_Statement", "$@11", "$@12", "$@13", "endCondition", "$@14", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
      61,    60,    60,    60,    60,    60,    60,    62,    62,    63,
      63,    63,    63,    64,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    67,    67,    67,    67,    67,    68,    69,
      69,    69,    69,    70,    72,    71,    73,    71,    74,    75,
      71,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    78,    77,    79,    77,    80,    81,    81,    82,    82,
      82,    83,    83,    83,    84,    84,    85,    86,    86,    86,
      88,    89,    87,    90,    87,    87,    92,    93,    94,    91,
      95,    96,    95
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     5,     4,     2,     1,
       0,     2,     1,     1,     2,     1,     1,     6,     3,     3,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     2,     1,     1,     1,
       1,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     2,
       3,     3,     0,     3,     0,     9,     0,     4,     0,     0,
       7,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     0,     7,     0,     7,     6,     1,     5,     4,     2,
       0,     3,     1,     0,     3,     4,     5,     2,     3,     0,
       0,     0,     7,     0,     4,     0,     0,     0,     0,     9,
       0,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,    68,    64,     0,    71,
      73,    72,    75,    74,     0,     0,     0,     0,     0,     3,
       0,    16,     0,    12,     0,    13,     0,    15,     9,     0,
       0,     0,     0,     0,    27,    39,    26,    40,    28,    38,
      37,    66,    23,    24,    25,     0,     0,     0,     0,    76,
      78,    77,    80,    79,     0,    93,    56,    57,     0,     0,
       0,     0,     0,     0,     0,     4,    11,     8,     0,    14,
      94,     0,    23,    24,    25,     0,    28,    36,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,    69,    10,   106,     0,    18,
      90,    92,     0,    51,    52,    53,    54,     0,    55,   105,
      10,    90,     5,     0,    35,    50,     0,    44,    46,    45,
      47,    48,    49,    41,    42,    67,    29,    30,    32,    31,
      34,    33,    10,     0,     0,     0,    21,     0,     0,     0,
      93,    95,     7,     0,     0,     0,    58,     0,     0,    63,
       0,     0,    59,     0,     0,   107,     0,     0,     0,    89,
      83,    91,     0,   103,    96,    81,     6,    60,    61,     0,
       0,    10,    22,    17,    19,    90,     0,   100,    99,     0,
      70,     0,     0,   108,     0,    88,     4,    86,    84,    99,
      10,     4,    82,     0,   110,    20,    10,   101,     0,    97,
      10,    65,   111,   109,     0,   105,    98,     0,    10,     0,
     102,     0,   112,    87,     0,    85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    19,    20,    21,   137,   101,    42,    43,
      22,    66,   132,    95,    23,    46,    87,    45,   133,    24,
      25,   179,   176,   192,   188,   139,   102,    44,    27,   190,
     145,   189,   205,   178,    28,   135,   171,   194,   203,   208
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -106
static const yytype_int16 yypact[] =
{
    -106,    21,   222,  -106,     5,    17,  -106,  -106,    29,  -106,
    -106,  -106,  -106,  -106,   -41,   151,   -10,   347,    17,  -106,
      34,  -106,    38,  -106,    13,  -106,    41,  -106,  -106,    61,
      71,    17,    12,    17,  -106,  -106,  -106,  -106,    61,  -106,
    -106,   416,   226,  -106,  -106,    64,    83,    17,     6,  -106,
    -106,  -106,  -106,  -106,    85,    17,  -106,  -106,    12,    12,
      12,    12,    17,    12,   145,  -106,  -106,  -106,    84,  -106,
    -106,   416,     2,    86,    71,    12,  -106,  -106,  -106,    17,
      17,    17,    17,    17,    17,    17,    17,    64,    12,    12,
      12,    12,    12,    12,  -106,  -106,   306,   416,    45,  -106,
     276,   410,    89,   226,   226,   226,   226,   349,   226,   -18,
     288,   276,  -106,    17,  -106,  -106,     2,   152,   152,    98,
      98,   -11,   -11,  -106,  -106,  -106,   153,   153,    70,    70,
    -106,    70,   242,    72,    17,   103,    87,     7,    68,   106,
      17,  -106,  -106,    82,   113,   119,  -106,   118,   365,  -106,
     124,   125,  -106,    17,   371,  -106,    17,   126,    77,   117,
    -106,  -106,   131,  -106,  -106,  -106,  -106,  -106,  -106,   387,
     101,   306,   416,  -106,   127,   276,   149,  -106,  -106,   154,
    -106,    88,   161,  -106,    17,  -106,  -106,  -106,  -106,  -106,
     264,  -106,  -106,    64,   121,   416,   102,   196,   167,  -106,
     175,  -106,  -106,  -106,   178,   -18,  -106,    17,   306,   155,
    -106,   393,  -106,  -106,   156,  -106
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -106,  -106,   -64,   -93,  -106,  -106,  -106,     0,   -17,   137,
      16,    11,  -106,   -83,  -106,  -106,  -106,  -106,  -106,   -88,
    -106,  -106,  -106,  -106,  -106,  -105,    56,    -2,  -106,     8,
      -5,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -105
static const yytype_int16 yytable[] =
{
      26,   110,    30,   134,   125,    41,   147,    48,   114,    98,
       4,   157,   138,    99,    72,    77,   158,    75,    64,    85,
      86,     3,    31,   138,    88,    89,    90,    91,    92,    74,
      93,    71,   143,    78,    47,    32,   144,    65,    54,   152,
      32,   103,   104,   105,   106,    67,   108,    97,    69,    33,
      34,    35,    36,    29,    37,    34,    35,    36,   116,    37,
      76,    68,   107,    39,    40,    38,    55,    94,    39,    40,
     185,   126,   127,   128,   129,   130,   131,    70,   183,   117,
     118,   119,   120,   121,   122,   123,   124,   138,    96,   111,
     100,   112,   115,   136,    26,   141,    92,   199,    56,    57,
      58,    59,    60,    61,   199,   153,   146,     4,    26,   155,
     201,   113,   160,   148,   156,   212,   159,    63,    83,    84,
     162,   163,   196,   164,   165,   174,   175,   200,    85,    86,
      26,   167,   168,   173,   154,     5,     6,     7,     8,   177,
       9,    10,    11,    12,    13,    14,    15,    16,   109,   181,
      17,    18,   186,   169,   184,   204,   172,   191,   202,   213,
     215,    79,    80,    81,    82,    83,    84,   193,    73,    26,
      81,    82,    83,    84,   206,    85,    86,    90,    91,    92,
       4,    93,    85,    86,   195,   209,   182,   187,    26,    49,
      50,    51,    52,    53,    26,    26,   161,   197,    26,   -10,
     210,     4,     0,     0,     0,     0,    26,   211,     5,     6,
       7,     8,     0,     9,    10,    11,    12,    13,    14,    15,
      16,     0,     0,    17,    18,   -10,     0,     4,   207,     5,
       6,     7,     8,     0,     9,    10,    11,    12,    13,    14,
      15,    16,   198,     0,    17,    18,   149,     4,    88,    89,
      90,    91,    92,     0,    93,     5,     6,     7,     8,     0,
       9,    10,    11,    12,    13,    14,    15,    16,  -104,     4,
      17,    18,     0,     0,     0,     5,     6,     7,     8,     0,
       9,    10,    11,    12,    13,    14,    15,    16,   150,   151,
      17,    18,   146,     4,     0,     0,     0,     5,     6,     7,
       8,     0,     9,    10,    11,    12,    13,    14,    15,    16,
     198,     4,    17,    18,     9,    10,    11,    12,    13,     0,
      15,     5,     6,     7,     8,     0,     9,    10,    11,    12,
      13,    14,    15,    16,     0,     0,    17,    18,     0,     5,
       6,     7,     8,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    55,     0,    17,    18,   142,    56,    57,    58,
      59,    60,    61,     0,     0,    79,    80,    81,    82,    83,
      84,     0,   166,     0,    62,     0,    63,     0,   170,    85,
      86,    79,    80,    81,    82,    83,    84,    79,    80,    81,
      82,    83,    84,     0,   180,    85,    86,     0,     0,     0,
     214,    85,    86,    79,    80,    81,    82,    83,    84,    79,
      80,    81,    82,    83,    84,     0,     0,    85,    86,   140,
       0,     0,     0,    85,    86,     0,    79,    80,    81,    82,
      83,    84,    79,    80,    81,    82,    83,    84,     0,     0,
      85,    86,     0,     0,     0,     0,    85,    86
};

static const yytype_int16 yycheck[] =
{
       2,    65,     4,    96,    87,     5,   111,    48,     6,     3,
       5,     4,   100,     7,    31,    32,     9,     5,    18,    30,
      31,     0,     5,   111,    22,    23,    24,    25,    26,    31,
      28,    31,    50,    33,     5,    23,    54,     3,    48,   132,
      23,    58,    59,    60,    61,     7,    63,    47,     7,    32,
      38,    39,    40,    48,    42,    38,    39,    40,    75,    42,
      48,    48,    62,    51,    52,    48,     5,     3,    51,    52,
     175,    88,    89,    90,    91,    92,    93,     6,   171,    79,
      80,    81,    82,    83,    84,    85,    86,   175,     5,     5,
       5,     7,     6,    48,    96,     6,    26,   190,    10,    11,
      12,    13,    14,    15,   197,    33,     4,     5,   110,     6,
     193,    27,     6,   113,    27,   208,    48,    29,    20,    21,
      38,     8,   186,     4,     6,    48,     9,   191,    30,    31,
     132,     7,     7,     7,   134,    33,    34,    35,    36,     8,
      38,    39,    40,    41,    42,    43,    44,    45,     3,    48,
      48,    49,     3,   153,    27,    53,   156,     3,    37,     4,
       4,    16,    17,    18,    19,    20,    21,     6,    31,   171,
      18,    19,    20,    21,     7,    30,    31,    24,    25,    26,
       5,    28,    30,    31,   184,     7,   170,   176,   190,    38,
      39,    40,    41,    42,   196,   197,   140,   189,   200,     3,
     205,     5,    -1,    -1,    -1,    -1,   208,   207,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    48,    49,     3,    -1,     5,    53,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,     4,     5,    22,    23,
      24,    25,    26,    -1,    28,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,     4,     5,
      48,    49,    -1,    -1,    -1,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,     4,     5,    -1,    -1,    -1,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     5,    48,    49,    38,    39,    40,    41,    42,    -1,
      44,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    48,    49,    -1,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,     5,    -1,    48,    49,     7,    10,    11,    12,
      13,    14,    15,    -1,    -1,    16,    17,    18,    19,    20,
      21,    -1,     7,    -1,    27,    -1,    29,    -1,     7,    30,
      31,    16,    17,    18,    19,    20,    21,    16,    17,    18,
      19,    20,    21,    -1,     7,    30,    31,    -1,    -1,    -1,
       7,    30,    31,    16,    17,    18,    19,    20,    21,    16,
      17,    18,    19,    20,    21,    -1,    -1,    30,    31,     9,
      -1,    -1,    -1,    30,    31,    -1,    16,    17,    18,    19,
      20,    21,    16,    17,    18,    19,    20,    21,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    30,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,    59,     0,     5,    33,    34,    35,    36,    38,
      39,    40,    41,    42,    43,    44,    45,    48,    49,    60,
      61,    62,    67,    71,    76,    77,    84,    85,    91,    48,
      84,     5,    23,    32,    38,    39,    40,    42,    48,    51,
      52,    64,    65,    66,    84,    74,    72,     5,    48,    38,
      39,    40,    41,    42,    48,     5,    10,    11,    12,    13,
      14,    15,    27,    29,    64,     3,    68,     7,    48,     7,
       6,    64,    65,    66,    84,     5,    48,    65,    64,    16,
      17,    18,    19,    20,    21,    30,    31,    73,    22,    23,
      24,    25,    26,    28,     3,    70,     5,    64,     3,     7,
       5,    64,    83,    65,    65,    65,    65,    64,    65,     3,
      59,     5,     7,    27,     6,     6,    65,    64,    64,    64,
      64,    64,    64,    64,    64,    70,    65,    65,    65,    65,
      65,    65,    69,    75,    60,    92,    48,    63,    76,    82,
       9,     6,     7,    50,    54,    87,     4,    82,    64,     4,
      46,    47,    60,    33,    64,     6,    27,     4,     9,    48,
       6,    83,    38,     8,     4,     6,     7,     7,     7,    64,
       7,    93,    64,     7,    48,     9,    79,     8,    90,    78,
       7,    48,    67,    60,    27,    82,     3,    68,    81,    88,
      86,     3,    80,     6,    94,    64,    59,    86,    46,    60,
      59,    70,    37,    95,    53,    89,     7,    53,    96,     7,
      87,    64,    60,     4,     7,     4
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    { current_return_code =add_variable_to_scope(current_scope, (yyvsp[(2) - (3)].variableName), 0, (yyvsp[(1) - (3)].intValue),variable_type,NULL,0);
												if(current_return_code == FAILURE)
													yyerror_with_variable("Redefinition of variable ", (yyvsp[(2) - (3)].variableName));
												else if(current_return_code == CONSTANT_NOT_INITIALIZED)
													yyerror_with_variable("Must initialize constant within declaration ", (yyvsp[(2) - (3)].variableName));
											;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    {if((yyvsp[(4) - (5)].information) != NULL){
																	
																	if((yyvsp[(4) - (5)].information)->is_initialized==0){
																		yyerror("use of uninitialized variable");
																	}
																	if(add_variable_to_scope(current_scope, (yyvsp[(2) - (5)].variableName), 1, (yyvsp[(1) - (5)].intValue),variable_type,NULL,0) == FAILURE){
																		yyerror_with_variable("Redefinition of variable ", (yyvsp[(2) - (5)].variableName));
																	}else{
																		operation = sides_implicit_conversion((yyvsp[(1) - (5)].intValue),(yyvsp[(4) - (5)].information)->my_type);
																		if(operation == DOWNGRADE_RHS){
																			current_return_code = down_convert_type(&(yyvsp[(4) - (5)].information),(yyvsp[(4) - (5)].information)->my_type, (yyvsp[(1) - (5)].intValue),yylineno);
																			if(current_return_code == STRING_INVALID_OPERATION){
																				yyerror("invalid string conversion");
																			}else{
																				
																				push(quad_stack," ",NULL,quadraplesFile);push(quad_stack,"=",(yyvsp[(2) - (5)].variableName),quadraplesFile);
																			}
																		}else if(operation == UPGRADE_RHS){
																
																			current_return_code = up_convert_my_type(&(yyvsp[(4) - (5)].information),(yyvsp[(4) - (5)].information)->my_type, (yyvsp[(1) - (5)].intValue),yylineno);
																			if(current_return_code == STRING_INVALID_OPERATION){
																				yyerror("invalid string conversion");
																			}else{
																				
																				push(quad_stack," ",NULL,quadraplesFile);push(quad_stack,"=",(yyvsp[(2) - (5)].variableName),quadraplesFile);
																			}
																		}else if(operation == ERROR){
																			yyerror("invalid string conversion");
																		}else{
																				// quadraples
																				push(quad_stack," ",NULL,quadraplesFile);push(quad_stack,"=",(yyvsp[(2) - (5)].variableName),quadraplesFile);
																		}
																	}
																}
															;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    { if((yyvsp[(3) - (4)].information) != NULL){
													if((yyvsp[(3) - (4)].information)->is_initialized==0){
														yyerror("use of uninitialized variable");
													}
													current_return_code = assign_variable_in_scope(current_scope, (yyvsp[(1) - (4)].variableName));
													if(current_return_code == FAILURE)
														yyerror_with_variable("Undeclared variable ", (yyvsp[(1) - (4)].variableName));
													else if(current_return_code == CONSTANT_REASSIGNMENT)
														yyerror_with_variable("cant reassign a constant variable :", (yyvsp[(1) - (4)].variableName));
													else{
															current_identifier = variable_found_in_scope(current_scope,(yyvsp[(1) - (4)].variableName));
															operation = sides_implicit_conversion(current_identifier->dataType,(yyvsp[(3) - (4)].information)->my_type);
															if(operation == DOWNGRADE_RHS){
																// downgrade conv to result dt needed
																current_return_code = down_convert_type(&(yyvsp[(3) - (4)].information),(yyvsp[(3) - (4)].information)->my_type, current_identifier->dataType,yylineno);
																if(current_return_code == STRING_INVALID_OPERATION){
																	yyerror("invalid string conversion");
																}else{
																	// quadraples
																	push(quad_stack," ",NULL,quadraplesFile);push(quad_stack,"=",(yyvsp[(1) - (4)].variableName),quadraplesFile);
																}
															}else if(operation == UPGRADE_RHS){
																// upgrade to result dt needed
																current_return_code = up_convert_my_type(&(yyvsp[(3) - (4)].information),(yyvsp[(3) - (4)].information)->my_type, current_identifier->dataType,yylineno);
																if(current_return_code == STRING_INVALID_OPERATION){
																	yyerror("invalid string conversion");
																}else{
																	// quadraples
																	push(quad_stack," ",NULL,quadraplesFile);push(quad_stack,"=",(yyvsp[(1) - (4)].variableName),quadraplesFile);
																}
															}else if(operation == ERROR){
																yyerror("invalid string conversion");
															}else{
																// quadraples
																push(quad_stack," ",NULL,quadraplesFile);push(quad_stack,"=",(yyvsp[(1) - (4)].variableName),quadraplesFile);
															}
														}
													}					
												;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 239 "parser.y"
    {enter_new_scope();;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 239 "parser.y"
    {exit_a_scope();;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 257 "parser.y"
    {(yyval.information) =(yyvsp[(1) - (1)].information);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 258 "parser.y"
    {(yyval.information) =(yyvsp[(1) - (1)].information);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 259 "parser.y"
    {(yyval.information) =(yyvsp[(1) - (1)].information);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 262 "parser.y"
    {set_lexeme(&(yyval.information), FLOAT_DT); (yyval.information)->floatValue = (yyvsp[(1) - (1)].floatValue);(yyval.information)->variableName=NULL;
							// setting the quadraple info
							char buf[100];
  							gcvt((yyval.information)->floatValue, 2, buf);
							push( quad_stack, buf,NULL,quadraplesFile);
							;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 269 "parser.y"
    {set_lexeme(&(yyval.information), INT_DT); (yyval.information)->intValue = (yyvsp[(1) - (1)].intValue); (yyval.information)->variableName=NULL;
							// setting the quadraple info
							char temp[4]; 
							push( quad_stack, itoa(((yyval.information)->intValue),temp,10), NULL,quadraplesFile);
							;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 275 "parser.y"
    { 
						current_identifier = variable_found_in_scope(current_scope,(yyvsp[(1) - (1)].variableName));
						if(current_identifier == NULL){
							yyerror_with_variable("identifier not declared in this scope",(yyvsp[(1) - (1)].variableName) );
							(yyval.information) = NULL;
						}else{
							set_lexeme(&(yyval.information),current_identifier->dataType);
							(yyval.information)->variableName = (yyvsp[(1) - (1)].variableName);
							(yyval.information)->is_initialized = current_identifier->is_initialized;
							set_variable_used_in_scope(current_scope, (yyvsp[(1) - (1)].variableName));
							// setting the quadraple info
							push(quad_stack,(yyvsp[(1) - (1)].variableName),NULL,quadraplesFile);
						}
					;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 289 "parser.y"
    { if((yyvsp[(1) - (3)].information) && (yyvsp[(3) - (3)].information)){
																	if((yyvsp[(1) - (3)].information)->is_initialized==0 || (yyvsp[(3) - (3)].information)->is_initialized==0){
																		yyerror("use of uninitialized variable");
																	}
																	current_return_code =  rhs_value(&(yyval.information),(yyvsp[(1) - (3)].information),(yyvsp[(3) - (3)].information),PLUS_OP,yylineno);
																	if(current_return_code == STRING_INVALID_OPERATION){
																		yyerror("invalid operation on strings");
																	}else if(current_return_code == OPERATION_NOT_SUPPORTED){
																		yyerror("Invalid Operations ");
																	}else{
																		// adding to quadraple
																		push(quad_stack, "+",NULL,quadraplesFile);
																	}
												}			
				;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 305 "parser.y"
    {if((yyvsp[(1) - (3)].information) && (yyvsp[(3) - (3)].information)){
																		 if((yyvsp[(1) - (3)].information)->is_initialized==0 || (yyvsp[(3) - (3)].information)->is_initialized==0){
																		yyerror("use of uninitialized variable");
																	}
																	current_return_code =  rhs_value(&(yyval.information),(yyvsp[(1) - (3)].information),(yyvsp[(3) - (3)].information),MINUS_OP,yylineno);
																	if(current_return_code == STRING_INVALID_OPERATION){
																		yyerror("invalid operation on strings");
																	}else if(current_return_code == OPERATION_NOT_SUPPORTED){
																		yyerror("Invalid Operations ");
																	}else{
																		// adding to quadraple
																		push(quad_stack, "-",NULL,quadraplesFile);
																	}
																}	
															;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 320 "parser.y"
    {if((yyvsp[(1) - (3)].information) && (yyvsp[(3) - (3)].information)){
																	if((yyvsp[(1) - (3)].information)->is_initialized==0 || (yyvsp[(3) - (3)].information)->is_initialized==0){
																		yyerror("use of uninitialized variable");
																	}
																	current_return_code =  rhs_value(&(yyval.information),(yyvsp[(1) - (3)].information),(yyvsp[(3) - (3)].information),DIVIDE_OP,yylineno);
																	if(current_return_code == STRING_INVALID_OPERATION){
																		yyerror("invalid operation on strings");
																	}else if(current_return_code == OPERATION_NOT_SUPPORTED){
																		yyerror("Invalid Operations ");
																	}else if(current_return_code ==DIVISION_BY_ZERO_ERROR){
																		yyerror("Divison by zero !");
																	}else{
																		// adding to quadraple
																		push(quad_stack, "/",NULL,quadraplesFile);
																	}
																}
															;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 337 "parser.y"
    {if((yyvsp[(1) - (3)].information) && (yyvsp[(3) - (3)].information)){
																 	if((yyvsp[(1) - (3)].information)->is_initialized==0 || (yyvsp[(3) - (3)].information)->is_initialized==0){
																		yyerror("use of uninitialized variable");
																	}
																	current_return_code =  rhs_value(&(yyval.information),(yyvsp[(1) - (3)].information),(yyvsp[(3) - (3)].information),TIMES_OP,yylineno);
																	if(current_return_code == STRING_INVALID_OPERATION){
																		yyerror("invalid operation on strings");
																	}else if(current_return_code == OPERATION_NOT_SUPPORTED){
																		yyerror("Invalid Operations ");
																	}else{
																		// adding to quadraple
																		push(quad_stack, "*",NULL,quadraplesFile);
																	}
																	}
																;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 352 "parser.y"
    {if((yyvsp[(1) - (3)].information) && (yyvsp[(3) - (3)].information)){
																 	if((yyvsp[(1) - (3)].information)->is_initialized==0 || (yyvsp[(3) - (3)].information)->is_initialized==0){
																		yyerror("use of uninitialized variable");
																	}
																	current_return_code =  rhs_value(&(yyval.information),(yyvsp[(1) - (3)].information),(yyvsp[(3) - (3)].information),MOD_OP,yylineno);
																	if(current_return_code == STRING_INVALID_OPERATION){
																		yyerror("invalid operation on strings");
																	}else if(current_return_code == OPERATION_NOT_SUPPORTED){
																		yyerror("Invalid Operations ");
																	}else{
																		// adding to quadraple
																		push(quad_stack, "%",NULL,quadraplesFile);
																	}
																}
															;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 367 "parser.y"
    {if((yyvsp[(1) - (3)].information) && (yyvsp[(3) - (3)].information)){
																 	if((yyvsp[(1) - (3)].information)->is_initialized==0 || (yyvsp[(3) - (3)].information)->is_initialized==0){
																		yyerror("use of uninitialized variable");
																	}
																	current_return_code =  rhs_value(&(yyval.information),(yyvsp[(1) - (3)].information),(yyvsp[(3) - (3)].information),POWER_OP,yylineno);
																	if(current_return_code == STRING_INVALID_OPERATION){
																		yyerror("invalid operation on strings");
																	}else if(current_return_code == OPERATION_NOT_SUPPORTED){
																		yyerror("Invalid Operations ");
																	}else{
																		// adding to quadraple
																		push(quad_stack, "^",NULL,quadraplesFile);
																	}													
																}	
															;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 382 "parser.y"
    {if((yyvsp[(2) - (3)].information))(yyval.information)=(yyvsp[(2) - (3)].information);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 383 "parser.y"
    {if((yyvsp[(2) - (2)].information)){
														 			if((yyvsp[(2) - (2)].information)->is_initialized==0){
																		yyerror("use of uninitialized variable");
																	}
																	current_return_code =  rhs_value(&(yyval.information),(yyvsp[(2) - (2)].information),NULL,UMINUS_OP,yylineno);
																	if(current_return_code == STRING_INVALID_OPERATION){
																		yyerror("invalid operation on strings");
																	}else if(current_return_code == OPERATION_NOT_SUPPORTED){
																		yyerror("Invalid Operations ");
																	}else{
																		// adding to quadraple
																		push(quad_stack, ".",NULL,quadraplesFile); // pushing delimiter to just handle this case
																		push(quad_stack, "-",NULL,quadraplesFile);
																	}
														}
													;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 399 "parser.y"
    {set_lexeme(&(yyval.information), BOOL_DT); (yyval.information)->boolValue = 1; push(quad_stack, "true",NULL,quadraplesFile);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 400 "parser.y"
    {set_lexeme(&(yyval.information), BOOL_DT); (yyval.information)->boolValue = 0; push(quad_stack, "false",NULL,quadraplesFile);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 401 "parser.y"
    {set_lexeme(&(yyval.information), CHAR_DT); (yyval.information)->charValue = (yyvsp[(1) - (1)].charValue); char x[1]="";strncat(x, &(yyvsp[(1) - (1)].charValue), 1); push(quad_stack,x,NULL,quadraplesFile);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 402 "parser.y"
    {set_lexeme(&(yyval.information), STRING_DT); (yyval.information)->stringValue = (yyvsp[(1) - (1)].stringValue);push(quad_stack, (yyvsp[(1) - (1)].stringValue),NULL,quadraplesFile);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 409 "parser.y"
    { current_return_code = down_convert_booleans(&(yyval.information), (yyvsp[(1) - (3)].information), (yyvsp[(3) - (3)].information), AND_OP);
													if(current_return_code == STRING_INVALID_OPERATION)
														yyerror("Invalid String Conversion to Boolean ");
												;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 413 "parser.y"
    { current_return_code = down_convert_booleans(&(yyval.information), (yyvsp[(1) - (3)].information), (yyvsp[(3) - (3)].information), OR_OP);
													if(current_return_code == STRING_INVALID_OPERATION)
														yyerror("Invalid String Conversion to Boolean ");
												;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 417 "parser.y"
    { current_return_code = down_convert_booleans(&(yyval.information), (yyvsp[(2) - (2)].information), NULL, NOT_OP);
													if(current_return_code == STRING_INVALID_OPERATION)
														yyerror("Invalid String Conversion to Boolean ");
									;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 421 "parser.y"
    { current_return_code = down_convert_booleans(&(yyval.information), (yyvsp[(1) - (3)].information), (yyvsp[(3) - (3)].information), GREATERTHAN_OP);
															if(current_return_code == STRING_INVALID_OPERATION)
																yyerror("Invalid String Conversion to Boolean ");
														;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 425 "parser.y"
    { current_return_code = down_convert_booleans(&(yyval.information), (yyvsp[(1) - (3)].information), (yyvsp[(3) - (3)].information), GREATERTHANOREQUAL_OP);
																if(current_return_code == STRING_INVALID_OPERATION)
																	yyerror("Invalid String Conversion to Boolean ");
															;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 429 "parser.y"
    { current_return_code = down_convert_booleans(&(yyval.information), (yyvsp[(1) - (3)].information), (yyvsp[(3) - (3)].information), LESSTHAN_OP);
																if(current_return_code == STRING_INVALID_OPERATION)
																	yyerror("Invalid String Conversion to Boolean ");
															;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 433 "parser.y"
    { current_return_code = down_convert_booleans(&(yyval.information), (yyvsp[(1) - (3)].information), (yyvsp[(3) - (3)].information), LESSTHANOREQUAL_OP);
																if(current_return_code == STRING_INVALID_OPERATION)
																	yyerror("Invalid String Conversion to Boolean ");
															;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 437 "parser.y"
    { current_return_code = down_convert_booleans(&(yyval.information), (yyvsp[(1) - (3)].information), (yyvsp[(3) - (3)].information), EQUALEQUAL_OP);
																if(current_return_code == STRING_INVALID_OPERATION)
																	yyerror("Invalid String Conversion to Boolean ");
															;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 441 "parser.y"
    { current_return_code = down_convert_booleans(&(yyval.information), (yyvsp[(1) - (3)].information), (yyvsp[(3) - (3)].information), NOTEQUAL_OP);
																if(current_return_code == STRING_INVALID_OPERATION)
																	yyerror("Invalid String Conversion to Boolean ");
														;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 445 "parser.y"
    {(yyval.information) = (yyvsp[(2) - (3)].information);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 449 "parser.y"
    {assigning_operation_with_conversion((yyvsp[(1) - (3)].variableName), &(yyvsp[(3) - (3)].information),"+"); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 450 "parser.y"
    {assigning_operation_with_conversion((yyvsp[(1) - (3)].variableName), &(yyvsp[(3) - (3)].information),"-");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 451 "parser.y"
    {assigning_operation_with_conversion((yyvsp[(1) - (3)].variableName), &(yyvsp[(3) - (3)].information),"*");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 452 "parser.y"
    {assigning_operation_with_conversion((yyvsp[(1) - (3)].variableName), &(yyvsp[(3) - (3)].information),"/");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 453 "parser.y"
    {assigning_operation_with_conversion((yyvsp[(1) - (3)].variableName), &(yyvsp[(3) - (3)].information),"%");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 454 "parser.y"
    {	current_identifier = variable_found_in_scope(current_scope,(yyvsp[(1) - (2)].variableName));
												if(current_identifier == NULL){
													yyerror_with_variable("identifier not declared in this scope",(yyvsp[(1) - (2)].variableName));
												}else if(current_identifier->dataType==STRING_DT){
													yyerror_with_variable("Invalid Operation on strings",(yyvsp[(1) - (2)].variableName));
												}else{
													// push in quadraples x 1 x +
													push(quad_stack,"1",NULL,quadraplesFile);push(quad_stack,current_identifier->name,NULL,quadraplesFile);push(quad_stack,"+",current_identifier->name,quadraplesFile);
												}
											;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 464 "parser.y"
    {	current_identifier = variable_found_in_scope(current_scope,(yyvsp[(1) - (2)].variableName));
												if(current_identifier == NULL){
													yyerror_with_variable("identifier not declared in this scope",(yyvsp[(1) - (2)].variableName));
												}else if(current_identifier->dataType==STRING_DT){
													yyerror_with_variable("Invalid Operation on strings",(yyvsp[(1) - (2)].variableName));
												}else{
													// push in quadraples x 1 x -
													push(quad_stack,"1",NULL,quadraplesFile);push(quad_stack,current_identifier->name,NULL,quadraplesFile);push(quad_stack,"-",current_identifier->name,quadraplesFile);
												}
											;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 489 "parser.y"
    {enter_new_scope();;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 489 "parser.y"
    {exit_a_scope();;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 490 "parser.y"
    {enter_new_scope();;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 490 "parser.y"
    {exit_a_scope();;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 491 "parser.y"
    {enter_new_scope();;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 491 "parser.y"
    {exit_a_scope();;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 494 "parser.y"
    {(yyval.intValue) = INT_DT; ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 495 "parser.y"
    {(yyval.intValue) = FLOAT_DT;;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 496 "parser.y"
    {(yyval.intValue) = CHAR_DT;;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 497 "parser.y"
    {(yyval.intValue) = STRING_DT;;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 498 "parser.y"
    {(yyval.intValue) = BOOL_DT;;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 499 "parser.y"
    {(yyval.intValue) = CONST_INT_DT;;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 500 "parser.y"
    {(yyval.intValue) = CONST_FLOAT_DT;;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 501 "parser.y"
    {(yyval.intValue) = CONST_CHAR_DT; ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 502 "parser.y"
    {(yyval.intValue) = CONST_STRING_DT;;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 503 "parser.y"
    {(yyval.intValue) = CONST_BOOL_DT;;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 513 "parser.y"
    {
					//getting arguments of these function
					int no_of_args = 0 ;
					DataType* arguments_list = get_parameters_of_array((yyvsp[(4) - (5)].argument_info),&no_of_args);
					// adding function to the symbol table
					current_return_code = add_variable_to_scope(current_scope, (yyvsp[(2) - (5)].variableName), 0, (yyvsp[(1) - (5)].intValue), function_type, arguments_list,no_of_args);
					if(current_return_code == FAILURE){
						yyerror_with_variable("Redefinition of function ", (yyvsp[(2) - (5)].variableName));
					}
					enter_new_scope(); // entering a new scope
					// we add parameters to symbol table after making new scope
					add_parameters_to_function_symbol_table(arguments_list, (yyvsp[(4) - (5)].argument_info));
								;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 525 "parser.y"
    {exit_a_scope();;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 527 "parser.y"
    {
					//getting arguments of these function
					int no_of_args = 0 ;
					DataType* arguments_list = get_parameters_of_array((yyvsp[(4) - (5)].argument_info),&no_of_args);
					// adding function to the symbol table
					current_return_code = add_variable_to_scope(current_scope, (yyvsp[(2) - (5)].variableName), 0, VOID_DT, function_type, arguments_list,no_of_args);
					if(current_return_code == FAILURE){
						yyerror_with_variable("Redefinition of function ", (yyvsp[(2) - (5)].variableName));
					}
					enter_new_scope(); // entering a new scope
					// we add parameters to symbol table after making new scope
					add_parameters_to_function_symbol_table(arguments_list, (yyvsp[(4) - (5)].argument_info));
								;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 539 "parser.y"
    {exit_a_scope();;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 548 "parser.y"
    {(yyval.argument_info) = (struct argument_info *)malloc(sizeof(struct argument_info));
														 (yyval.argument_info)->next_arg = (yyvsp[(4) - (4)].argument_info);
														 (yyval.argument_info)->my_name = (yyvsp[(2) - (4)].variableName);
														 (yyval.argument_info)->my_type = (yyvsp[(1) - (4)].intValue);
														;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 553 "parser.y"
    {(yyval.argument_info) = (struct argument_info *)malloc(sizeof(struct argument_info));
											(yyval.argument_info)->next_arg = NULL;
											(yyval.argument_info)->my_name = (yyvsp[(2) - (2)].variableName);
											(yyval.argument_info)->my_type = (yyvsp[(1) - (2)].intValue);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 557 "parser.y"
    {(yyval.argument_info) = NULL;;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 560 "parser.y"
    { (yyval.argument_info) = (struct argument_info *)malloc(sizeof(struct argument_info));
												(yyval.argument_info)->next_arg = (yyvsp[(3) - (3)].argument_info);
												(yyval.argument_info)->my_name = (yyvsp[(1) - (3)].information)->variableName;
												(yyval.argument_info)->my_type = (yyvsp[(1) - (3)].information)->my_type; 
												;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 566 "parser.y"
    {	(yyval.argument_info) = (struct argument_info *)malloc(sizeof(struct argument_info)); 
								(yyval.argument_info)->my_name = (yyvsp[(1) - (1)].information)->variableName;
								(yyval.argument_info)->my_type = (yyvsp[(1) - (1)].information)->my_type; 
								(yyval.argument_info)->next_arg = NULL;;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 570 "parser.y"
    {(yyval.argument_info) = NULL;;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 573 "parser.y"
    {(yyval.information) = (yyvsp[(2) - (3)].information);;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 574 "parser.y"
    { 
						// first of all we need to find the function
						current_identifier = variable_found_in_scope(current_scope,(yyvsp[(1) - (4)].variableName));
						if(current_identifier == NULL){
							yyerror("function not initialzed in this scope");
						}else{
							// we need to match the parameters with the real arguments
							// the real input params to function
							DataType *my_params = current_identifier->params;

							int parameterCount = current_identifier->parameterCount;
							int i = 0;
							int success = 1;
							while((yyvsp[(3) - (4)].argument_info)){
								if(i==parameterCount){
									yyerror("Number of arguments doesnt match function");
									success = 0;
									break;
								}
								
								// then we will check the types of them one by one
								if((yyvsp[(3) - (4)].argument_info)->my_name == NULL){
									// therefore its not an identifier and its a value
									// we will check the implicit conversion
									check_Type_Conversion(my_params[i] ,(yyvsp[(3) - (4)].argument_info));
								}else{
									// identifer is sent
									// first of all we need to check that the variable passed is in table
									struct variableEntry * arg_identifier = variable_found_in_scope(current_scope,(yyvsp[(3) - (4)].argument_info)->my_name);
									if(arg_identifier == NULL){
										yyerror("variable in the argument list not initialzed in this scope");
									}else{
										// then we need to check on the type
										if(my_params[i] != (yyvsp[(3) - (4)].argument_info)->my_type){
											// we will check the implicit conversion
											check_Type_Conversion(my_params[i] ,(yyvsp[(3) - (4)].argument_info));
										}
									}
								}
								(yyvsp[(3) - (4)].argument_info)= (yyvsp[(3) - (4)].argument_info)->next_arg;
								i++;
							}
							if(i < parameterCount){
									yyerror("Number of arguments doesnt match function");
									success = 0;
							}
							if(success == 1){
								set_variable_used_in_scope(current_scope, current_identifier->name);
								set_lexeme(&(yyval.information),current_identifier->dataType);
								(yyval.information)->variableName = (yyvsp[(1) - (4)].variableName);
							}else{
								(yyval.information) = NULL;
							}
						}
					;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 640 "parser.y"
    { enter_new_scope();;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 640 "parser.y"
    {exit_a_scope();;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 641 "parser.y"
    {enter_new_scope();;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 641 "parser.y"
    {exit_a_scope();;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 646 "parser.y"
    {if((yyvsp[(3) - (3)].information)->my_type==STRING_DT)yyerror("Invalid String Conversion to Boolean");;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 646 "parser.y"
    {enter_new_scope();;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 646 "parser.y"
    {exit_a_scope();;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 649 "parser.y"
    {enter_new_scope();;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 649 "parser.y"
    {exit_a_scope();;}
    break;



/* Line 1455 of yacc.c  */
#line 2547 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



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
		      yytoken, &yylval);
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 653 "parser.y"
 
 int yyerror(char *s) { printf("line number : %d %s\n", yylineno,s);     return 0; }
 int yyerror_with_variable(char *s, char* var) { printf("line number : %d %s %s\n", yylineno,s, var);     return 0; }
 void enter_new_scope(){
	// setting the parent to currnt scope
	parent_scope = current_scope;
	// make the new scope by malloc
 	current_scope = (struct scope *)malloc(sizeof(struct scope)); 
 	// calling initialize fn in scope.h
	(*current_scope) = initScope();
	// updating my parent
 	setParent(current_scope,parent_scope);
 }

 void exit_a_scope(){
	 print_symbol_table_in_scope(current_scope, symbolTableFile);

	// if there's parent, will set it to grandparent
	// not all cases we will have parent since at first and last scope it will be null
	
	if(parent_scope)
		parent_scope = parent_scope->parent;
	// delete_scope fn return the parent of current scope  
	current_scope =  delete_scope(current_scope);
	return;
 }

 DataType* get_parameters_of_array(struct argument_info* temp, int * no_of_arguments){
	(*no_of_arguments) = 0 ;
	struct argument_info* start_ptr = temp;
	while(start_ptr){
		(*no_of_arguments)++;
		start_ptr = start_ptr->next_arg;
	}
	start_ptr = temp;
	// Dynamically allocate memory using malloc()
	if((*no_of_arguments) == 0 )
		return NULL;
	DataType* arguments_list = (DataType*)malloc((*no_of_arguments) * sizeof(DataType));
	int i = 0 ;
	while(start_ptr){
		arguments_list[i] = start_ptr->my_type;
		start_ptr = start_ptr->next_arg;
		i++;
	}
	return arguments_list;
 }

 void add_parameters_to_function_symbol_table(DataType* arguments_list,struct argument_info* temp){
	int i = 0 ;
	struct argument_info* start_ptr = temp;
	while(start_ptr){
		// adding each parameter to the symbol table assuming its init
		current_return_code = add_variable_to_scope(current_scope, start_ptr->my_name, 1, start_ptr->my_type,parameter_type,NULL,0);
		if(current_return_code == FAILURE)
		{
			yyerror_with_variable("Redefinition of parameter in function ", start_ptr->my_name);
		}
		start_ptr = start_ptr->next_arg;
		i++;
	}
 }

void assigning_operation_with_conversion(char* lhs, struct lexemeInfo ** rhs,char* op){
	// Number_Declaration will be ready and upgraded if needed
	current_return_code = assign_variable_in_scope(current_scope,lhs);
	if(current_return_code == FAILURE){
		yyerror_with_variable("Undeclared variable ", lhs);
		return;
	}
	else if(current_return_code == CONSTANT_REASSIGNMENT)
	{
		yyerror_with_variable("cant reassign a constant variable :", lhs);
		return;
	}

	current_identifier = variable_found_in_scope(current_scope,lhs);
	if(current_identifier == NULL){
		yyerror_with_variable("identifier not declared in this scope",lhs );
	}else{
		operation = sides_implicit_conversion(current_identifier->dataType,(*rhs)->my_type);
		if(operation == DOWNGRADE_RHS){
			// downgrade conv to result dt needed
			current_return_code = down_convert_type(rhs,(*rhs)->my_type, current_identifier->dataType,yylineno);
			if(current_return_code == STRING_INVALID_OPERATION){
				yyerror("invalid string conversion");
			}else{
				//quadraples
				push(quad_stack,lhs,NULL,quadraplesFile);push(quad_stack,op,lhs,quadraplesFile);
			}
		}else if(operation == UPGRADE_RHS){
			// upgrade to result dt needed
			current_return_code = up_convert_my_type(rhs,(*rhs)->my_type, current_identifier->dataType,yylineno);
			if(current_return_code == STRING_INVALID_OPERATION){
				yyerror("invalid string conversion");
			}else{
				//quadraples
				push(quad_stack,lhs,NULL,quadraplesFile);push(quad_stack,op,lhs,quadraplesFile);
			}
		}else if(operation == ERROR){
			yyerror("invalid string conversion");
		}else{
				//quadraples
				push(quad_stack,lhs,NULL,quadraplesFile);push(quad_stack,op,lhs,quadraplesFile);
		}
	}
}

void check_Type_Conversion(DataType real_identifier ,struct argument_info* input_argument){
		operation = sides_implicit_conversion(real_identifier,input_argument->my_type);
		
		struct lexemeInfo *input_lexeme ;
		set_lexeme(&input_lexeme, input_argument->my_type);
		
		if(operation == DOWNGRADE_RHS){
			// downgrade conv to result dt needed
			current_return_code = down_convert_type(&input_lexeme,input_lexeme->my_type, real_identifier,yylineno);
			
			
			if(current_return_code == STRING_INVALID_OPERATION){
				yyerror("invalid string conversion");
			}

		}else if(operation == UPGRADE_RHS){
			// upgrade to result dt needed
			
			current_return_code = up_convert_my_type(&input_lexeme,input_lexeme->my_type, real_identifier,yylineno);
			if(current_return_code == STRING_INVALID_OPERATION){
				yyerror("invalid string conversion");
			}
		}else if(operation == ERROR){
			yyerror("invalid string conversion");
		}
}

 int main(void) {

	enter_new_scope(); // whole scope containing all global variables and functions
	
	// clearing files before working
	remove( "symbolTables.txt" );

	yyin = fopen("input.txt", "r");
	printf("REAdd file\n");
	symbolTableFile = fopen("symbolTables.txt", "a");
	remove( "quadraples.txt" );
	quadraplesFile = fopen("quadraples.txt", "a");
	quad_stack = (struct Stack*)malloc(sizeof(struct Stack));
	quad_stack->top = 0;
	quad_stack->id_quadruple = 1;
	
	if(!yyparse()) {
	}
	else {
		printf("Parsing failed\n");
		return 0;
	}
	
	fclose(yyin);
	fclose(f1);

	// clearing the final scope 
	exit_a_scope();

	fclose(symbolTableFile);
	fclose(quadraplesFile);
	return 0;
}
