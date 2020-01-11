/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 21:10:47 by agutierr          #+#    #+#             */
/*   Updated: 2020/01/11 17:21:42 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (2000)
# endif

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

/**FUNCIONES A UTILIZAR**/

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, char c);
char	*ft_substr(char *s, unsigned int start, unsigned int len);
char	*ft_strjoin(char *s1, char *s2);

#endif