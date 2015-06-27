/*
** handle.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Mon Apr  6 14:50:37 2015 Brendan LE GLAUNEC
** Last update Sun Apr 12 18:05:41 2015 pele_a
*/

#include "irc_s.h"

int  handle_fd(int r, int w)
{
  int   len;
  char  buff[8];
  int   len2;

  if ((len = read(r, buff, 8)) == 0)
    return (intmsg("Client disconnected.", EXIT_FAILURE));
  len2 = 0;
  while (len2 != len)
  {
    len -= len2;
    len2 = write(w, buff + len2, len);
    if (len2 == -1)
      return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

static int big_cs_cl(t_usr* u, int s)
{
  t_usr* tmp;
  int ret;

  if (!(tmp = u))
    return (s + 1);
  ret = (u->s > s ? u->s : s);
  while (tmp->next != NULL)
    {
      tmp = tmp->next;
      if (tmp->s > ret)
        ret = tmp->s;
    }
  return (ret + 1);
}

static int  handle_new_client_connect(t_srv *server)
{
    socklen_t           psize;
    struct sockaddr_in  csin;
    int                 cs;
    t_usr*              client;

    psize = sizeof(csin);
    if ((cs = accept(server->s, (struct sockaddr *)&csin,
        &(psize))) == ACCEPT_ERROR)
        return (intmsg(ERROR_ACCEPT, 42));
    if ((client = (t_usr *)add_client(&(server->u), cs)) == NULL)
        return (intmsg("Error: malloc failed.\n", 42));
    client->ip = inet_ntoa(csin.sin_addr);
    client->port = ntohs(csin.sin_port);
    printf("Connection from %s:%d\n", client->ip, client->port);
    server_send(client->s, WELCOME_MSG);
    irc_server_cmd_motd(server, client, NULL);
    return (0);
}

static int  fd_isset_cl(t_srv *server, fd_set *set)
{
    t_usr*              tmp;
    t_usr*              next_tmp;

    tmp = server->u;
    while (tmp != NULL)
    {
        next_tmp = tmp->next;
        if (FD_ISSET(tmp->s, set) && server_handle_request(server, tmp) == 42)
            return (42);
        tmp = next_tmp;
    }
    if (FD_ISSET(server->s, set))
        return (handle_new_client_connect(server));
    return (0);
}

void	handle_client(t_srv *server)
{
    fd_set  readfds;
    int     ret;
    int     bigest_fd;

    ret = 0;
    while (ret != 42)
    {
        fd_set_cl(server->u, &readfds, server->s);
        bigest_fd = big_cs_cl(server->u, server->s);
        if (select(bigest_fd, &readfds, NULL, NULL, NULL) == -1)
        {
            perror("select");
            break;
        }
        else
            ret = fd_isset_cl(server, &readfds);
    }
    clear_all_server(server);
}
