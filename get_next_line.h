/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:21:09 by vde-prad          #+#    #+#             */
/*   Updated: 2022/08/23 20:52:38 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
//********************** STANDARD LIBRARIES ***********************************
#include <unsitd.h>
#include <fcntl.h>
#include <stdlib.h>
//************************** FUNCTIONS ****************************************
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
#endif
