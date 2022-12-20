/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/12/20 14:23:22 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    //if (argc < 5)
      //  return (1);
    if (!ft_strncmp((++argv)[0], "heredoc", 7) && !argv[0][7])
        heredoc_pipe(--argc, argv, envp);
    else
        read_file_pipe(--argc, argv, envp);
    return (0);
}