

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>



#define MAX_MSG 100
#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 3786


 main ( ) {

  int sd, newSd, cliLen, n,num1,num2,sum;

  struct sockaddr_in cliAddr, servAddr;
  char line[MAX_MSG],line1[MAX_MSG],line2[MAX_MSG];


  /**********************************/ 
  /* build server address structure */
  /**********************************/ 

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


  /************************/ 
  /* create stream socket */
  /************************/ 

  sd = socket(AF_INET, SOCK_STREAM, 0);
  printf("successfully created stream socket \n");

  /**************************/ 
  /* bind local port number */
  /**************************/ 

  bind(sd, (struct sockaddr *) &servAddr, sizeof(servAddr));
  printf("bound local port successfully\n");


  /********************************/ 
  /* specify number of concurrent */
  /* clients to listen for        */
  /********************************/ 

  listen(sd,5);


  while(1) {

    printf("waiting for client connection on port TCP %u\n",SERVER_PORT);

    /*****************************/
    /* wait for client connection*/
    /*****************************/   

    cliLen = sizeof(cliAddr);
    newSd = accept(sd, (struct sockaddr *) &cliAddr, &cliLen);

    printf("received connection from host [IP %s ,TCP port %d]\n",
                 inet_ntoa(cliAddr.sin_addr), ntohs(cliAddr.sin_port));

    /*****************************/
    /* wait for data from client */
    /*****************************/     
  
    do{
      memset(line,0x0,MAX_MSG);
  
      n=recv(newSd, line, MAX_MSG, 0);
      num1=atoi(line);
    
      n=recv(newSd, line, MAX_MSG, 0);
      num2=atoi(line);

    
      sum=num1+num2;

      sprintf(line1,"%d",sum);
    
  
      printf("received from host [IP %s ,TCP port %d] : %s\n", 
                 inet_ntoa(cliAddr.sin_addr), ntohs(cliAddr.sin_port), line1);
  send(newSd, line1, strlen(line1) + 1, 0);

    }while(abs(strcmp(line, "quit")));


    /**************************/
    /* close client connection*/
    /**************************/   

    printf("closing connection with host [IP %s ,TCP port %d]\n",
                 inet_ntoa(cliAddr.sin_addr), ntohs(cliAddr.sin_port));

    close(newSd);
  }
}
/*OUTPUT
student@student:~$ gcc tcps1.c
tcps1.c:20:2: warning: return type defaults to ‘int’ [-Wimplicit-int]
  main ( ) {
  ^~~~
tcps1.c: In function ‘main’:
tcps1.c:90:12: warning: implicit declaration of function ‘atoi’ [-Wimplicit-function-declaration]
       num1=atoi(line);
            ^~~~
tcps1.c:105:12: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
     }while(abs(strcmp(line, "quit")));
            ^~~
student@student:~$ ./a.out
successfully created stream socket 
bound local port successfully
waiting for client connection on port TCP 3786
received connection from host [IP 127.0.0.1 ,TCP port 34141]
received from host [IP 127.0.0.1 ,TCP port 34141] : 8
received from host [IP 127.0.0.1 ,TCP port 34141] : 15
received from host [IP 127.0.0.1 ,TCP port 34141] : 0
received from host [IP 127.0.0.1 ,TCP port 34141] : 0
*/

