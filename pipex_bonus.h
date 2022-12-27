/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/12/23 15:43:46 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_process_fd_info
{
	int	id;
	int	read_fd;
	int	write_fd;
}	t_process_fd_info;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		heredoc_pipe(int argc, char **argv, char **envp);
void		read_file_pipe(int argc, char **argv, char **envp);
char		*pipex_strjoin(char *s1, char *s2);
char		*get_pathname(char *command, char **envp);
char *const	*get_command_arg(char *argv);
char		**ft_split(char const *s, char c);
void		handle_error(void);
void		free_string_arr(char **arr);
int			make_process(int command_count, int file1_fd, int file2_fd);
void		print_command_not_found(char *command);
void		print_file_error(char *filename);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strjoin(char *s1, char *s2);
char		**pipex_split(char *s);

#endif
