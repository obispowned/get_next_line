/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:50:18 by agutierr          #+#    #+#             */
/*   Updated: 2020/01/24 13:16:38 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int			main(void)
{
	int 	i;
	int 	fd;
	char 	*line;
	int 	pruebas;

		fd = open ("jajaja.txt", O_RDONLY);
		printf("fd1 = %d\n\n\n", fd);
		while ((pruebas = get_next_line(fd, &line)) == 1)
		{
			printf("get next line: %d  - linea: %s\n", pruebas, line);
			free (line);
		}
		close(fd);
		printf("get next line: %d  - linea: %s\n", pruebas, line);
		system("leaks a.out");
}
