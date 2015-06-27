/*
** nickname.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Wed Apr  8 11:50:11 2015 Brendan LE GLAUNEC
** Last update Sun Apr 12 17:03:30 2015 Brendan LE GLAUNEC
*/

#include <string.h>
#include <ctype.h>
#include "irc_s.h"

int irc_server_cmd_nick(t_srv *s, t_usr* u, char **cmd)
{
  t_usr *user;

  (void)s;
  if (cmd[1] == NULL)
    {
      server_send(u->s, ERR_NONICKNAMEGIVEN);
      return (EXIT_FAILURE);
    }
  else if (strspn(cmd[1], LEGAL_CHARS) != strlen(cmd[1]) \
  || isalpha(cmd[1][0]) == 0)
    {
      server_send(u->s, ERR_ERRONEUSNICKNAME);
      return (EXIT_FAILURE);
    }
  else if ((user = get_user(u, cmd[1])) != NULL)
    {
      server_send(u->s, ERR_NICKNAMEINUSE);
      return (EXIT_FAILURE);
    }
  if (u->n)
    free(u->n);
  u->n = strdup(cmd[1]);
  return (EXIT_SUCCESS);
}
