/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:28:21 by svigouro          #+#    #+#             */
/*   Updated: 2017/12/11 12:28:24 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

/*
** Search for the file descriptor in the lst
** Create it if doesn't exist
** Add a new node if fd haven't been found in the lst
*/

static t_list	*ft_node(t_list **lst, int fd)
{
	t_list	*node;

	node = *lst;
	while (node)
	{
		if ((int)node->content_size == fd)
			return (node);
		node = node->next;
	}
	if (!(node = ft_lstnew("", 1)))
		return (NULL);
	node->content_size = fd;
	ft_lstadd(lst, node);
	return (node);
}

/*
** Read and join buf until it finds a '\n' or read returns 0
*/

char			*ft_read(char **buf, int fd, char *str)
{
	int		ret;
	char	rd[BUFF_SIZE + 1];
	char	*free_str;

	while ((ret = read(fd, rd, BUFF_SIZE)))
	{
		rd[ret] = '\0';
		free_str = *buf;
		if (!(*buf = ft_strjoin(*buf, rd)))
			return (NULL);
		free(free_str);
		if ((str = ft_strchr(*buf, '\n')))
			return (str);
	}
	return (0);
}

/*
** This function verify if conditions are ok, set the pointer to '\n'
** call ft_read or split the buffer if necessary
*/

int				get_next_line(const int fd, char **line)
{
	char			*str;
	static t_list	*lst;
	t_list			*node;
	char			*free_str;

	if (!(node = ft_node(&lst, fd)) || fd > 10240 || fd < 0 ||
			line == NULL || read(fd, node->content, 0) < 0)
		return (-1);
	str = ft_strchr(node->content, '\n');
	if (!str)
		str = ft_read((char **)&node->content, fd, str);
	if (str)
	{
		*str = '\0';
		*line = ft_strdup((char *)node->content);
		free_str = node->content;
		node->content = ft_strdup(str + 1);
		free(free_str);
		return (1);
	}
	*line = ft_strdup(node->content);
	node->content = ft_strdup("\0");
	return ((**line) ? 1 : 0);
}
