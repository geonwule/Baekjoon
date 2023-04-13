/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:08:22 by geonwule          #+#    #+#             */
/*   Updated: 2023/01/13 10:54:30 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_txt(t_list *lst, char **n_ptr, int readsize)
{
	char		*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (0);
	*n_ptr = ft_strchr(lst->content, '\n');
	while ((*n_ptr == NULL) && (readsize != 0))
	{
		readsize = read(lst->fd, buf, BUFFER_SIZE);
		if (readsize == -1)
		{
			if (lst->content)
				free(lst->content);
			free(buf);
			return (0);
		}
		if (readsize == 0)
			break ;
		buf[readsize] = '\0';
		lst->content = ft_strjoin(lst->content, buf);
		*n_ptr = ft_strchr(lst->content, '\n');
	}
	free(buf);
	return (lst->content);
}

char	*line_set(char *back)
{
	char	*line;
	int		i;

	i = 0;
	if (back == NULL || back[i] == '\0')
		return (0);
	while (back[i] != '\0')
	{
		if (back[i] == '\n')
			break ;
		i++;
	}
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (0);
	ft_strlcpy(line, back, i + 2);
	return (line);
}

t_list	*ft_lstnew_add_back(char *content, int fd, t_list **head)
{
	t_list	*new;
	t_list	*prev;
	t_list	*temp;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new->fd = fd;
	new->content = content;
	new->next = NULL;
	prev = *head;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
	}
	temp->next = new;
	*head = prev;
	return (new);
}

void	lst_clear(t_list *lst, t_list **head, int fd)
{
	t_list	*head_prev;
	t_list	*temp;

	head_prev = *head;
	temp = *head;
	if (lst->content)
		free(lst->content);
	if ((*head)->fd == fd)
	{
		*head = (*head)->next;
		free(temp);
		return ;
	}
	while (*head && (*head)->fd != fd)
	{
		temp = *head;
		*head = (*head)->next;
	}
	temp->next = lst->next;
	*head = head_prev;
	free(lst);
}

char	*get_next_line(int fd)
{
	t_list			*lst;
	static t_list	*head;
	char			*n_ptr;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	lst = head;
	while (lst && lst->fd != fd)
		lst = lst->next;
	if (lst == NULL)
	{
		lst = ft_lstnew_add_back(NULL, fd, &head);
		if (lst == NULL)
			return (0);
	}	
	lst->content = read_txt(lst, &n_ptr, -1);
	line = line_set(lst->content);
	if (n_ptr != NULL)
		lst->content = ft_strdup(n_ptr + 1, lst->content);
	else
		lst_clear(lst, &head, fd);
	return (line);
}
