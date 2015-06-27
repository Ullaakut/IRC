/*
** join.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Thu Apr  9 12:45:55 2015 Brendan LE GLAUNEC
** Last update Sun Apr 12 00:21:43 2015 Brendan LE GLAUNEC
*/

#include "irc_s.h"

int  is_in_chan(t_chn *c, t_usr* u)
{
  t_usr_list *tmp;

  tmp = c->u;
  while (tmp != NULL)
  {
    if (tmp->usr == u)
      return (1);
    tmp = tmp->next;
  }
  return (0);
}

void swap_server(t_srv* s, t_usr* u, t_chn *new)
{
  if (u->c != NULL)
  {
    if (remove_user_from_chan(u->c, u, "joined another channel.") == 0)
      remove_chan(s, u->c);
    u->c = new;
  }
}

int  irc_server_cmd_join(t_srv *s, t_usr* u, char** cmd)
{
  t_chn *channel;

  if (!cmd[1])
    return (server_send(u->s, ERR_NEEDMOREPARAMS));
  if (u->n == NULL)
    return (server_send(u->s, ERR_NOLOGIN));
  if (cmd[1][0] != '#' && cmd[1][0] != '&')
    return (server_send(u->s, ERR_ERRONEUSCHANNEL));
  if (((channel = get_channel(s->c, cmd[1])) != NULL) && \
  !is_in_chan(channel, u))
  {
    swap_server(s, u, channel);
    add_user_on_chan(channel, u);
  }
  else if (channel == NULL)
  {
    add_chan(&(s->c), cmd[1]);
    swap_server(s, u, s->c);
    add_user_on_chan(s->c, u);
  }
  return (irc_server_cmd_names(s, u, cmd));
}
