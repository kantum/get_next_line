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
	if (!(buff = (char *)malloc(sizeof(buff) * BUFF_SIZE + 1)))
		return (-1);
	if (!(data = (t_data *)malloc(sizeof(data))))
		return (-1);
	ft_bzero(buff, BUFF_SIZE + 1);
	*line = ft_strnew(0);
	if (!(tmp_line = (char *)malloc(sizeof(char *) * BUFF_SIZE + 1)))
		return (-1);
	if (data->save)
		*line = ft_strdup(data->save);
	else
		if (!(data->save = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
			return (-1);
	ft_bzero(data->save, BUFF_SIZE + 1);
	while ((read_check = read(fd, buff, BUFF_SIZE)) != 0)	
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
	}
	if (read_check == 0)
		free(data);
	free(tmp_line);
	free(buff);
	return (0);
}
