#include "shell.h"
char *replace_alias(char *line)
{
alias_t *tmp = alias_list;
char *cmd, *new;
cmd = _strtok(line, " ");
if (!cmd)
return (line);
while (tmp)
{
if (_strcmp(cmd, tmp->name) == 0)
{
new = _strdup(tmp->value);
free(line);
return (new);    
}
tmp = tmp->next;
}
return (line);
}
