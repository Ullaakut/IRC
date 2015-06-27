/*
** str_concat.c for str_concat in /home/souls/Projects/rendu/PSU_2014_myirc/src/
**
** Made by pele_a
** Login   <pele_a@epitech.eu>
**
** Started on  Thu Apr  9 03:45:16 2015 pele_a
** Last update Thu Apr  9 04:05:38 2015 pele_a
*/

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char    *str_concat(char *s1, char *s2)
{
    char    *res;

    if (s1 == NULL || s2 == NULL ||
        (res = malloc(sizeof(*res) * (strlen(s1) + strlen(s2) + 1))) == NULL)
        return (NULL);
    strcpy(res, s1);
    strcat(res, s2);
    return (res);
}

static char	*str_concat_var_recurse(va_list *ap, int n, int pos, int len)
{
    char    *res;
    char    *s;
    int     l;

    if (pos == n)
    {
        if ((res = malloc(sizeof(*res) * (len + 1))) == NULL)
        return (NULL);
        res[len] = '\0';
        return (res);
    }
    s = va_arg(*ap, char *);
    l = strlen(s);
    if ((res = str_concat_var_recurse(ap, n, pos + 1, len + l)) == NULL)
        return (NULL);
    strncpy(&(res[len]), s, l);
    return (res);
}

char	*str_concat_var(int n, ...)
{
    va_list	ap;
    char	*res;

    va_start(ap, n);
    res = str_concat_var_recurse(&ap, n, 0, 0);
    va_end(ap);
    return (res);
}
