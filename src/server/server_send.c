/*
** server_send.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Fri Apr 10 12:43:44 2015 Brendan LE GLAUNEC
** Last update Sat Apr 11 21:08:52 2015 Brendan LE GLAUNEC
*/

#include "irc_s.h"

int     server_send(int sock_fd, char *msg)
{
    if (msg == NULL || sock_fd == -1)
        return (EXIT_FAILURE);
    printf("\t--> %s\n", msg);
    dprintf(sock_fd, "%s\n", msg);
    return (EXIT_SUCCESS);
}

int     server_send_msg_to_chanel(t_chn *channel, char *msg)
{
    t_usr_list   *list;

    if (channel == NULL || msg == NULL)
        return (EXIT_FAILURE);
    list = channel->u;
    while (list)
    {
        server_send(list->usr->s, msg);
        list = list->next;
    }
    return (EXIT_SUCCESS);
}
