/*
** server_handle_request.c for myIRC in /home/souls/Projects/rendu/PSU_2014_myirc/src/server/
**
** Made by pele_a
** Login   <pele_a@epitech.eu>
**
** Started on  Sat Apr 11 18:32:59 2015 pele_a
** Last update Sun Apr 12 17:06:12 2015 pele_a
*/

#include "irc_s.h"

static struct {
    char    *cmd_code;
    int     (*cmd_func_ptr)(t_srv *, t_usr *, char **);
} cmd_tab[NB_CMD + 1] = {
    { CMD_NICK,           &irc_server_cmd_nick },
    { CMD_LIST,           &irc_server_cmd_list },
    { CMD_JOIN,           &irc_server_cmd_join },
    { CMD_PART,           &irc_server_cmd_part },
    { CMD_NAMES,          &irc_server_cmd_names },
    { CMD_PRIVMSG,        &irc_server_cmd_privmsg },
    { CMD_AWAY,           &irc_server_cmd_away },
    { CMD_QUIT,           &irc_server_cmd_quit },
    { CMD_MOTD,           &irc_server_cmd_motd },
    { CMD_PING,           &irc_server_cmd_ping },
    { CMD_HELP,           &irc_server_cmd_help },
    { CMD_TOPIC,          &irc_server_cmd_topic },
    { CMD_USER,           &irc_server_cmd_user },
    { CMD_PASS,           &irc_server_cmd_pass },
    { CMD_OPER,           &irc_server_cmd_oper },
    { CMD_SQUIT,          &irc_server_cmd_squit },
/*  { CMD_SEND_FILE,      &irc_server_cmd_send_file },
    { CMD_ACCEPT_FILE,    &irc_server_cmd_accept_file }, */
/*  { CMD_,               &irc_server_cmd_ }, */
    { NULL, NULL }
};

int     server_handle_request_loop(t_srv *server, t_usr *usr, char **cmd)
{
    enum e_cmd  i;

    i = 0;
    while (cmd_tab[i].cmd_code != NULL)
    {
        if (strcmp(cmd[0], cmd_tab[i].cmd_code) == 0)
            return ((cmd_tab[i].cmd_func_ptr)(server, usr, cmd));
        i += 1;
    }
    if (cmd_tab[i].cmd_code == NULL)
      server_send(usr->s, ERR_UNKNOWNCOMMAND);
    return (0);
}

int     server_handle_request(t_srv *server, t_usr *usr)
{
    char        *request;
    char        **cmd;
    int         ret;

    if ((request = get_next_line(usr->s)) == NULL)
    {
        remove_client(server, usr, "disconnected");
        return (0);
    }
    printf("From %s:%d : %s\n", usr->ip, usr->port, request);
    if ((cmd = str_to_tab(request)) == NULL)
        return (handle_error("malloc failed"));
    ret = server_handle_request_loop(server, usr, cmd);
    free_tab(cmd);
    free(request);
    return (ret);
}
