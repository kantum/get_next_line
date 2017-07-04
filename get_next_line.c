/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:37:12 by svigouro          #+#    #+#             */
/*   Updated: 2017/07/04 11:34:41 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./libft/includes/libft.h"
#include "get_next_line.h"

int		ft_realloc_save(char **save)
{
	char	*swap;

	if (!(swap = ft_strnew(ft_strlen(*save))))
		return (0);
	ft_strcpy(swap, *save);
	*save = NULL;
	if (!(*save = ft_strnew(ft_strlen(swap) + BUFF_SIZE)))
		return (0);
	ft_strcpy(*save, swap);
	return (1);
}

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
		if (!(ft_realloc_save(&save)))
			return (-1);
		ft_strncat(save, *line, BUFF_SIZE);
		if (ft_memchr(*line, '\n', BUFF_SIZE))
			break ;
	}
	return (0);
}
