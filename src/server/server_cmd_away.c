/*
** server_cmd_away.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Sat Apr 11 23:32:31 2015 Brendan LE GLAUNEC
** Last update Sun Apr 12 00:09:36 2015 pele_a
*/

#include "irc_s.h"

int irc_server_cmd_away(t_srv *s, t_usr* u, char **cmd)
{
  (void)s;
  if (u->n == NULL)
    return (server_send(u->s, ERR_NOLOGIN));
  if (u->away == NULL && cmd[1])
    {
      free(u->away);
      u->away = concat_message(&(cmd[1]));
      server_send(u->s, RPL_NOWAWAY);
    }
  else if (!cmd[1])
    {
      free(u->away);
      u->away = NULL;
      server_send(u->s, RPL_UNAWAY);
    }
  return (EXIT_SUCCESS);
}
