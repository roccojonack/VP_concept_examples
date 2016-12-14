#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
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
    exit(0);
};
bool my_server(int);
bool my_client(int);

int main(int argc, char **argv)
{
    printf("--beginning of program\n");

    int counter = 0;
    pid_t pid = fork();
    int portno;
    struct hostent *server;

    if (argc<3) error("not enough arguments");
    // portno = atoi(argv[2]);
    portno = 8880;
    server = gethostbyname(argv[1]);
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
      error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
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

    // struct sockaddr_in serv_addr;
 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

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
    
    if (pid == 0) {
      sleep(1);
        // child process
      my_client(sockfd);
    }
    else 
      if (pid > 0) {
        // parent process
	my_server(newsockfd);
      }
      else {
        // fork failed
        printf("fork() failed!\n");
        return 1;
      };

    printf("--end of program--\n");

    return 0;
}

bool my_server(int newsockfd)
{
     char buffer[256];
     int n;
     bzero(buffer,256);
     n = read(newsockfd,buffer,255);
     if (n < 0) error("ERROR reading from socket");
     printf("Here is the received message: %s\n",buffer);
     n = write(newsockfd,"I got your message",18);
     if (n < 0) error("ERROR writing to socket");
     return 0; 
};

bool my_client(int sockfd)
{
  int n;
  char buffer[256];
  const char msg[] = "Hello Rocco!";
  
  printf("Please enter the message: %s", msg);
  bzero(buffer,256);
  memcpy(buffer,msg,255);
  n = write(sockfd,buffer,strlen(buffer));
  if (n < 0) 
    error("ERROR writing to socket");
  bzero(buffer,256);
  n = read(sockfd,buffer,255);
  if (n < 0) 
    error("ERROR reading from socket");
  printf("got response as %s\n",buffer);
  return 0;
};
