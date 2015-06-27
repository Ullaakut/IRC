/*
** client_handle_replies.c for myIRC in /home/souls/Projects/rendu/PSU_2014_myirc/src/client/
**
** Made by pele_a
** Login   <pele_a@epitech.eu>
**
** Started on  Tue Apr  7 19:02:36 2015 pele_a
** Last update Sat Apr 11 21:31:17 2015 Brendan LE GLAUNEC
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "irc_client.h"
#include "gnl.h"

int     irc_client_handle_replies(t_client *client)
{
    char    *response;

    if ((response = get_next_line(client->sock_fd)) == NULL)
    {
        printf("Error: Connection with server %s:%d ended.\n",
                client->ip, client->port);
        irc_clear_client(client);
    }
    else
        printf("%s\n", response);
    free(response);
    return (1);
}
