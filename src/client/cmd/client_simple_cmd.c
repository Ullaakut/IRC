/*
** client_simple_cmd.c for myIRC in /home/souls/Projects/rendu/PSU_2014_myirc/src/client/cmd/
**
** Made by pele_a
** Login   <pele_a@epitech.eu>
**
** Started on  Tue Apr  7 19:06:54 2015 pele_a
** Last update Fri Apr 10 01:32:42 2015 pele_a
*/

#include "irc_client.h"

int     irc_client_cmd_nick(t_client *client, char **cmd)
{
    if (irc_client_check_connection(client))
        irc_client_send_msg(client, CMD_NICK, cmd);
    return (1);
}

int     irc_client_cmd_list(t_client *client, char **cmd)
{
    if (irc_client_check_connection(client))
        irc_client_send_msg(client, CMD_LIST, cmd);
    return (1);
}

int     irc_client_cmd_join(t_client *client, char **cmd)
{
    if (irc_client_check_connection(client))
        irc_client_send_msg(client, CMD_JOIN, cmd);
    return (1);
}

int     irc_client_cmd_part(t_client *client, char **cmd)
{
    if (irc_client_check_connection(client))
        irc_client_send_msg(client, CMD_PART, cmd);
    return (1);
}

int     irc_client_cmd_users(t_client *client, char **cmd)
{
    if (irc_client_check_connection(client))
        irc_client_send_msg(client, CMD_USERS, cmd);
    return (1);
}
