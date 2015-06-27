/*
** server_cmd_privmsg.c for myIRC in /home/souls/Projects/rendu/PSU_2014_myirc/src/server/
**
** Made by pele_a
** Login   <pele_a@epitech.eu>
**
** Started on  Sat Apr 11 22:39:29 2015 pele_a
** Last update Sun Apr 12 17:18:59 2015 Brendan LE GLAUNEC
*/

#include "irc_s.h"

static int  send_global_message(t_usr *user, char *msg)
{
    if (user->c)
    {
        msg = str_concat_var(5, user->n, ": ", user->c->n, ": ", msg);
        server_send_msg_to_chanel(user->c, msg);
        free(msg);
    }
    else
        return (server_send(user->s, ERR_NOTONCHANNEL));
    return (0);
}

static int  send_channel_message(t_usr *user, char *dest, char *msg)
{
    if (user->c && strcmp(user->c->n, dest) == 0)
    {
        msg = str_concat_var(5, user->n, ": ", user->c->n, ": ", msg);
        server_send_msg_to_chanel(user->c, msg);
        free(msg);
    }
    else
        return (server_send(user->s, ERR_NOTONCHANNEL));
    return (0);
}

static int  send_user_message(t_srv *server, t_usr *user,
                                char *dest, char *msg)
{
    t_usr   *r;
    char    *away;

    if ((r = get_user(server->u, dest)) == NULL)
        return (server_send(user->s, ERR_NOSUCHNICK));
    if (r->away)
    {
        away = str_concat_var(4, "301 ", user->n, ": ", r->away);
        server_send(user->s, away);
        free(away);
    }
    msg = str_concat_var(5, user->n, ": ", r->n, ": ", msg);
    server_send(r->s, msg);
    free(msg);
    return (0);
}

char    *concat_message(char **cmd)
{
    char    *msg;
    char    *tmp;
    int     i;

    msg = strdup((cmd[0][0] == ':' ? &(cmd[0][1]) : cmd[0]));
    i = 0;
    while (cmd[++i])
    {
        if ((msg = str_concat_var(3, (tmp = msg), " ", cmd[i])) == NULL)
            return (NULL);
        free(tmp);
    }
    return (msg);
}

int     irc_server_cmd_privmsg(t_srv *server, t_usr *user, char **cmd)
{
    char    **dest;
    char    *msg;
    int     i;

    if (user->n == NULL)
        return (server_send(user->s, ERR_NOLOGIN));
    if (cmd[1] == NULL)
        return (server_send(user->s, ERR_NORECIPIENT));
    if (cmd[2] == NULL)
        return (server_send(user->s, ERR_NOTEXTTOSEND));
    if (!(dest = str_split(cmd[1], ",")) || !(msg = concat_message(&(cmd[2]))))
        return (handle_error("malloc failed"));
    i = -1;
    while (dest[++i])
    {
        if (strcmp(dest[i], "$*") == 0)
            send_global_message(user, msg);
        else if (dest[i][0] == '&' || dest[i][0] == '#')
            send_channel_message(user, dest[i], msg);
        else
            send_user_message(server, user, dest[i], msg);
    }
    free(msg);
    free_tab(dest);
    return (EXIT_SUCCESS);
}
