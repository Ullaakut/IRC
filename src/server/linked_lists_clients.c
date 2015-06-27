/*
** ll_clients.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Mon Apr  6 14:24:37 2015 Brendan LE GLAUNEC
** Last update Sun Apr 12 17:43:34 2015 pele_a
*/

#include "irc_s.h"

void*   add_client(t_usr **list, int cs)
{
    t_usr* new;

    if ((new = malloc(sizeof(*new))) == NULL)
        return (ptrmsg("Malloc failure\n", NULL));
    new->s = cs;
    new->n = NULL;
    new->c = NULL;
    new->away = NULL;
    new->is_oper = 0;
    if ((new->next = *list))
        new->next->prev = new;
    new->prev = NULL;
    *list = new;
    return (new);
}

void    remove_client(t_srv *server, t_usr *usr, char *msg)
{
    if (usr->next)
        usr->next->prev = usr->prev;
    if (usr->prev)
        usr->prev->next = usr->next;
    else
        server->u = usr->next;
    if (usr->n)
    {
        if (usr->c)
            remove_user_from_chan(usr->c, usr, msg);
        free(usr->n);
        if (usr->away)
            free(usr->away);
    }
    close(usr->s);
    printf("Disconnection from %s:%d\n", usr->ip, usr->port);
    free(usr);
}

void fd_set_cl(t_usr *list, fd_set *set, int s)
{
  t_usr *tmp;

  tmp = list;
  FD_ZERO(set);
  while (tmp != NULL)
  {
    FD_SET(tmp->s, set);
    tmp = tmp->next;
  }
  FD_SET(s, set);
}
