/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:21:09 by vde-prad          #+#    #+#             */
/*   Updated: 2022/09/09 19:48:00 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
//********************** STANDARD LIBRARIES ***********************************
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
//************************** FUNCTIONS ****************************************
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char 	*get_next_line(int fd);
#endif
