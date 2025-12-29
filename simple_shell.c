#include "shell.h"
#include <sys/wait.h>
#include <fcntl.h>
/**
 * main - Point d'entrée du programme.
 * @ac: nombre d'arguments passés au programme
 * @av: tableau des arguments passés au programme
 * @envp: tableau des variables d'environnement
 *
 * Cette fonction affiche un prompt, lit les commandes de l'utilisateur,
 * puis les exécute en boucle jusqu'à la fin de l'entrée standard.
 * Si un fichier de script est passé en argument,il est exécuté à la place.
 *
 * Return: 0 en cas de succès
 */
int last_status = 0;
int main(int ac, char **av, char **envp)
{
char *line = NULL;
size_t len = 0;
ssize_t read;
char *cmd;
(void)ac;
(void)av;
signal(SIGINT, sigint_handler);
while (1)
{
if (isatty(STDOUT_FILENO))
{
char *cwd = _getcwd();
if (cwd)
{
write(1, cwd, _strlen(cwd));
write(1, "$ ", 2);
free(cwd);
}
}
read = get_line(&line, &len);
if (read == -1)
{
free(line);
exit(last_status);
}
/* Supprimer le \n */
if (read > 0 && line[read - 1] == '\n')
line[read - 1] = '\0';
cmd = del_space(line);
if (*cmd == '\0')
continue;
exe_cmd(cmd, envp);
}
}
