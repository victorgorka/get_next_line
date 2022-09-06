/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:01:33 by vde-prad          #+#    #+#             */
/*   Updated: 2022/09/06 14:13:47 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
//Recibe el buffer y copia todos los caracteres despues del primer salto de
//linea y lo devuelve con reserva de memoria
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
/*
   char	*ft_get_line(char *buff)
   {
   char	*line;

   line = ft_strdup(buff);
   return (line);
   }
   */
//Funcion que lee el fichero tantas veces que sea necesario hasta encontrar un
//salto de linea con reserva de memoria
void	ft_read_fd(int fd, char **buff)
{
	char	got[BUFFER_SIZE];
	char 	*temp;
	int 	len;
	int		found;

	found = 0;
	len = 0;
	puts("read 1");
	while (found != 1)
	{
		temp = *buff;
		puts("read 2");
		len = read(fd, got, BUFFER_SIZE);
		printf("%d\n", len);
		if (len == -1)
		{	
			puts("read 3");
			return ;
		}
		puts(*buff);
		*buff = ft_strjoin(*buff, got);
		puts(*buff);
		found = ft_strchr(*buff, '\n');
		free(temp);
	}
}

char 	*get_next_line(int fd)
{
	char		*line;
	static char	*buff;

	buff = "1";
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	puts("get_next 1");
	ft_read_fd(fd, &buff);
	puts("get_next 2");
	if(!buff)
		return (NULL);
	puts("get_next 3");
	line = ft_strdup(buff);
	buff = ft_save_chars(buff);
	if (*line == 0)
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
	int 	fd;
	char	*line;
	int		i;

	i = 0;
	//	We open the file and assign the returned file descriptor
	//	to the fd variable in order to use it later:
	fd = open("text.txt", O_RDONLY);
	//	Was correctly open?
	if(fd == -1)
		return (-1);
	while (i != 2)
	{
		i++;
		line = get_next_line(fd);
		puts(line);
	}
	free(line);
	//	Close the file
	close(fd);

	return (0);
}
