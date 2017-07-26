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
#include "libft/includes/libft.h"

int		main(void)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open("./test2", O_RDWR);
	while((ret = get_next_line(fd, &line)) >= 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		ft_putnbr(ret);
		ft_putchar('\n');
	}
	close(fd);
	return (0);
}
