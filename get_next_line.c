/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:01:33 by vde-prad          #+#    #+#             */
/*   Updated: 2022/09/09 19:00:50 by vde-prad         ###   ########.fr       */
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

char	*ft_get_line(const char *s1)
{
	char	*cpy;
	size_t	size;

	size = 0;
	while (s1[size] && s1[size] != '\n' )
		size++;
	cpy = malloc((size + 2) * sizeof(char));
	if (cpy == 0)
		return (0);
	ft_memcpy(cpy, s1, ++size);
	cpy[size] = '\0';
	return (cpy);
}
//Funcion que lee el fichero tantas veces que sea necesario hasta encontrar un
//salto de linea con reserva de memoria

void	ft_read_fd(int fd, char **buff)
{
	char	got[BUFFER_SIZE + 1];
	char	*temp;
	int		len;
	int		i;

	len = 1;
	i = 0;
	while (len != 0 && !ft_strchr(*buff, '\n'))
	{
		temp = *buff;
		len = read(fd, got, BUFFER_SIZE);
		got[BUFFER_SIZE] = '\0';
		if (len == -1 || len == 0)
			return ;
		*buff = ft_strjoin(*buff, got);
		while (i < BUFFER_SIZE)
			got[i++] = 0;
		i = 0;
		free(temp);
	}
}

char	*get_next_line(int fd)
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
	if (!ft_strchr(buff, '\n'))
		ft_read_fd(fd, &buff);
	if (!buff)
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

//int main()
//{
	//int 	fd;
	//char	*line;
	//int		i;

	//line = malloc(1);
	//line[0] = 0;
	//i = 0;
	////	We open the file and assign the returned file descriptor
	////	to the fd variable in order to use it later:
	//fd = open("text.txt", O_RDONLY);
	////	Was correctly open?
	//if(fd == -1)
		//return (-1);
	//while (i < 16)
	//{
		//i++;
		//line = get_next_line(fd);
		//printf("%s", line);
		//free(line);
	//}
	////	Close the file

	//ft_read_fd(fd, &line); 
	//// printf("%s",line);
	//close(fd);

	//return (0);
//}
