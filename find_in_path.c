#include "shell.h"
/**
* find_in_path - Cherche une commande dans les dossiers du PATH,
* @cmd: commande à chercher*,
* Return: chemin complet si trouvé, NULL sinon
*/
char *find_in_path(char *cmd, char **envp)
{
char *path = NULL, *copy = NULL, *token = NULL, *full = NULL;
int i = 0;
if (!cmd || !*cmd)
return (NULL);
/* récupérer PATH */
for (i = 0; envp && envp[i]; i++)
{
if (_strncmp(envp[i], "PATH=", 5) == 0)
{
path = envp[i] + 5;
break;
}
}
if (!path)
return (NULL);
copy = _strdup(path);
if (!copy)
return (NULL);
token = _strtok(copy, ":");
while (token)
{
full = malloc(_strlen(token) + _strlen(cmd) + 2);
if (!full)
break;
_strcpy(full, token);
_strcat(full, "/");
_strcat(full, cmd);
if (access(full, X_OK) == 0)
{
free(copy);
return (full);
}
free(full);
token = _strtok(NULL, ":");
}
free(copy);
return (NULL);
}