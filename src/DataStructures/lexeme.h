#pragma once
#ifndef _STRUCTS
#define _STRUCTS
#include <stdlib.h>
#include "enums.h"

struct lexemeInfo
{
    char *name;
    DataType dataType;
    int intValue;
    float floatValue;
    char charValue;
    char *stringValue;
    int boolValue;

    int initialized;
};

void set_lexeme(struct lexemeInfo **input_lexeme, DataType type)
{
    (*input_lexeme) = (struct lexemeInfo *)malloc(sizeof(struct lexemeInfo));
    (*input_lexeme)->dataType = type;
    (*input_lexeme)->initialized = 1;
}

#endif