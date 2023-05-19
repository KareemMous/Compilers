#ifndef _SYMTABENTRY
#define _SYMTABENTRY
#include "uthash.h"
#include "enums.h"

struct variableEntry
{
    char *name;

    Type type;
    DataType dataType;

    DataType *parameterTypes;
    int parameterCount;

    int initialized;
    int used;

    UT_hash_handle hh;
};

struct variableEntry *copy_variable(struct variableEntry *oldVariable)
{
    struct variableEntry *newVariable = (struct variableEntry *)malloc(sizeof(struct variableEntry));
    newVariable->name = oldVariable->name;
    newVariable->type = oldVariable->type;
    newVariable->dataType = oldVariable->dataType;
    newVariable->parameterTypes = oldVariable->parameterTypes;
    newVariable->parameterCount = oldVariable->parameterCount;
    newVariable->initialized = oldVariable->initialized;
    newVariable->used = oldVariable->used;
    return newVariable;
}

#endif