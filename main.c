#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(int argc, char *argv[])
{
	int		fd;
	int		ret;
	char	*line[4096];
	
	(void)argc;
	ret = 1;
	fd = open(argv[1], O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, line);
		printf("%s\n", *line);
	}
	return (0);
}
