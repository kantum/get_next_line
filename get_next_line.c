/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:37:12 by svigouro          #+#    #+#             */
/*   Updated: 2017/06/07 10:38:24 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./libft/includes/libft.h"
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char	*rest;
	int			i;

	if (fd < 0 || !line || (!rest && !(rest = ft_strnew(BUFF_SIZE))))
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	while ((i = read(fd, *line, BUFF_SIZE)) > 0)
	{

	}
	return (0);
}
