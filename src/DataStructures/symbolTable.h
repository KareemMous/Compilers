#ifndef _SYMTAB
#define _SYMTAB
#include "uthash.h"
#include "symbolTableEntry.h"
#include <stdio.h>

struct variableEntry *variable_found(struct variableEntry **symbolTable, char *name)
{
    struct variableEntry *variable = NULL;
    HASH_FIND_STR(*symbolTable, name, variable);

    if (variable == NULL)
    {
        return NULL;
    }
    return variable;
}

ReturnCode add_variable_to_symbol_table(struct variableEntry **symbolTable, struct variableEntry *variable)
{

    if (variable_found(symbolTable, variable->name) != NULL)
    {
        return SEMANTIC_ERROR;
    }

    if (variable->dataType == CONST_BOOL || variable->dataType == CONST_CHAR || variable->dataType == CONST_INT || variable->dataType == CONST_FLOAT || variable->dataType == CONST_STRING)
    {
        if (variable->initialized == 0)
        {
            return SEMANTIC_ERROR;
        }
    }

    HASH_ADD_STR(*symbolTable, name, variable);
    return SUCCESS;
}

ReturnCode set_variable(struct variableEntry **symbolTable, struct variableEntry *variable)
{

    if (variable->dataType == CONST_BOOL || variable->dataType == CONST_CHAR || variable->dataType == CONST_INT || variable->dataType == CONST_FLOAT || variable->dataType == CONST_STRING)
    {
        return SEMANTIC_ERROR;
    }

    struct variableEntry *newVariable = copy_variable(variable);
    HASH_DEL(*symbolTable, variable);

    newVariable->initialized = 1;
    HASH_ADD_STR(*symbolTable, name, newVariable);
    return SUCCESS;
}

void print(struct variableEntry **symbolTable, FILE *file)
{
    fputs("Symbol Table:\n", file);
    struct variableEntry *tmp;

    fputs("Name\t\tType\t\tDataType\t\tInitialized\t\tValue\n", file);

    for (tmp = *symbolTable; tmp != NULL; tmp = (struct variableEntry *)(tmp->hh.next))
    {
        fprintf(file, "%s\t\t%s\t\t%s\t\t%d\t\t", tmp->name, tmp->type, tmp->dataType, tmp->initialized);
    }
    fprintf(file, "\n");
}

#endif