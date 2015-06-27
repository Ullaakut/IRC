/*
** server_cmd_user.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Sun Apr 12 18:09:09 2015 Brendan LE GLAUNEC
** Last update Sun Apr 12 18:10:43 2015 Brendan LE GLAUNEC
*/

#include "irc_s.h"

int  irc_server_cmd_user(t_srv *s, t_usr* u, char** cmd)
{
  (void)s;
  if (!cmd[1] && !cmd[2] && !cmd[3] && !cmd[4])
    return (server_send(u->s, ERR_NEEDMOREPARAMS));
  return (EXIT_SUCCESS);
}

int  irc_server_cmd_pass(t_srv *s, t_usr* u, char** cmd)
{
  (void)s;
  if (!cmd[1])
    return (server_send(u->s, ERR_NEEDMOREPARAMS));
  return (EXIT_SUCCESS);
}
