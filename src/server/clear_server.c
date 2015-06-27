/*
** clear_server.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Thu Apr  9 13:10:36 2015 Brendan LE GLAUNEC
** Last update Sun Apr 12 18:09:01 2015 pele_a
*/

#include "irc_s.h"

static void free_channels(t_chn *channel)
{
    t_usr_list  *list;
    void        *tmp;

    while (channel)
    {
        list = channel->u;
        while (list)
        {
            tmp = list;
            list = list->next;
            free(tmp);
        }
        tmp = channel;
        if (channel->n)
            free(channel->n);
        if (channel->topic)
            free(channel->topic);
        channel = channel->next;
        free(tmp);
    }
}

void    clear_all_server(t_srv *server)
{
    t_usr   *user;
    void    *tmp;

    free_channels(server->c);
    user = server->u;
    while (user)
    {
        if (user->n)
            free(user->n);
        if (user->away)
            free(user->away);
        server_send(user->s, ERR_YOUREBANNEDCREEP);
        close(user->s);
        tmp = user;
        user = user->next;
        free(tmp);
    }
}
