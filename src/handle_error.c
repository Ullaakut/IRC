/*
** handle_error.c for myFTP in /home/souls/Projects/rendu/PSU_2014_myftp/srcs/
**
** Made by pele_a
** Login   <pele_a@epitech.eu>
**
** Started on  Thu Mar 12 15:49:47 2015 pele_a
** Last update Mon Apr  6 19:39:11 2015 pele_a
*/

#include <unistd.h>
#include <stdio.h>

int   handle_error(char *error)
{
    printf("Error: %s.\n", error);
    return (-1);
}

int   close_socket(int sockfd, char *error)
{
    int ret;

    ret = 0;
    if (error != NULL)
        ret = handle_error(error);
    if (close(sockfd) == -1)
        return (handle_error("Couldn't close socket"));
    return (ret);
}
