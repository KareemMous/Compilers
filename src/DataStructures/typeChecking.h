#ifndef _TYPECHECKING
#define _TYPECHECKING
#include "enums.h"

ReturnCode check_sides(DataType type1, DataType type2)
{
    if (type1 != type2)
    {
        return FAILURE;
    }
    return SUCCESS;
}

OperationsToDo sides_implicit_conversion(DataType rhs, DataType lhs)
{

    if ((rhs == STRING || rhs == CONST_STRING) && (lhs != STRING && lhs != CONST_STRING) || (lhs == STRING || lhs == CONST_STRING) && (rhs != STRING && rhs != CONST_STRING))
    {
        return ERROR;
    }

    if (lhs > rhs)
    {
        return UPGRADE_RHS;
    }
    else if (lhs < rhs)
    {
        return DOWNGRADE_RHS;
    }
    else
    {
        return NONE;
    }
}

OperationsToDo sides_implicit_conversion_check(DataType rhs, DataType lhs)
{
    ReturnCode code = check_sides(rhs, lhs);
    if (code == SUCCESS)
    {
        return NONE;
    }

    return sides_implicit_conversion(rhs, lhs);
}
#endif
