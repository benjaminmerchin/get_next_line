#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

int get_next_line(int fd, char **line)
{
	static t_struct data;

	*line = (char *)malloc(sizeof(char));
	*line[0] = '\0';
	if (/* il reste des char sur le buff et une newline*/)
		/*je renvoie strjoin de line et ce qu'il faut du buffer puis j'exit*/
	data->ret = read(fd, buff, BUFFER_SIZE);
	buff[data->ret] = '\0';
	while (ret > 0)
	{
		if (/* il y a une newline sur le buffer */)
			/*je renvoie strjoin de line et ce qu'il faut du buffer puis j'exit*/
		if (/* il reste des char dans le buffer */)
			/*je strjoin a mon line */
		data->ret = read(fd, buff, BUFFER_SIZE);
		buff[data->ret] = '\0';
	}
	return (0);
}
