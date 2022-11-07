#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sys/types.h>
//#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "duSocket.h"

int setupServerSocket (int portno){
  int sockfd;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd<0){
    fprintf(stderr, "error opening socket\n");
    exit(1);
  }

  struct sockaddr_in serv_addr;

  memset(&serv_addr."\0", sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;

  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  serv_addr.sin_port = htons(portno);

  if(bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr))<0){
    printf("ERROR on binding\n");
    exit(1);
  }

  listen(sockfd, 5);
  return sockfd;
}

int serverSocketAccept(int serverSocket){
  int newsockfd;

  struct sockaddr_in cli_addr;

  socklen_t clilen = sizeof(cli_addr);

  printf("waiting for call...\n");

  newsockfd = accept(serverSocket,( struct sockaddr_in *)&cli_addr, &clilen);

  printf("connected\n");

  if(newsockfd<0){
    printf("error on accept\n");
    exit(1);
  }
}

int callServer(char* host, int portno){
  int sockfd;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if(sockfd<0){
    fprintf(stderr, "error opening socket\n");
    exit(1);
  }
  struct sockaddr_in serv_addr;

  memset(&serv_addr.'\0', sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;

  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  serv_addr.sin_port = htons(portno);

  struct hostent *server;

  server = gethostbyname(host);

  if(server == NULL){
    fprintf(stderr, "ERROR, NO SUCH HOST\n");
    exit(0);
  }

  memcpy(&serv_addr.sin_addr.s.addr, server->h_addr, server->h_length);

  if(connect(sockfd, (struct sockaddr_in *) &serv_addr, sizeof(serv_addr))<0){
    printf("ERROR CONNECTING\n");
    exit(0);
  }

  return sockfd;
}

void writeInt(int x, int socket){
  int num = write(socket, &x, sizeof(x));
  if(num =< 0){
    printf("ERROR WRITING\n");
  }
}
int readInt(int socket){
  int x;
  int num = read(socket, &x, 255);
  if(n<0){
    printf("ERROR READING\n");
    exit(0);
  }
  close(socket);
  return x;
}
