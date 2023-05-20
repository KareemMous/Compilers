#ifndef _SCOPE
#define _SCOPE
#include "symbolTable.h"

struct scope
{
    struct variableEntry *symbolTable;
    struct scope *parent;
};

struct scope initScope()
{
    struct scope scope;
    scope.parent = NULL;
    scope.symbolTable = NULL;
    return scope;
}

void setParent(struct scope *scope, struct scope *parent)
{
    scope->parent = parent;
    return;
}

struct scope *getParent(struct scope *scope)
{
    return scope->parent;
}

struct variableEntry *variable_found_in_scope(struct scope *scope, char *name)
{
    struct variableEntry *variable = NULL;

    variable = variable_found_in_table(&scope->symbolTable, name);
    if (variable != NULL)
    {
        return variable;
    }

    // check our parent's parents
    struct scope *parent = getParent(scope);

    while (parent != NULL)
    {
        variable = variable_found_in_table(&parent->symbolTable, name);
        if (variable != NULL)
        {
            return variable;
        }
        parent = getParent(parent);
    }
    return NULL;
}

ReturnCode add_variable_to_scope(struct scope *scope, char *name, int initialized, DataType dataType, Type type, DataType *parameterTypes, int parameterCount)
{
    struct variableEntry *variable = (struct variableEntry *)malloc(sizeof(struct variableEntry));
    variable->name = name;
    variable->type = type;
    variable->dataType = dataType;
    variable->params = parameterTypes;
    variable->parameterCount = parameterCount;
    variable->is_initialized = initialized;
    variable->used = 0;
    return add_variable_to_symbol_table(&scope->symbolTable, variable);
}

ReturnCode set_variable_used_in_scope(struct scope *scope, char *variableName)
{
    struct variableEntry *variable = variable_found_in_table(&scope->symbolTable, variableName);

    if (variable != NULL)
    {
        return set_variable_used(&scope->symbolTable, variable);
    }

    struct scope *parent = getParent(scope);

    while (parent != NULL)
    {
        variable = variable_found_in_table(&parent->symbolTable, variableName);
        if (variable != NULL)
        {
            return set_variable_used(&parent->symbolTable, variable);
        }
        parent = getParent(parent);
    }
    return FAILURE;
}

ReturnCode assign_variable_in_scope(struct scope *scope, char *variableName)
{
    struct variableEntry *variable = variable_found_in_table(&scope->symbolTable, variableName);

    if (variable != NULL)
    {
        return assign_variable(&scope->symbolTable, variable);
    }

    struct scope *parent = getParent(scope);

    while (parent != NULL)
    {
        variable = variable_found_in_table(&parent->symbolTable, variableName);
        if (variable != NULL)
        {
            return assign_variable(&parent->symbolTable, variable);
        }
        parent = getParent(parent);
    }
    return FAILURE;
}
void delete_all_variables_in_scope(struct scope *scope)
{
    struct variableEntry *variable, *tmp;

    HASH_ITER(hh, scope->symbolTable, variable, tmp)
    {
        HASH_DEL(scope->symbolTable, variable);
        free(variable);
    }
}

struct scope *delete_scope(struct scope *scope)
{
    struct scope *parent = getParent(scope);
    delete_all_variables_in_scope(scope);
    free(scope);
    return parent;
}

void print_symbol_table_in_scope(struct scope *scope, FILE *file)
{
    print(&scope->symbolTable, file);
}

#endif