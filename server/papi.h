#ifndef papi_h
#define papi_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <netinet/in.h>

#include <ncurses.h>
#include <pthread.h>

#define BUFSIZE 9999
#define SOCKET_ERROR -1
#define NUMOCLIENTS 5

/*
 * Thread structure
 ***/
typedef struct {

	char cliNum;
	int * saved_sockets;
	int connectedTo;
	int allDone;
	int ncurses, cmd, grtk;

	char buf[BUFSIZE];

} serverthread;

/*
 * Argument options structure
 ***/
struct arg_options {

	char * usb_path;

};

/*
 * Main variable structure
 ***/
struct server_info {

	int s;	//socket desc

	int portno;
	char ip[16];
	char username[50];
	char * hostaddrp;

	struct arg_options argo;
	struct sockaddr_in server, client;

};

/*
 * Main structure for global variables
 */
serverthread serverThread;

/*
 * window variables
 */
int row, col;

/*
 * Function declarations see p4p1-s_linux.c
 * for each function details
 ***/
void init_variables(struct server_info * inf, char * argv[]);
void error(char * msg, int num);
void usage(char * exname);
void quit(int c, int s);
int reusesock(struct server_info * inf);
void printlogo();
void clastrow();
void exitmsg();
void clearmain();

#endif	/* end of papi.h */