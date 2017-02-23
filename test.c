#include <stdio.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*lines[256];
	int		fd;
	int		file;
	int		res;
	int		num;

	res = 0;
	num = 0;
	file = 1;
	while (file <= ac && (fd = open(av[file++], O_RDONLY)))
	{	
		while ((res = get_next_line(fd, lines)))
		{
			printf("[Ret: %d, # of Line: %d, FD: %d] %s\n", res, ++num, fd, lines[fd]);
			free(lines[fd]);
		}
		fd++;
	}
	if ((fd > 0 && (close(fd) == -1 || res != 0)) || fd < 0)
	{
		if (!(*(lines)))
			write(1, "error\n", 6);
		return (1);
	}
	printf ("/* Ret == 1 ; read line\n   Ret == 0 ; end of line(finish) */\n");
	return (0);
}
