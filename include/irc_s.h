/*
** irc_s.h for IRC_S in /home/le-gla_b/rendu/PSU_2014_myirc/include/
**
** Made by Brendan LE GLAUNEC
** Login   <le-gla_b@epitech.eu>
**
** Started on  Mon Mar 30 11:01:49 2015 Brendan LE GLAUNEC
** Last update Sun Apr 12 21:01:46 2015 Brendan LE GLAUNEC
*/

#ifndef _IRC_SERVER_H_
#define _IRC_SERVER_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <time.h>
#include "gnl.h"

#define ERR_NOSUCHNICK  "401 No such nickname"
#define ERR_NOSUCHSERVER  "402 No such server"
#define ERR_NOSUCHCHANNEL "403 No such channel"
#define ERR_CANNOTSENDTOCHAN "404 Cannot send to channel"
#define ERR_TOOMANYCHANNELS "405 You have joined too many channels"
#define ERR_WASNOSUCHNICK "406 There was no such nickname"
#define ERR_TOOMANYTARGETS "407 Duplicate recipients. No message delivered"
#define ERR_NOORIGIN "409 No origin specified"
#define ERR_NORECIPIENT "411 No recipient given"
#define ERR_NOTEXTTOSEND "412 No text to send"
#define ERR_NOTOPLEVEL "413 No toplevel domain specified"
#define ERR_WILDTOPLEVEL "414 Wildcard in toplevel domain"
#define ERR_UNKNOWNCOMMAND "421 Unknown command"
#define ERR_NOMOTD "422 MOTD File is missing"
#define ERR_NOADMININFO "423 No administrative info available"
#define ERR_FILEERROR "424 File error"
#define ERR_NONICKNAMEGIVEN "431 No nickname given"
#define ERR_ERRONEUSNICKNAME "432 Erroneus nickname"
#define ERR_NICKNAMEINUSE "433 Nickname is already in use"
#define ERR_NICKCOLLISION "436 Nickname collision KILL"
#define ERR_USERNOTINCHANNEL "441 They aren't on that channel"
#define ERR_NOTONCHANNEL "442 You're not on that channel"
#define ERR_USERONCHANNEL "443 User already on channel"
#define ERR_NOLOGIN "444 User not logged in"
#define ERR_SUMMONDISABLED "445 SUMMON has been disabled"
#define ERR_USERDISABLED "446 USERS has been disabled"
#define ERR_NOTREGISTERED "451 You have not registered"
#define ERR_NEEDMOREPARAMS "461 Not enough parameters"
#define ERR_ALREADYREGISTERED "462 You may not reregister"
#define ERR_NOPERFORHOST "463 Your host isn't among the privileged"
#define ERR_PASSWDMISMATCH "464 Password incorrect"
#define ERR_YOUREBANNEDCREEP "465 You are banned from this server"
#define ERR_KEYSET "467 Channel key already set"
#define ERR_CHANNELISFULL "471 Cannot join channel (+l)"
#define ERR_UNKNOWNMODE "472 Unknown mode char to me"
#define ERR_INVITEONLYCHAN "473 Cannot join channel (+i)"
#define ERR_BANNEDFROMCHAN "474 Cannot join channel (+b)"
#define ERR_BADCHANNELKEY "475 Cannot join channel (+k)"
#define ERR_NOPRIVILEGES "481 Permission denied"
#define ERR_CHANOPRIVSNEEDED "482 You're not a channel operator"
#define ERR_CANTKILLSERVER "483 You can't kill a server!"
#define ERR_NOOPERHOST "491 No 0-lines for your host"
#define ERR_UMODEUNKNOWNFLAG "501 Unknown MODE flag"
#define ERR_USERSDONTMATCH "502 "
#define ERR_NOTONACHANNEL "069 You must be on a channel to perform this action"
#define ERR_ERRONEUSCHANNEL "070 Erroneus channel name"

