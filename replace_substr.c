#include "shell.h"

char *replace_substr(char *line, char *old, char *new)
{
char *pos, *res;
size_t len;
pos = _strstr(line, old);
if (!pos)
return (line);
len = _strlen(line) - _strlen(old) + _strlen(new);
res = malloc(len + 1);
strncpy(res, line, pos - line);
res[pos - line] = '\0';
_strcat(res, new);
_strcat(res, pos + strlen(old));
free(line);
return (res);
}