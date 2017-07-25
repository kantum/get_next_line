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

	if (!line || fd < 0)
		return (-1);
	if (!(buff = (char *)malloc(sizeof(buff) * BUFF_SIZE + 1)))
		return (-1);
	if (!(data = (t_data *)malloc(sizeof(data))))
		return (-1);
	ft_bzero(buff, BUFF_SIZE + 1);
	while ((read_check = read(fd, buff, BUFF_SIZE)) != 0)	
	{
		if ((data->save = ft_memchr(buff, '\n', BUFF_SIZE)))
		{
			if (!(tmp_line = (char *)malloc(sizeof(char *) * BUFF_SIZE + 1)))
				return (-1);
			while (*buff != '\n')
			{
			}
		}
	}
	return (0);
}
