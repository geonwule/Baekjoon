#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>


#include <stdlib.h>
#include <sys/select.h>

#define MAX_CLIENTS 1024
#define BUFFER_SIZE 4096

int clients[MAX_CLIENTS];

void add_new_client(int new_fd);
void handle_client_message(int client_fd);

int main(int ac, char **av) {

    if (ac != 2)
    {
        write(2, "Wrong number of arguments\n", 26);
        exit(1);       
    }
    int port_num = atoi(av[1]);
	int server_fd, new_fd, len;
	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	server_fd = socket(AF_INET, SOCK_STREAM, 0); 
	if (server_fd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 

	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port_num);
  
	// Binding newly created socket to given IP and verification 
	if ((bind(server_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		printf("socket bind failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully binded..\n");
	if (listen(server_fd, 10) != 0) {
		printf("cannot listen\n"); 
		exit(0); 
	}
    
    fd_set read_fds;
    int max_fd;

    while (1)
    {
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);
        max_fd = server_fd;

        for (int i = 0; i < MAX_CLIENTS; i++)
        {
            if (clients[i] > 0)
            {
                FD_SET(clients[i], &read_fds);
                if (clients[i] > max_fd)
                    max_fd = clients[i];
            }
        }

        int activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
        if (activity < 0)
        {
            exit(1);
        }

        if (FD_ISSET(server_fd, &read_fds))
        {
            len = sizeof(cli);
	        new_fd = accept(server_fd, (struct sockaddr *)&cli, (socklen_t *)&len);
            if (new_fd < 0) { 
                printf("server acccept failed...\n"); 
                exit(1);
            } 

            printf("server acccept the client...\n");
            add_new_client(new_fd);
        }

        for (int i = 0; i < MAX_CLIENTS; i++)
        {
            int client_fd = clients[i];
            if (FD_ISSET(client_fd, &read_fds))
            {
                handle_client_message(client_fd);
            }
        }
    }
}

void add_new_client(int new_fd)
{
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        if (clients[i] == 0)
        {
            clients[i] = new_fd;
            return;
        }
    }

    printf("client overflow\n");
    exit(1);
}

void handle_client_message(int client_fd)
{
    char buffer[BUFFER_SIZE];
    int read_bytes = recv(client_fd, buffer, sizeof(buffer), 0);

    if (read_bytes == 0)
    {
        printf("client [%d] disconnected\n", client_fd);
        close(client_fd);
    }
    else if (read_bytes < 0)
    {
        printf("recv error\n");
        exit(1);
    }
    else
    {
        for (int i = 0; i < MAX_CLIENTS; i++)
        {
            send(clients[i], buffer, read_bytes, 0);
        }
    }
}