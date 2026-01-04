#include "shell.h"
/* ===================== STRING ===================== */
/**
 * _strlen - Calcule la longueur d'une chaîne de caractères
 * @s: La chaîne dont on veut connaître la longueur
 *
 * Return: La longueur de la chaîne
 */
unsigned int _strlen(const char *s)
{
unsigned int len = 0;
if (!s)
return (0);
while (s[len])
len++;
return (len);
}
/**
 * _strcmp - Compare deux chaînes de caractères
 * @s1: Première chaîne
 * @s2: Deuxième chaîne
 *
 * Return: 0 si identiques, négatif si s1 < s2, positif si s1 > s2
 */
int _strcmp(const char *s1, const char *s2)
{
if (!s1 || !s2)
return (s1 - s2);
while (*s1 && *s1 == *s2)
{
s1++;
s2++;
}
return ((unsigned char)*s1 - (unsigned char)*s2);
}
/**
 * _strncmp - Compare les n premiers caractères de deux chaînes
 * @s1: Première chaîne
 * @s2: Deuxième chaîne
 * @n: Nombre de caractères à comparer
 *
 * Return: 0 si identiques, négatif si s1 < s2, positif si s1 > s2
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
size_t i;
if (!s1 || !s2)
return (s1 - s2);
for (i =0; i < n; i++)
{
if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
return (0);
}
/**
 * _strdup - Duplique une chaîne de caractères
 * @s: Chaîne à dupliquer
 *
 * Return: Un pointeur vers la nouvelle chaîne, ou NULL en cas d'échec
 */
char *_strdup(const char *str)
{
size_t i, len;
char *dup;
if (!str)
return (NULL);
len = _strlen(str);
dup = malloc(len + 1);
if (!dup)
return (NULL);
for (i = 0; i <= len; i++)
dup[i] = str[i];
return (dup);
}
/**
 * _strchr - Recherche un caractère dans une chaîne
 * @s: La chaîne à analyser
 * @c: Le caractère recherché
 *
 * Return: Un pointeur vers la première occurrence de c, ou NULL si absent
 */
char *_strchr(const char *s, char c)
{
if (!s)
return (NULL);
while (*s)
{
if (*s == c)
return ((char *)s);
s++;
}
if (c == '\0')
return ((char *)s);
return (NULL);
}
/**
 * _strcpy - Copie une chaîne dans une autre
 * @dest: Destination de la copie
 * @src: Source à copier
 *
 * Return: Un pointeur vers dest
 */
char *_strcpy(char *dest, const char *src)
{
int i = 0;
if (!dest || !src)
return (NULL);
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
}
/**
 * _strcat - Concatène deux chaînes
 * @dest: Chaîne de destination
 * @src: Chaîne à ajouter
 *
 * Return: Un pointeur vers dest
 */
char *_strcat(char *dest, const char *src)
{
int i = 0;
int j = 0;
if (!dest || !src)
return (NULL);
while (dest[i])
i++;
while (src[j])
{
dest[i + j] = src[j];
j++;
}
dest[i + j] = '\0';
return (dest);
}

/* ===================== CHAR / INT ===================== */
/**
 * _isdigit - Vérifie si un caractère est un chiffre
 * @c: Caractère à tester
 *
 * Return: 1 si c est un chiffre, 0 sinon
 */
int _isdigit(char c)
{
return (c >= '0' && c <= '9');
}
/**
 * _atoi - Convertit une chaîne en entier
 * @s: La chaîne à convertir
 *
 * Return: L'entier converti
 */
int _atoi(const char *s)
{
int sign = 1;
int result = 0;
if (!s)
return (0);
while (*s == ' ' || *s == '\t' || *s == '\n')
s++;
if (*s == '-' || *s == '+')
{
if (*s == '-')
sign = -1;
s++;
}
while (*s && _isdigit(*s))
{
result = result * 10 + (*s - '0');
s++;
}
return (result * sign);
}

/* ===================== STRTOK ===================== */
/**
 * _strtok - Découpe une chaîne en tokens selon un délimiteur
 * @str: La chaîne à découper (ou NULL pour continuer)
 * @delim: Les délimiteurs
 *
 * Return: Le prochain token, ou NULL s'il n'y en a plus
 */
char *_strtok(char *str, const char *delim)
{
static char *next;
char *start;
if (!delim)
return (NULL);
if (str)
next = str;
if (!next)
return (NULL);
while (*next && _strchr(delim, *next))
next++;
if (*next == '\0')
{
next = NULL;
return (NULL);
}
start = next;
while (*next && !_strchr(delim, *next))
next++;
if (*next)
{
*next = '\0';
next++;
}
else
next = NULL;
return (start);
}
/* ===================== STRSTR ===================== */
/**
 * _strstr - Trouve une sous-chaîne dans une chaîne
 * @haystack: La chaîne principale
 * @needle: La sous-chaîne recherchée
 *
 * Return: Un pointeur vers la première occurrence de needle, ou NULL
 */
char *_strstr(const char *h, const char *n)
{
size_t i, j;
if (!*n)
return ((char *)h);
for (i = 0; h[i]; i++)
{
for (j = 0; n[j] && h[i + j] == n[j]; j++)
;
if (!n[j])
return ((char *)(h + i));
}
return (NULL);
}
/* ===================== REALLOC ===================== */
/**
 * _realloc - Réalloue un bloc mémoire
 * @ptr: Pointeur vers la mémoire précédemment allouée
 * @old_size: Ancienne taille du bloc
 * @new_size: Nouvelle taille souhaitée
 *
 * Return: Un pointeur vers la nouvelle zone mémoire, ou NULL en cas d'échec
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
char *new;
size_t i;
if (ptr == NULL)
return (malloc(new_size));
if (new_size == 0)
{
free(ptr);
return (NULL);
}
if (new_size == old_size)
return (ptr);
new = malloc(new_size);
if (!new)
return (NULL);
for (i = 0; i < old_size && i < new_size; i++)
new[i] = ((char *)ptr)[i];
free(ptr);
return (new);
}
