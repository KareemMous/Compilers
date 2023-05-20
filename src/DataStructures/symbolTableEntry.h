#ifndef _SYMTABENTRY
#define _SYMTABENTRY
#include "uthash.h"
#include "enums.h"

struct variableEntry
{
    char *name;

    Type type;
    DataType dataType;

    DataType *params;
    int parameterCount;

    int is_initialized;
    int used;

    UT_hash_handle hh;
};

struct variableEntry *copy_variable(struct variableEntry *oldVariable)
{
    struct variableEntry *newVariable = (struct variableEntry *)malloc(sizeof(struct variableEntry));
    newVariable->name = oldVariable->name;
    newVariable->type = oldVariable->type;
    newVariable->dataType = oldVariable->dataType;
    newVariable->params = oldVariable->params;
    newVariable->parameterCount = oldVariable->parameterCount;
    newVariable->is_initialized = oldVariable->is_initialized;
    newVariable->used = oldVariable->used;
    return newVariable;
}

#endif