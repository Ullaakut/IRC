/*
** errmsg.c for errmsg in /home/le-gla_b/rendu/cpp_abstractvm
**
** Made by le-gla_b
** Login   <le-gla_b@epitech.net>
**
** Started on  Mon Mar  2 19:43:23 2015 le-gla_b
** Last update Mon Mar  2 19:43:56 2015 le-gla_b
*/

#include <unistd.h>
#include <string.h>

int	intmsg(char *str, int ret)
{
  write(2, str, strlen(str));
  write(2, "\n", 1);
  return (ret);
}

void*	ptrmsg(char *str, void *ret)
{
  write(2, str, strlen(str));
  write(2, "\n", 1);
  return (ret);
}
