#include "shell.h"
void add_history(char *line)
{
    if (!line || !*line)
        return;

    if (hist_count == HIST_MAX)
    {
        free(history[0]);
        memmove(history, history + 1, sizeof(char *) * (HIST_MAX - 1));
        hist_count--;
    }
    history[hist_count++] = _strdup(line);
}