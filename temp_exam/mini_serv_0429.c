#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

enum    s_err{
    ARG_ERR,
    FATAL_ERR,
};

void error_msg(enum s_err flag)
{
    if (flag == ARG_ERR)
    {
        write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
    }
    else
    {
        write(2, "Fatal error\n", strlen("Fatal error\n"));
    }
    exit(1);
}

#define BUFFER_SIZE 1024
#define MAX_CLIENT 1024

typedef struct s_Client
{
    int fd, id;
    char buff[BUFFER_SIZE];
}   t_Client;

t_Client clients[MAX_CLIENT];
int max_fd;
fd_set fdsets;

enum e_msg{
	MSG,
	ARRIVE,
	LEFT,
}

int servfd, connfd, len;
void send_all(int my_id, char *msg, enum e_msg flag);

int main(int ac, char **av) {

    if (ac != 3)
        error_msg(ARG_ERR);

	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	servfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (servfd == -1) { 
		error_msg(FATAL_ERR);
	} 
	
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(servfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		error_msg(FATAL_ERR);
	} 
	
	if (listen(servfd, 10) != 0) {
		error_msg(FATAL_ERR);
	}

    while (1)
    {
        FD_ZERO(&fdsets);
        FD_SET(servfd, &fdsets);
        max_fd = servfd;

        for (int i = 0; i < MAX_CLIENT; i++)
        {
            t_Client client = clients[i];
            if (client.fd > 0)
            {
                FD_SET(client.fd, &fdsets);
                if (client.fd > max_fd)
                    max_fd = client.fd;
            }
        }

        if (select(max_fd+1, &fdsets, NULL, NULL, NULL) < 0)
            continue;

        if (FD_ISSET(servfd, &fdsets))
        {
            len = sizeof(cli);
	        connfd = accept(servfd, (struct sockaddr *)&cli, (socklen_t *)&len);
	        if (connfd < 0) { 
                error_msg(FATAL_ERR);
            }

            for (int i = 0; i < MAX_CLIENT; i++)
            {
                t_Client client = clients[i];
                if (client.fd == 0)
                {
                    client.fd = connfd;
					client.id = i;
                    client.buff = NULL;
                    clients[i] = client;
					//arrive
					send_all(client.id, NULL, ARRIVE);
                    break;
                }
            }
        }

		for (int i = 0; i < MAX_CLIENT; i++)
		{
			t_client client = clients[i];
			if (FD_ISSET(client.fd. &fdsets))
			{
				ssize_t read_byte = recv(client.fd, client.buff, BUFFER_SIZE, 0);

				if (read_byte <= 0)
				{
					//left
					close(client.fd);
					clients[i].fd = 0;
					send_all(client.id, NULL, LEFT);
				}
				else
				{
					char *msg;
					while(read_byte)
					{
						int status = extract_message(&client.buff, &msg);
						if (status == -1)
							error_msg(FATAL_ERR);
						if (status == 0)
							continue;
						if (status == 1)
						{
							send_all(client.id, msg, MSG);
						}
						if (read_byte != BUFFER_SIZE)
							break;
						read_byte = recv(client.fd, client.buff, BUFFER_SIZE, 0);
					}
				}
			}
		}
    }
}

void send_all(int my_id, char *msg, enum e_msg flag)
{
	char buff[BUFFER_SIZE];
	int read_bytes;
	if (flag == ARRIVE)
	{
		read_bytes = sprintf(buff, "server: client %d just arrived\n", my_id);
	}
	else if (flag == LEFT)
	{
		read_bytes = sprintf(buff, "server: client %d just left\n", my_id);
	}
	else
	{
		read_bytes = sprintf(buff, "client %d: ", my_id);
	}

	for (int i = 0; i < MAX_CLIENT; i++)
	{
		t_Client client = clients[i];
		if (client.fd > 0 && client.id != my_id)
		{
			send(client.fd, buff, read_bytes, 0);
			if (flag == MSG)
			{
				send(client.fd, msg, strlen(msg), 0);
			}
		}
	}
}
