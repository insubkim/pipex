/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:08:10 by inskim            #+#    #+#             */
/*   Updated: 2022/12/27 10:11:48 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	cnt_word(char const *s)
{
	int	i;
	int	in_quote;
	int	flag;

	if (!s)
		return (0);
	i = 0 ;
	flag = 1;
	in_quote = 0;
	while (*s)
	{
		if (*s == ' ' || in_quote)
			flag = 1;
		else if (flag == 1)
		{
			i++;
			flag = 0;
		}
		if (*s == '\'' && in_quote)
			in_quote = 0;
		else if (*s == '\'' && !in_quote)
			in_quote = 1;
		s++;
	}
	return (i);
}

void	set_arr(char **arr, char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != ' ')
		{
			arr[i++] = s;
			if (*s == '\'')
			{
				arr[i - 1] = ++s;
				while (*s && *s != '\'')
					s++;
			}
			else
				while (*s && *s != ' ')
					s++;
			if (!*s)
				break ;
			*s = 0;
		}
		s++;
	}
	arr[i] = 0;
}

char	**pipex_split(char *s)
{
	int		cnt;
	char	**arr;

	cnt = cnt_word(s);
	arr = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!arr)
		return (0);
	set_arr(arr, s);
	return (arr);
}
