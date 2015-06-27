/*
** client_init.c for myIRC in /home/souls/Projects/rendu/PSU_2014_myirc/src/client/
**
** Made by pele_a
** Login   <pele_a@epitech.eu>
**
** Started on  Tue Apr  7 19:04:14 2015 pele_a
** Last update Fri Apr 10 01:39:17 2015 pele_a
*/

#include <stdlib.h>
#include <netdb.h>
#include "irc_client.h"

void    irc_clear_client(t_client *client)
{
    if (client->ip)
        free(client->ip);
    client->ip = NULL;
    client->port = -1;
    if (client->user_name)
        free(client->user_name);
    client->user_name = NULL;
    if (client->sock_fd != -1)
    {
        if (FD_ISSET(client->sock_fd, &(client->readfds)))
            FD_CLR(client->sock_fd, &(client->readfds));
        close_socket(client->sock_fd, NULL);
    }
    client->sock_fd = -1;
}

int     irc_init_client(t_client *client)
{
    client->ip = NULL;
    client->port = -1;
    client->user_name = NULL;
    client->s_in.sin_family = AF_INET;
    if (!(client->pe = getprotobyname("TCP")))
        return (handle_error("getprotobyname failed"));
    client->sock_fd = -1;
    FD_ZERO(&(client->readfds));
    FD_SET(0, &(client->readfds));
    return (0);
}
