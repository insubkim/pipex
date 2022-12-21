/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/12/21 13:25:08 by inskim           ###   ########.fr       */
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
        if (read_end < 0 && i == 0)
        {
            i++;
            continue ;
        }
        pipe(pipe_fd);
        if (read_end < 0 && i != 0)
        {
            int fd[2];
        pipe(fd);
            read_end = fd[0];
            dup2(fd[0], 0);
            close(fd[1]);
        }
        else
        {
            dup2(read_end, 0);
            close(read_end);
        }
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
        read_end = dup(pipe_fd[0]);
        close(pipe_fd[0]);
        if (!pid)
            break;
        i++;
    }
    if (pid)
        exit(0);
    write(2, strerror(errno), strlen(strerror(errno)));
    return (i);
}