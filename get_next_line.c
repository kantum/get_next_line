/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:37:12 by svigouro          #+#    #+#             */
/*   Updated: 2017/07/13 14:08:58 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./libft/includes/libft.h"
#include "get_next_line.h"

int		ft_realloc_rest(char **rest)
{
	char	*swap;

	if (!(swap = ft_strnew(ft_strlen(*rest))))
		return (0);
	ft_strcpy(swap, *rest);
	*rest = NULL;
	if (!(*rest = ft_strnew(ft_strlen(swap) + BUFF_SIZE)))
		return (0);
	ft_strcpy(*rest, swap);
	return (1);
}

int		ft_write_line(int j, char **rest, char **line)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (j != 0 || ft_strlen(*rest) != 0)
	{
		while (*rest[i] != '\n')
		{
			*line[i] = *rest[i];
			i++;
		}
		*line[i++] = '\0';
		if (*rest[0] == '\n')
		{
			while (*rest[i])
				*rest[y++] = *rest[i++];
			*rest[y] = '\0';
			return (0);
		}
		while (*rest[i])
			*rest[y++] = *rest[i++];
		*rest[y] = '\0';
	}
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
		if (!(ft_realloc_rest(&rest)))
			return (-1);
		ft_strncat(rest, *line, BUFF_SIZE);
		if (ft_memchr(*line, '\n', BUFF_SIZE))
			break ;
	}
	if ((ft_write_line(i, &rest, &(*line)) == 0))
		return (1);
	if (ft_memcmp(*line, rest, ft_strlen(*line)) == 0)
	{
		if (!(*line = ft_strdup("")))
			return (1);
		return (0);
	}
	return (0);
}

