#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>

void err_msg(int flag)
{
    if (flag == 0)
    {
        write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
    }
    else
    {
        write(2, "Fatal error\n", strlen("Fatal error\n"));
    }
    exit(1);
}

int extract_message(char **buf, char **msg)
{
    char    *newbuf;
    int i;

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
    char    *newbuf;
    int     len;

    if (buf == 0)
        len = 0;
    else
        len = strlen(buf);
    newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
    if (newbuf == 0)
        return (0);
    newbuf[0] = 0;
    if (buf != 0)
    {
        strcat(newbuf, buf);
        free(buf);
    }
    strcat(newbuf, add);
    return (newbuf);
}


enum e_define
{
    BUFFER_SIZE=1024,
    MAX_CLIENT=1024,
};

enum e_msg
{
    ARRIVE,
    LEFT,
    MSG,
};

int servfd, connfd, len, max_fd, client_id = 0;
struct sockaddr_in servaddr, cli;
fd_set fdset;

typedef struct s_client
{
    int id, fd;
    char *buff;
}   t_client;

t_client clients[MAX_CLIENT];

void send_all(int my_id, enum e_msg flag, char *msg)
{
    char buff[BUFFER_SIZE];
    int read_bytes;
    if (flag == ARRIVE)
        read_bytes = sprintf(buff, "server: client %d just arrived\n", my_id);
    else if (flag == LEFT)
        read_bytes = sprintf(buff, "server: client %d just left\n", my_id);
    else if (flag == MSG)
        read_bytes = sprintf(buff, "client %d: ", my_id);

    for (int i = 0; i < MAX_CLIENT; i++)
    {
        t_client client = clients[i];
        if (client.fd > 0 && client.id != my_id)
        {
            send(client.fd, buff, read_bytes, 0);
            write(1, buff, read_bytes);//test
            if (flag == MSG)
            {
                send(client.fd, msg, strlen(msg), 0);
                write(1, msg, strlen(msg));//test
            }
        }
    }
}

int main(int ac, char **av) {

    if (ac != 2)
        err_msg(0);

    // socket create and verification 
    servfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (servfd == -1)
        err_msg(1);
    
    bzero(&servaddr, sizeof(servaddr)); 

    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
    servaddr.sin_port = htons(atoi(av[1])); 
  
    // Binding newly created socket to given IP and verification 
    if ((bind(servfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
        err_msg(1);
    if (listen(servfd, 10) != 0)
        err_msg(1);

    while (1)
    {
        FD_ZERO(&fdset);
        FD_ISSET(servfd, &fdset);
        max_fd = servfd;

        for (int i = 0; i < MAX_CLIENT; i++)
        {
            t_client client = clients[i];
            if (client.fd > 0)
            {
                FD_ISSET(client.fd, &fdset);
                if (client.fd > max_fd)
                    max_fd = client.fd;
            }
        }

        if (select(max_fd + 1, &fdset, NULL, NULL, NULL) < 0)
            continue;
        
        if (FD_ISSET(servfd, &fdset))
        {
            len = sizeof(cli);
            connfd = accept(servfd, (struct sockaddr *)&cli, (socklen_t *)&len);
            if (connfd < 0)
                err_msg(1);

            for (int i = 0; i < MAX_CLIENT; i++)
            {
                t_client client = clients[i];
                if (client.fd == 0)
                {
                    client.id = client_id++;
                    client.fd = connfd;
                    client.buff = NULL;
                    clients[i] = client;
                    send_all(client.id, ARRIVE, NULL);
                    break;
                }
            }
        }
        for (int i = 0; i < MAX_CLIENT; i++)
        {
            t_client client = clients[i];
            char buff[BUFFER_SIZE];
            ssize_t read_bytes = recv(client.fd, buff, BUFFER_SIZE - 1, 0);
            if (read_bytes <= 0)
            {
                close(client.fd);
                clients[i].fd = 0;
                if (clients[i].buff)
                    free(clients[i].buff);
                send_all(client.id, LEFT, NULL);
                continue;
            }

            buff[read_bytes] = 0;
            client.buff = str_join(client.buff, buff);
            while (read_bytes == BUFFER_SIZE - 1)
            {
                read_bytes = recv(client.fd, buff, BUFFER_SIZE - 1, 0);
                if (read_bytes == 0)
                    break;
                buff[read_bytes] = 0;
                client.buff = str_join(client.buff, buff);
                if (client.buff == 0)
                    err_msg(1);
            }

            while (1)
            {
                char *msg;
                int status = extract_message(&client.buff, &msg);
                if (status == -1)
                    err_msg(1);
                else if (status == 0)
                    break;
                else
                {
                    send_all(client.id, MSG, msg);
                    // free(msg);
                }
            }
        }
    }
}

