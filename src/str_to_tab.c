/*
** str_to_tab.c for myFTP in /home/souls/Projects/rendu/PSU_2014_myftp/srcs/
**
** Made by pele_a
** Login   <pele_a@epitech.eu>
**
** Started on  Wed Mar 18 11:47:39 2015 pele_a
** Last update Fri Apr 10 00:16:56 2015 pele_a
*/

#include <stdlib.h>
#include <string.h>
#include <strings.h>

char    **recurse_str_split(char *s, char *split, int i, int n)
{
    char    **tab;

    if (!(s[i]))
    {
        if ((tab = malloc(sizeof(*tab) * (n + 1))) == NULL)
            return (NULL);
        tab[n] = NULL;
        return (tab);
    }
    while (s[i] && !index(split, s[i]))
        i += 1;
    while (s[i] && index(split, s[i]))
        i += 1;
    if ((tab = recurse_str_split(s, split, i, n + 1)) == NULL)
        return (NULL);
    while (--i > 0 && index(split, s[i]));
    s[i + 1] = '\0';
    while (i >= 0 && !index(split, s[i]))
        i -= 1;
    if ((tab[n] = strdup(&(s[i + 1]))) == NULL)
        return (NULL);
    return (tab);
}

char    **str_split(char *s, char *split)
{
    char  **tab;
    char  *str;

    while (s && *s && index(split, *s))
        s += 1;
    if (s == NULL || (str = strdup(s)) == NULL)
        return (NULL);
    tab = recurse_str_split(str, split, 0, 0);
    free(str);
    return (tab);
}

char    **str_to_tab(char *s)
{
    return (str_split(s, " \t"));
}

void    free_tab(char **tab)
{
    int i;

    i = -1;
    while (tab[++i] != NULL)
        free(tab[i]);
    free(tab);
}
