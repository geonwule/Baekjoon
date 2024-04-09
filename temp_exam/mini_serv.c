#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s[i])
        i++;
    return i;
}

void ft_error(const char* msg)
{
    write(2, msg, ft_strlen(msg));
    exit(1);
}

void *ft_malloc(size_t _size)
{
    void *buff = malloc(_size);
    if (!buff)
        ft_error("Fatal error\n");
    return buff;
}

char *arrive_msg(int client_num)
{
    char buff[BUFFER_SIZE];
    sprintf(buff, "server: client %d just arrived\n", client_num);
    char *ret = (char *)ft_malloc(ft_strlen(buff) * sizeof(char));
    strcpy(ret, buff);
    return ret;
}

char *left_msg(int client_num)
{
    char buff[BUFFER_SIZE];
    sprintf(buff, "server: client %d just left\n", client_num);
    char *ret = (char *)ft_malloc(ft_strlen(buff) * sizeof(char));
    strcpy(ret, buff);
    return ret;
}

char *all_msg(int client_num, const char *msg)
{
    char buff[BUFFER_SIZE];
    sprintf(buff, "client %d: ", client_num);
    char *ret = (char *)ft_malloc((ft_strlen(buff) + ft_strlen(msg)) * sizeof(char));
    sprintf(ret, "client %d: %s", client_num, msg);
    return ret;
}

void leaks() { system("leaks test"); }

#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h> //sockaddr_in
int client_sockets[MAX_CLIENTS];

void send_all(const char *buff)
{
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        if (client_sockets[i] > 0)
        {
            send(client_sockets[i], buff, ft_strlen(buff), 0);
        }
    }
}

int main(int ac, char **av)
{
    // atexit(leaks);
    if (ac != 2)
        ft_error("Wrong number of arguments\n");

    int port_number = atoi(av[1]);
    
    int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli; 

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1)
		ft_error("Fatal error\n");

    bzero(&servaddr, sizeof(servaddr)); 

    // assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port_number);

    // Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		ft_error("Fatal error\n");
	
	if (listen(sockfd, 10) != 0)
		ft_error("Fatal error\n");

    printf("Listening for connections...\n");

    fd_set readfds;

    // Initialize client_sockets array
    for (int i = 0; i < MAX_CLIENTS; i++) {
        client_sockets[i] = 0;
    }

    int maxfd, activity;
    while (1)
    {
        //clear the socket set
        FD_ZERO(&readfds);

        //add master socket to set
        FD_SET(sockfd, &readfds);
        maxfd = sockfd;

        //add child sockets to set
        for (int i = 0; i < MAX_CLIENTS; i++)
        {
            if (client_sockets[i] > 0){
                FD_SET(client_sockets[i], &readfds);
            }

            if (client_sockets[i] > maxfd) {
                maxfd = client_sockets[i];
            }
        }

        activity = select(maxfd + 1, &readfds, NULL, NULL, NULL);
        if (activity < 0)
	    	ft_error("Fatal error\n");

        len = sizeof(cli);
        if (FD_ISSET(sockfd, &readfds)){
            if ((connfd = accept(sockfd, (struct sockaddr *)&cli, &len)) < 0)
                ft_error("Fatal error\n");

            // Set the client socket to non-blocking mode
            if (fcntl(connfd, F_SETFL, O_NONBLOCK) < 0) {
                ft_error("Fatal error\n");
            }

            printf("New connection\n");

            // Add new socket to array of sockets
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = connfd;
                    send_all(arrive_msg(i));
                    break;
                }
            }
        }

        int valread;
        char buffer[BUFFER_SIZE];
        // Else it's some IO operation on some other socket
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (FD_ISSET(client_sockets[i], &readfds)) {
                // Check if it was for closing, and also read the incoming message
                if ((valread = recv(client_sockets[i], buffer, BUFFER_SIZE, 0)) == 0) {
                    // Somebody disconnected, get his details and print
                    printf("Host disconnected\n");

                    // Close the socket and mark as 0 in list for reuse
                    close(client_sockets[i]);
                    client_sockets[i] = 0;
                    send_all(left_msg(i));
                }
                else {
                    buffer[valread] = '\0';
                    send_all(all_msg(i, buffer));
                }
            }
        }
    }



    size_t client_num;
    int *clients_socket;
    fd_set readfds;
    while (1)
    {
        //clear
        FD_ZERO(&readfds);

        //FD_SET
        FD_SET(sockfd, &readfds);
        maxfd = sockfd;

        for (int i = 0; i < client_num; i++)
        {
            if (clients_socket[i] > 0)
                FD_SET(clients_socket[i], &readfds);
            
            if (maxfd < clients_socket[i])
                maxfd = clients_socket[i];
        }

        //select
        if (select(maxfd + 1, &readfds, NULL, NULL, NULL) < 0)
            exit(1);

        	// struct sockaddr_in cli; 
        
        len = sizeof(cli);
        if (FD_ISSET(sockfd, &readfds)){
            int connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
            if (connfd < 0)
                exit(1);

            if (fcntl(connfd, F_SETFL, O_NONBLOCK) < 0) {
                ft_error("Fatal error\n");
            }
        }

                    // Add new socket to array of sockets
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = connfd;
                    send_all(arrive_msg(i));
                    break;
                }
            }

        for (MAXCLIENTs)
        {
            if (FD_ISSET(clients_socket[i], &readfds))
            {
                readsize = recv(clients_socket[i], buffer, BUFFERSIZE, 0)
                if (readsize == 0)
                    disconnectx

                close

                else
                    send all
            }

        }
    }
}

