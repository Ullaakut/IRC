/*
** server_cmd_users.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Sat Apr 11 15:17:39 2015 Brendan LE GLAUNEC
** Last update Sat Apr 11 23:48:28 2015 Brendan LE GLAUNEC
*/

#include "irc_s.h"

int  irc_server_cmd_names(t_srv *s, t_usr* u, char** cmd)
{
  t_usr_list *tmp;

  (void)cmd;
  (void)s;
  if (u->n == NULL)
    return (server_send(u->s, ERR_NOLOGIN));
  if (u->c == NULL)
    return (server_send(u->s, ERR_NOTONACHANNEL));
  tmp = u->c->u;
  server_send(u->s, RPL_NAMEREPLY);
  while (tmp != NULL)
  {
    server_send(u->s, str_concat_var(4, "393- [", \
    (tmp->usr->away ? "+" : ""), "] ", tmp->usr->n));
    tmp = tmp->next;
  }
  server_send(u->s, RPL_ENDOFNAMES);
  return (EXIT_SUCCESS);
}
