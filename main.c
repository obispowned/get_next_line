/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:50:18 by agutierr          #+#    #+#             */
/*   Updated: 2020/01/17 17:21:55 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			main(int argc, char **argv)
{
	int 	i;
	int 	fd;
	char 	*line;
	int 	pruebas;

	if (argc >= 2)
	{
		i = 0;
		fd = open (argv[1], O_RDONLY);
		printf("fd1 = %d\n\n\n", fd);
		while ((pruebas = get_next_line(fd, &line)) == 1)
			printf("get next line: %d  - linea: %s\n", pruebas, line);
		close(fd);
		printf("get next line: %d  - linea: %s\n", pruebas, line);
	}
	return (0);
}
