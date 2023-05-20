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

    if (op == UMINUS_OP && operand2 == NULL)
    {
        if (operand1->my_type == INT_DT || operand1->my_type == CONST_INT_DT)
            (*result)->intValue = -operand1->intValue;
        else if (operand1->my_type == FLOAT_DT || operand1->my_type == CONST_FLOAT_DT)
            (*result)->floatValue = -operand1->floatValue;
        else
            return OPERATION_NOT_SUPPORTED;
        return SUCCESS;
    }

    DataType highestDT = highest_data_type(operand1->my_type, operand2->my_type);

    ReturnCode code = check_sides(operand1->my_type, operand2->my_type);
    if (code == FAILURE)
    {
        if (operand1->my_type == highestDT)
        {
            DataType lowerDT = operand2->my_type;
            operand2->my_type = highestDT;
            up_convert_my_type(&operand2, lowerDT, highestDT, yylineno);
        }
        else if (operand2->my_type == highestDT)
        {
            DataType lowerDT = operand1->my_type;
            operand1->my_type = highestDT;
            up_convert_my_type(&operand1, lowerDT, highestDT, yylineno);
        }
        code = SUCCESS;
    }

    if (code == SUCCESS)
    {
        if (highestDT < INT_DT)
        {
            set_lexeme(result, highestDT);
            if (highestDT == BOOL_DT || highestDT == CONST_BOOL_DT)
            {
                if (op == PLUS_OP)
                {
                    (*result)->intValue = (int)(operand1->boolValue + operand2->boolValue);
                }
                else if (op == MINUS_OP)
                {
                    (*result)->intValue = (int)(operand1->boolValue - operand2->boolValue);
                }
                else
                {
                    return OPERATION_NOT_SUPPORTED;
                }
                printf("implicit conversion from bool to int in line number: %d\n", yylineno);
            }
            else if (highestDT == CHAR_DT || highestDT == CONST_CHAR_DT)
            { // if its char
                if (op == PLUS_OP)
                {
                    (*result)->intValue = (int)(operand1->charValue + operand2->charValue);
                }
                else if (op == MINUS_OP)
                {
                    (*result)->intValue = (int)(operand1->charValue - operand2->charValue);
                }
                else
                {
                    return OPERATION_NOT_SUPPORTED;
                }
                printf("implicit conversion from char to int in line number: %d\n", yylineno);
            }
        }
        else if (highestDT == INT_DT || highestDT == CONST_INT_DT)
        {
            int op1 = operand1->intValue;
            int op2 = operand2->intValue;
            if (op == PLUS_OP)
            {
                (*result)->intValue = operand1->intValue + operand2->intValue;
            }
            else if (op == MINUS_OP)
            {
                (*result)->intValue = operand1->intValue - operand2->intValue;
            }
            else if (op == TIMES_OP)
            {
                (*result)->intValue = operand1->intValue * operand2->intValue;
            }
            else if (op == DIVIDE_OP)
            {
                if (op2 == 0)
                {
                    printf("division by zero in line number: %d\n", yylineno);
                    return DIVISION_BY_ZERO_ERROR;
                }
                (*result)->intValue = operand1->intValue / operand2->intValue;
            }
            else if (op == MOD_OP)
            {
                if (op2 == 0)
                {
                    printf("division by zero in line number: %d\n", yylineno);
                    return DIVISION_BY_ZERO_ERROR;
                }
                (*result)->intValue = operand1->intValue % operand2->intValue;
            }
            else if (op == POWER_OP)
            {
                if (op2 == 0 && op1 == 0)
                {
                    printf("0^0 is undefined in line number: %d\n", yylineno);
                    return DIVISION_BY_ZERO_ERROR;
                }
                (*result)->intValue = pow(operand1->intValue, operand2->intValue);
            }
        }
        else if (highestDT == FLOAT_DT || highestDT == CONST_FLOAT_DT)
        {
            float op1 = operand1->floatValue;
            float op2 = operand2->floatValue;
            if (op == PLUS_OP)
            {
                (*result)->floatValue = operand1->floatValue + operand2->floatValue;
            }
            else if (op == MINUS_OP)
            {
                (*result)->floatValue = operand1->floatValue - operand2->floatValue;
            }
            else if (op == TIMES_OP)
            {
                (*result)->floatValue = operand1->floatValue * operand2->floatValue;
            }
            else if (op == DIVIDE_OP)
            {
                if (op2 == 0)
                {
                    printf("division by zero in line number: %d\n", yylineno);
                    return DIVISION_BY_ZERO_ERROR;
                }
                (*result)->floatValue = operand1->floatValue / operand2->floatValue;
            }
            else if (op == MOD_OP)
            {
                return OPERATION_NOT_SUPPORTED;
            }
            else if (op == POWER_OP)
            {
                if (op2 == 0 && op1 == 0)
                {
                    printf("0^0 is undefined in line number: %d\n", yylineno);
                    return DIVISION_BY_ZERO_ERROR;
                }
                (*result)->floatValue = pow(operand1->floatValue, operand2->floatValue);
            }
        }
        else if (highestDT == STRING_DT || highestDT == CONST_STRING_DT)
        {
            return FAILURE;
        }
    }
    return SUCCESS;
}

#endif
