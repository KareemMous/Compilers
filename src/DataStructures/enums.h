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
    BOOL_DT,
    CONST_BOOL_DT,
    CHAR_DT,
    CONST_CHAR_DT,
    INT_DT,
    CONST_INT_DT,
    FLOAT_DT,
    CONST_FLOAT_DT,
    STRING_DT,
    CONST_STRING_DT,
    VOID
} DataType;

typedef enum
{
    PLUS_OP,
    MINUS_OP,
    TIMES_OP,
    DIVIDE_OP,
    MOD_OP,
    POWER_OP,
    UMINUS_OP
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
    AND_OP,
    OR_OP,
    NOT_OP,
    GREATERTHAN_OP,
    GREATERTHANOREQUAL_OP,
    LESSTHAN_OP,
    LESSTHANOREQUAL_OP,
    EQUALEQUAL_OP,
    NOTEQUAL_OP
} RelationalOperator;

typedef enum
{
    SUCCESS,
    FAILURE,
    SYNTAX_ERROR,
    SEMANTIC_ERROR,
    RUNTIME_ERROR,
    CONSTANT_NOT_INITIALIZED,
    STRING_INVALID_OPERATION,
    CONSTANT_REASSIGNMENT,
    OPERATION_NOT_SUPPORTED,
    DIVISION_BY_ZERO_ERROR
} ReturnCode;

#endif