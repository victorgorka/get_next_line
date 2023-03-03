/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:56:03 by vde-prad          #+#    #+#             */
/*   Updated: 2023/03/03 15:17:00 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
//********************** STANDARD LIBRARIES ***********************************
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
//**************************** MACROS *****************************************
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
//************************** FUNCTIONS ****************************************

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	ft_save_chars(char **buff, int len);
char	*ft_get_line(const char *s1);
int		ft_read_fd(int fd, char **buff);
char	*get_next_line(int fd);
#endif
