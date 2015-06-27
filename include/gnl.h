/*
** headers.h for headers in /home/moran-_d/rendu/Getnextline
**
** Made by moran-_d
** Login   <moran-_d@epitech.net>
**
** Started on  Sun Nov 17 13:24:08 2013 moran-_d
** Last update Wed Apr  8 13:11:22 2015 pele_a
*/

#ifndef GETNEXTLINE_H_
# define GETNEXTLINE_H_

#define BUFF_SIZE	10

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*
** GETNEXTLINE.C
*/

char	*get_next_line(const int);
char	*copy_in_str(char *, char);
char	*get_buff(char *, int *, int);
char    *my_strdup(char *, char *);

#endif
