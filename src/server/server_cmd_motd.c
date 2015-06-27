/*
** server_cmd_motd.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Sun Apr 12 15:17:19 2015 Brendan LE GLAUNEC
** Last update Sun Apr 12 15:27:59 2015 Brendan LE GLAUNEC
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "irc_s.h"

int irc_server_cmd_motd(t_srv *s, t_usr* u, char **cmd)
{
  char *motd;
  int   mfd;

  (void)cmd;
  (void)s;
  if ((mfd = open("./MOTD", O_RDONLY)) == -1)
    return (server_send(u->s, ERR_NOMOTD));
  server_send(u->s, RPL_MOTDSTART);
  while ((motd = get_next_line(mfd)))
    server_send(u->s, str_concat("372-", motd));
  return (server_send(u->s, RPL_ENDOFMOTD));
}
