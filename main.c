#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include <stdlib.h>

int		main()
{
	int		fd;
	char	**line = NULL;

	*line = (char *)malloc(sizeof (*line) * 4096);
	line = (char **)malloc(sizeof (line) * 4096);

	fd = open("./test", O_RDWR);
	get_next_line(fd, line);
	printf("%s\n", *line);
	return 0;
}
