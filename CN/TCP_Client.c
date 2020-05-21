 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netdb.h>
 #include <stdio.h>
 #include <string.h>
 #include <strings.h>
 #include<arpa/inet.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>




#define MAX_MSG 100
 #define SERVER_ADDR "127.0.0.1"
 #define CLIENT_ADDR "127.0.0.1"
 #define SERVER_PORT 3786
 #define CLIENT_PORT 8229

main () {

int sd, rc, i,n;
 struct sockaddr_in clientAddr, servAddr;
 char line[MAX_MSG];


bzero((char *)&servAddr, sizeof(servAddr));
 servAddr.sin_family = AF_INET;
 servAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
 servAddr.sin_port = htons(SERVER_PORT);

/*
 bzero((char *)&servAddr, sizeof(servAddr));
 servAddr.sin_family = AF_INET;
 inet_aton(SERVER_ADDR, &servAddr.sin_addr);
 servAddr.sin_port = htons(SERVER_PORT);
 */



bzero((char *)&clientAddr, sizeof(clientAddr));
 clientAddr.sin_family = AF_INET;
 clientAddr.sin_addr.s_addr = INADDR_ANY;
 clientAddr.sin_port = htons(0);

/*
 bzero((char *)&clientAddr, sizeof(clientAddr));
 clientAddr.sin_family = AF_INET;
 clientAddr.sin_addr.s_addr = inet_addr(CLIENT_ADDR);
 clientAddr.sin_port = htons(CLIENT_PORT);
 */


sd = socket(AF_INET, SOCK_STREAM, 0);
 printf("successfully created stream socket \n");



bind(sd, (struct sockaddr *) &clientAddr, sizeof(clientAddr));
 printf("bound local port successfully\n");



connect(sd, (struct sockaddr *) &servAddr, sizeof(servAddr));
 printf("connected to server successfully\n");


do{
 printf("Enter 1st number : ");
 scanf("%s", line);

send(sd, line, strlen(line) + 1, 0);
 printf("data sent (%s)\n", line);
 printf("Enter 2nd number : ");
 scanf("%s", line);
 send(sd, line, strlen(line) + 1, 0);
 printf("data sent (%s)\n", line);

n=recv(sd, line, MAX_MSG, 0);
 printf("received from server %s\n", line);
 }while(strcmp(line, "quit"));

printf("closing connection with the server\n");
 close(sd);
 }

/* OUTPUT

student@student:~$ gcc tcpc1.c
tcpc1.c:23:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main () {
 ^~~~
student@student:~$ ./a.out
successfully created stream socket 
bound local port successfully
connected to server successfully
Enter 1st number : 3
data sent (3)
Enter 2nd number : 5
data sent (5)
received from server 8
Enter 1st number : 7
data sent (7)
Enter 2nd number : 8
data sent (8)
received from server 15
Enter 1st number : ^C

*/

