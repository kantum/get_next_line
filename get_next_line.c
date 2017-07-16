/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:37:12 by svigouro          #+#    #+#             */
/*   Updated: 2017/07/16 01:19:07 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/includes/libft.h"
#include "get_next_line.h"

int		check_fd(t_data *data, const int fd)
{
	if (data)
	{
		while (data)
		{
			if (data->fd == fd)
				return (1);
			data = data->nxt;
		}
	}
	return (0);
}

int		fill_line(char *buff, char *line, size_t size)
{
	if (!(line = (char *)malloc(ft_strlen(buff) - size + 1)))
		return (-1);
	while (*buff != '\n' && *buff && *line)
			*line++ = *buff++;
	*line++ = '\0';
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_data	*data;
	char			*buff;

	if (!line || fd < 0)
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char *) * BUFF_SIZE + 1)))
		return (-1);
	if (check_fd(data, fd) == 0)
	{
		data->fd = fd;
		while ((data->index = read(fd, buff, BUFF_SIZE)) > 0)
		{
			if ((data->save = (char *)ft_memchr(buff, '\n', BUFF_SIZE)) != NULL)
			{
				if ((fill_line(buff, *line, ft_strlen(data->save))) == -1)
					return (-1);
				return (1);
			}
		}
	}
	return (0);
}

