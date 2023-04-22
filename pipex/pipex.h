/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:56:46 by geonwule          #+#    #+#             */
/*   Updated: 2023/04/21 16:50:52 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h> // EXIT_FAILURE, malloc
# include <unistd.h> //, close, execve
# include <string.h> // modify
# include <sys/types.h> // pid_t
# include <sys/wait.h>
# include <stdio.h> // perror
# include <fcntl.h> // read, open

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

typedef struct s_vars
{
	char	file1[BUFFER_SIZE];
	char	file2[BUFFER_SIZE];
	char	limiter[BUFFER_SIZE];
	char	**cmd1;
	char	**cmd2;
	char	**bin;
	char	filepath[BUFFER_SIZE];
	int		env_i;
}	t_vars;

char	**ft_split(char const *s, char c);

#endif
