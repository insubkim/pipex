/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/12/20 14:41:04 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX
# define PIPEX

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_process_fd_info
{
    int id;
    int read_fd;
    int write_fd;
}    t_process_fd_info;

int	ft_strncmp(const char *s1, const char *s2, size_t n);
void    heredoc_pipe(int argc, char **argv, char **envp);
void    read_file_pipe(int argc, char **argv, char **envp);
char	*pipex_strjoin(char *s1, char *s2);
char    *get_pathname(char *command, char **envp);
char *const* get_command_arg(char *argv);
char	**ft_split(char const *s, char c);
void    handle_error(void);
void    free_string_arr(char **arr);
int make_command_process(int command_count, char **commands, int file1_fd, \
int file2_fd);

#endif