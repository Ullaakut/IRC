/*
** client_message_cmd.c for myIRC in /home/souls/Projects/rendu/PSU_2014_myirc/src/client/cmd/
**
** Made by pele_a
** Login   <pele_a@epitech.eu>
**
** Started on  Fri Apr 10 01:28:52 2015 pele_a
** Last update Sat Apr 11 23:59:35 2015 pele_a
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "irc_client.h"

int     irc_client_cmd_msg(t_client *client, char **cmd)
{
    char    *msg;
    char    *tmp;
    int     i;

    if (irc_client_check_connection(client))
    {
        if (cmd[1] == NULL || cmd[2] == NULL)
        {
            printf("%s: usage: <receiver>{,<receiver>} <text to be sent>\n",
                    cmd[0]);
            return (1);
        }
        msg = str_concat_var(5, CMD_PRIVMSG, " ", cmd[1],
                                (cmd[3] ? " :" : " "), cmd[2]);
        i = 2;
        while (cmd[++i])
        {
            msg = str_concat_var(3, (tmp = msg), " ", cmd[i]);
            free(tmp);
        }
        irc_client_send(client, msg);
        free(msg);
    }
    return (1);
}

int     irc_client_cmd_away(t_client *client, char **cmd)
{
    char    *msg;
    char    *tmp;
    int     i;

    if (irc_client_check_connection(client))
    {
        if (cmd[1] == NULL)
            msg = strdup(CMD_AWAY);
        else
        {
            msg = str_concat_var(3, CMD_AWAY, (cmd[2] ? " :" : " "), cmd[1]);
            i = 1;
            while (cmd[++i])
            {
                msg = str_concat_var(3, (tmp = msg), " ", cmd[i]);
                free(tmp);
            }
        }
        irc_client_send(client, msg);
        free(msg);
    }
    return (1);
}

int     irc_client_cmd_msg_global(t_client *client, char *msg)
{
    char    *tmp;

    if (irc_client_check_connection(client))
    {
        tmp = str_concat_var(3, CMD_PRIVMSG, " $* :", msg);
        irc_client_send(client, tmp);
        free(tmp);
    }
    return (1);
}
