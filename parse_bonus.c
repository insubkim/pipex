/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/12/27 10:21:35 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**get_path_variable(char **envp)
{
	if (!envp)
		return (0);
	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
			return (ft_split(&((*envp)[5]), ':'));
		envp++;
	}
	return (0);
}

char	*get_file_name(char *command)
{
	int		len;
	char	*name;

	len = 0;
	while (command[len] && command[len] != ' ')
		len++;
	name = (char *)malloc(sizeof(char) * (len + 1));
	if (!name)
		handle_error();
	name[len] = 0;
	while (--len >= 0)
		name[len] = command[len];
	return (name);
}

int	is_pathname(char *commmand)
{
	if (!access((const char *)commmand, F_OK))
		return (1);
	return (0);
}

char	*get_pathname(char *command, char **envp)
{
	char	*pathname;
	int		i;

	envp = get_path_variable(envp);
	command = get_file_name(command);
	if (!envp)
		return (command);
	i = -1;
	while (envp[++i])
	{
		pathname = pipex_strjoin(envp[i], command);
		if (!pathname)
			handle_error();
		if (!access((const char *)pathname, F_OK))
			break ;
		free(pathname);
		pathname = 0;
	}
	free_string_arr(envp);
	if (pathname)
		return (pathname);
	else if (is_pathname(command))
		return (command);
	print_command_not_found(command);
	return (0);
}

char	*const	*get_command_arg(char *argv)
{
	return ((char *const *)pipex_split(argv));
}
