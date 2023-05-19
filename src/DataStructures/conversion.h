#ifndef _CONVERSION
#define _CONVERSION
#include "enums.h"
#include "lexeme.h"
#include "typeChecking.h"
#include "typeConversion.h"
#include <stdio.h>
#include <math.h>

DataType highest_data_type(DataType type1, DataType type2)
{
    return (type1 > type2) ? type1 : type2;
}

ReturnCode rhs_value(struct lexemeInfo **result, struct lexemeInfo *operand1, struct lexemeInfo *operand2, Operator op, int yylineno)
{

    if (op == UMINUS && operand2 == NULL)
    {
        if (operand1->dataType == INT)
            (*result)->intValue = -operand1->intValue;
        else if (operand1->dataType == FLOAT)
            (*result)->floatValue = -operand1->floatValue;
        else
            return FAILURE;
        return SUCCESS;
    }

    DataType highestDT = highest_data_type(operand1->dataType, operand2->dataType);

    ReturnCode code = check_sides(operand1->dataType, operand2->dataType);
    if (code == FAILURE)
    {
        if (operand1->dataType == highestDT)
        {
            DataType lowerDT = operand2->dataType;
            operand2->dataType = highestDT;
            up_convert_my_type(&operand2, lowerDT, highestDT, yylineno);
        }
        else if (operand2->dataType == highestDT)
        {
            DataType lowerDT = operand1->dataType;
            operand1->dataType = highestDT;
            up_convert_my_type(&operand1, lowerDT, highestDT, yylineno);
        }
        code = SUCCESS;
    }

    if (code == SUCCESS)
    {
        if (highestDT == BOOL || highestDT == CONST_BOOL)
        {
            int op1 = operand1->boolValue;
            int op2 = operand2->boolValue;
            if (op == PLUS)
            {
                (*result)->charValue = (char)(operand1->boolValue + operand2->boolValue);
                printf("implicit conversion from bool to char in line number: %d\n", yylineno);
            }
            else if (op == MINUS)
            {
                (*result)->charValue = (char)(operand1->boolValue - operand2->boolValue);
                printf("implicit conversion from bool to char in line number: %d\n", yylineno);
            }
            else if (op == TIMES)
            {
                (*result)->boolValue = operand1->boolValue * operand2->boolValue;
            }
            else if (op == DIVIDE)
            {
                if (op2 == 0)
                {
                    printf("division by zero in line number: %d\n", yylineno);
                    return RUNTIME_ERROR;
                }
                (*result)->boolValue = operand1->boolValue / operand2->boolValue;
            }
            else if (op == MOD)
            {
                if (op2 == 0)
                {
                    printf("division by zero in line number: %d\n", yylineno);
                    return RUNTIME_ERROR;
                }
                (*result)->boolValue = operand1->boolValue % operand2->boolValue;
            }
            else if (op == POWER)
            {
                if (op2 == 0 && op1 == 0)
                {
                    printf("0^0 is undefined in line number: %d\n", yylineno);
                    return RUNTIME_ERROR;
                }
                (*result)->boolValue = pow(operand1->boolValue, operand2->boolValue);
            }
        }
        else if (highestDT == CHAR || highestDT == CONST_CHAR)
        {
            char op1 = operand1->charValue;
            char op2 = operand2->charValue;
            if (op == PLUS)
            {
                (*result)->charValue = (char)(operand1->charValue + operand2->charValue);
            }
            else if (op == MINUS)
            {
                (*result)->charValue = (char)(operand1->charValue - operand2->charValue);
            }
            else if (op == TIMES)
            {
                (*result)->charValue = operand1->charValue * operand2->charValue;
            }
            else if (op == DIVIDE)
            {
                if (op2 == 0)
                {
                    printf("division by zero in line number: %d\n", yylineno);
                    return RUNTIME_ERROR;
                }
                (*result)->charValue = operand1->charValue / operand2->charValue;
            }
            else if (op == MOD)
            {
                if (op2 == 0)
                {
                    printf("division by zero in line number: %d\n", yylineno);
                    return RUNTIME_ERROR;
                }
                (*result)->charValue = operand1->charValue % operand2->charValue;
            }
            else if (op == POWER)
            {
                if (op2 == 0 && op1 == 0)
                {
                    printf("0^0 is undefined in line number: %d\n", yylineno);
                    return RUNTIME_ERROR;
                }
                (*result)->charValue = pow(operand1->charValue, operand2->charValue);
            }
        }
        else if (highestDT == INT || highestDT == CONST_INT)
        {
            int op1 = operand1->intValue;
            int op2 = operand2->intValue;
            if (op == PLUS)
            {
                (*result)->intValue = operand1->intValue + operand2->intValue;
            }
            else if (op == MINUS)
            {
                (*result)->intValue = operand1->intValue - operand2->intValue;
            }
            else if (op == TIMES)
            {
                (*result)->intValue = operand1->intValue * operand2->intValue;
            }
            else if (op == DIVIDE)
            {
                if (op2 == 0)
                {
                    printf("division by zero in line number: %d\n", yylineno);
                    return RUNTIME_ERROR;
                }
                (*result)->intValue = operand1->intValue / operand2->intValue;
            }
            else if (op == MOD)
            {
                if (op2 == 0)
                {
                    printf("division by zero in line number: %d\n", yylineno);
                    return RUNTIME_ERROR;
                }
                (*result)->intValue = operand1->intValue % operand2->intValue;
            }
            else if (op == POWER)
            {
                if (op2 == 0 && op1 == 0)
                {
                    printf("0^0 is undefined in line number: %d\n", yylineno);
                    return RUNTIME_ERROR;
                }
                (*result)->intValue = pow(operand1->intValue, operand2->intValue);
            }
        }
        else if (highestDT == FLOAT || highestDT == CONST_FLOAT)
        {
            float op1 = operand1->floatValue;
            float op2 = operand2->floatValue;
            if (op == PLUS)
            {
                (*result)->floatValue = operand1->floatValue + operand2->floatValue;
            }
            else if (op == MINUS)
            {
                (*result)->floatValue = operand1->floatValue - operand2->floatValue;
            }
            else if (op == TIMES)
            {
                (*result)->floatValue = operand1->floatValue * operand2->floatValue;
            }
            else if (op == DIVIDE)
            {
                if (op2 == 0)
                {
                    printf("division by zero in line number: %d\n", yylineno);
                    return RUNTIME_ERROR;
                }
                (*result)->floatValue = operand1->floatValue / operand2->floatValue;
            }
            else if (op == MOD)
            {
                return NOT_SUPPORTED;
            }
            else if (op == POWER)
            {
                if (op2 == 0 && op1 == 0)
                {
                    printf("0^0 is undefined in line number: %d\n", yylineno);
                    return RUNTIME_ERROR;
                }
                (*result)->floatValue = pow(operand1->floatValue, operand2->floatValue);
            }
        }
        else if (highestDT == STRING || highestDT == CONST_STRING)
        {
            return FAILURE;
        }
    }
    return SUCCESS;
}

#endif
