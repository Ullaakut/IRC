/*
** client.c for my_IRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/client/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Tue Mar 31 09:42:09 2015 Brendan LE GLAUNEC
** Last update Sat Apr 11 20:58:54 2015 Brendan LE GLAUNEC
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "irc_client.h"

int     irc_client_check_connection(t_client *client)
{
    if (!CLIENT_CHECK_IS_CONNECTED(client))
    {
        printf("Error: You need to be connect to a server %s\n\t%s\n",
                "to perform this action", "Try : /server _host_[:_port_]");
        return (0);
    }
    return (1);
}

int     irc_client_send(t_client *client, char *msg)
{
    if (msg == NULL || client->sock_fd == -1)
        return (-1);
    dprintf(client->sock_fd, "%s\n", msg);
    return (0);
}

int     irc_client_send_msg(t_client *client, char *msg_type, char **arg)
{
    char    *msg;
    char    *tmp;
    int     i;

    msg = strdup(msg_type);
    i = 0;
    if (arg && arg[0])
        while (arg[++i])
        {
            msg = str_concat_var(3, (tmp = msg), " ", arg[i]);
            free(tmp);
        }
    irc_client_send(client, msg);
    free(msg);
    return (1);
}

int     irc_client(t_client *client)
{
    int ret;
    fd_set  rfds;

    ret = 1;
    while (ret > 0)
    {
        rfds = client->readfds;
        if (select((client->sock_fd != -1 ? client->sock_fd + 1 : 1),
                    &rfds, NULL, NULL, NULL) == -1)
            return (handle_error("select failed"));
        if (CLIENT_CHECK_IS_CONNECTED(client)
            && FD_ISSET(client->sock_fd, &rfds))
            ret = irc_client_handle_replies(client);
        if (ret > 0 && FD_ISSET(0, &rfds))
            ret = irc_client_handle_command(client);
    }
    return (ret);
}

int     main()
{
    t_client    client;

    if (irc_init_client(&client) == -1)
        return (-1);
    return (irc_client(&client));
}
