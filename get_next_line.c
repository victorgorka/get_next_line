/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:01:33 by vde-prad          #+#    #+#             */
/*   Updated: 2022/09/08 18:45:03 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
//Recibe el buffer y copia todos los caracteres despues del primer salto de
//linea y lo devuelve con reserva de memoria
void	ft_save_chars(char **buff)
{
	char			*temp;
	unsigned int	i;

	temp = *buff;
	i = 0;
	while ((*buff)[i] != '\n' && (*buff)[i])
		i++;
	if ((*buff)[i] == '\n')
		i++;
	*buff = ft_strdup((*buff) + i);
	free(temp);
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

	len = 1;
	while (len != 0)
	{
		temp = *buff;
		len = read(fd, got, BUFFER_SIZE);
		if (len == -1 || len == 0)
			return ;
		*buff = ft_strjoin(*buff, got);
		free(temp);
	}
}

char 	*get_next_line(int fd)
{
	char		*line;
	static char	*buff;

	if (buff == 0)
	{
		buff = malloc(sizeof(char));
		buff[0] = '\0';
	}
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_fd(fd, &buff);
	printf("%s\n////////////////////////\n", buff);
	if(!buff)
		return (NULL);
	line = ft_get_line(buff);
	ft_save_chars(&buff);
	if (*line == 0)
		return (NULL);
	return (line);
}
// int main()
// {
//     char	*line;
// 
//     line = malloc(50);
//     ft_memcpy(line, "Hola\nmundo\nardiente", 20);
// 
//     ft_save_chars(&line);
//     puts(line);
//     free(line);
//     return (0);
// }

int	main()
{
	int 	fd;
	char	*line;
	// int		i;
	
	line = malloc(1);
	line[0] = 0;
	// i = 0;
	//	We open the file and assign the returned file descriptor
	//	to the fd variable in order to use it later:
	fd = open("text.txt", O_RDONLY);
	//	Was correctly open?
	// if(fd == -1)
	//     return (-1);
	// while (i < 10)
	// {
	//     i++;
	//     line = get_next_line(fd);
	//     // printf("%s", line);
	//     free(line);
	// }
	//	Close the file

	ft_read_fd(fd, &line); 
	puts(line);
	close(fd);

	return (0);
}
