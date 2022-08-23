/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:01:33 by vde-prad          #+#    #+#             */
/*   Updated: 2022/08/23 20:52:34 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char *get_next_line(int fd)
{
	char		*buff;
	static char	*saved;
	
	(!fd || !BUFFER_SIZE) ? return NULL : ;
	buff = malloc(BUFFER_SIZE*sizeof(char));
	
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
