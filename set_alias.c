#include "shell.h"
void set_alias(char *name, char *value)
{
alias_t *tmp = alias_list;
while (tmp)
{
if (_strcmp(tmp->name, name) == 0)
{
free(tmp->value);
tmp->value = _strdup(value);
return;
}
tmp = tmp->next;
}
tmp = malloc(sizeof(alias_t));
tmp->name = _strdup(name);
tmp->value = _strdup(value);
tmp->next = alias_list;
alias_list = tmp;
}
