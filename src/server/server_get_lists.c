/*
** get_in_list.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Sat Apr 11 12:12:05 2015 Brendan LE GLAUNEC
** Last update Sat Apr 11 21:07:09 2015 Brendan LE GLAUNEC
*/

#include "irc_s.h"

t_chn* get_channel(t_chn *list, char *n)
{
  t_chn *tmp;

  tmp = list;
  while (tmp != NULL && strcmp(tmp->n, n) != 0)
    tmp = tmp->next;
  if (tmp)
    return (tmp);
  return (NULL);
}

t_usr* get_user(t_usr *list, char *n)
{
  t_usr *tmp;

  tmp = list;
  while (tmp != NULL)
  {
    if (tmp->n != NULL && strcmp(tmp->n, n) == 0)
      return (tmp);
    tmp = tmp->next;
  }
  return (NULL);
}
