/*
** list_channels.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Thu Apr  9 11:53:04 2015 Brendan LE GLAUNEC
** Last update Sun Apr 12 17:10:32 2015 Brendan LE GLAUNEC
*/

#include "irc_s.h"

int  irc_server_cmd_list(t_srv *s, t_usr* u, char** cmd)
{
  t_chn *tmp;
  char  **channels;
  int   i;

  tmp = s->c;
  if (u->n == NULL)
    return (server_send(u->s, ERR_NOLOGIN));
  server_send(u->s, RPL_LISTSTART);
  (cmd[1] ? (channels = str_split(cmd[1], ",")) : (channels = NULL));
  while (tmp != NULL)
  {
    if (!cmd[1])
      server_send(u->s, str_concat_var(4, "322-", tmp->n, " : ", \
      (tmp->topic ? tmp->topic : NOTOPIC)));
    else
      {
        i = 0;
        while (channels[i])
          if (strstr(tmp->n, channels[i++]) != NULL)
            server_send(u->s, str_concat_var(4, "322-", tmp->n, \
            " : ", (tmp->topic ? tmp->topic : NOTOPIC)));
      }
    tmp = tmp->next;
  }
  return (server_send(u->s, RPL_LISTEND));
}
