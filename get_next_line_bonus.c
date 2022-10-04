/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:01:33 by vde-prad          #+#    #+#             */
/*   Updated: 2022/10/04 12:37:31 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
//Recibe el buffer y copia todos los caracteres despues del primer salto de
//linea y lo devuelve con reserva de memoria
void	ft_save_chars(char **buff, int len)
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
	if (!ft_strchr(*buff, '\n') && len == 0)
	{
		free(*buff);
		*buff = NULL;
	}
}

char	*ft_get_line(const char *s1)
{
	char	*cpy;
	size_t	size;

	size = 0;
	while (s1[size] && s1[size] != '\n' )
		size++;
	if (s1[size] == '\n')
		size++;
	cpy = malloc((size + 1) * sizeof(char));
	if (cpy == 0)
		return (0);
	ft_memcpy(cpy, s1, size);
	cpy[size] = '\0';
	if (*cpy == 0)
	{
		free(cpy);
		return (NULL);
	}
	return (cpy);
}
//Funcion que lee el fichero hasta que encuentre un salto de linea, modifica
//buff con las nuevas lecturas

int	ft_read_fd(int fd, char **buff)
{
	char	got[BUFFER_SIZE + 1];
	char	*temp;
	int		len;
	int		i;

	len = 1;
	i = 0;
	while (len > 0 && !ft_strchr(*buff, '\n'))
	{
		temp = *buff;
		len = read(fd, got, BUFFER_SIZE);
		if (len == -1 || len == 0)
			return (len);
		got[len] = '\0';
		*buff = ft_strjoin(*buff, got);
		while (i < BUFFER_SIZE)
			got[i++] = 0;
		i = 0;
		free(temp);
	}
	return (len);
}

char	*get_next_line(int fd)
{
	int			len;
	char		*line;
	static char	*buff[256];

	if (fd < 0 || fd > 255)
		return (0);
	if (buff[fd] == 0)
	{
		buff[fd] = malloc(sizeof(char));
		buff[fd][0] = '\0';
	}
	if (!ft_strchr(buff[fd], '\n'))
		len = ft_read_fd(fd, &buff[fd]);
	if (!buff[fd] || len == -1 || fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buff[fd]);
		buff[fd] = NULL;
		return (NULL);
	}
	line = ft_get_line(buff[fd]);
	ft_save_chars(&buff[fd], len);
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

// int main()
// {
//     int 	fd;
//     char	*line;
//     int		i;
// // 
//     i = 0;
//     //	We open the file and assign the returned file descriptor
//     //	to the fd variable in order to use it later:
//     fd = open("text.txt", O_RDONLY);
//     //	Was correctly open?
//     if(fd == -1)
//         return (-1);
//     while ((line = get_next_line(fd)))
//     {
//         printf("%s", line);
//         free(line);
//     }
//     //	Close the file
// // 
//     // ft_read_fd(fd, &line); 
//     // printf("%s",line);
//     close(fd);
// // 
//     return (0);
// }
