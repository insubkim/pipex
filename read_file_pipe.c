/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/12/21 13:14:57 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    read_file_pipe(int argc, char **argv, char **envp)
{
    int file1_fd;
    int file2_fd;
    int command_idx;

    //open file1 in O_RDONLY
    file1_fd = open(argv[0], O_RDONLY);
    //open file2 in O_TRUNC | O_CREAT | O_WRONLY
    file2_fd = open(argv[argc - 1], O_TRUNC | O_WRONLY | O_CREAT, 0644);
    //make child processes
    //pipe each processes
    command_idx = make_command_process(argc - 2, file1_fd, file2_fd);
    //parse argv to pathname, file arguments
    //run commands
    execve(get_pathname(argv[command_idx], envp), \
    get_command_arg(argv[command_idx]), envp);
}