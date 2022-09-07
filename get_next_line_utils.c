/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:44:19 by vde-prad          #+#    #+#             */
/*   Updated: 2022/09/07 14:42:21 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
/*
int	ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == (unsigned char)c || *s == 0)
			return (1);
		s++;
		if (*s == (unsigned char)c || *s == 0)
			return (1);
	}
	return (0);
}
*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != 0)
	{
		len++;
		s++;
	}
	return (len);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	size_t			size;
	unsigned int	i;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
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
	char	*cpy;
	size_t	size;

	size = 0;
	while (s1[size] && s1[size] != '\n' )
		size++;
	
	cpy = malloc((++size) * sizeof(char));
	if (cpy == 0)
		return (0);
	ft_memcpy(cpy, s1, size);
	return (cpy);
}

char	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*gooddst;
	const char	*goodsrc;

	goodsrc = src;
	gooddst = dst;
	if (dst == src || !n)
		return (dst);
	while (n-- > 0)
		*gooddst++ = *goodsrc++;
	return (dst);
}