#define RPL_NONE "300 Ping!"
#define RPL_USERHOST "302 List users [*]:operators [+|-]:away/notaway"
#define RPL_ISON "303 List replies to the query list"
#define RPL_AWAY "301 Away message"
#define RPL_UNAWAY "305 You are no longer marked as away"
#define RPL_NOWAWAY "306 You have been marked as away"
#define RPL_WHOISUSER "311 Lists users real names"
#define RPL_WHOISSERVER "312 Displays server info"
#define RPL_WHOISOPERATOR "313 Displays IRC operators"
#define RPL_WHOISIDLE "317 Displays idle users"
#define RPL_ENDOFWHOIS "318 End of /WHOIS list"
#define RPL_WHOISCHANNELS "319 Displays channels [@]:operator [+]:permission"
#define RPL_WHOWASUSER "314 List all users through time"
#define RPL_ENDOFWHOWAS "369 End of /WHOWAS"
#define RPL_LISTSTART "321 Channel : Topic "
#define RPL_LIST "322 <channel> <#visible>:<topic>"
#define RPL_LISTEND "323 End of /LIST"
#define RPL_CHANNELMODEIS "324 <channel> <mode> <mode params>"
#define RPL_NOTOPIC "331 <channel> No topic is set"
#define RPL_TOPIC "332 <channel>:<topic>"
#define RPL_INVITING "341 <channel><nick> - Invite successful"
#define RPL_SUMMONING "342 Summoning user to IRC"
#define RPL_VERSION "351 <version>.<debuglevel> <server>:<comments>"
#define RPL_WHOREPLY "352 <channel> <user> <host> <server> <nick>"
#define RPL_ENDOFWHO "315 End of /WHO list"
#define RPL_NAMEREPLY "353 List users (+ means away)"
#define RPL_ENDOFNAMES "366 End of /NAMES list"
#define RPL_LINKS "364 <mask><server>:<hopcount><server info>"
#define RPL_ENDOFLINKS "365 End of /LINKS list"
#define RPL_BANLIST "367 Lists banned users <channel> <banid>"
#define RPL_ENDOFBANLIST "368 End of channel ban list"
#define RPL_INFO "371 <string>"
#define RPL_ENDOFINFO "374 End of /INFO list"
#define RPL_MOTDSTART "375 Message of the day"
#define RPL_MOTD "372 <text>"
#define RPL_ENDOFMOTD "376 End of /MOTD command"
#define RPL_YOUREOPER "381 You are now an IRC operator"
#define RPL_REHASHING "382 <config file> Rehashing"
#define RPL_TIME "391 <server> <server hour>"
#define RPL_USERSSTART "392 UserID Terminal Host"
#define RPL_USERS "393 %-8s %-9s %-8s"
#define RPL_ENDOFUSERS "394 End of users"
#define RPL_NOUSERS "395 Nobody logged in"
#define RPL_TRACELINK "200 Link <version/debuglevel> <destination>"
#define RPL_TRACECONNECTING "201 Try <class> <server>"
#define RPL_TRACEHANDSHAKE "202 H.S. <class> <server>"
#define RPL_TRACEUNKNOWN "203 ??? <class> [<client IP>]"
#define RPL_TRACEOPERATOR "204 Oper <class> <nick>"
#define RPL_TRACEUSER "205 User <class> <nick>"
#define RPL_TRACESERVER "206 Serv <class> <int>S <int>C <server>"
#define RPL_TRACENEWTYPE "208 <newtype> 0 <client name>"
#define RPL_TRACELOG "261 File <logfile> <debuglevel>"
#define RPL_STATSLINKINFO "211 <linkname> <sq> <smsg> <sb> <rmsg> <sb> <t>"
#define RPL_STATSCOMMANDS "212 <command> <count>"
#define RPL_STATSCLINE "213 C <host> * <name> <port> <class>"
#define RPL_STATSNLINE "214 N <host> * <name> <port> <class>"
#define RPL_STATSILINE "215 I <host> * <name> <port> <class>"
#define RPL_STATSKLINE "216 K <host> * <name> <port> <class>"
#define RPL_STATSYLINE "218 Y <class> <ping f> <c f> <max sendq>"
#define RPL_ENDOFSTATS "219 <stats letter> End pf /STATS report"
#define RPL_STATSLLINE "241 L <hostmask> * <servername> <maxdepth>"
#define RPL_STATSUPTIME "242 Server up time"
#define RPL_STATSOLINE "243 0 <hostmask> * <name>"
#define RPL_STATSHLINE "244 H <hostmask> * <servername>"
#define RPL_UMODEIS "221 <usermode string>"
#define RPL_LUSERCLIENT "251 Lists users on servers"
#define RPL_LUSEROP "252 Online operators"
#define RPL_LUSERUNKNOWN "253 Unknown connection(s)"
#define RPL_LUSERCHANNELS "254 Channels formed"
#define RPL_LUSERME "255 Number of clients and servers"
#define RPL_ADMINME "256 <server> Administrative info"
#define RPL_ADMINLOC1 "257 <admin info>"
#define RPL_ADMINLOC2 "258 <admin info>"
#define RPL_ADMINEMAIL "259 <admin info>"
#define RPL_HELPTOPICS "704 Help topics:"
#define RPL_HELPSTART "703 Help :"
#define RPL_HELPFIRST "705-JOIN\tPART\tNICK\tHELP"
#define RPL_HELPSECND "705-LIST\tNAMES\tPRIVMSG\tAWAY"
#define RPL_HELPTHIRD "705-TOPIC\tPING\tMOTD\tQUIT"
#define RPL_HELPFOUR  "705-OPER\tSQUIT"
#define RPL_HELP "705-"
#define RPL_ENDOFHELP "706 End of /HELP"
#define RPL_PONG "099 PONG!"

