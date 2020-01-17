/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 21:08:24 by agutierr          #+#    #+#             */
/*   Updated: 2020/01/17 17:31:54 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen2(char *str)
{
	unsigned int	i;

	i = 0;
	while(str[i] != '\n')
		i++;
	return (i);
}

void			destroy(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

char 		*feed(char *aux, char **line, int *len)
{
	int		i;
	char	*temp;

	i = 0;
	while (aux[i] != '\n' && aux[i] != '\0')
		i++;
	if (aux[i] == '\n')
	{
		*line = ft_substr(aux, 0, i);
		temp = ft_substr(aux, i+1, ft_strlen(aux)-i);
		destroy (&aux);
		aux = ft_strdup(temp);
		destroy (&temp);
		*len = 1;
	}
	else
	{
		*line = aux;
		destroy (&aux);
		*len = 0;
	}
	return (aux);
}

int				get_next_line(int fd, char **line)
{
	int			len; 		// bytes leidos | 0 fin de fichero | -1 error.
	char		*buff;		// aqui guarda lo que va leyendo
	static char	*aux[4096]; // variable estatica que usaremos como aux.
	char		*temp;

	buff = malloc(BUFFER_SIZE + 1);
	if (fd < 0 || !line || !buff || BUFFER_SIZE < 1)
		return (-1);
	while ((len = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		printf("bytes leidos en esta lectura: %d\n", len);
		buff[len] = '\0';
		if (!aux[fd])        // si esta libre el aux
		{
			aux[fd] = ft_strdup(buff); // añadimos lo leido
			destroy(&buff);
		}
		else
		{
			temp = ft_strjoin(aux[fd], buff);
			destroy (&aux[fd]);
			aux[fd] = ft_strdup(temp);
			destroy (&temp);
		}
		if (ft_strchr(aux[fd], '\n'))  //movemos puntero hasta \n
			break;
	}
	destroy (&buff);				// liberamos y ponemos a null buff
	if (len < 0)
		return (-1);
	else if (len == 0 && aux[fd] == 0)		// si hemos terminado de leer rt 0
	{									// y devolvemos linea vacía.
		*line = ft_strdup("");
		return (0);
	}
	aux[fd] = feed(aux[fd], line, &len);
	return (len);
}
