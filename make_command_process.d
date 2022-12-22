/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/12/21 23:45:57 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int make_command_process(int command_count, int file1_fd, \
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
        pipe(pipe_fd);
        dup2(read_end, 0);
        close(read_end);
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
        pid = fork();
        if (!pid)
            break;
        read_end = dup(pipe_fd[0]);
        close(pipe_fd[0]);
        i++;
    }
    if (pid)
    {
        close(read_end);
        exit(0);
    }
    perror("");
    return (i);
}