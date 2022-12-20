/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/12/20 15:22:10 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int make_command_process(int command_count, char **commands, int file1_fd, \
int file2_fd)
{
    int     i;
    pid_t   pid;
    int     read_end;
    int     pipe_fd[2];

    i = 0;
    read_end = file1_fd;
    while (i < command_count)
    {
        if (read_end < 0)
        {
            read_end = 0;
            i++;
            perror("");
            continue ;
        }
        if (read_end != 0)
        {
            dup2(read_end, 0);
            close(read_end);
        }
        pipe(pipe_fd);
        if (i == command_count - 1)
        {
            dup2(file2_fd, 1);
            close(file2_fd);
            close(pipe_fd[1]);
        }
        else
        {
            dup2(pipe_fd[1], 1);
            close(pipe_fd[1]);
        }
        read_end = pipe_fd[0];
        pid = fork();
        if (!pid)
            break;
        i++;
    }
    close(pipe_fd[0]);
    if (pid)
        exit(0);
    return (i);
}