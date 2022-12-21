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

void    make_pipe(int file1_fd, int file2_fd, int index, int *read_end)
{
    
}

int make_process(int command_count, int file1_fd, \
int file2_fd)
{
    int     i;
    pid_t   pid;
    int     read_end;

    i = 0;
    while (i < command_count)
    {
        make_pipe(file1_fd, file2_fd, i, &read_end);
        pid = fork();
        if (!pid)
            break ;
        i++;
    }
    if (pid)
        exit(0);
    perror("");
    return (i);
}