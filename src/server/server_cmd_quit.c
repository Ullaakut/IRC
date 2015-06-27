/*
** server_cmd_quit.c for myIRC in /home/souls/Projects/rendu/PSU_2014_myirc/src/server/
**
** Made by pele_a
** Login   <pele_a@epitech.eu>
**
** Started on  Sun Apr 12 16:55:58 2015 pele_a
** Last update Sun Apr 12 18:22:32 2015 pele_a
*/

#include "irc_s.h"

int     irc_server_cmd_quit(t_srv *server, t_usr *user, char **cmd)
{
    char    *msg;

    msg = concat_message(&(cmd[1]));
    remove_client(server, user, msg);
    free(msg);
    return (0);
}

int     irc_server_cmd_oper(t_srv *server, t_usr *user, char **cmd)
{
    (void)server;
    if (cmd[1] == NULL || cmd[2] == NULL)
        return (server_send(user->s, ERR_NEEDMOREPARAMS));
    if (strcmp(cmd[1], "root"))
        return (server_send(user->s, ERR_NOOPERHOST));
    if (strcmp(cmd[2], "root"))
        return (server_send(user->s, ERR_PASSWDMISMATCH));
    user->is_oper = 1;
    return (server_send(user->s, RPL_YOUREOPER));
}

int     irc_server_cmd_squit(t_srv *server, t_usr *user, char **cmd)
{
    t_usr *usr;
    char    *msg;

    if (!(user->is_oper))
        return (server_send(user->s, ERR_NOPRIVILEGES));
    if (cmd[1])
    {
        msg = concat_message(&(cmd[1]));
        usr = server->u;
        while (usr)
        {
            if (usr != user)
                server_send(usr->s, msg);
            usr = usr->next;
        }
        free(msg);
    }
    return (42);
}
