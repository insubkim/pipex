/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/12/23 15:35:36 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

void	handle_error(void)
{
	perror("");
	exit(EXIT_FAILURE);
}

void	print_command_not_found(char *command)
{
	write(2, "bash: ", 6);
	write(2, command, ft_strlen(command));
	write(2, ": command not found\n", 20);
	exit (EXIT_FAILURE);
}

void	print_file_error(char *filename)
{
	write(2, "bash: ", 6);
	write(2, filename, ft_strlen(filename));
	write(2, ": ", 2);
	perror("");
}
