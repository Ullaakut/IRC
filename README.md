# IRC
A simple IRC server and a client.

In the client, the commands are :

NICK to set-up your nickname
LIST to list channels  (can take a string to search through the channels)
JOIN to join a channel
PART to leave a channel
USERS to list users (can take a string to search through the users)
PRIVMSG to send a private message to someone (takes as argument the person you want to send it to)
AWAY to toogle your away status (can take as argument the reason why you're away)
SEND_FILE to send a file
ACCEPT_FILE to accept a file someone sent you
HELP to list the different commands
PING to ping the server
MOTD to display the message of the day
USER to log in using your user name
PASS to log in using your password
TOPIC to change a channel's topic
QUIT to quit the server
OPER to become a server's operator
SQUIT to shut down the server if you're the operator

Just write raw text if you want to write to everyone on your current channel

The default port is 4242