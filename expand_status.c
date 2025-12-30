#include "shell.h"
/**
* expand_status - fonction $? retour de la dernière commande 
* @line: poiteur à la line  
* Return: la dernière commande exécutée
*/
char *expand_status(char *line)
{
char buf[16];
char *pos;
pos = _strstr(line, "$?");
if (!pos)
return (line);
snprintf(buf, sizeof(buf), "%d", last_status);
return replace_substr(line, "$?", buf);
}
