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
    bool printing = true;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    unsigned int MessageLength = 256;
    char returnBuffer[MessageLength];
    char buffer[MessageLength];
    const char msg[] = "Hello Rocco!";
    bzero(returnBuffer,MessageLength);
    bzero(buffer,MessageLength);
    memcpy(buffer,msg,MessageLength);

    if (argc < 4) {
      fprintf(stderr,"usage %s hostname port transfers\n", argv[0]);
      exit(1);
    }
    if (argc < 4) NumberOfTransfers = 1000;
    else NumberOfTransfers = atoi(argv[3]);
    if (argc < 3) portno = 8888;
    else  portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR opening socket\n");
	exit (1);
    };
    if (argc < 2) server = gethostbyname("localhost");
    else server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("ERROR, no such host\n");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        printf("ERROR connecting\n");
	exit (1);
    };
    
    printf("message to send : %s\n", msg);
    for (i=0; i<NumberOfTransfers/2; ++i) {
      n = write(sockfd,buffer,strlen(buffer));
      if (n < 0) 
	printf("ERROR writing to socket");
      n = read(sockfd,returnBuffer,(MessageLength-1));
      if (n < 0) 
	printf("ERROR reading from socket");
      if (printing) printf("got response as %s\n",returnBuffer);
    };
    return 0;
};
