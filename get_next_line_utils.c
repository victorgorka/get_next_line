/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:44:19 by vde-prad          #+#    #+#             */
/*   Updated: 2022/08/23 10:55:27 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
		if (*s == (unsigned char)c)
			return ((char *)s);
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	size_t			size;
	unsigned int	i;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	size = 1;
	while(*s1)
		size++;
	while(*s2)
		size++;
	res = malloc(size * sizeof(char));
	if (res == 0)
		return (0);
	while (*s1 != 0)
		res[i++] = *s1++;
	while (*s2 != 0)
		res[i++] = *s2++;
	res[i] = 0;
	return (res);
}
