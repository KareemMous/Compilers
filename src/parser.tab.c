
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
     CONST = 298,
     VOID = 299,
     BREAK = 300,
     CONTINUE = 301,
     IDENTIFIER = 302,
     SWITCH = 303,
     CASE = 304,
     FALSE = 305,
     TRUE = 306,
     RET = 307,
     DEFAULT = 308,
     IFX = 309,
     UMINUS = 310
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
#line 177 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */

/* Line 264 of yacc.c  */
#line 103 "parser.y"
  
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
#line 230 "parser.tab.c"

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
#define YYLAST   426

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNRULES -- Number of states.  */
#define YYNSTATES  201

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

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
      55
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    13,    19,    24,    27,
      29,    30,    33,    35,    37,    40,    42,    44,    46,    48,
      50,    52,    54,    58,    62,    66,    70,    74,    78,    82,
      85,    87,    89,    91,    93,    97,   101,   104,   108,   112,
     116,   120,   124,   128,   132,   136,   140,   144,   148,   152,
     155,   158,   162,   165,   169,   173,   174,   178,   179,   189,
     190,   195,   196,   197,   205,   207,   209,   211,   213,   215,
     218,   221,   224,   227,   230,   231,   239,   240,   248,   255,
     257,   263,   268,   271,   272,   276,   278,   279,   283,   288,
     294,   297,   301,   302,   303,   304,   312,   313,   318,   319,
     320,   321,   322,   332,   333,   334
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    58,    -1,    58,    59,    -1,    -1,    73,
      47,     7,    -1,    73,    47,    27,    61,     7,    -1,    47,
      27,    61,     7,    -1,    64,     7,    -1,    88,    -1,    -1,
      60,    65,    -1,    68,    -1,    74,    -1,    81,     7,    -1,
      82,    -1,    62,    -1,    63,    -1,    81,    -1,    40,    -1,
      38,    -1,    47,    -1,    62,    22,    62,    -1,    62,    23,
      62,    -1,    62,    25,    62,    -1,    62,    24,    62,    -1,
      62,    28,    62,    -1,    62,    26,    62,    -1,     5,    62,
       6,    -1,    23,    62,    -1,    51,    -1,    50,    -1,    39,
      -1,    42,    -1,    61,    30,    61,    -1,    61,    31,    61,
      -1,    32,    61,    -1,    61,    16,    61,    -1,    61,    18,
      61,    -1,    61,    17,    61,    -1,    61,    19,    61,    -1,
      61,    20,    61,    -1,    61,    21,    61,    -1,     5,    63,
       6,    -1,    47,    12,    62,    -1,    47,    13,    62,    -1,
      47,    14,    62,    -1,    47,    15,    62,    -1,    47,    29,
      62,    -1,    47,    10,    -1,    47,    11,    -1,     3,    58,
       4,    -1,    66,    59,    -1,    66,    45,     7,    -1,    66,
      46,     7,    -1,    -1,     3,    66,     4,    -1,    -1,    35,
      69,     5,    59,    61,     7,    64,     6,    67,    -1,    -1,
      33,    61,    70,    67,    -1,    -1,    -1,    34,    71,    67,
      72,    33,    61,     7,    -1,    38,    -1,    40,    -1,    39,
      -1,    42,    -1,    41,    -1,    43,    38,    -1,    43,    40,
      -1,    43,    39,    -1,    43,    42,    -1,    43,    41,    -1,
      -1,    73,    47,     5,    79,     6,    75,    77,    -1,    -1,
      44,    47,     5,    79,     6,    76,    78,    -1,     3,    58,
      52,    61,     7,     4,    -1,    65,    -1,     3,    58,    52,
       7,     4,    -1,    73,    47,     9,    79,    -1,    73,    47,
      -1,    -1,    61,     9,    80,    -1,    61,    -1,    -1,     5,
      81,     6,    -1,    47,     5,    80,     6,    -1,    48,    61,
       3,    84,     4,    -1,    83,    59,    -1,    83,    45,     7,
      -1,    -1,    -1,    -1,    49,    38,     8,    85,    83,    86,
      84,    -1,    -1,    53,     8,    87,    83,    -1,    -1,    -1,
      -1,    -1,    36,     5,    61,    89,     6,    90,    59,    91,
      92,    -1,    -1,    -1,    37,    93,    59,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   146,   146,   149,   150,   153,   160,   196,   236,   237,
     238,   238,   239,   240,   241,   242,   246,   247,   248,   251,
     258,   264,   278,   294,   309,   326,   341,   356,   371,   372,
     388,   389,   390,   391,   398,   402,   406,   410,   414,   418,
     422,   426,   430,   434,   438,   439,   440,   441,   442,   443,
     453,   462,   466,   467,   468,   469,   472,   475,   475,   476,
     476,   477,   477,   477,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   499,   499,   513,   513,   528,   530,
     531,   534,   539,   543,   546,   552,   556,   559,   560,   618,
     621,   622,   623,   626,   626,   626,   627,   627,   628,   632,
     632,   632,   632,   635,   635,   635
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
  "ELSE", "INT", "CHAR", "FLOAT", "BOOL", "STRING", "CONST", "VOID",
  "BREAK", "CONTINUE", "IDENTIFIER", "SWITCH", "CASE", "FALSE", "TRUE",
  "RET", "DEFAULT", "IFX", "UMINUS", "$accept", "program", "statements",
  "stmt", "$@1", "EXPRESSION", "Number_Declaration", "Boolean_Expression",
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
     305,   306,   307,   308,   309,   310
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    59,    59,
      60,    59,    59,    59,    59,    59,    61,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    65,    66,    66,    66,    66,    67,    69,    68,    70,
      68,    71,    72,    68,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    75,    74,    76,    74,    77,    78,
      78,    79,    79,    79,    80,    80,    80,    81,    81,    82,
      83,    83,    83,    85,    86,    84,    87,    84,    84,    89,
      90,    91,    88,    92,    93,    92
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     5,     4,     2,     1,
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     1,     1,     1,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     2,     3,     3,     0,     3,     0,     9,     0,
       4,     0,     0,     7,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     0,     7,     0,     7,     6,     1,
       5,     4,     2,     0,     3,     1,     0,     3,     4,     5,
       2,     3,     0,     0,     0,     7,     0,     4,     0,     0,
       0,     0,     9,     0,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,    61,    57,     0,    64,
      66,    65,    68,    67,     0,     0,     0,     0,     3,     0,
       0,    12,     0,    13,     0,    15,     9,     0,     0,     0,
       0,     0,    20,    32,    19,    33,    21,    31,    30,    59,
      16,    17,    18,     0,     0,     0,    69,    71,    70,    73,
      72,     0,    86,    49,    50,     0,     0,     0,     0,     0,
       0,     0,     4,    11,     8,     0,    14,    87,     0,    16,
      17,    18,     0,    21,    29,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    62,    10,    99,    83,    85,     0,    44,    45,
      46,    47,     0,    48,    98,    10,    83,     5,     0,    28,
      43,     0,    37,    39,    38,    40,    41,    42,    34,    35,
      60,    22,    23,    25,    24,    27,    26,    10,     0,     0,
       0,     0,     0,    86,    88,     7,     0,     0,     0,    51,
       0,     0,    56,     0,     0,    52,     0,     0,   100,    82,
      76,    84,     0,    96,    89,    74,     6,    53,    54,     0,
       0,    10,    83,     0,    93,    92,     0,    63,     0,     0,
     101,    81,     4,    79,    77,    92,    10,     4,    75,     0,
     103,    10,    94,     0,    90,    10,    58,   104,   102,     0,
      98,    91,     0,    10,     0,    95,     0,   105,    80,     0,
      78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    18,    19,    96,    40,    41,    20,    63,
     127,    92,    21,    44,    84,    43,   128,    22,    23,   166,
     163,   178,   174,   132,    97,    42,    25,   176,   138,   175,
     190,   165,    26,   130,   161,   180,   188,   193
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -101
static const yytype_int16 yypact[] =
{
    -101,    19,   195,  -101,     6,    10,  -101,  -101,    23,  -101,
    -101,  -101,  -101,  -101,   169,    -6,   293,    10,  -101,    27,
      36,  -101,    -3,  -101,    39,  -101,  -101,    42,    57,    10,
     155,    10,  -101,  -101,  -101,  -101,    42,  -101,  -101,   294,
     128,  -101,  -101,    67,    66,    10,  -101,  -101,  -101,  -101,
    -101,    68,    10,  -101,  -101,   155,   155,   155,   155,    10,
     155,   229,  -101,  -101,  -101,     5,  -101,  -101,   294,   396,
      80,    57,   155,  -101,  -101,  -101,    10,    10,    10,    10,
      10,    10,    10,    10,    67,   155,   155,   155,   155,   155,
     155,  -101,  -101,    79,   294,   147,   395,    82,   128,   128,
     128,   128,   335,   128,   -33,   297,   147,  -101,    10,  -101,
    -101,   396,    76,    76,    69,    69,   -17,   -17,  -101,  -101,
    -101,    30,    30,    49,    49,  -101,    49,   236,    52,    10,
      86,    58,   103,    10,  -101,  -101,    72,   116,   124,  -101,
     136,   341,  -101,   140,   141,  -101,    10,   357,  -101,   134,
    -101,  -101,   149,  -101,  -101,  -101,  -101,  -101,  -101,   363,
     108,    79,   147,   158,  -101,  -101,   163,  -101,    11,   152,
    -101,  -101,  -101,  -101,  -101,  -101,   252,  -101,  -101,    67,
     138,    97,   179,   189,  -101,   129,  -101,  -101,  -101,   192,
     -33,  -101,    10,    79,   197,  -101,   379,  -101,  -101,   199,
    -101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,   -61,   -89,  -101,     0,   -21,   175,    56,    62,
    -101,   -81,  -101,  -101,  -101,  -101,  -101,   -88,  -101,  -101,
    -101,  -101,  -101,  -100,   111,    -2,  -101,    77,    61,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -98
static const yytype_int16 yytable[] =
{
      24,   105,    28,   120,   129,    39,   140,   131,    69,    74,
     106,     4,   107,    82,    83,    29,   136,    61,   131,     3,
     137,    53,    54,    55,    56,    57,    58,    71,    45,    68,
      62,    75,   108,    30,    98,    99,   100,   101,   145,   103,
      60,    51,    31,    64,    65,    94,    66,    52,    32,    33,
      34,   111,    35,    27,    87,    88,    89,    36,    90,   102,
      37,    38,   171,    67,   121,   122,   123,   124,   125,   126,
      91,    93,   170,    95,   131,    89,   112,   113,   114,   115,
     116,   117,   118,   119,     4,   146,   110,   184,   134,    80,
      81,    24,   148,   184,    78,    79,    80,    81,   186,    82,
      83,   139,     4,    24,   197,   149,    82,    83,   141,   150,
     152,   181,     5,     6,     7,     8,   185,     9,    10,    11,
      12,    13,    14,    15,   153,    24,    16,    17,   154,   147,
       5,     6,     7,     8,     4,     9,    10,    11,    12,    13,
      14,    15,   155,   162,    16,    17,   159,   157,   158,   189,
      85,    86,    87,    88,    89,   168,    90,   164,   179,    24,
      72,   172,     5,     6,     7,     8,   177,     9,    10,    11,
      12,    13,    14,    15,    24,   187,    16,    17,    30,    24,
      24,   192,   -10,    24,     4,     9,    10,    11,    12,    13,
      14,    24,   196,    32,    33,    34,   191,    35,   -10,   194,
       4,   198,    73,   200,    70,    37,    38,    46,    47,    48,
      49,    50,     5,     6,     7,     8,   169,     9,    10,    11,
      12,    13,    14,    15,   183,   173,    16,    17,     5,     6,
       7,     8,   104,     9,    10,    11,    12,    13,    14,    15,
     142,     4,    16,    17,   151,    76,    77,    78,    79,    80,
      81,   195,   182,     0,     0,     0,   -97,     4,     0,    82,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     0,     9,    10,    11,    12,    13,    14,
      15,   143,   144,    16,    17,     5,     6,     7,     8,     0,
       9,    10,    11,    12,    13,    14,    15,   183,    52,    16,
      17,   139,     4,    53,    54,    55,    56,    57,    58,     0,
      76,    77,    78,    79,    80,    81,     0,     0,     0,     0,
      59,     0,    60,     0,    82,    83,     0,     0,     0,     0,
       5,     6,     7,     8,     0,     9,    10,    11,    12,    13,
      14,    15,   135,     0,    16,    17,     0,     0,   156,     0,
       0,    76,    77,    78,    79,    80,    81,    76,    77,    78,
      79,    80,    81,     0,   160,    82,    83,     0,     0,     0,
     167,    82,    83,    76,    77,    78,    79,    80,    81,    76,
      77,    78,    79,    80,    81,     0,   199,    82,    83,     0,
       0,     0,     0,    82,    83,    76,    77,    78,    79,    80,
      81,     0,   109,     0,   133,     0,     0,     0,     0,    82,
      83,    76,    77,    78,    79,    80,    81,     0,    85,    86,
      87,    88,    89,     0,    90,    82,    83
};

static const yytype_int16 yycheck[] =
{
       2,    62,     4,    84,    93,     5,   106,    95,    29,    30,
       5,     5,     7,    30,    31,     5,    49,    17,   106,     0,
      53,    10,    11,    12,    13,    14,    15,    29,     5,    29,
       3,    31,    27,    23,    55,    56,    57,    58,   127,    60,
      29,    47,    32,     7,    47,    45,     7,     5,    38,    39,
      40,    72,    42,    47,    24,    25,    26,    47,    28,    59,
      50,    51,   162,     6,    85,    86,    87,    88,    89,    90,
       3,     5,   161,     5,   162,    26,    76,    77,    78,    79,
      80,    81,    82,    83,     5,    33,     6,   176,     6,    20,
      21,    93,     6,   182,    18,    19,    20,    21,   179,    30,
      31,     4,     5,   105,   193,    47,    30,    31,   108,     6,
      38,   172,    33,    34,    35,    36,   177,    38,    39,    40,
      41,    42,    43,    44,     8,   127,    47,    48,     4,   129,
      33,    34,    35,    36,     5,    38,    39,    40,    41,    42,
      43,    44,     6,     9,    47,    48,   146,     7,     7,    52,
      22,    23,    24,    25,    26,    47,    28,     8,     6,   161,
       5,     3,    33,    34,    35,    36,     3,    38,    39,    40,
      41,    42,    43,    44,   176,    37,    47,    48,    23,   181,
     182,    52,     3,   185,     5,    38,    39,    40,    41,    42,
      43,   193,   192,    38,    39,    40,     7,    42,     3,     7,
       5,     4,    47,     4,    29,    50,    51,    38,    39,    40,
      41,    42,    33,    34,    35,    36,   160,    38,    39,    40,
      41,    42,    43,    44,    45,   163,    47,    48,    33,    34,
      35,    36,     3,    38,    39,    40,    41,    42,    43,    44,
       4,     5,    47,    48,   133,    16,    17,    18,    19,    20,
      21,   190,   175,    -1,    -1,    -1,     4,     5,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,     5,    47,
      48,     4,     5,    10,    11,    12,    13,    14,    15,    -1,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      27,    -1,    29,    -1,    30,    31,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    44,     7,    -1,    47,    48,    -1,    -1,     7,    -1,
      -1,    16,    17,    18,    19,    20,    21,    16,    17,    18,
      19,    20,    21,    -1,     7,    30,    31,    -1,    -1,    -1,
       7,    30,    31,    16,    17,    18,    19,    20,    21,    16,
      17,    18,    19,    20,    21,    -1,     7,    30,    31,    -1,
      -1,    -1,    -1,    30,    31,    16,    17,    18,    19,    20,
      21,    -1,     6,    -1,     9,    -1,    -1,    -1,    -1,    30,
      31,    16,    17,    18,    19,    20,    21,    -1,    22,    23,
      24,    25,    26,    -1,    28,    30,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    57,    58,     0,     5,    33,    34,    35,    36,    38,
      39,    40,    41,    42,    43,    44,    47,    48,    59,    60,
      64,    68,    73,    74,    81,    82,    88,    47,    81,     5,
      23,    32,    38,    39,    40,    42,    47,    50,    51,    61,
      62,    63,    81,    71,    69,     5,    38,    39,    40,    41,
      42,    47,     5,    10,    11,    12,    13,    14,    15,    27,
      29,    61,     3,    65,     7,    47,     7,     6,    61,    62,
      63,    81,     5,    47,    62,    61,    16,    17,    18,    19,
      20,    21,    30,    31,    70,    22,    23,    24,    25,    26,
      28,     3,    67,     5,    61,     5,    61,    80,    62,    62,
      62,    62,    61,    62,     3,    58,     5,     7,    27,     6,
       6,    62,    61,    61,    61,    61,    61,    61,    61,    61,
      67,    62,    62,    62,    62,    62,    62,    66,    72,    59,
      89,    73,    79,     9,     6,     7,    49,    53,    84,     4,
      79,    61,     4,    45,    46,    59,    33,    61,     6,    47,
       6,    80,    38,     8,     4,     6,     7,     7,     7,    61,
       7,    90,     9,    76,     8,    87,    75,     7,    47,    64,
      59,    79,     3,    65,    78,    85,    83,     3,    77,     6,
      91,    58,    83,    45,    59,    58,    67,    37,    92,    52,
      86,     7,    52,    93,     7,    84,    61,    59,     4,     7,
       4
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
#line 153 "parser.y"
    { current_return_code =add_variable_to_scope(current_scope, (yyvsp[(2) - (3)].variableName), 0, (yyvsp[(1) - (3)].intValue),variable_type,NULL,0);
												if(current_return_code == FAILURE)
													yyerror_with_variable("Redefinition of variable ", (yyvsp[(2) - (3)].variableName));
												else if(current_return_code == CONSTANT_NOT_INITIALIZED)
													yyerror_with_variable("Must initialize constant within declaration ", (yyvsp[(2) - (3)].variableName));
											;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
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
#line 196 "parser.y"
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
#line 238 "parser.y"
    {enter_new_scope();;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    {exit_a_scope();;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 246 "parser.y"
    {(yyval.information) =(yyvsp[(1) - (1)].information);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    {(yyval.information) =(yyvsp[(1) - (1)].information);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 248 "parser.y"
    {(yyval.information) =(yyvsp[(1) - (1)].information);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 251 "parser.y"
    {set_lexeme(&(yyval.information), FLOAT_DT); (yyval.information)->floatValue = (yyvsp[(1) - (1)].floatValue);(yyval.information)->variableName=NULL;
							// setting the quadraple info
							char buf[100];
  							gcvt((yyval.information)->floatValue, 2, buf);
							push( quad_stack, buf,NULL,quadraplesFile);
							;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 258 "parser.y"
    {set_lexeme(&(yyval.information), INT_DT); (yyval.information)->intValue = (yyvsp[(1) - (1)].intValue); (yyval.information)->variableName=NULL;
							// setting the quadraple info
							char temp[4]; 
							push( quad_stack, itoa(((yyval.information)->intValue),temp,10), NULL,quadraplesFile);
							;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 264 "parser.y"
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

  case 22:

/* Line 1455 of yacc.c  */
#line 278 "parser.y"
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

  case 23:

/* Line 1455 of yacc.c  */
#line 294 "parser.y"
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

  case 24:

/* Line 1455 of yacc.c  */
#line 309 "parser.y"
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

  case 25:

/* Line 1455 of yacc.c  */
#line 326 "parser.y"
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

  case 26:

/* Line 1455 of yacc.c  */
#line 341 "parser.y"
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

  case 27:

/* Line 1455 of yacc.c  */
#line 356 "parser.y"
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

  case 28:

/* Line 1455 of yacc.c  */
#line 371 "parser.y"
    {if((yyvsp[(2) - (3)].information))(yyval.information)=(yyvsp[(2) - (3)].information);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 372 "parser.y"
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

  case 30:

/* Line 1455 of yacc.c  */
#line 388 "parser.y"
    {set_lexeme(&(yyval.information), BOOL_DT); (yyval.information)->boolValue = 1; push(quad_stack, "true",NULL,quadraplesFile);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 389 "parser.y"
    {set_lexeme(&(yyval.information), BOOL_DT); (yyval.information)->boolValue = 0; push(quad_stack, "false",NULL,quadraplesFile);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 390 "parser.y"
    {set_lexeme(&(yyval.information), CHAR_DT); (yyval.information)->charValue = (yyvsp[(1) - (1)].charValue); char x[1]="";strncat(x, &(yyvsp[(1) - (1)].charValue), 1); push(quad_stack,x,NULL,quadraplesFile);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 391 "parser.y"
    {set_lexeme(&(yyval.information), STRING_DT); (yyval.information)->stringValue = (yyvsp[(1) - (1)].stringValue);push(quad_stack, (yyvsp[(1) - (1)].stringValue),NULL,quadraplesFile);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 398 "parser.y"
    { current_return_code = down_convert_booleans(&(yyval.information), (yyvsp[(1) - (3)].information), (yyvsp[(3) - (3)].information), AND_OP);
													if(current_return_code == STRING_INVALID_OPERATION)
														yyerror("Invalid String Conversion to Boolean ");
												;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 402 "parser.y"
    { current_return_code = down_convert_booleans(&(yyval.information), (yyvsp[(1) - (3)].information), (yyvsp[(3) - (3)].information), OR_OP);
													if(current_return_code == STRING_INVALID_OPERATION)
														yyerror("Invalid String Conversion to Boolean ");
												;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 406 "parser.y"
    { current_return_code = down_convert_booleans(&(yyval.information), (yyvsp[(2) - (2)].information), NULL, NOT_OP);
													if(current_return_code == STRING_INVALID_OPERATION)
														yyerror("Invalid String Conversion to Boolean ");
									;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 410 "parser.y"
    { current_return_code = down_convert_booleans(&(yyval.information), (yyvsp[(1) - (3)].information), (yyvsp[(3) - (3)].information), GREATERTHAN_OP);
															if(current_return_code == STRING_INVALID_OPERATION)
																yyerror("Invalid String Conversion to Boolean ");
														;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 414 "parser.y"
    { current_return_code = down_convert_booleans(&(yyval.information), (yyvsp[(1) - (3)].information), (yyvsp[(3) - (3)].information), GREATERTHANOREQUAL_OP);
																if(current_return_code == STRING_INVALID_OPERATION)
																	yyerror("Invalid String Conversion to Boolean ");
															;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 418 "parser.y"
    { current_return_code = down_convert_booleans(&(yyval.information), (yyvsp[(1) - (3)].information), (yyvsp[(3) - (3)].information), LESSTHAN_OP);
																if(current_return_code == STRING_INVALID_OPERATION)
																	yyerror("Invalid String Conversion to Boolean ");
															;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 422 "parser.y"
    { current_return_code = down_convert_booleans(&(yyval.information), (yyvsp[(1) - (3)].information), (yyvsp[(3) - (3)].information), LESSTHANOREQUAL_OP);
																if(current_return_code == STRING_INVALID_OPERATION)
																	yyerror("Invalid String Conversion to Boolean ");
															;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 426 "parser.y"
    { current_return_code = down_convert_booleans(&(yyval.information), (yyvsp[(1) - (3)].information), (yyvsp[(3) - (3)].information), EQUALEQUAL_OP);
																if(current_return_code == STRING_INVALID_OPERATION)
																	yyerror("Invalid String Conversion to Boolean ");
															;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 430 "parser.y"
    { current_return_code = down_convert_booleans(&(yyval.information), (yyvsp[(1) - (3)].information), (yyvsp[(3) - (3)].information), NOTEQUAL_OP);
																if(current_return_code == STRING_INVALID_OPERATION)
																	yyerror("Invalid String Conversion to Boolean ");
														;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 434 "parser.y"
    {(yyval.information) = (yyvsp[(2) - (3)].information);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 438 "parser.y"
    {assigning_operation_with_conversion((yyvsp[(1) - (3)].variableName), &(yyvsp[(3) - (3)].information),"+"); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 439 "parser.y"
    {assigning_operation_with_conversion((yyvsp[(1) - (3)].variableName), &(yyvsp[(3) - (3)].information),"-");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 440 "parser.y"
    {assigning_operation_with_conversion((yyvsp[(1) - (3)].variableName), &(yyvsp[(3) - (3)].information),"*");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 441 "parser.y"
    {assigning_operation_with_conversion((yyvsp[(1) - (3)].variableName), &(yyvsp[(3) - (3)].information),"/");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 442 "parser.y"
    {assigning_operation_with_conversion((yyvsp[(1) - (3)].variableName), &(yyvsp[(3) - (3)].information),"%");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 443 "parser.y"
    {	current_identifier = variable_found_in_scope(current_scope,(yyvsp[(1) - (2)].variableName));
												if(current_identifier == NULL){
													yyerror_with_variable("identifier not declared in this scope",(yyvsp[(1) - (2)].variableName));
												}else if(current_identifier->dataType==STRING_DT){
													yyerror_with_variable("Invalid Operation on strings",(yyvsp[(1) - (2)].variableName));
												}else{
													// push in quadraples 1 x x +
													push(quad_stack,"1",NULL,quadraplesFile);push(quad_stack,current_identifier->name,NULL,quadraplesFile);push(quad_stack,"+",current_identifier->name,quadraplesFile);
												}
											;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 453 "parser.y"
    {	current_identifier = variable_found_in_scope(current_scope,(yyvsp[(1) - (2)].variableName));
												if(current_identifier == NULL){
													yyerror_with_variable("identifier not declared in this scope",(yyvsp[(1) - (2)].variableName));
												}else if(current_identifier->dataType==STRING_DT){
													yyerror_with_variable("Invalid Operation on strings",(yyvsp[(1) - (2)].variableName));
												}
											;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 475 "parser.y"
    {enter_new_scope();;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 475 "parser.y"
    {exit_a_scope();;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 476 "parser.y"
    {enter_new_scope();;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 476 "parser.y"
    {exit_a_scope();;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 477 "parser.y"
    {enter_new_scope();;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 477 "parser.y"
    {exit_a_scope();;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 480 "parser.y"
    {(yyval.intValue) = INT_DT; ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 481 "parser.y"
    {(yyval.intValue) = FLOAT_DT;;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 482 "parser.y"
    {(yyval.intValue) = CHAR_DT;;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 483 "parser.y"
    {(yyval.intValue) = STRING_DT;;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 484 "parser.y"
    {(yyval.intValue) = BOOL_DT;;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 485 "parser.y"
    {(yyval.intValue) = CONST_INT_DT;;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 486 "parser.y"
    {(yyval.intValue) = CONST_FLOAT_DT;;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 487 "parser.y"
    {(yyval.intValue) = CONST_CHAR_DT; ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 488 "parser.y"
    {(yyval.intValue) = CONST_STRING_DT;;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 489 "parser.y"
    {(yyval.intValue) = CONST_BOOL_DT;;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 499 "parser.y"
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

  case 75:

/* Line 1455 of yacc.c  */
#line 511 "parser.y"
    {exit_a_scope();;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 513 "parser.y"
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

  case 77:

/* Line 1455 of yacc.c  */
#line 525 "parser.y"
    {exit_a_scope();;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 534 "parser.y"
    {(yyval.argument_info) = (struct argument_info *)malloc(sizeof(struct argument_info));
														 (yyval.argument_info)->next_arg = (yyvsp[(4) - (4)].argument_info);
														 (yyval.argument_info)->my_name = (yyvsp[(2) - (4)].variableName);
														 (yyval.argument_info)->my_type = (yyvsp[(1) - (4)].intValue);
														;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 539 "parser.y"
    {(yyval.argument_info) = (struct argument_info *)malloc(sizeof(struct argument_info));
											(yyval.argument_info)->next_arg = NULL;
											(yyval.argument_info)->my_name = (yyvsp[(2) - (2)].variableName);
											(yyval.argument_info)->my_type = (yyvsp[(1) - (2)].intValue);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 543 "parser.y"
    {(yyval.argument_info) = NULL;;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 546 "parser.y"
    { (yyval.argument_info) = (struct argument_info *)malloc(sizeof(struct argument_info));
												(yyval.argument_info)->next_arg = (yyvsp[(3) - (3)].argument_info);
												(yyval.argument_info)->my_name = (yyvsp[(1) - (3)].information)->variableName;
												(yyval.argument_info)->my_type = (yyvsp[(1) - (3)].information)->my_type; 
												;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 552 "parser.y"
    {	(yyval.argument_info) = (struct argument_info *)malloc(sizeof(struct argument_info)); 
								(yyval.argument_info)->my_name = (yyvsp[(1) - (1)].information)->variableName;
								(yyval.argument_info)->my_type = (yyvsp[(1) - (1)].information)->my_type; 
								(yyval.argument_info)->next_arg = NULL;;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 556 "parser.y"
    {(yyval.argument_info) = NULL;;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 559 "parser.y"
    {(yyval.information) = (yyvsp[(2) - (3)].information);;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 560 "parser.y"
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

  case 93:

/* Line 1455 of yacc.c  */
#line 626 "parser.y"
    { enter_new_scope();;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 626 "parser.y"
    {exit_a_scope();;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 627 "parser.y"
    {enter_new_scope();;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 627 "parser.y"
    {exit_a_scope();;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 632 "parser.y"
    {if((yyvsp[(3) - (3)].information)->my_type==STRING_DT)yyerror("Invalid String Conversion to Boolean");;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 632 "parser.y"
    {enter_new_scope();;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 632 "parser.y"
    {exit_a_scope();;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 635 "parser.y"
    {enter_new_scope();;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 635 "parser.y"
    {exit_a_scope();;}
    break;



/* Line 1455 of yacc.c  */
#line 2528 "parser.tab.c"
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
#line 639 "parser.y"
 
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
