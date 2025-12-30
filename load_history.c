#include "shell.h"
void load_history(void)
{
char *home;
char path[1024];
FILE *fp;
char *line = NULL;
size_t len = 0;
home = _getenv("HOME", environ);
    if (!home)
        return;

    snprintf(path, sizeof(path), "%s/.simple_shell_history", home);
    fp = fopen(path, "r");
    if (!fp)
        return;

    while (getline(&line, &len, fp) != -1)
    {
        line[_strlen(line) - 1] = '\0';
        add_history(line);
    }
    free(line);
    fclose(fp);
}