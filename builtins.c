#include "shell.h"
/**
 * builtin_env - Affiche l'environnement courant
 * @envp: tableau des variables d'environnement
 *
 * Return: 0 en cas de succès
 */
int builtin_env(char **envp)
{
int i = 0;
while (envp && envp[i])
{
write(1, envp[i], _strlen(envp[i]));
write(1, "\n", 1);
i++;
}
return (0);
}
/**
 * builtin_cd - Changer le repertoire actuel courant
 * @av: argument de la commande cd
 *
 * Return: -1 en cas de succès
 */
int builtin_cd(char **av)
{
char *oldpwd;
char *newpwd;
char *args[4];
oldpwd = _getcwd();
if (!oldpwd)
return (1);
if (!av[1])
{
if (chdir(_getenv("HOME", environ)) == -1)
{
perror("cd");
free(oldpwd);
return (1);
}
}
else if (chdir(av[1]) == -1)
{
perror("cd");
free(oldpwd);
return (1);
}
newpwd = _getcwd();
if (!newpwd)
{
free(oldpwd);
return (1);
}
/* OLDPWD */
args[0] = "setenv";
args[1] = "OLDPWD";
args[2] = oldpwd;
args[3] = NULL;
_setenv(args);
/* PWD */
args[1] = "PWD";
args[2] = newpwd;
_setenv(args);
free(oldpwd);
free(newpwd);
return (0);
}
/**
 * builtin_exit - Quitter proprement simple shell
 * @envp: tableau de la sortie
 *
 * Return: 0 en cas de succès
 */
int builtin_exit(char **av)
{
int status = 0;
if (av[1])
status = _atoi(av[1]);
exit(status);
}
