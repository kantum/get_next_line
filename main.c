/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 18:28:51 by svigouro          #+#    #+#             */
/*   Updated: 2017/07/24 18:30:07 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("./test", O_RDWR);
	get_next_line(fd, &line);
	printf("%s\n", line);
	close(fd);
	return (0);
}
