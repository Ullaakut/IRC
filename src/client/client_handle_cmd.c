/*
** client_handle_cmd.c for myIRC in /home/souls/Projects/rendu/PSU_2014_myirc/src/client/
**
** Made by pele_a
** Login   <pele_a@epitech.eu>
**
** Started on  Tue Apr  7 19:01:39 2015 pele_a
** Last update Sun Apr 12 17:57:51 2015 pele_a
*/

#include <stdlib.h>
#include <stdio.h>
#include "irc_client.h"
#include "gnl.h"

static struct {
    char    *cmd_name;
    char    *cmd_code;
    int     (*cmd_func_ptr)(t_client *, char **);
} cmd_tab[NB_CMD + 1] = {
    { "/server",        NULL,               &irc_client_cmd_connect_server },
    { "/nick",          CMD_NICK,           &irc_client_cmd_nick },
    { "/list",          CMD_LIST,           &irc_client_cmd_list },
    { "/join",          CMD_JOIN,           &irc_client_cmd_join },
    { "/part",          CMD_PART,           &irc_client_cmd_part },
    { "/users",         CMD_USERS,          &irc_client_cmd_users },
    { "/msg",           CMD_PRIVMSG,        &irc_client_cmd_msg },
    { "/away",          CMD_AWAY,           &irc_client_cmd_away },
    { "/send_file",     CMD_SEND_FILE,      &irc_client_cmd_send_file },
    { "/accept_file",   CMD_ACCEPT_FILE,    &irc_client_cmd_accept_file },
    { "/ping",          CMD_PING,           &irc_client_cmd_ping },
    { "/help",          CMD_HELP,           &irc_client_cmd_help },
    { "/motd",          CMD_MOTD,           &irc_client_cmd_motd },
    { "/topic",         CMD_TOPIC,          &irc_client_cmd_topic },
    { "/quit",          CMD_QUIT,           &irc_client_cmd_quit },
    { "/oper",          CMD_OPER,           &irc_client_cmd_oper },
    { "/squit",         CMD_SQUIT,          &irc_client_cmd_squit },
/*  { "",   CMD_,   &irc_client_cmd_ }, */
    { NULL, NULL, NULL }
};

static int  irc_client_handle_command_check(t_client *client,
                                            char **cmd, char *line)
{
    int         ret;
    enum e_cmd  i;

    ret = 1;
    if (cmd[0][0] == '/')
    {
        i = 0;
        while (cmd_tab[i].cmd_name != NULL)
        {
            if (strcmp(cmd[0], cmd_tab[i].cmd_name) == 0)
                return ((cmd_tab[i].cmd_func_ptr)(client, cmd));
            i += 1;
        }
        if (cmd_tab[i].cmd_name == NULL)
            printf("%s: command not found.\n", cmd[0]);
    }
    else
        ret = irc_client_cmd_msg_global(client, line);
    return (ret);
}

int     irc_client_handle_command(t_client *client)
{
    int         ret;
    char        *line;
    char        **cmd;

    if ((line = get_next_line(0)) == NULL)
    {
        if (CLIENT_CHECK_IS_CONNECTED(client))
            irc_client_cmd_quit(client, NULL);
        return (0);
    }
    if ((cmd = str_split(line, " \t\n")) == NULL)
        return (handle_error("malloc failed"));
    ret = 1;
    if (cmd[0] != NULL)
        ret = irc_client_handle_command_check(client, cmd, line);
    free(line);
    free_tab(cmd);
    return (ret);
}
