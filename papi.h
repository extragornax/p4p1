#ifndef papi_h
#define papi_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <fcntl.h> // for cp
#include <errno.h> // for cp

#include <ncurses.h>
#include <pthread.h>

#define BUFSIZE 9999
#define SOCKET_ERROR -1

struct window {

	int row, col;

};

struct arg_options {

	char * usb_path;

};

struct server_info {

	int s;	//socket desc
	int cliNum;

	int portno;
	char ip[16];
	char username[50];
	char * hostaddrp;

	struct arg_options argo;
	struct window win;
	struct sockaddr_in server, client;

};

void init_variables(struct server_info * inf, char * argv[]);
void pscreen(char * str, int x, int y);
void error(char * msg, int num);
void usage(char * exname);
void quit(int c, int s);
int reusesock(struct server_info * inf);
void printlogo();
void clastrow();
void clearmain();

#endif
