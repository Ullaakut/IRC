/*
** ll_channels.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Mon Apr  6 15:21:52 2015 Brendan LE GLAUNEC
** Last update Sun Apr 12 16:19:27 2015 Brendan LE GLAUNEC
*/

#include <string.h>
#include "irc_s.h"

void    *add_user_on_chan(t_chn *channel, t_usr *user)
{
    t_usr_list  *new;

    if ((new = malloc(sizeof(*new))) == NULL)
        return (ptrmsg("Malloc failure", NULL));
    new->prev = NULL;
    if ((new->next = channel->u))
        new->next->prev = new;
    new->usr = user;
    channel->u = new;
    user->c = channel;
    return (new);
}

/* return  -1 si le usr n'est pas dans le chan;
 *          1 si reste des usrs dans le chan sinon 0;
 */
int     remove_user_from_chan(t_chn *channel, t_usr *user, char *msg)
{
    t_usr_list *tmp;

    tmp = channel->u;
    while (tmp && tmp->usr != user)
        tmp = tmp->next;
    if (!tmp)
        return (-1);
    if (tmp->next)
        tmp->next->prev = tmp->prev;
    if (tmp->prev)
        tmp->prev->next = tmp->next;
    else
        channel->u = tmp->next;
    msg = str_concat_var(3, user->n, " ", (msg ? msg : "part the channel"));
    server_send_msg_to_chanel(channel, msg);
    free(msg);
    free(tmp);
    return ((channel->u ? 1 : 0));
}

void*   add_chan(t_chn **list, char *name)
{
    t_chn   *new;

    if ((new = malloc(sizeof(*new))) == NULL)
        return (ptrmsg("Malloc failure\n", NULL));
    new->prev = NULL;
    if ((new->next = *list))
        new->next->prev = new;
    new->n = strdup(name);
    new->u = NULL;
    new->topic = NULL;
    *list = new;
    return (new);
}

void    remove_chan(t_srv *server, t_chn *channel)
{
    if (channel->next)
        channel->next->prev = channel->prev;
    if (channel->prev)
        channel->prev->next = channel->next;
    else
        server->c = channel->next;
    free(channel->n);
    free(channel->topic);
    free(channel);
}
