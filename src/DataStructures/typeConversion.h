#ifndef _TYPECONVERSION
#define _TYPECONVERSION
#include "enums.h"
#include "lexeme.h"
#include <stdio.h>

ReturnCode down_convert_type(struct lexemeInfo **lexeme, DataType oldDT, DataType newDT, int yylineno)
{
    int yylineno;
    if (oldDT == newDT)
        return SUCCESS;

    if (newDT == CONST_CHAR_DT || newDT == CHAR_DT)
    {
        if (oldDT == INT_DT || oldDT == CONST_INT_DT)
        {
            (*lexeme)->charValue = (char)(*lexeme)->intValue;
            printf("implicit conversion from int to char in line number: %d\n", yylineno);
        }
        else if (oldDT == FLOAT_DT || oldDT == CONST_FLOAT_DT)
        {
            (*lexeme)->charValue = (char)(*lexeme)->floatValue;
            printf("implicit conversion from float to char in line number: %d\n", yylineno);
        }
    }
    else if (newDT == CONST_INT_DT || newDT == INT_DT)
    {
        if (oldDT == FLOAT_DT || oldDT == CONST_FLOAT_DT)
        {
            (*lexeme)->intValue = (int)(*lexeme)->floatValue;
            printf("implicit conversion from float to int in line number: %d\n", yylineno);
        }
    }
    else if (newDT == BOOL_DT || newDT == CONST_BOOL_DT)
    {
        if (oldDT == INT_DT || oldDT == CONST_INT_DT)
        {
            (*lexeme)->boolValue = (int)(*lexeme)->intValue;
            printf("implicit conversion from int to bool in line number: %d\n", yylineno);
        }
        else if (oldDT == FLOAT_DT || oldDT == CONST_FLOAT_DT)
        {
            (*lexeme)->boolValue = (int)(*lexeme)->floatValue;
            printf("implicit conversion from float to bool in line number: %d\n", yylineno);
        }
        else if (oldDT == CHAR_DT || oldDT == CONST_CHAR_DT)
        {
            (*lexeme)->boolValue = (int)(*lexeme)->charValue;
            printf("implicit conversion from char to bool in line number: %d\n", yylineno);
        }
    }
    else
    {
        return STRING_INVALID_OPERATION;
    }
    return SUCCESS;
}

ReturnCode up_convert_my_type(struct lexemeInfo **lexeme, DataType oldDT, DataType newDT, int yylineno)
{
    if (oldDT == newDT)
        return SUCCESS;

    if (newDT == CONST_FLOAT_DT || newDT == FLOAT_DT)
    {
        if (oldDT == CONST_INT_DT || oldDT == INT_DT)
        {
            (*lexeme)->floatValue = (float)(*lexeme)->intValue;
            printf("implicit conversion from int to float in line number: %d\n", yylineno);
        }
        else if (oldDT == CONST_CHAR_DT || oldDT == CHAR_DT)
        {
            (*lexeme)->floatValue = (float)(*lexeme)->charValue;
            printf("implicit conversion from char to float in line number: %d\n", yylineno);
        }
        else if (oldDT == CONST_BOOL_DT || oldDT == BOOL_DT)
        {
            (*lexeme)->floatValue = (float)(*lexeme)->boolValue;
            printf("implicit conversion from bool to float in line number: %d\n", yylineno);
        }
    }
    else if (newDT == CONST_INT_DT || newDT == INT_DT)
    {
        if (oldDT == CONST_CHAR_DT || oldDT == CHAR_DT)
        {
            (*lexeme)->intValue = (int)(*lexeme)->charValue;
            printf("implicit conversion from char to int in line number: %d\n", yylineno);
        }
        else if (oldDT == CONST_BOOL_DT || oldDT == BOOL_DT)
        {
            (*lexeme)->intValue = (int)(*lexeme)->boolValue;
            printf("implicit conversion from bool to int in line number: %d\n", yylineno);
        }
    }
    else if (newDT == CONST_CHAR_DT || newDT == CHAR_DT)
    {
        if (oldDT == CONST_BOOL_DT || oldDT == BOOL_DT)
        {
            (*lexeme)->charValue = (char)(*lexeme)->boolValue;
            printf("implicit conversion from bool to char in line number: %d\n", yylineno);
        }
    }
    else
    {
        return STRING_INVALID_OPERATION;
    }
    return SUCCESS;
}

ReturnCode down_convert_booleans(struct lexemeInfo **result, struct lexemeInfo *firstExp, struct lexemeInfo *secExp, RelationalOperator op)
{
    if (firstExp->dataType == STRING_DT || secExp->dataType == STRING_DT || firstExp->dataType == CONST_STRING_DT || secExp->dataType == CONST_STRING_DT)
        return STRING_INVALID_OPERATION;

    set_lexeme(result, BOOL_DT);
    (*result)->boolValue = 0;
    return SUCCESS;
}

#endif