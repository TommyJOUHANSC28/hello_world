#include "shell.h"
/**
* expand_pid - PID du shell
* @line: pointeur line
* Return : $$
*/
char *expand_pid(char *line)
{
char buf[16];
char *pos;
pos = _strstr(line, "$$");
if (!pos)
return (line);
snprintf(buf, sizeof(buf), "%d", getpid());
return replace_substr(line, "$$", buf);
}