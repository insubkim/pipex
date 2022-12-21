/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/12/21 13:07:15 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int fork_command(int command_count, char **commands, int file1_fd, \
int file2_fd)
{
    int i;
    pid_t pid;
    int pipe_fd[2];

    i = 0;
    while (i < command_count)
    {
        pipe(pipe_fd);
        pid = fork();
        if (pid)
        {

        }
        else
        {
            
        }
    }
    close(pipe_fd[0]);
    if(pid)
        exit(0);
    return (i);
}