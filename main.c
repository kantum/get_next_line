#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include <stdlib.h>

int		main(void)
{
	int		fd;
	char	**line;

	fd = open("./test", O_RDWR);
	get_next_line(fd, line);
	printf("%s\n", *line);
	return 0;
}