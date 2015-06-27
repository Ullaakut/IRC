/*
** welcome.c for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/src/server/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Thu Apr  9 11:48:48 2015 Brendan LE GLAUNEC
** Last update Sat Apr 11 15:18:02 2015 Brendan LE GLAUNEC
*/

#include "irc_s.h"

//remplacer les printf
void  send_welcome(t_usr* u)
{
  server_send(u, WELCOME_MSG);
}
