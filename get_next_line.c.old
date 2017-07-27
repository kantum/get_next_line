/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 18:29:06 by svigouro          #+#    #+#             */
/*   Updated: 2017/07/24 18:29:20 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft/includes/libft.h"
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static t_data	*data;
	char			*buff;
	int				read_check;
	char			*tmp_line;
	int				i;

	if (!line || fd < 0)
		return (-1);
	if (!data)
	{
		if (!(data = (t_data *)malloc(sizeof(t_data))))
			return (-1);
		data->save = NULL;
	}
	if (!(buff = (char *)malloc(sizeof(buff) * BUFF_SIZE + 1)))
		return (-1);
	ft_bzero(buff, BUFF_SIZE + 1);
	if (!*line)
		*line = ft_strnew(0);
	if (!(tmp_line = (char *)malloc(sizeof(tmp_line) * BUFF_SIZE + 1)))
		return (-1);
	if (data->save)
		*line = ft_strcpy(*line, data->save);
	else
		if (!(data->save = (char *)malloc(sizeof(data->save) * BUFF_SIZE + 1)))
			return (-1);
	ft_bzero(data->save, BUFF_SIZE + 1);
	while ((read_check = read(fd, buff, BUFF_SIZE)) > 0)
	{
		i = 0;
		if ((data->save = ft_memchr(buff, '\n', BUFF_SIZE)))
		{
			while (buff[i] != '\n')
			{
				tmp_line[i] = buff[i];
				i++;
			}
			tmp_line[i] = '\0';
			*line = ft_strjoin(*line, tmp_line);
			ft_bzero(tmp_line, BUFF_SIZE + 1);
			free(tmp_line);
			free(buff);
			return (1);
		}
		while (buff[i])
		{
			tmp_line[i] = buff[i];
			i++;
		}
		tmp_line[i] = '\0';
		*line = ft_strjoin(*line, tmp_line);
		ft_bzero(buff, BUFF_SIZE + 1);
		ft_bzero(tmp_line, BUFF_SIZE + 1);
	}
	//free(data);
	free(tmp_line);
	free(buff);
	return (0);
}
