#include "get_next_line.h"




int main(int ac, char **av)
{
	int fd;
	int i;
	int retour;
	char *line;

	i = 0;
	(void)av;
	line = NULL;
	if (ac != 2)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		write(2, "OpenError\n", 10);
		return (0);
	}
	while (i++ < 30)
	{
		if ((retour = get_next_line(fd, &line)) == 0)
			break ;
		printf("%s\n", line);
		free(line);
	//	printf("---------------\n");
	}
//	printf("%d\n%s\n", retour, *line);
	return (0);
}
