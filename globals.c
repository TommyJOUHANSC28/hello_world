#include "shell.h"

char *history[HIST_MAX];
int hist_count = 0;
int last_status = 0;