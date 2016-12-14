#include <sys/socket.h>
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
     int sockfd, newsockfd, portno, clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     int i;
     int NumberOfTransfers = 1000000;

     if (argc < 3) {
       fprintf(stderr,"usage %s port transfers\n", argv[0]);
       exit(1);
     };
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     if (argc < 3) NumberOfTransfers = 1000;
     else NumberOfTransfers = atoi(argv[2]);
     if (argc>2) portno = 8888;
     else portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");
     bzero(buffer,256);

     for (i=0; i<NumberOfTransfers/2; ++i) {
       n = read(newsockfd,buffer,255);
       if (n < 0) error("ERROR reading from socket");
       // printf("Here is the received message: %s\n",buffer);
       n = write(newsockfd,"I got your message",18);
       if (n < 0) error("ERROR writing to socket");
     };
     return 0; 
};
