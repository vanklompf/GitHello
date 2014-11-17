#include "client.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

static void error(const char *msg)
{
    perror(msg);
    exit(1);
}

void client_main(int port)
{
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int n;

    char buffer[256];

    int socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketDescriptor < 0)
    {
        error("ERROR opening socket");
    }

    server = gethostbyname("localhost");
    if (server == NULL)
    {
        error("ERROR, no such host\n");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(socketDescriptor,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
    {
        error("ERROR connecting");
    }

    n = write(socketDescriptor,"12345XXX",8);
    if (n < 0)
    {
         error("ERROR writing to socket");
    }
    memset(buffer,0,256);
    n = read(socketDescriptor,buffer,255);
    if (n < 0)
    {
         error("ERROR reading from socket");
    }
    printf("CLIENT: %s\n",buffer);
    close(socketDescriptor);
}
