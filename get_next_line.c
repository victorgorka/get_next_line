/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:01:33 by vde-prad          #+#    #+#             */
/*   Updated: 2022/09/01 19:27:37 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_save_chars(const char *buff)
{
	unsigned int	before;
	unsigned int	after;
	unsigned int	i;
	char			*saved;

	before = 0;
	after = 0;
	i = 0;
	while (*buff != '\n' && *buff)
		buff++;
	if (*buff == '\n')
		buff++;
	while (buff[after])
		after++;
	saved = ft_strdup(buff);
	return (saved);
}

char	*ft_get_line(char *buff)
{
	char	*line;

	line = ft_strdup(buff);
	return (line);
}

void	ft_read_fd(int fd, char **buff)
{
	char	got[BUFFER_SIZE];
	char 	*temp;
	int 	len;
	
	temp = *buff;
	len = 0;
	while (!ft_strchr(*buff, '\n'))
	{
		len = read(fd, got, BUFFER_SIZE);
		if (len == -1)
		{
			free(buff);
			exit(0);
		}
		*buff = ft_strjoin(*buff, got);
		free(temp);
	}
}

char 	*get_next_line(int fd)
{
	char		*line;
	static char	*buff;

	*buff = "";
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_fd(fd, &buff);
	if(!buff)
		return (NULL);
	line = ft_get_line(buff);
	buff = ft_save_chars(buff);
	if (*line == 0 || *line == "")
		return (NULL);
	return (line);
}
/*
int main()
{
	char *line = "Hola\n mundo";

	line = ft_save_chars(line);
	puts(line);
	free(line);
	return (0);
}
*/

int	main(void)
{
	int fd;

//	We open the file and assign the returned file descriptor
//	to the fd variable in order to use it later:
	fd = open("text.txt", O_READONLY);
//	Was correctly open?
	if(fd == -1)
		return (-1);
//	Close the file
	close(fd);

	return (0);
}
