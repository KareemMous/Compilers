#ifndef _ENUMS
#define _ENUMS

typedef enum
{
    function,
    parameter,
    variable
} Type;

typedef enum
{
    BOOL,
    CONST_BOOL,
    CHAR,
    CONST_CHAR,
    INT,
    CONST_INT,
    FLOAT,
    CONST_FLOAT,
    STRING,
    CONST_STRING,
    VOID
} DataType;

typedef enum
{
    PLUS,
    MINUS,
    TIMES,
    DIVIDE,
    MOD,
    POWER,
    UMINUS
} Operator;

typedef enum
{
    NONE,
    DOWNGRADE_RHS,
    UPGRADE_RHS,
    ERROR
} OperationsToDo;

typedef enum
{
    AND,
    OR,
    NOT,
    EQ,
    EQEQ,
    NEQ,
    LT,
    GT,
    LEQ,
    GEQ
} RelationalOperator;

typedef enum
{
    SUCCESS,
    FAILURE,
    SYNTAX_ERROR,
    SEMANTIC_ERROR,
    RUNTIME_ERROR,
    NOT_SUPPORTED
} ReturnCode;

#endif