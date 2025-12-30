#include "shell.h"
#define SHELL_NAME "./hsh"
/**
 * exe_cmd - Crée un processus enfant et exécute la commande donnée.
 * @line: commande saisie par l'utilisateur
 * @envp: tableau des variables d'environnement
 * @line_buf: buffer alloué par getline à libérer dans le processus enfant
 *
 * Cette fonction lance un fork, exécute la commande dans l'enfant
 * et attend la fin du processus dans le parent.
 * Return: 1
 */
int exe_cmd(char *cmd, char **envp)
{
pid_t pid;
int status, i;
char **av;
char *path;
av = split_line(cmd);
if (!av || !av[0])
return (0);
/* BUILTINS */
if (_strcmp(av[0], "exit") == 0)
{
handle_exit(av);
}
if (_strcmp(av[0], "cd") == 0)
{
builtin_cd(av);
goto clean;
}
if (_strcmp(av[0], "env") == 0)
{
builtin_env(envp);
goto clean;
}
if (_strchr(cmd, ';'))
{
handle_semicolon(cmd, envp);
goto clean;
}
if (_strstr(cmd, "&&") || _strstr(cmd, "||"))
{
handle_logical(cmd, envp);
goto clean;
}
if (_strcmp(av[0], "alias") == 0)
{
builtin_alias(av);
goto clean;
}
if (_strcmp(av[0], "history") == 0)
{
builtin_history();
goto clean;
}
path = find_in_path(av[0], envp);
if (!path)
{
fprintf(stderr, "./hsh: %s: not found\n", av[0]);
last_status = 127;
goto clean;
}
pid = fork();
if (pid == 0)
{
execve(path, av, envp);
perror("execve");
_exit(126);
}
waitpid(pid, &status, 0);
if (WIFEXITED(status))
last_status = WEXITSTATUS(status);
free(path);
clean:
for (i = 0; av[i]; i++)
free(av[i]);
free(av);
return (last_status);
}
