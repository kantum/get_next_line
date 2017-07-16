/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 10:37:12 by svigouro          #+#    #+#             */
/*   Updated: 2017/07/16 12:42:49 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/includes/libft.h"
#include "get_next_line.h"

int		fill_line(char *buff, char *line)
{
	if (!buff)
		return (0);
	if (!(line = (char *)malloc(sizeof(line) * BUFF_SIZE + 1)))
		return (0);
	while (buff && line && *buff != '\n')
		*buff++ = *line++;
	*line = '\0';
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_data	*data;
	char			*buff;
	int				read_check;

	if (!line || fd < 0)
		return (-1);
	if (!(buff = (char *)malloc(sizeof(buff) * BUFF_SIZE + 1)))
		return (-1);
	ft_bzero(buff, BUFF_SIZE + 1);
	if ((read_check = read(fd, buff, BUFF_SIZE)) < 0)	
		return (0);
	while (read_check > 0)
	{
		if ((data->save = ft_strchr(buff, '\n')))
		{
			if (!(fill_line(buff, *line)))
				return (-1);
			return (1);
		}
	}
	return (0);
}