#define	WELCOME_MSG		"Welcome to an awesome IRC server."
#define	GOODBYE_MSG		"Good bye, come again :)"
#define P_MSG         "quit the channel without saying why."
#define NOTOPIC       "No topic defined"

#define	PORT_DFAULT		4242
#define	HOST_DFAULT		"127.0.0.1"

#define CMD_NICK        "NICK"
#define CMD_LIST        "LIST"
#define CMD_JOIN        "JOIN"
#define CMD_PART        "PART"
#define CMD_NAMES       "NAMES"
#define CMD_PRIVMSG     "PRIVMSG"
#define CMD_AWAY        "AWAY"
#define CMD_QUIT        "QUIT"
#define CMD_HELP        "HELP"
#define CMD_MOTD        "MOTD"
#define CMD_PING        "PING"
#define CMD_TOPIC       "TOPIC"
#define CMD_USER        "USER"
#define CMD_PASS        "PASS"
#define CMD_SEND_FILE   "SEND_FILE"
#define CMD_ACCEPT_FILE "ACCEPT_FILE"
#define CMD_OPER        "OPER"
#define CMD_SQUIT       "SQUIT"

#define HELP_NICK       "/nick <nickname>\n705-\\t-- Changes your nickname."
#define HELP_LIST       "/list <channel>\n705-\t-- Lists channels on server."
#define HELP_JOIN       "/join <channel>\n705-\t-- Joins a channel."
#define HELP_PART       "/part <channel>\n705-\t-- Quits a channel."
#define HELP_NAMES      "/users\n705-\t-- Displays user names on your channel."
#define HELP_PRIVMSG    "/msg reciever text\n705-\t-- Sends a private message."
#define HELP_AWAY       "/away [<reason>]\n705-\t-- Tells people you're away."
#define HELP_QUIT       "/quit [<message>]\n705-\t-- Quits the server."
#define HELP_MOTD       "/motd\n705-\t-- Displays the message of the day."
#define HELP_PING       "/ping\n705-\t-- Pings the server.\
You should receive a pong."
#define HELP_HELP       "/help [command]\n705-\t-- Displays this help."
#define HELP_TOPIC      "/topic <chan topic>\n705-\
\t-- Change a channel's topic."
#define HELP_USER       "No help for this."
#define HELP_PASS       "No help for this."
#define HELP_OPER       "/oper <login> <passwd>\n705-\
\t-- Login as IRC operator."
#define HELP_SQUIT      "/squit [<message>]\n705-\
\t-- As oper, shutdown server."

enum    e_cmd
{
    NICK = 0,
    LIST,
    JOIN,
    PART,
    NAMES,
    PRIVMSG,
    AWAY,
    QUIT,
    MOTD,
    PING,
    HELP,
    TOPIC,
    USER,
    PASS,
    OPER,
    SQUIT,
/*  SEND_FILE,
    ACCEPT_FILE, */
    NB_CMD
};

#define	ERROR_SOCKET		"Error : socket creation failure.\n"
#define	ERROR_BIND		"Error : socket binding failure.\n"
#define	ERROR_LISTEN		"Error : socket listen failure.\n"
#define	ERROR_ACCEPT		"Error : socket accept failure.\n"
#define	ERROR_CONNECT		"Error : socket connexion failure.\n"
#define	ERROR_SELECT		"Error : select failed.\n"

#define SOCKET_ERROR		-1
#define BIND_ERROR		  -1
#define LISTEN_ERROR		-1
#define ACCEPT_ERROR		-1
#define	CONNECT_ERROR		-1
#define SELECT_ERROR    -1

#define PTR_FAILURE      ((void*)0)
#define PTR_SUCCESS      ((void*)42)

#define USAGE            "./server host port\n"

