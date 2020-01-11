/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 21:10:10 by agutierr          #+#    #+#             */
/*   Updated: 2020/01/11 16:47:31 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlen(char *s) //CONTAR CHARS DE UN STRING
{
	unsigned	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char				*ft_strdup(char *s1) //COPIO UN STRING EN OTRO CON RESERVA DE MEMORIA
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (s1[size])
		++size;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char				*ft_strchr(char *s, char c) //MUEVE EL PUNTERO HASTA EL SIGUIENTE CHAR 'c'
{
	while (*s && *s != c)
		s++;
	return ((*s == c) ? s : NULL);
}

char				*ft_strjoin(char *s1, char *s2) //CONCATENAMOS DOS STRING CON MALLOC
{
	char			*dest;
	size_t			size1;
	size_t			size2;
	size_t			i;

	if (!(s1 && s2))
		return (0);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(dest = (char *)malloc(sizeof(char) * (size1 + size2 + 1))))
		return (0);
	i = 0;
	while (i < size1)
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < size2)
	{
		dest[size1 + i] = s2[i];
		i++;
	}
	dest[size1 + size2] = 0;
	return (dest);
}

char				*ft_substr(char *s, unsigned int start, unsigned int len)
{
	char			*dest;
	unsigned int	i;
	unsigned int	total;
	unsigned int	lenglo;

	lenglo = ft_strlen(s);
	if (start > lenglo)
		return (ft_strdup(""));
	i = 0;
	total = start + len;
	if (len < (lenglo - start))
		dest = (char*)malloc(sizeof(char) * (len + 1));
	else
		dest = (char*)malloc(sizeof(char) * (lenglo - start + 1));
	if (!dest)
		return (NULL);
	while (start < total)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
