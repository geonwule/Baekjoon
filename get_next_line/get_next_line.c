/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:44:44 by geonwule          #+#    #+#             */
/*   Updated: 2023/01/12 11:07:03 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_txt(char *back, char **n_ptr, int readsize, int fd)
{
	char		*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (0);
	*n_ptr = ft_strchr(back, '\n');
	while ((*n_ptr == NULL) && (readsize != 0))
	{
		readsize = read(fd, buf, BUFFER_SIZE);
		if (readsize == -1)
		{
			if (back)
				free(back);
			free(buf);
			return (0);
		}
		if (readsize == 0)
			break ;
		buf[readsize] = '\0';
		back = ft_strjoin(back, buf);
		*n_ptr = ft_strchr(back, '\n');
	}
	free(buf);
	return (back);
}

char	*line_set(char *back)
{
	char	*line;
	int		i;

	i = 0;
	if (back[i] == '\0')
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

char	*get_next_line(int fd)
{
	static char	*back;
	char		*n_ptr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	back = read_txt(back, &n_ptr, -1, fd);
	if (back == NULL)
		return (0);
	line = line_set(back);
	if (n_ptr != NULL)
		back = ft_strdup(n_ptr + 1, back);
	else
	{
		free(back);
		back = 0;
	}
	return (line);
}
