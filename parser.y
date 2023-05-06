%start program

%union
{  
    int intValue;
    float floatValue;
	char charValue;                
    char* stringValue;
	int boolValue;
    char* variableName;
	struct lexemeInfo * information;
	struct argument_info * argument_info;
}

	%token OCBRACKET
	%token CCBRACKET
	%token ORBRACKET
	%token CRBRACKET

	%token SEMICOLON
	%token COLON
	%token COMMA

	%token INCREMENT
	%token DECREMENT
	%token PLUSEQUAL
	%token MINUSEQUAL
	%token MULTIPLYEQUAL
	%token DIVIDEEQUAL

	%token GREATERTHAN
	%token LESSTHAN
	%token GREATERTHANOREQUAL
	%token LESSTHANOREQUAL
	%token EQUALEQUAL
	%token NOTEQUAL

	%token PLUS
	%token MINUS
	%token MULTIPLY
	%token DIVIDE
	%token POWER
	%token ASSIGN
	%token REM
	%token REMEQUAL

	%token AND
	%token OR
	%token NOT

	%token WHILE
	%token DO
	%token FOR

	%token IF 
	%token ELSE



	%token <intValue> INT
	%token <charValue> CHAR
	%token <floatValue> FLOAT
	%token <boolValue> BOOL
	%token <stringValue> STRING
	%token ENUM
	%token CONST
	%token VOID

	%token BREAK
	%token CONTINUE

  	%token <variableName> IDENTIFIER

	%token SWITCH
	%token CASE

	%token FALSE
	%token TRUE


	%token RET
	%left GREATERTHAN LESSTHAN
	%left ASSIGN 
	%left GREATERTHANOREQUAL LESSTHANOREQUAL
	%left EQUALEQUAL NOTEQUAL
	%left AND OR NOT
	%left PLUS MINUS 
	%left DIVIDE MULTIPLY REM
	%left POWER
	%left ORBRACKET CRBRACKET

	%token DEFAULT

%type <intValue> Type_Identifier   
%type <information> Number_Declaration EXPRESSION Boolean_Expression Function_Calls
%type <argument_info> ARGUMENTS Arguments_Call

%nonassoc IFX
%nonassoc ELSE
%nonassoc UMINUS



%{  
	#include <stdio.h>
	#include <stdlib.h>   
	#include <string.h>
	#include <math.h>


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

	// variables to use through the code to check semantics
	struct variable_entry * current_identifier;

	struct Stack * quad_stack;
%}



%%
program	: statements
		;
	
statements: statements stmt  
			|		
			;
		
stmt:   Type_Identifier IDENTIFIER SEMICOLON 

	|	Type_Identifier IDENTIFIER ASSIGN EXPRESSION  SEMICOLON
	|	IDENTIFIER ASSIGN EXPRESSION SEMICOLON 
	|	Mathematical_Statement SEMICOLON
    |   {enter_new_scope();} Scope {exit_a_scope();}
	|	IF_Statement
	| 	LOOPS
	|   FUNCTIONS
	| 	Function_Calls SEMICOLON  // f1();
	| 	Switch_Case
	;

Enum_Declaration: ENUM IDENTIFIER OCBRACKET ENUM_LIST CCBRACKET SEMICOLON
			| ENUM IDENTIFIER SEMICOLON
			;

ENUM_LIST:
		ENUM_LIST COMMA IDENTIFIER
		| ENUM_LIST COMMA IDENTIFIER ASSIGN EXPRESSION
		| IDENTIFIER
		| IDENTIFIER ASSIGN EXPRESSION
		;

EXPRESSION: Number_Declaration 
		| 	Boolean_Expression 
		|	Function_Calls
		;

Number_Declaration: FLOAT 	
				|	INT
				|   IDENTIFIER 
				| 	Number_Declaration PLUS Number_Declaration 
				| 	Number_Declaration MINUS Number_Declaration 
				| 	Number_Declaration DIVIDE Number_Declaration 
				| 	Number_Declaration MULTIPLY Number_Declaration 	
				| 	Number_Declaration REM Number_Declaration 	
				| 	Number_Declaration POWER Number_Declaration
				|	ORBRACKET Number_Declaration CRBRACKET 
				| 	MINUS Number_Declaration %prec UMINUS 	
				|	TRUE			
				|	FALSE			
				| 	CHAR			
				| 	STRING			
				;


/* defining boolean expression */
Boolean_Expression: 
					// for logical expressions we can pass any data type
					// as (x) equivalent to (x!=0) whatever x is int, char, string, ...
					EXPRESSION AND EXPRESSION 
					| EXPRESSION OR EXPRESSION 
					| NOT EXPRESSION 
					/* 	boolean expressions for datatypes only 
						ex: 'a' > 'b'   -     1>2
					 */ 
					| EXPRESSION GREATERTHAN EXPRESSION 
					| EXPRESSION GREATERTHANOREQUAL EXPRESSION
					| EXPRESSION LESSTHAN EXPRESSION 
					| EXPRESSION LESSTHANOREQUAL EXPRESSION 
					| EXPRESSION EQUALEQUAL EXPRESSION 
					| EXPRESSION NOTEQUAL EXPRESSION 
					| ORBRACKET Boolean_Expression CRBRACKET
					;

