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
	#include "DataStructures/scope.h"
	#include "DataStructures/quadruple.h"
	#include "DataStructures/typeConversion.h"
	#include "DataStructures/conversions.h"


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
%}



%%
program	: statements
		;
	
statements: statements stmt  
			|		
			;
		
stmt:   Type_Identifier IDENTIFIER SEMICOLON { current_return_code =add_variable_to_scope(current_scope, $2, 0, $1,variable,NULL,0);
												if(current_return_code == FAILURE)
													yyerror_with_variable("Redefinition of variable ", $2);
												else if(current_return_code == CONSTANT_NOT_INITIALIZED)
													yyerror_with_variable("Must initialize constant within declaration ", $2);
											}  

	|	Type_Identifier IDENTIFIER ASSIGN EXPRESSION  SEMICOLON  {if($4 != NULL){
																	
																	if($4->is_initialized==0){
																		yyerror("use of uninitialized variable");
																	}
																	if(add_variable_to_scope(current_scope, $2, 1, $1,variable,NULL,0) == FAILURE){
																		yyerror_with_variable("Redefinition of variable ", $2);
																	}else{
																		operation = implicit_conversion($1,$4->my_type);
																		if(operation == DOWNGRADE_RHS){
																			current_return_code = downgrade_my_value(&$4,$4->my_type, $1,yylineno);
																			if(current_return_code == STRING_INVALID_OPERATION){
																				yyerror("invalid string conversion");
																			}else{
																				
																				push(quad_stack," ",NULL,quadraplesFile);push(quad_stack,"=",$2,quadraplesFile);
																			}
																		}else if(operation == UPGRADE_RHS){
																
																			current_return_code = upgrade_my_value(&$4,$4->my_type, $1,yylineno);
																			if(current_return_code == STRING_INVALID_OPERATION){
																				yyerror("invalid string conversion");
																			}else{
																				
																				push(quad_stack," ",NULL,quadraplesFile);push(quad_stack,"=",$2,quadraplesFile);
																			}
																		}else if(operation == ERROR){
																			yyerror("invalid string conversion");
																		}else{
																				// quadraples
																				push(quad_stack," ",NULL,quadraplesFile);push(quad_stack,"=",$2,quadraplesFile);
																		}
																	}
																}
															}

	|	IDENTIFIER ASSIGN EXPRESSION SEMICOLON { if($3 != NULL){
													if($3->is_initialized==0){
														yyerror("use of uninitialized variable");
													}
													current_return_code = assign_variable_in_scope(current_scope, $1);
													if(current_return_code == FAILURE)
														yyerror_with_variable("Undeclared variable ", $1);
													else if(current_return_code == CONSTANT_REASSIGNMENT)
														yyerror_with_variable("cant reassign a constant variable :", $1);
													else{
															current_identifier = variable_found_in_scope(current_scope,$1);
															operation = sides_implicit_conversion(current_identifier->dataType,$3->my_type);
															if(operation == DOWNGRADE_RHS){
																// downgrade conv to result dt needed
																current_return_code = down_convert_type(&$3,$3->my_type, current_identifier->dataType,yylineno);
																if(current_return_code == STRING_INVALID_OPERATION){
																	yyerror("invalid string conversion");
																}else{
																	// quadraples
																	push(quad_stack," ",NULL,quadraplesFile);push(quad_stack,"=",$1,quadraplesFile);
																}
															}else if(operation == UPGRADE_RHS){
																// upgrade to result dt needed
																current_return_code = up_convert_my_type(&$3,$3->my_type, current_identifier->dataType,yylineno);
																if(current_return_code == STRING_INVALID_OPERATION){
																	yyerror("invalid string conversion");
																}else{
																	// quadraples
																	push(quad_stack," ",NULL,quadraplesFile);push(quad_stack,"=",$1,quadraplesFile);
																}
															}else if(operation == ERROR){
																yyerror("invalid string conversion");
															}else{
																// quadraples
																push(quad_stack," ",NULL,quadraplesFile);push(quad_stack,"=",$1,quadraplesFile);
															}
														}
													}					
												} 
 
	|	Mathematical_Statement SEMICOLON
	|	IF_Statement
	|	{enter_new_scope();} Scope {exit_a_scope();}
	| 	LOOPS
	|   FUNCTIONS
	| 	Function_Calls SEMICOLON
	| 	Switch_Case
	;


