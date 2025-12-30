#include "shell.h"
char *replace_alias(char *line)
{
    alias_t *tmp = alias_list;
    char *cmd;

    cmd = _strtok(line, " ");
    if (!cmd)
        return (line);

    while (tmp)
    {
        if (_strcmp(cmd, tmp->name) == 0)
            return (_strdup(tmp->value));
        tmp = tmp->next;
    }
    return (line);
}