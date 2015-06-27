/*
** part.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Sat Apr 11 15:03:35 2015 Brendan LE GLAUNEC
** Last update Sun Apr 12 00:32:31 2015 Brendan LE GLAUNEC
*/

#include "irc_s.h"

int  irc_server_cmd_part(t_srv *s, t_usr* u, char** cmd)
{
  t_chn *channel;
  int r;

  if (!cmd[1])
    return (server_send(u->s, ERR_NEEDMOREPARAMS));
  if (u->n == NULL)
    return (server_send(u->s, ERR_NOLOGIN));
  if (((channel = get_channel(s->c, cmd[1])) == NULL))
    return (server_send(u->s, ERR_NOSUCHCHANNEL));
  else if (is_in_chan(channel, u))
  {
    if (!(r = remove_user_from_chan(s->c, u, (cmd[2] ? cmd[2] : P_MSG))))
      remove_chan(s, channel);
    u->c = NULL;
    return (EXIT_SUCCESS);
  }
  return (server_send(u->s, ERR_NOTONCHANNEL));
}
