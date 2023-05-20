#ifndef _SYMTAB
#define _SYMTAB
#include "uthash.h"
#include "symbolTableEntry.h"
#include <stdio.h>

struct variableEntry *variable_found_in_table(struct variableEntry **symbolTable, char *name)
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

    if (variable_found_in_table(symbolTable, variable->name) != NULL)
    {
        return FAILURE;
    }

    if (variable->dataType == CONST_BOOL_DT || variable->dataType == CONST_CHAR_DT || variable->dataType == CONST_INT_DT || variable->dataType == CONST_FLOAT_DT || variable->dataType == CONST_STRING_DT)
    {
        if (variable->is_initialized == 0)
        {
            return CONSTANT_NOT_INITIALIZED;
        }
    }

    HASH_ADD_STR(*symbolTable, name, variable);
    return SUCCESS;
}

ReturnCode set_variable_used(struct variableEntry **symbolTable, struct variableEntry *variable)
{

    struct variableEntry *newVariable = copy_variable(variable);
    HASH_DEL(*symbolTable, variable);

    newVariable->used = 1;
    HASH_ADD_STR(*symbolTable, name, newVariable);
    return SUCCESS;
}

ReturnCode assign_variable(struct variableEntry **symbolTable, struct variableEntry *variable)
{
    if (variable->dataType == CONST_BOOL_DT || variable->dataType == CONST_CHAR_DT || variable->dataType == CONST_INT_DT || variable->dataType == CONST_FLOAT_DT || variable->dataType == CONST_STRING_DT)
    {
        return CONSTANT_REASSIGNMENT;
    }

    struct variableEntry *newVariable = copy_variable(variable);
    HASH_DEL(*symbolTable, variable);

    newVariable->is_initialized = 1;
    HASH_ADD_STR(*symbolTable, name, newVariable);
    return SUCCESS;
}

void print(struct variableEntry **symbolTable, FILE *file)
{
    fputs("Symbol Table:\n", file);
    struct variableEntry *tmp;

    fputs("variable name \t data_type \t is_initialized \t kind \n", file);

    for (tmp = *symbolTable; tmp != NULL; tmp = (struct variableEntry *)(tmp->hh.next))
    {
        fprintf(file, "%s \t %d \t %d \t %d \n", tmp->name, tmp->dataType, tmp->is_initialized, tmp->type);
    }
    fprintf(file, "\n");
}

#endif