/*
** irc_c.h for CLIENT in /home/le-gla_b/rendu/PSU_2014_myirc/include/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Mon Mar 30 11:01:03 2015 Brendan LE GLAUNEC
** Last update Sun Apr 12 18:26:46 2015 pele_a
*/

#ifndef _IRC_CLIENT_H_
#define _IRC_CLIENT_H_

#include <sys/types.h>
#include <netinet/in.h>
#include <sys/select.h>

#define	PORT_DEFAULT     4242

#define CMD_NICK        "NICK"
#define CMD_LIST        "LIST"
#define CMD_JOIN        "JOIN"
#define CMD_PART        "PART"
#define CMD_USERS       "NAMES"

#define CMD_PRIVMSG     "PRIVMSG"
#define CMD_AWAY        "AWAY"

#define CMD_SEND_FILE   "SEND_FILE"
#define CMD_ACCEPT_FILE "ACCEPT_FILE"

#define CMD_HELP        "HELP"
#define CMD_PING        "PING"
#define CMD_MOTD        "MOTD"

#define CMD_USER        "USER"
#define CMD_PASS        "PASS"

#define CMD_TOPIC       "TOPIC"

#define CMD_QUIT        "QUIT"

#define CMD_OPER        "OPER"
#define CMD_SQUIT       "SQUIT"

#define ARG_USER        "USER a a a a"
#define ARG_PASS        "PASS a"

enum    e_cmd
{
    SERVER = 0,
    NICK,
    LIST,
    JOIN,
    PART,
    USERS,
    MSG,
    AWAY,
    SEND_FILE,
    ACCEPT_FILE,
    HELP,
    PING,
    MOTD,
    TOPIC,
    QUIT,
    OPER,
    SQUIT,
    NB_CMD
};

typedef struct s_client
{
    char                *ip;
    int                 port;
    char                *user_name;
    struct protoent     *pe;
    struct sockaddr_in  s_in;
    int                 sock_fd;
    fd_set              readfds;
} t_client;

#define CLIENT_CHECK_IS_CONNECTED(client)     (client->sock_fd != -1 ? 1 : 0)

/* client.c - utils */
int     irc_client_check_connection(t_client *client);
int     irc_client_send(t_client *client, char *msg);
int     irc_client_send_msg(t_client *client, char *msg_type, char **arg);

/* client_init.c */
int     irc_init_client(t_client *client);
void    irc_clear_client(t_client *client);

/* client_handle_cmd.c */
int     irc_client_handle_command(t_client *client);

/* client_handle_replies.c */
int     irc_client_handle_replies(t_client *client);

/* cmd */
int     irc_client_cmd_connect_server(t_client *client, char **cmd);
int     irc_client_cmd_nick(t_client *client, char **cmd);
int     irc_client_cmd_list(t_client *client, char **cmd);
int     irc_client_cmd_join(t_client *client, char **cmd);
int     irc_client_cmd_part(t_client *client, char **cmd);
int     irc_client_cmd_users(t_client *client, char **cmd);
int     irc_client_cmd_msg(t_client *client, char **cmd);
int     irc_client_cmd_away(t_client *client, char **cmd);
int     irc_client_cmd_send_file(t_client *client, char **cmd);
int     irc_client_cmd_accept_file(t_client *client, char **cmd);
int     irc_client_cmd_msg_global(t_client *client, char *msg);
int     irc_client_cmd_ping(t_client *client, char **cmd);
int     irc_client_cmd_motd(t_client *client, char **cmd);
int     irc_client_cmd_help(t_client *client, char **cmd);
int     irc_client_cmd_topic(t_client *client, char **cmd);
int     irc_client_cmd_quit(t_client *client, char **cmd);
int     irc_client_cmd_oper(t_client *client, char **cmd);
int     irc_client_cmd_squit(t_client *client, char **cmd);

/* handle_error.c */
int     handle_error(char *error);
int     close_socket(int sockfd, char *error);

/* str_to_tab.c */
char    **str_split(char *s, char *split);
char    **str_to_tab(char *s);
void    free_tab(char **tab);

/* str_concat.c */
char    *str_concat(char *s1, char *s2);
char	*str_concat_var(int n, ...);

#endif
