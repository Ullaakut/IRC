##
## Makefile for MyIRC in /home/le-gla_b/rendu/PSU_2014_myirc/
##
## Made by Brendan LE GLAUNEC
## Login   <le-gla_b@epitech.eu>
##
## Started on  Mon Mar 30 10:58:48 2015 Brendan LE GLAUNEC
## Last update Sun Apr 12 18:14:13 2015 pele_a
##

CC			=	gcc

RM			=	rm -rf

SERVER		=	server

CLIENT		=	client

SRCS_DIR	=	src
SERVER_DIR	=	$(SRCS_DIR)/server
CLIENT_DIR	=	$(SRCS_DIR)/client

SRCS		=	$(SRCS_DIR)/str_to_tab.c \
					$(SRCS_DIR)/str_concat.c \
					$(SRCS_DIR)/handle_error.c \
					$(SRCS_DIR)/gnl.c \
					$(SRCS_DIR)/errmsg.c

SERVER_SRCS	=	$(SERVER_DIR)/server_init.c \
							$(SERVER_DIR)/server_send.c \
							$(SERVER_DIR)/server_handle_connexions.c \
							$(SERVER_DIR)/server_handle_request.c \
							$(SERVER_DIR)/linked_lists_clients.c \
							$(SERVER_DIR)/linked_lists_channels.c \
							$(SERVER_DIR)/server_handle_channels.c \
							$(SERVER_DIR)/clear_server.c \
							$(SERVER_DIR)/server_cmd_privmsg.c \
							$(SERVER_DIR)/server_cmd_nick.c \
							$(SERVER_DIR)/server_cmd_join.c \
							$(SERVER_DIR)/server_cmd_part.c \
							$(SERVER_DIR)/server_cmd_list.c \
							$(SERVER_DIR)/server_cmd_away.c \
							$(SERVER_DIR)/server_cmd_users.c \
							$(SERVER_DIR)/server_cmd_motd.c \
							$(SERVER_DIR)/server_cmd_help.c \
							$(SERVER_DIR)/server_cmd_ping.c \
							$(SERVER_DIR)/server_cmd_user.c \
							$(SERVER_DIR)/server_cmd_topic.c \
							$(SERVER_DIR)/server_cmd_quit.c \
							$(SERVER_DIR)/server_get_lists.c

CLIENT_SRCS	=	$(CLIENT_DIR)/client.c \
							$(CLIENT_DIR)/client_init.c \
							$(CLIENT_DIR)/client_handle_cmd.c \
							$(CLIENT_DIR)/client_handle_replies.c \
							$(CLIENT_DIR)/cmd/client_simple_cmd.c \
							$(CLIENT_DIR)/cmd/client_bonus_cmd.c \
							$(CLIENT_DIR)/cmd/client_message_cmd.c \
							$(CLIENT_DIR)/cmd/client_cmd_others.c \
							$(CLIENT_DIR)/cmd/client_cmd_connect_server.c

SERVER_OBJS	=	$(SERVER_SRCS:.c=.o)

CLIENT_OBJS	=	$(CLIENT_SRCS:.c=.o)

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=		-W -Wall -Wextra -Werror
CFLAGS		+=		-I ./include


all:	$(SERVER) $(CLIENT)

$(SERVER):	$(OBJS) $(SERVER_OBJS)
	$(CC) -o $(SERVER) $(SERVER_OBJS) $(OBJS) $(CFLAGS)
	@echo "\033[0;32m" "> Server compiled" "\\033[0;39m"

$(CLIENT):	$(OBJS)	$(CLIENT_OBJS)
	$(CC) -o $(CLIENT) $(CLIENT_OBJS) $(OBJS) $(CFLAGS)
	@echo "\033[0;32m" "> Client compiled" "\\033[0;39m"

clean:
	$(RM) $(SERVER_OBJS)
	$(RM) $(CLIENT_OBJS)
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

re:		fclean all
