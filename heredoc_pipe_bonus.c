/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/12/27 10:21:05 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "get_next_line_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1++ == 0)
			return (0);
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	read_stdin_until_limiter(char *limiter)
{
	int		pipe_fd[2];
	char	*read_line;

	pipe(pipe_fd);
	write(1, ">", 1);
	limiter = ft_strjoin(limiter, "\n");
	read_line = get_next_line(0);
	while (read_line && ft_strcmp(read_line, limiter))
	{
		write(pipe_fd[1], read_line, ft_strlen((const char *)read_line));
		free(read_line);
		write(1, ">", 1);
		read_line = get_next_line(0);
	}
	if (read_line)
		free(read_line);
	free(limiter);
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}

void	heredoc_pipe(int argc, char **argv, char **envp)
{
	int	file1_fd;
	int	file2_fd;
	int	command_idx;

	file2_fd = open(argv[argc - 1], O_APPEND | O_WRONLY | O_CREAT, 0644);
	file1_fd = read_stdin_until_limiter(argv[1]);
	command_idx = make_process(argc - 3, file1_fd, file2_fd);
	if (argc != 4)
		argv++;
	argv++;
	execve(get_pathname(argv[command_idx], envp), \
			get_command_arg(argv[command_idx]), envp);
}
