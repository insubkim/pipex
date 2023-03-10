/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:13:04 by inskim            #+#    #+#             */
/*   Updated: 2022/12/23 15:37:07 by inskim           ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*p;
	int		i;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (0);
	i = 0;
	if (!s1 || !s2)
		return (0);
	while (*s1)
		p[i++] = *s1++;
	while (*s2)
		p[i++] = *s2++;
	p[i] = 0;
	return (p);
}

char	*pipex_strjoin(char *s1, char *s2)
{
	int		len;
	char	*p;
	int		i;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len + 2));
	if (!p)
		handle_error();
	i = 0;
	if (!s1 || !s2)
		return (0);
	while (*s1)
		p[i++] = *s1++;
	p[i++] = '/';
	while (*s2)
		p[i++] = *s2++;
	p[i] = 0;
	return (p);
}