EXPRESSION: Number_Declaration {$$ =$1;}
		| 	Boolean_Expression {$$ =$1;}
		|	Function_Calls	{$$ =$1;}
		;

Number_Declaration: FLOAT 	{set_lexeme(&$$, FLOAT_DT); $$->floatValue = $1;$$->variableName=NULL;
							// setting the quadraple info
							char buf[100];
  							gcvt($$->floatValue, 2, buf);
							push( quad_stack, buf,NULL,quadraplesFile);
							}
				
				|	INT 	{set_lexeme(&$$, INT_DT); $$->intValue = $1; $$->variableName=NULL;
							// setting the quadraple info
							char temp[4]; 
							push( quad_stack, itoa(($$->intValue),temp,10), NULL,quadraplesFile);
							}

				|   IDENTIFIER { 
						current_identifier = variable_found_in_scope(current_scope,$1);
						if(current_identifier == NULL){
							yyerror_with_variable("identifier not declared in this scope",$1 );
							$$ = NULL;
						}else{
							set_lexeme(&$$,current_identifier->dataType);
							$$->variableName = $1;
							$$->is_initialized = current_identifier->is_initialized;
							set_variable_used_in_scope(current_scope, $1);
							// setting the quadraple info
							push(quad_stack,$1,NULL,quadraplesFile);
						}
					}
				| 	Number_Declaration PLUS Number_Declaration  { if($1 && $3){
																	if($1->is_initialized==0 || $3->is_initialized==0){
																		yyerror("use of uninitialized variable");
																	}
																	current_return_code =  rhs_value(&$$,$1,$3,PLUS_OP,yylineno);
																	if(current_return_code == STRING_INVALID_OPERATION){
																		yyerror("invalid operation on strings");
																	}else if(current_return_code == OPERATION_NOT_SUPPORTED){
																		yyerror("Invalid Operations ");
																	}else{
																		// adding to quadraple
																		push(quad_stack, "+",NULL,quadraplesFile);
																	}
												}			
				}

				| 	Number_Declaration MINUS Number_Declaration {if($1 && $3){
																		 if($1->is_initialized==0 || $3->is_initialized==0){
																		yyerror("use of uninitialized variable");
																	}
																	current_return_code =  rhs_value(&$$,$1,$3,MINUS_OP,yylineno);
																	if(current_return_code == STRING_INVALID_OPERATION){
																		yyerror("invalid operation on strings");
																	}else if(current_return_code == OPERATION_NOT_SUPPORTED){
																		yyerror("Invalid Operations ");
																	}else{
																		// adding to quadraple
																		push(quad_stack, "-",NULL,quadraplesFile);
																	}
																}	
															}
				| 	Number_Declaration DIVIDE Number_Declaration {if($1 && $3){
																	if($1->is_initialized==0 || $3->is_initialized==0){
																		yyerror("use of uninitialized variable");
																	}
																	current_return_code =  rhs_value(&$$,$1,$3,DIVIDE_OP,yylineno);
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
															}	
				| 	Number_Declaration MULTIPLY Number_Declaration {if($1 && $3){
																 	if($1->is_initialized==0 || $3->is_initialized==0){
																		yyerror("use of uninitialized variable");
																	}
																	current_return_code =  rhs_value(&$$,$1,$3,TIMES_OP,yylineno);
																	if(current_return_code == STRING_INVALID_OPERATION){
																		yyerror("invalid operation on strings");
																	}else if(current_return_code == OPERATION_NOT_SUPPORTED){
																		yyerror("Invalid Operations ");
																	}else{
																		// adding to quadraple
																		push(quad_stack, "*",NULL,quadraplesFile);
																	}
																	}
																}	
				| 	Number_Declaration REM Number_Declaration {if($1 && $3){
																 	if($1->is_initialized==0 || $3->is_initialized==0){
																		yyerror("use of uninitialized variable");
																	}
																	current_return_code =  rhs_value(&$$,$1,$3,MOD_OP,yylineno);
																	if(current_return_code == STRING_INVALID_OPERATION){
																		yyerror("invalid operation on strings");
																	}else if(current_return_code == OPERATION_NOT_SUPPORTED){
																		yyerror("Invalid Operations ");
																	}else{
																		// adding to quadraple
																		push(quad_stack, "%",NULL,quadraplesFile);
																	}
																}
															}	
				| 	Number_Declaration POWER Number_Declaration {if($1 && $3){
																 	if($1->is_initialized==0 || $3->is_initialized==0){
																		yyerror("use of uninitialized variable");
																	}
																	current_return_code =  rhs_value(&$$,$1,$3,POWER_OP,yylineno);
																	if(current_return_code == STRING_INVALID_OPERATION){
																		yyerror("invalid operation on strings");
																	}else if(current_return_code == OPERATION_NOT_SUPPORTED){
																		yyerror("Invalid Operations ");
																	}else{
																		// adding to quadraple
																		push(quad_stack, "^",NULL,quadraplesFile);
																	}													
																}	
															}
				|	ORBRACKET Number_Declaration CRBRACKET {if($2)$$=$2;}
				| 	MINUS Number_Declaration %prec UMINUS {if($2){
														 			if($2->is_initialized==0){
																		yyerror("use of uninitialized variable");
																	}
																	current_return_code =  rhs_value(&$$,$2,NULL,UMINUS_OP,yylineno);
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
													}	
				|	TRUE			{set_lexeme(&$$, BOOL_DT); $$->boolValue = 1; push(quad_stack, "true",NULL,quadraplesFile);}
				|	FALSE			{set_lexeme(&$$, BOOL_DT); $$->boolValue = 0; push(quad_stack, "false",NULL,quadraplesFile);}
				| 	CHAR			{set_lexeme(&$$, CHAR_DT); $$->charValue = $1; char x[1]="";strncat(x, &$1, 1); push(quad_stack,x,NULL,quadraplesFile);}
				| 	STRING			{set_lexeme(&$$, STRING_DT); $$->stringValue = $1;push(quad_stack, $1,NULL,quadraplesFile);}
				;


/* defining boolean expression */
Boolean_Expression: 
					
					EXPRESSION AND EXPRESSION { current_return_code = down_convert_booleans(&$$, $1, $3, AND_OP);
													if(current_return_code == STRING_INVALID_OPERATION)
														yyerror("Invalid String Conversion to Boolean ");
												}
					| EXPRESSION OR EXPRESSION { current_return_code = down_convert_booleans(&$$, $1, $3, OR_OP);
													if(current_return_code == STRING_INVALID_OPERATION)
														yyerror("Invalid String Conversion to Boolean ");
												}
					| NOT EXPRESSION { current_return_code = down_convert_booleans(&$$, $2, NULL, NOT_OP);
													if(current_return_code == STRING_INVALID_OPERATION)
														yyerror("Invalid String Conversion to Boolean ");
									}
					| EXPRESSION GREATERTHAN EXPRESSION { current_return_code = down_convert_booleans(&$$, $1, $3, GREATERTHAN_OP);
															if(current_return_code == STRING_INVALID_OPERATION)
																yyerror("Invalid String Conversion to Boolean ");
														}
					| EXPRESSION GREATERTHANOREQUAL EXPRESSION{ current_return_code = down_convert_booleans(&$$, $1, $3, GREATERTHANOREQUAL_OP);
																if(current_return_code == STRING_INVALID_OPERATION)
																	yyerror("Invalid String Conversion to Boolean ");
															}
					| EXPRESSION LESSTHAN EXPRESSION { current_return_code = down_convert_booleans(&$$, $1, $3, LESSTHAN_OP);
																if(current_return_code == STRING_INVALID_OPERATION)
																	yyerror("Invalid String Conversion to Boolean ");
															}
					| EXPRESSION LESSTHANOREQUAL EXPRESSION { current_return_code = down_convert_booleans(&$$, $1, $3, LESSTHANOREQUAL_OP);
																if(current_return_code == STRING_INVALID_OPERATION)
																	yyerror("Invalid String Conversion to Boolean ");
															}
					| EXPRESSION EQUALEQUAL EXPRESSION { current_return_code = down_convert_booleans(&$$, $1, $3, EQUALEQUAL_OP);
																if(current_return_code == STRING_INVALID_OPERATION)
																	yyerror("Invalid String Conversion to Boolean ");
															}
					| EXPRESSION NOTEQUAL EXPRESSION { current_return_code = down_convert_booleans(&$$, $1, $3, NOTEQUAL_OP);
																if(current_return_code == STRING_INVALID_OPERATION)
																	yyerror("Invalid String Conversion to Boolean ");
														}
					| ORBRACKET Boolean_Expression CRBRACKET {$$ = $2;}
					;


Mathematical_Statement: IDENTIFIER PLUSEQUAL Number_Declaration {assigning_operation_with_conversion($1, &$3,"+"); }
				|		IDENTIFIER MINUSEQUAL Number_Declaration {assigning_operation_with_conversion($1, &$3,"-");}
				|		IDENTIFIER MULTIPLYEQUAL Number_Declaration {assigning_operation_with_conversion($1, &$3,"*");}
				|		IDENTIFIER DIVIDEEQUAL Number_Declaration {assigning_operation_with_conversion($1, &$3,"/");}
				|		IDENTIFIER REMEQUAL Number_Declaration {assigning_operation_with_conversion($1, &$3,"%");}
				|   	IDENTIFIER INCREMENT {	current_identifier = variable_found_in_scope(current_scope,$1);
												if(current_identifier == NULL){
													yyerror_with_variable("identifier not declared in this scope",$1);
												}else if(current_identifier->dataType==STRING_DT){
													yyerror_with_variable("Invalid Operation on strings",$1);
												}else{
													// push in quadraples 1 x x +
													push(quad_stack,"1",NULL,quadraplesFile);push(quad_stack,current_identifier->name,NULL,quadraplesFile);push(quad_stack,"+",current_identifier->name,quadraplesFile);
												}
											}
				|   	IDENTIFIER DECREMENT {	current_identifier = variable_found_in_scope(current_scope,$1);
												if(current_identifier == NULL){
													yyerror_with_variable("identifier not declared in this scope",$1);
												}else if(current_identifier->dataType==STRING_DT){
													yyerror_with_variable("Invalid Operation on strings",$1);
												}
											}
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

LOOPS: FOR  {enter_new_scope();}ORBRACKET stmt EXPRESSION SEMICOLON Mathematical_Statement CRBRACKET Loop_Scope {exit_a_scope();}
	|  WHILE EXPRESSION {enter_new_scope();} Loop_Scope {exit_a_scope();}
	|  DO {enter_new_scope();} Loop_Scope {exit_a_scope();} WHILE EXPRESSION SEMICOLON
	;

Type_Identifier:  INT {$$ = INT_DT; }
				| FLOAT {$$ = FLOAT_DT;}
				| CHAR  {$$ = CHAR_DT;}
				| STRING{$$ = STRING_DT;}
				| BOOL {$$ = BOOL_DT;}
				| CONST INT{$$ = CONST_INT_DT;}
				| CONST FLOAT{$$ = CONST_FLOAT_DT;}
				| CONST CHAR{$$ = CONST_CHAR_DT; }
				| CONST STRING{$$ = CONST_STRING_DT;}
				| CONST BOOL{$$ = CONST_BOOL_DT;}
				;
		

// Function declaration - added void option
// in void we can return or not 
// while in any other return type fn , we must return expression ; 



FUNCTIONS : Type_Identifier IDENTIFIER ORBRACKET ARGUMENTS CRBRACKET {
					//getting arguments of these function
					int no_of_args = 0 ;
					DataType* arguments_list = get_parameters_of_array($4,&no_of_args);
					// adding function to the symbol table
					current_return_code = add_variable_to_scope(current_scope, $2, 0, $1, function, arguments_list,no_of_args);
					if(current_return_code == FAILURE){
						yyerror_with_variable("Redefinition of function ", $2);
					}
					enter_new_scope(); // entering a new scope
					// we add parameters to symbol table after making new scope
					add_parameters_to_function_symbol_table(arguments_list, $4);
								} Function_Scope {exit_a_scope();} 

			| VOID IDENTIFIER ORBRACKET ARGUMENTS CRBRACKET {
					//getting arguments of these function
					int no_of_args = 0 ;
					DataType* arguments_list = get_parameters_of_array($4,&no_of_args);
					// adding function to the symbol table
					current_return_code = add_variable_to_scope(current_scope, $2, 0, VOID_DT, function, arguments_list,no_of_args);
					if(current_return_code == FAILURE){
						yyerror_with_variable("Redefinition of function ", $2);
					}
					enter_new_scope(); // entering a new scope
					// we add parameters to symbol table after making new scope
					add_parameters_to_function_symbol_table(arguments_list, $4);
								} Void_Function_Scope {exit_a_scope();}
			;

Function_Scope:	OCBRACKET statements RET EXPRESSION SEMICOLON CCBRACKET 	
			;
Void_Function_Scope:  Scope
			| OCBRACKET statements RET SEMICOLON CCBRACKET 	
			;

ARGUMENTS: Type_Identifier IDENTIFIER COMMA  ARGUMENTS	{$$ = (struct argument_info *)malloc(sizeof(struct argument_info));
														 $$->next_arg = $4;
														 $$->my_name = $2;
														 $$->my_type = $1;
														}
			| Type_Identifier IDENTIFIER 	{$$ = (struct argument_info *)malloc(sizeof(struct argument_info));
											$$->next_arg = NULL;
											$$->my_name = $2;
											$$->my_type = $1;}
			| {$$ = NULL;}//it can be empty
			;

Arguments_Call : EXPRESSION COMMA  Arguments_Call{ $$ = (struct argument_info *)malloc(sizeof(struct argument_info));
												$$->next_arg = $3;
												$$->my_name = $1->variableName;
												$$->my_type = $1->my_type; 
												}

				| EXPRESSION {	$$ = (struct argument_info *)malloc(sizeof(struct argument_info)); 
								$$->my_name = $1->variableName;
								$$->my_type = $1->my_type; 
								$$->next_arg = NULL;}
				| {$$ = NULL;}//it can be empty
				;

Function_Calls: ORBRACKET Function_Calls CRBRACKET  {$$ = $2;}
				| IDENTIFIER ORBRACKET Arguments_Call CRBRACKET { 
						// first of all we need to find the function
						current_identifier = variable_found_in_scope(current_scope,$1);
						if(current_identifier == NULL){
							yyerror("function not initialzed in this scope");
						}else{
							// we need to match the parameters with the real arguments
							// the real input params to function
							DataType *my_params = current_identifier->params;

							int parameterCount = current_identifier->parameterCount;
							int i = 0;
							int success = 1;
							while($3){
								if(i==parameterCount){
									yyerror("Number of arguments doesnt match function");
									success = 0;
									break;
								}
								
								// then we will check the types of them one by one
								if($3->my_name == NULL){
									// therefore its not an identifier and its a value
									// we will check the implicit conversion
									check_Type_Conversion(my_params[i] ,$3);
								}else{
									// identifer is sent
									// first of all we need to check that the variable passed is in table
									struct variableEntry * arg_identifier = variable_found_in_scope(current_scope,$3->my_name);
									if(arg_identifier == NULL){
										yyerror("variable in the argument list not initialzed in this scope");
									}else{
										// then we need to check on the type
										if(my_params[i] != $3->my_type){
											// we will check the implicit conversion
											check_Type_Conversion(my_params[i] ,$3);
										}
									}
								}
								$3= $3->next_arg;
								i++;
							}
							if(i < parameterCount){
									yyerror("Number of arguments doesnt match function");
									success = 0;
							}
							if(success == 1){
								set_variable_used_in_scope(current_scope, current_identifier->name);
								set_lexeme(&$$,current_identifier->dataType);
								$$->variableName = $1;
							}else{
								$$ = NULL;
							}
						}
					}

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

  
IF_Statement : IF  ORBRACKET EXPRESSION {if($3->my_type==STRING_DT)yyerror("Invalid String Conversion to Boolean");} CRBRACKET{enter_new_scope();} stmt {exit_a_scope();} endCondition 
			;

endCondition: %prec IFX | ELSE  {enter_new_scope();} stmt {exit_a_scope();}
			;


%% 
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
		current_return_code = add_variable_to_scope(current_scope, start_ptr->my_name, 1, start_ptr->my_type,parameter,NULL,0);
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
			current_return_code = down_convert_type(&input_lexeme,input_lexeme->dataType, real_identifier,yylineno);
			
			
			if(current_return_code == STRING_INVALID_OPERATION){
				yyerror("invalid string conversion");
			}

		}else if(operation == UPGRADE_RHS){
			// upgrade to result dt needed
			
			current_return_code = up_convert_my_type(&input_lexeme,input_lexeme->dataType, real_identifier,yylineno);
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