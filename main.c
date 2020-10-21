#include "get_next_line.h"




int main(int ac, char **av)
{
	int fd;
	int i;
	int retour;
	char **line;

	i = 0;
	if (ac != 2)
		return (0);
	fd = open(av[1]);
	retour = get_next_line(fd, line);
	printf("%d\n%s\n", retour, *line);
	return (0);
}
