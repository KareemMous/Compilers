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
    SYNTAX_ERROR,
    SEMANTIC_ERROR,
    RUNTIME_ERROR,
} ReturnCode;

#endif