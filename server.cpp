#include "server.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

static void error(const char *msg)
{
    perror(msg);
    exit(1);
}

void server_main(int port)
{
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    int n;

    int listeningSocketDescriptor = socket(AF_INET, SOCK_STREAM, 0);

    if (listeningSocketDescriptor < 0)
    {
       error("ERROR opening socket");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(listeningSocketDescriptor, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        error("ERROR on binding");
    }

    listen(listeningSocketDescriptor,5);
    clilen = sizeof(cli_addr);
    int incomingSocketDescriptor = accept(listeningSocketDescriptor, (struct sockaddr *) &cli_addr, &clilen);
    if (incomingSocketDescriptor < 0)
    {
         error("ERROR on accept");
    }

    std::memset(&buffer, 0, 256);
    n = read(incomingSocketDescriptor, buffer, 255);
    if (n < 0)
    {
    	error("ERROR reading from socket");
    }
    printf("SERVER: Received message: %s\n",buffer);
    n = write(incomingSocketDescriptor,"I got your message",18);
    if (n < 0)
    {
    	error("ERROR writing to socket");
    }
    close(incomingSocketDescriptor);
    close(listeningSocketDescriptor);
}


