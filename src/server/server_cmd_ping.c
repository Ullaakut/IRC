/*
** server_cmd_ping.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Sun Apr 12 15:38:34 2015 Brendan LE GLAUNEC
** Last update Sun Apr 12 16:00:06 2015 Brendan LE GLAUNEC
*/

#include "irc_s.h"

int irc_server_cmd_ping(t_srv *s, t_usr* u, char **cmd)
{
  (void)s;
  (void)cmd;
  return (server_send(u->s, RPL_PONG));
}
