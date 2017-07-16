/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:47:12 by svigouro          #+#    #+#             */
/*   Updated: 2017/07/16 01:28:43 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32


typedef struct	s_data
{
	const int		fd;
	int				index;
	char			*save;
	struct s_data	*nxt;
}				t_data;

int				get_next_line(const int fd, char **line);
#endif
