/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:44:19 by vde-prad          #+#    #+#             */
/*   Updated: 2022/08/25 17:32:56 by vde-prad         ###   ########.fr       */
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
char	*ft_strdup(const char *s1)
{
	char			*cpy;	
	unsigned int	i;

	i = 1;
	while (s1[i - 1] != '\n' || s1[i - 1])
		i++;
	cpy = malloc(i * sizeof(char));
	if (cpy == 0)
		return (0);
	ft_memcpy(cpy, s1, size);
	return (cpy);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*gooddst;
	const char	*goodsrc;

	goodsrc = src;
	gooddst = dst;
	if (dst == src || !n)
		return (dst);
	while (n-- > 0)
	{
		*gooddst++ = *goodsrc++;
	}
	return (dst);
}
