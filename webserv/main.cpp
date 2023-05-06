#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>

int main()
{
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	if (socket_fd < 0)
		perror("cannot create sokcet");

	
}