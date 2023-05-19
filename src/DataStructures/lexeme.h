#pragma once
#ifndef _STRUCTS
#define _STRUCTS
#include <stdlib.h>
#include "enums.h"

struct lexemeInfo
{
    char *variableName;
    DataType dataType;
    int intValue;
    float floatValue;
    char charValue;
    char *stringValue;
    int boolValue;

    int is_initialized;
};

void set_lexeme(struct lexemeInfo **input_lexeme, DataType type)
{
    (*input_lexeme) = (struct lexemeInfo *)malloc(sizeof(struct lexemeInfo));
    (*input_lexeme)->dataType = type;
    (*input_lexeme)->is_initialized = 1;
}

struct argument_info
{
    DataType my_type;
    char *my_name;
    struct argument_info *next_arg; // points to next arguments in linked list
};

#endif