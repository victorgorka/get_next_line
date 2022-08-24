/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:01:33 by vde-prad          #+#    #+#             */
/*   Updated: 2022/08/23 21:27:12 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_read_fd(int fd, char *buff)
{
	char	*read;
	int 	len;

	len = 0;
	while(!ft_strchr(buff, '\n'))
	{
		len = read(fd, read, BUFFER_SIZE);
		if (len == -1)
		{
			free(buff);
			free(read);
			return NULL;		
		}	
	}
	ft_strjoin(buff, read);
	return buff;
}

char 	*get_next_line(int fd)
{
	char		*line;
	static char	*buff;
	
	(fd <= 0 || BUFFER_SIZE <= 0) ? return NULL : ;
	buff = ft_read_fd(fd, buff);
	line = ft_get_line(buff);
	buff = ft_get_leftchars(buff);
	if (*line == 0 || *line =="")
		return NULL;
	return line;
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
