/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:57:07 by geonwule          #+#    #+#             */
/*   Updated: 2023/04/21 17:55:49 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define READ_END 0
#define WRITE_END 1

int	env_idx(char *env[])
{
	int i = -1;
	while (env[++i] != NULL)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
			break;
	}
	return (i);
}

void	filepath_init(char *path)
{
	int	i;

	i = -1;
	while (++i < BUFFER_SIZE)
	{
		path[i] = 0;
	}
}

void	filepath_search(t_vars vars, char *cmd, char *filepath)
{
	for (int i = 0; vars.bin[i] != NULL; i++)
	{
		filepath_init(filepath);
		strcat(filepath, vars.bin[i]);
		strcat(filepath, "/");
		strcat(filepath, cmd);
		if (access(filepath, F_OK) == 0)
			return ;
	}
	perror("path_error");
	exit(EXIT_FAILURE);
}

void one_child(t_vars vars, int *fd, char **env)
{
	int fd2[2]; // 두번째 파이프
	
	if (pipe(fd2) == -1)
	{
		perror("pipe2");
		exit(EXIT_FAILURE);
	}
	pid_t pid2;
	pid2 = fork(); // 두번째 자식프로세스 생성
	if (pid2 == -1)
	{
		perror("fork2");
		exit(EXIT_FAILURE);
	}
	if (pid2 == 0) // 두번째 자식 프로세스
	{
		dup2(fd2[READ_END], STDIN_FILENO);
		close(fd2[READ_END]);
		close(fd2[WRITE_END]);
		// int fd_file2 = open(vars.file2, O_WRONLY | O_TRUNC | O_CREAT, 777);
		// dup2(fd_file2, STDOUT_FILENO);
		filepath_search(vars, vars.cmd2[0], vars.filepath);
		if (execve(vars.filepath, vars.cmd2, env) == -1)
		{
			perror("execve2");
			exit(EXIT_FAILURE);
		}
	}
	else // 첫번째 자식 프로세스
	{
		close(fd[WRITE_END]);
		close(fd2[READ_END]);
		dup2(fd[READ_END], STDIN_FILENO);
		close(fd[READ_END]);
		dup2(fd2[WRITE_END], STDOUT_FILENO);
		close(fd2[WRITE_END]);
		filepath_search(vars, vars.cmd1[0], vars.filepath);
		if (execve(vars.filepath, vars.cmd1, env) == -1)
		{
			perror("execve1");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
}


int main(int ac, char *av[], char *env[])
{
	int fd[2];
	pid_t pid;
	t_vars vars;

	if (strcmp(av[1], "here_doc") == 0)
	{
		vars.cmd1 = ft_split(av[3], ' ');
		vars.cmd2 = ft_split(av[4], ' ');
		strcpy(vars.file2, av[5]);
		strcpy(vars.limiter, av[2]);

		int read_size = 1;
		int input_size = 0;
		char	*input = NULL;
		char	buf[BUFFER_SIZE];

		while (read_size = read(0, buf, BUFFER_SIZE))
		{
			input_size += read_size;
			input = (char *)malloc(sizeof(char) * (input_size));
			if (input == NULL)
				exit(EXIT_FAILURE);
			
		}
	}
	strcpy(vars.file1, av[1]);
	vars.cmd1 = ft_split(av[2], ' ');
	vars.cmd2 = ft_split(av[3], ' ');
	strcpy(vars.file2, av[4]);
	vars.env_i = env_idx(env);
	vars.bin = ft_split(&env[vars.env_i][5], ':');
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork(); // 자식프로세스 생성
	if (pid == -1)
	{
		perror("fork1");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) // 자식 프로세스
	{
		// one_child(vars, fd, env);
		close(fd[READ_END]);
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[WRITE_END]);
		int fd_file1 = open(vars.file1, O_RDONLY);
		dup2(fd_file1, STDIN_FILENO);
		close(fd_file1);
		filepath_search(vars, vars.cmd1[0], vars.filepath);
		if (execve(vars.filepath, vars.cmd1, env) == -1)
		{
			perror("execve1");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else // 부모 프로세스
	{
		close(fd[READ_END]);
		char *buf[BUFFER_SIZE];
		int fd_file1 = open(vars.file1, O_RDONLY);
		if (fd_file1 != -1)
		{
			int read_byte = read(fd_file1, buf, BUFFER_SIZE);
			close(fd_file1);
			write(fd[WRITE_END], buf, read_byte);
		}
		close(fd[WRITE_END]);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (src_len);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

static int word_count(char const *s, char c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static char *word_set(char const *s, char c, int idx)
{
	char *result;
	int result_len;
	int ori_idx;

	ori_idx = idx;
	while (s[idx] != '\0' && s[idx] != c)
		idx++;
	result_len = idx - ori_idx;
	result = (char *)malloc(sizeof(char) * (result_len + 1));
	if (result == NULL)
		return (0);
	result[result_len] = '\0';
	ft_strlcpy(result, s + ori_idx, result_len + 1);
	return (result);
}

static void free_split(char **result, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static char **ft_split2(char **result, char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			result[j] = word_set(s, c, i);
			if (result[j] == NULL)
			{
				free_split(result, j);
				return (0);
			}
			j++;
		}
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (result);
}

char **ft_split(char const *s, char c)
{
	char **result;
	int result_len;

	result_len = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (result_len + 1));
	if (result == NULL)
		return (0);
	result[result_len] = 0;
	return (ft_split2(result, s, c));
}

// void	file_cpy(char *file, char *av)
// {
// 	file = (char *)malloc(sizeof(char) * (strlen(av) + 1));
// 	if (file == NULL)
// 		exit(1);
// 	strcpy(file, av);	//ft_strcpy
// }

// void	vars_init(t_vars *vars, char **av)
// {
// 	file_cpy(vars.file1, av[1]);
// 	file_cpy(vars.file2, av[4]);
// 	file_cpy(vars.cmd1, av[2]);
// 	file_cpy(vars.cmd2, av[3]);
// }

// void	file1_open(char *file1, t_list **infile)
// {
// 	int		fd;
// 	char	*temp;

// 	fd = open(file1, O_RDONLY);
// 	temp = get_next_line(fd);
// 	while (temp)
// 	{
// 		ft_lstadd_back(infile, ft_lstnew(temp));
// 		temp = get_next_line(fd);
// 	}
// 	close(file1);
// }

// int main(int ac, char **av)
// {
// 	t_list	*infile;
// 	t_vars	*vars;

// 	infile = NULL;
// 	if (ac != 5)
// 	{
// 		printf("Error\n");
// 		return (0);
// 	}
// 	vars_init(vars, av);
// 	file1_open(vars.file1, &infile);
// 	execve("./", av[2], NULL); // 여기서 필요한 아이들을 인자로 담아서 av에 넣고 다음 실행파일로 이동해야함

// }
