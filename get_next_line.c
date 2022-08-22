/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:01:33 by vde-prad          #+#    #+#             */
/*   Updated: 2022/08/22 19:00:52 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	*buff;
	
}


int	main(void)
{
	int fd;

//	We open the file and assign the returned file descriptor
//	to the fd variable in order to use it later:
	fd = open("", O_READONLY);
//	Was correctly open?
	if(fd == -1)
		return (-1);
//	Close the file
	close(fd);

	return (0);
}
