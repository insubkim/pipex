/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:27:09 by inskim            #+#    #+#             */
/*   Updated: 2022/12/26 11:52:34 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 100

typedef struct s_list
{
	int				fd;
	char			*str;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*error_handle(t_list **lst, int fd, char *read_buf);
int		has_newline(t_list *lst, int fd);
int		ft_strlen(const char *s);
char	*gnl_strjoin(char *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, int len);
t_list	*get_node(t_list *lst, int fd);

#endif