// Mathematical statements  
/* IDENTIFIER ASSIGN EXPRESSION SEMICOLON {printf("Variable assignment\n");}  */
// We made the assign separetely in the stmt cfg since assign can take any thing on the RHS
// while if we made it here , it will take number only

Mathematical_Statement: IDENTIFIER PLUSEQUAL Number_Declaration
				|		IDENTIFIER MINUSEQUAL Number_Declaration 
				|		IDENTIFIER MULTIPLYEQUAL Number_Declaration 
				|		IDENTIFIER DIVIDEEQUAL Number_Declaration 
				|		IDENTIFIER REMEQUAL Number_Declaration 
				|   	IDENTIFIER INCREMENT 
				|   	IDENTIFIER DECREMENT 
				; 

Scope: OCBRACKET statements CCBRACKET	 
	;

// we separated Loop_statements bec they contain BREAK, Continue and we cant use them in normal context
Loop_statements: Loop_statements stmt
				| Loop_statements BREAK SEMICOLON 
				| Loop_statements CONTINUE SEMICOLON
				|
				;

Loop_Scope : OCBRACKET Loop_statements CCBRACKET 
			;

LOOPS: FOR {enter_new_scope();} ORBRACKET stmt EXPRESSION SEMICOLON Mathematical_Statement CRBRACKET Loop_Scope {exit_a_scope();}
	|  WHILE EXPRESSION {enter_new_scope();} Loop_Scope {exit_a_scope();}
	|  DO {enter_new_scope();} Loop_Scope {exit_a_scope();} WHILE EXPRESSION SEMICOLON
	;

Type_Identifier:  INT 
				| FLOAT 
				| CHAR  
				| STRING
				| BOOL
				| CONST INT
				| CONST FLOAT
				| CONST CHAR
				| CONST STRING
				| CONST BOOL
				;
		

// Function declaration - added void option
// in void we can return or not 
// while in any other return type fn , we must return expression ; 



FUNCTIONS : Type_Identifier IDENTIFIER ORBRACKET ARGUMENTS CRBRACKET Function_Scope
			| VOID IDENTIFIER ORBRACKET ARGUMENTS CRBRACKET Void_Function_Scope
			;

Function_Scope:	OCBRACKET statements RET EXPRESSION SEMICOLON CCBRACKET 	
			;
Void_Function_Scope:  Scope
			| OCBRACKET statements RET SEMICOLON CCBRACKET 	
			;

ARGUMENTS: Type_Identifier IDENTIFIER COMMA  ARGUMENTS
			| Type_Identifier IDENTIFIER 
			| 
			;

Arguments_Call : EXPRESSION COMMA Arguments_Call
				| EXPRESSION
				| 
				;

Function_Calls: ORBRACKET Function_Calls CRBRACKET 
				| IDENTIFIER ORBRACKET Arguments_Call CRBRACKET 
				;

// we made switch take a no (int , float ,.. ) or a fn call which returns int
// will check that later
Switch_Case : SWITCH EXPRESSION OCBRACKET Case_Expressions CCBRACKET 
			;

Switch_Case_Statements: Switch_Case_Statements stmt
				| Switch_Case_Statements BREAK SEMICOLON
				|
				;

Case_Expressions : CASE INT COLON { enter_new_scope();} Switch_Case_Statements {exit_a_scope();} Case_Expressions
				|	DEFAULT COLON {enter_new_scope();} Switch_Case_Statements {exit_a_scope();}
				|	// since we can have no default or any case (tested on C++)
				;

/* 
IF ELSE Case
https://stackoverflow.com/questions/6911214/how-to-make-else-associate-with-farthest-if-in-yacc 
*/
//   
IF_Statement : IF ORBRACKET EXPRESSION CRBRACKET {enter_new_scope();} stmt {exit_a_scope();} endCondition 
			;

endCondition: %prec IFX | ELSE {enter_new_scope();} stmt {exit_a_scope();}
			;


%% 
 int yyerror(char *s) { printf("line number : %d %s\n", yylineno,s);     return 0; }
 int yyerror_with_variable(char *s, char* var) { printf("line number : %d %s %s\n", yylineno,s, var);     return 0; }

 void enter_new_scope(){
	// setting the parent to currnt scope
	parent_scope = current_scope;
	// make the new scope by malloc
 	//current_scope = (struct scope *)malloc(sizeof(struct scope)); 
 	// calling initialize fn in scope.h
	//(*current_scope) = initialize_scope();
	// updating my parent
 	//set_parent_of_scope(current_scope,parent_scope);
 }

 void exit_a_scope(){
	 //print_symbol_table_in_scope(current_scope, symbolTableFile);

	// if there's parent, will set it to grandparent
	// not all cases we will have parent since at first and last scope it will be null
	
	if(parent_scope)

		//parent_scope = parent_scope->my_parent;
	// delete_scope fn return the parent of current scope  
	//current_scope =  delete_scope(current_scope);
	return;
 }


 int main(void) {
	
    enter_new_scope();

	yyin = fopen("test_phase_1.cpp.txt", "r");
	
	if(!yyparse()) {
       printf("Correct\n");
	}
	else {
		printf("Parsing failed\n");
		return 0;
	}

    exit_a_scope();
	
	fclose(yyin);

	return 0;
	
}