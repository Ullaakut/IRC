/*
** server.c for My_IRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Tue Mar 31 09:42:57 2015 Brendan LE GLAUNEC
** Last update Sun Apr 12 00:02:20 2015 pele_a
*/

#include "irc_s.h"

t_srv   init_server(int ac, char * const av[])
{
  struct protoent   *pe;
  t_srv             ret;

  pe = getprotobyname("TCP");
  ret.port = PORT_DFAULT;
  ret.sin.sin_port = htons(PORT_DFAULT);
  if ((ret.s = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == SOCKET_ERROR)
    fprintf(stderr, "%s", ERROR_SOCKET);
  else if (ac == 2)
  {
    ret.port = atoi(av[1]);
    ret.sin.sin_port = htons(ret.port);
  }
  ret.sin.sin_family = AF_INET;
  ret.sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(ret.s, (struct sockaddr *) &(ret.sin),
    sizeof(struct sockaddr_in)) == -1)
    {
      printf("Error: bind failed.\n");
      close(ret.s_data);
      exit(1);
    }
  if ((listen(ret.s, 42)) == -1)
    fprintf(stderr, "%s", ERROR_LISTEN);
  return (ret);
}

int get_clients(t_srv *s)
{
  handle_client(s);
  close(s->s);
  return (EXIT_SUCCESS);
}

int main(int ac, char * const av[])
{
  t_srv     s;

  s = init_server(ac, av);
  s.u = NULL;
  s.c = NULL;
  return (get_clients(&s));
}
