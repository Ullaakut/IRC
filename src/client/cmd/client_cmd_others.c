/*
** client_cmd_others.c for myIRC in /home/souls/Projects/rendu/PSU_2014_myirc/src/client/cmd/
**
** Made by pele_a
** Login   <pele_a@epitech.eu>
**
** Started on  Fri Apr 10 01:31:49 2015 pele_a
** Last update Sun Apr 12 18:52:14 2015 pele_a
*/

#include <stdio.h>
#include "irc_client.h"

int     irc_client_cmd_quit(t_client *client, char **cmd)
{
    if (irc_client_check_connection(client))
    {
        irc_client_send_msg(client, CMD_QUIT, cmd);
        printf("Disconnected from %s:%d\n", client->ip, client->port);
        irc_clear_client(client);
    }
    return (1);
}

int     irc_client_cmd_squit(t_client *client, char **cmd)
{
    if (irc_client_check_connection(client))
        irc_client_send_msg(client, CMD_SQUIT, cmd);
    return (1);
}

int     irc_client_cmd_send_file(t_client *client, char **cmd)
{
    (void)client;
    (void)cmd;
    printf("%s: Command not implemented.", cmd[0]);
    return (1);
}

int     irc_client_cmd_accept_file(t_client *client, char **cmd)
{
    (void)client;
    (void)cmd;
    printf("%s: Command not implemented.", cmd[0]);
    return (1);
}
