#include "get_next_line_bonus.h"

int ft_strlennn(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_putstr(char *str)
{
	write(1, str, ft_strlennn(str));
	write(1, "\n", 1);
}

int main(int ac, char **av)
{
	int fd;
	int i;
	int retour;
	char *line;

	if (ac != 3)
	{
		ft_putstr(" Merci de mettre 2 fichiers en entree");
		return (0);
	}
	i = 0;
	line = NULL;
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		write(2, "OpenError\n", 10);
		return (0);
	}
	while ((retour = get_next_line(fd, &line)) == 1)
	{
		ft_putstr(line);
		free(line);
		i++;
		/*if (i == 10)
			break ;*/
//		write(1, "1", 1);
	}
	if (line[0] != 0)
	{
		ft_putstr(line);
		free(line);
	}


	i = 0;
	line = NULL;
	if ((fd = open(av[2], O_RDONLY)) < 0)
	{
		write(2, "OpenError\n", 10);
		return (0);
	}
	while ((retour = get_next_line(fd, &line)) == 1)
	{
		ft_putstr(line);
		free(line);
		i++;
		/*if (i == 10)
			break ;*/
//		write(1, "1", 1);
	}
	if (line[0] != 0)
	{
		ft_putstr(line);
		free(line);
	}
	return (0);
}
