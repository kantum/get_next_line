#include <unistd.h>
#include "get_next_line.h"
#include "libft/includes/libft.h"

/** 
 * fill_line
 **/

int		ft_read(int fd, t_list buf, char **line)
{
	int		ret;
	char	*ptr;
	char	rd[BUFF_SIZE + 1];

	rd[BUFF_SIZE] = '\0';
	ptr = NULL;
	if (buf.content)
	{
		ptr = ft_strchr(buf.content, '\n');
		if (ptr)
		{
			*ptr = '\0';
			*line = ft_strsub(*line, 0, (ptr - (char *)buf.content));
		}
		else 
			*line = ft_strjoin(*line, (char *)buf.content);
	}
	while (!ptr && (ret = read(fd, rd, BUFF_SIZE)) > 0)
	{
		buf.content = ft_strjoin(buf.content, rd);
		ptr = ft_strchr(buf.content, '\n');
	}
	if (ptr && buf.content)
	{
		*ptr = '\0';
		*line = ft_strsub(buf.content, 0, (ptr - (char *)buf.content));
		if (ptr + 1)
			buf.content = ft_strdup(ptr + 1);
		return (1);
	}
	*line = ft_strdup(buf.content); //malloc de line 
	return(0);
}

int		get_next_line(const int fd, char **line)
{
	static char	**buf[FD_MAX];
	int			ret;

	if (fd < 0 || fd > FD_MAX)
		return (-1);
	if (!(buf[fd].content))
		buf[fd] = *ft_lstnew(ft_strnew(BUFF_SIZE), BUFF_SIZE); //malloc buf[].content
	ret = ft_read(fd, buf[fd], line);
	if (fd < 0 || ret < 0)
		return (-1);
	return (ret);
}
