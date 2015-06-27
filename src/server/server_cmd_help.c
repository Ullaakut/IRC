/*
** server_cmd_help.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Sun Apr 12 15:29:03 2015 Brendan LE GLAUNEC
** Last update Sun Apr 12 20:59:12 2015 Brendan LE GLAUNEC
*/

#include "irc_s.h"

void    get_idx(char **ret)
{
  ret[NICK] = CMD_NICK;
  ret[LIST] = CMD_LIST;
  ret[JOIN] = CMD_JOIN;
  ret[PART] = CMD_PART;
  ret[NAMES] = CMD_NAMES;
  ret[PRIVMSG] = CMD_PRIVMSG;
  ret[AWAY] = CMD_AWAY;
  ret[QUIT] = CMD_QUIT;
  ret[MOTD] = CMD_MOTD;
  ret[PING] = CMD_PING;
  ret[HELP] = CMD_HELP;
  ret[TOPIC] = CMD_TOPIC;
  ret[USER] = CMD_USER;
  ret[PASS] = CMD_PASS;
  ret[OPER] = CMD_OPER;
  ret[SQUIT] = CMD_SQUIT;
  ret[NB_CMD] = NULL;
}

void    get_help(char **ret)
{
  ret[NICK] = HELP_NICK;
  ret[LIST] = HELP_LIST;
  ret[JOIN] = HELP_JOIN;
  ret[PART] = HELP_PART;
  ret[NAMES] = HELP_NAMES;
  ret[PRIVMSG] = HELP_PRIVMSG;
  ret[AWAY] = HELP_AWAY;
  ret[QUIT] = HELP_QUIT;
  ret[MOTD] = HELP_MOTD;
  ret[PING] = HELP_PING;
  ret[HELP] = HELP_HELP;
  ret[TOPIC] = HELP_TOPIC;
  ret[USER] = HELP_USER;
  ret[PASS] = HELP_PASS;
  ret[OPER] = HELP_OPER;
  ret[SQUIT] = HELP_SQUIT;
  ret[NB_CMD] = NULL;
}

int simple_help(t_usr *u)
{
  server_send(u->s, RPL_HELPTOPICS);
  server_send(u->s, RPL_HELPFIRST);
  server_send(u->s, RPL_HELPSECND);
  server_send(u->s, RPL_HELPTHIRD);
  server_send(u->s, RPL_HELPFOUR);
  return (server_send(u->s, RPL_ENDOFHELP));
}

int irc_server_cmd_help(t_srv *s, t_usr* u, char **cmd)
{
    char    *idx[NB_CMD + 1];
    char    *help[NB_CMD + 1];
    int     i;

    (void)s;
    if (!cmd[1])
        return (simple_help(u));
    get_idx(idx);
    get_help(help);
    i = -1;
    server_send(u->s, RPL_HELPSTART);
    while (idx[++i])
        if (strcasecmp(idx[i], cmd[1]) == 0)
        {
          server_send(u->s, str_concat(RPL_HELP, help[i]));
          return (server_send(u->s, RPL_ENDOFHELP));
        }
    return (server_send(u->s, ERR_UNKNOWNCOMMAND));
}
