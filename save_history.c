#include "shell.h"
void save_history(void)
{
char *home;
char path[1024];
int fd, i;
home = _getenv("HOME", environ);
if (!home)
return;

    snprintf(path, sizeof(path), "%s/.simple_shell_history", home);
    fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0600);

    if (fd == -1)
        return;

    for (i = 0; i < hist_count; i++)
    {
        write(fd, history[i], _strlen(history[i]));
        write(fd, "\n", 1);
        free(history[i]);
    }
    close(fd);
}