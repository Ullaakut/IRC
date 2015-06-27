/*
** server_cmd_topic.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Sun Apr 12 16:15:49 2015 Brendan LE GLAUNEC
** Last update Sun Apr 12 18:26:12 2015 pele_a
*/

#include "irc_s.h"

int irc_server_cmd_topic(t_srv *s, t_usr* u, char **cmd)
{
  char *msg;

  (void)s;
  if (u->n == NULL)
    return (server_send(u->s, ERR_NOLOGIN));
  if (u->c == NULL)
    return (server_send(u->s, ERR_NOTONACHANNEL));
  if (!cmd[1])
    return (server_send(u->s, ERR_NEEDMOREPARAMS));
  if (u->c->topic)
    free(u->c->topic);
  u->c->topic = concat_message(&(cmd[1]));
  msg = str_concat_var(4, "322 ", u->c->n, ":", u->c->topic);
  server_send(u->s, msg);
  free(msg);
  return (0);
}
