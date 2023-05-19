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

    if (newDT == CONST_CHAR || newDT == CHAR)
    {
        if (oldDT == INT || oldDT == CONST_INT)
        {
            (*lexeme)->charValue = (char)(*lexeme)->intValue;
            printf("implicit conversion from int to char in line number: %d\n", yylineno);
        }
        else if (oldDT == FLOAT || oldDT == CONST_FLOAT)
        {
            (*lexeme)->charValue = (char)(*lexeme)->floatValue;
            printf("implicit conversion from float to char in line number: %d\n", yylineno);
        }
    }
    else if (newDT == CONST_INT || newDT == INT)
    {
        if (oldDT == FLOAT || oldDT == CONST_FLOAT)
        {
            (*lexeme)->intValue = (int)(*lexeme)->floatValue;
            printf("implicit conversion from float to int in line number: %d\n", yylineno);
        }
    }
    else if (newDT == BOOL || newDT == CONST_BOOL)
    {
        if (oldDT == INT || oldDT == CONST_INT)
        {
            (*lexeme)->boolValue = (int)(*lexeme)->intValue;
            printf("implicit conversion from int to bool in line number: %d\n", yylineno);
        }
        else if (oldDT == FLOAT || oldDT == CONST_FLOAT)
        {
            (*lexeme)->boolValue = (int)(*lexeme)->floatValue;
            printf("implicit conversion from float to bool in line number: %d\n", yylineno);
        }
        else if (oldDT == CHAR || oldDT == CONST_CHAR)
        {
            (*lexeme)->boolValue = (int)(*lexeme)->charValue;
            printf("implicit conversion from char to bool in line number: %d\n", yylineno);
        }
    }
    else
    {
        return SYNTAX_ERROR;
    }
    return SUCCESS;
}

ReturnCode up_convert_my_type(struct lexemeInfo **lexeme, DataType oldDT, DataType newDT, int yylineno)
{
    if (oldDT == newDT)
        return SUCCESS;

    if (newDT == CONST_FLOAT || newDT == FLOAT)
    {
        if (oldDT == CONST_INT || oldDT == INT)
        {
            (*lexeme)->floatValue = (float)(*lexeme)->intValue;
            printf("implicit conversion from int to float in line number: %d\n", yylineno);
        }
        else if (oldDT == CONST_CHAR || oldDT == CHAR)
        {
            (*lexeme)->floatValue = (float)(*lexeme)->charValue;
            printf("implicit conversion from char to float in line number: %d\n", yylineno);
        }
        else if (oldDT == CONST_BOOL || oldDT == BOOL)
        {
            (*lexeme)->floatValue = (float)(*lexeme)->boolValue;
            printf("implicit conversion from bool to float in line number: %d\n", yylineno);
        }
    }
    else if (newDT == CONST_INT || newDT == INT)
    {
        if (oldDT == CONST_CHAR || oldDT == CHAR)
        {
            (*lexeme)->intValue = (int)(*lexeme)->charValue;
            printf("implicit conversion from char to int in line number: %d\n", yylineno);
        }
        else if (oldDT == CONST_BOOL || oldDT == BOOL)
        {
            (*lexeme)->intValue = (int)(*lexeme)->boolValue;
            printf("implicit conversion from bool to int in line number: %d\n", yylineno);
        }
    }
    else if (newDT == CONST_CHAR || newDT == CHAR)
    {
        if (oldDT == CONST_BOOL || oldDT == BOOL)
        {
            (*lexeme)->charValue = (char)(*lexeme)->boolValue;
            printf("implicit conversion from bool to char in line number: %d\n", yylineno);
        }
    }
    else
    {
        return SYNTAX_ERROR;
    }
    return SUCCESS;
}

ReturnCode down_convert_booleans(struct lexemeInfo **result, struct lexemeInfo *firstExp, struct lexemeInfo *secExp, RelationalOperator op)
{
    if (firstExp->dataType == STRING || secExp->dataType == STRING || firstExp->dataType == CONST_STRING || secExp->dataType == CONST_STRING)
        return SYNTAX_ERROR;

    set_lexeme(result, BOOL);
    (*result)->boolValue = 0;
    return SUCCESS;
}

#endif