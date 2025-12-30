#include "shell.h"
void print_alias(alias_t *a)
{
write(1, a->name, _strlen(a->name));
write(1, "='", 2);
write(1, a->value, _strlen(a->value));
write(1, "'\n", 2);
}