/*
** client_cmd_connect_server.c for myIRC in /home/souls/Projects/rendu/PSU_2014_myirc/src/client/cmd/
**
** Made by pele_a
** Login   <pele_a@epitech.eu>
**
** Started on  Tue Apr  7 19:08:34 2015 pele_a
** Last update Sun Apr 12 18:06:40 2015 Brendan LE GLAUNEC
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "irc_client.h"

char* get_ip_from_hostname(char *host)
{
    struct hostent *he;
    struct in_addr **addr_list;
    char *ip;

    if ((he = gethostbyname(host)) == NULL)
      return (NULL);
    addr_list = (struct in_addr **)he->h_addr_list;
    ip = strdup(inet_ntoa(*addr_list[0]));
    return (ip);
}

static int  irc_client_cmd_connect_server_create(t_client *client)
{
    int     ret;

    ret = 1;
    if ((client->sock_fd = socket(AF_INET, SOCK_STREAM,
                                    client->pe->p_proto)) == -1)
        ret = handle_error("Can't create socket");
    else if (connect(client->sock_fd, (struct sockaddr *)&(client->s_in),
                sizeof(client->s_in)) == -1)
        ret = handle_error("connect failed");
    if (ret == -1)
    {
        printf("Not connected to %s:%d\n", client->ip, client->port);
        irc_clear_client(client);
    }
    else
    {
        printf("Successfuly connected to %s:%d\n", client->ip, client->port);
        irc_client_send_msg(client, CMD_PASS, str_to_tab(ARG_PASS));
        irc_client_send_msg(client, CMD_USER, str_to_tab(ARG_USER));
        FD_SET(client->sock_fd, &(client->readfds));
    }
    return (1);
}

int     irc_client_cmd_connect_server(t_client *client, char **cmd)
{
    char    **param;

    if (cmd[1] == NULL)
    {
        printf("%s: syntax error: need at least _host_ parameter.\n", cmd[0]);
        return (1);
    }
    if (CLIENT_CHECK_IS_CONNECTED(client))
        irc_client_cmd_quit(client, NULL);
    if ((param = str_split(cmd[1], ":")) == NULL
        || (client->ip = get_ip_from_hostname(param[0])) == NULL)
        return (handle_error("malloc failed"));
    client->port = (param[1] != NULL ? atoi(param[1]) : PORT_DEFAULT);
    free_tab(param);
    client->s_in.sin_port = htons(client->port);
    client->s_in.sin_addr.s_addr = inet_addr(client->ip);
    return (irc_client_cmd_connect_server_create(client));
}
