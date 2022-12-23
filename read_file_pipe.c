/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/12/23 10:15:04 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int make_eof_fd(void)
{
    int tmp_pipe[2];

    pipe(tmp_pipe);
    dup2(tmp_pipe[0], 0);
    close(tmp_pipe[0]);
    close(tmp_pipe[1]);
    return (0);
}

void    read_file_pipe(int argc, char **argv, char **envp)
{
    int file1_fd;
    int file2_fd;
    int command_idx;

    //open file2 in O_TRUNC | O_CREAT | O_WRONLY
    file2_fd = open(argv[argc - 1], O_TRUNC | O_WRONLY | O_CREAT, 0644);
    //open file1 in O_RDONLY
    file1_fd = open(argv[0], O_RDONLY);
    if (file1_fd < 0)
    {
        perror("");
        file1_fd = make_eof_fd();
        argc--;
        argv++;
    }
    command_idx = make_process(argc - 2, file1_fd, file2_fd);
    argv++;
    execve(get_pathname(argv[command_idx], envp), \
    get_command_arg(argv[command_idx]), envp);
}