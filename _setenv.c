#include "shell.h"
/**
 * _setenv - builtin setenv (maison)
 * @av: arguments (av[0] = "setenv", av[1] = VAR, av[2] = VALUE)
 *
 * Return:
 *  0 en cas de succès
 *  1 en cas d'erreur
 */
int _setenv(char **av)
{
char *var;
if (!av || !av[1] || !av[2])
return (1);
var = malloc(_strlen(av[1]) + _strlen(av[2]) + 2);
if (!var)
return (1);
_strcpy(var, av[1]);
_strcat(var, "=");
_strcat(var, av[2]);
if (putenv(var) != 0)
return (1);
return (0);
}
