#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>

uint32_t	ine(uint32_t one, uint32_t deux, uint32_t trois, uint32_t quatre)
{
	uint32_t k = 0;

	uint32_t o = one;
	uint32_t d = deux;
	uint32_t t = trois;
	uint32_t q = quatre;

	o = o << 24;
	d = d << 16;
	t = t << 8;

	k = o | d | t | q;
	std::cout << k;
	return k;
}



#define PORT 8080
int main(int argc, char const *argv[])
{
    int server_fd, new_socket; long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    char hello[1000000];
	memset(hello, 64, 1000000 - 1);
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("In socket");
        exit(EXIT_FAILURE);
    }
    
	memset(&address, '\0', sizeof(address));


    address.sin_family = AF_INET;
	address.sin_addr.s_addr = ine(1,1,0,127);
    address.sin_port = htons( PORT );
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("In bind");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 10) < 0)
    {
        perror("In listen");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        printf("\n+++++++ Waiting for new connection ++++++++\n\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
        {
            perror("In accept");
            exit(EXIT_FAILURE);
        }
        
        char buffer[30000] = {0};
        printf("READ\n");
        valread = read( new_socket , buffer, 30000);
        printf("%s\n",buffer );
        int r = write(new_socket , hello , strlen(hello));
		if (r != strlen(hello))
			printf("WRITE %d\n", r);
		printf("------------------Hello message sent-------------------\n");
        close(new_socket);
    }
    return 0;
}