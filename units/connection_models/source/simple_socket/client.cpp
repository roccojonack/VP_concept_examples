#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    int i;
    int NumberOfTransfers;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    const char msg[] = "Hello Rocco!";

    if (argc < 4) {
      fprintf(stderr,"usage %s hostname port transfers\n", argv[0]);
      exit(1);
    }
    if (argc < 4) NumberOfTransfers = 1000;
    else NumberOfTransfers = atoi(argv[3]);
    if (argc < 3) portno = 8888;
    else  portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    if (argc < 2) server = gethostbyname("localhost");
    else server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    printf("message to send : %s", msg);
    bzero(buffer,256);
    memcpy(buffer,msg,255);
    for (i=0; i<NumberOfTransfers/2; ++i) {
      n = write(sockfd,buffer,strlen(buffer));
      if (n < 0) 
	error("ERROR writing to socket");
      bzero(buffer,256);
      n = read(sockfd,buffer,255);
      if (n < 0) 
	error("ERROR reading from socket");
      //printf("got response as %s\n",buffer);
     };
    return 0;
};
