/*
** client_bonus_cmd.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/client/cmd/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Sun Apr 12 16:04:10 2015 Brendan LE GLAUNEC
** Last update Sun Apr 12 17:59:44 2015 pele_a
*/

#include <stdio.h>
#include "irc_client.h"

int     irc_client_cmd_help(t_client *client, char **cmd)
{
    if (irc_client_check_connection(client))
        irc_client_send_msg(client, CMD_HELP, cmd);
    return (1);
}

int     irc_client_cmd_motd(t_client *client, char **cmd)
{
    if (irc_client_check_connection(client))
        irc_client_send_msg(client, CMD_MOTD, cmd);
    return (1);
}

int     irc_client_cmd_ping(t_client *client, char **cmd)
{
    if (irc_client_check_connection(client))
        irc_client_send_msg(client, CMD_PING, cmd);
    return (1);
}

int     irc_client_cmd_topic(t_client *client, char **cmd)
{
    if (irc_client_check_connection(client) && cmd[1])
        irc_client_send_msg(client, CMD_TOPIC, cmd);
    else if (!cmd[1])
      printf("%s: usage: <topic name>\n", cmd[0]);
    return (1);
}

int     irc_client_cmd_oper(t_client *client, char **cmd)
{
    if (irc_client_check_connection(client))
        irc_client_send_msg(client, CMD_OPER, cmd);
    return (1);
}