#define LEGAL_CHARS     "abcdefghijklmnopqrstuvwxyzABCDEFGHIJ\
KLMNOPQRSTFUVWXYZ0123456879-[]`\\^{}"

typedef struct s_usr {
  struct s_chn*         c;
  int                   s;
  char*                 n;
  char*                 away;
  int                   is_oper;
  char*                 ip;
  int                   port;
  struct s_usr*         next;
  struct s_usr*         prev;
} t_usr;

typedef struct s_usr_list
{
    t_usr               *usr;
    struct s_usr_list   *next;
    struct s_usr_list   *prev;
} t_usr_list;

typedef struct s_chn {
  t_usr_list*           u;
  char*                 n;
  char*                 topic;
  struct s_chn*         next;
  struct s_chn*         prev;
} t_chn;

typedef struct s_srv {
  t_chn*                c;
  t_usr*                u;
  int                   s;
  int                   s_data;
  int                   port;
  struct sockaddr_in    sin;
} t_srv;

/* ERRMSG.C */
int	    intmsg(char*, int);
void*	  ptrmsg(char*, void*);
int     handle_error(char *error);
int     close_socket(int sockfd, char *error);

/* STWT.C */
char    **str_to_tab(char *s);
void    free_tab(char **tab);
char    **str_split(char *s, char *split);

/* LL_CLIENTS.C */
void*   add_client(t_usr **list, int cs);
void    remove_client(t_srv *server, t_usr *usr, char *msg);
void    fd_set_cl(t_usr *list, fd_set *set, int s);

/* LL_CHANNELS.C */
void*   add_chan(t_chn **list, char *name);
void    remove_chan(t_srv *server, t_chn *channel);
void*   add_user_on_chan(t_chn *channel, t_usr *user);
int     remove_user_from_chan(t_chn *channel, t_usr *user, char *msg);

/* HANDLE_CONNEXIONS.C */
int     handle_fd(int r, int w);
void	handle_client(t_srv *s);

/* HANDLE_REQUEST.C */
int     server_handle_request(t_srv *server, t_usr *usr);

/* USERS.C */
int list_users_from_chan(t_usr* u, t_chn *c);
int name_command(t_usr* u, t_chn *c);

/* NICKNAME.C */
int irc_server_cmd_nick(t_srv *s, t_usr* u, char **cmd);

/* PRIVMSG.C */
char    *concat_message(char **cmd);
int     irc_server_cmd_privmsg(t_srv *s, t_usr* u, char **cmd);

/* SERVER_CMD_USERS.C */
int irc_server_cmd_names(t_srv *s, t_usr* u, char **cmd);

/* SERVER_CMD_AWAY.C */
int irc_server_cmd_away(t_srv *s, t_usr* u, char **cmd);

/* SERVER_CMD_MOTD.C */
int irc_server_cmd_motd(t_srv *s, t_usr* u, char **cmd);

/* SERVER_CMD_HELP.C */
int irc_server_cmd_help(t_srv *s, t_usr* u, char **cmd);

/* SERVER_CMD_PING.C */
int irc_server_cmd_ping(t_srv *s, t_usr* u, char **cmd);

/* SERVER_CMD_TOPIC.C */
int irc_server_cmd_topic(t_srv *s, t_usr* u, char **cmd);

/* SERVER_CMD_USER.C */
int irc_server_cmd_user(t_srv *s, t_usr* u, char **cmd);
int irc_server_cmd_pass(t_srv *s, t_usr* u, char **cmd);

/* WELCOME.C */
void send_welcome();

/* SERVER_CMD_LIST.C */
int irc_server_cmd_list(t_srv *s, t_usr* u, char** cmd);

/* CLEAR_SERVER.C */
void    clear_all_server(t_srv *server);

/* JOIN.C*/
int  irc_server_cmd_join(t_srv *s, t_usr* u, char** cmd);
int  is_in_chan(t_chn *c, t_usr* u);

/* PART.C */
int  irc_server_cmd_part(t_srv *s, t_usr* u, char** cmd);

/* QUIT.C */
int     irc_server_cmd_quit(t_srv *server, t_usr *user, char **cmd);
int     irc_server_cmd_oper(t_srv *server, t_usr *user, char **cmd);
int     irc_server_cmd_squit(t_srv *server, t_usr *user, char **cmd);

/* SERVER_SEND.C */
int   server_send(int sock_fd, char *msg);
int     server_send_msg_to_chanel(t_chn *channel, char *msg);

/* STR_CONCAT.C */
char    *str_concat(char *s1, char *s2);
char	*str_concat_var(int n, ...);

/* GET_IN_LIST.C */
t_chn* get_channel(t_chn *list, char *n);
t_usr* get_user(t_usr *list, char *n);

#endif
