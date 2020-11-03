/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 03:32:36 by bmerchin          #+#    #+#             */
/*   Updated: 2020/11/03 22:13:39 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2, t_struct *data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlenn(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\n' && s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
		data->curs += 1;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

int get_next_line(int fd, char **line)
{
	static t_struct data;

	*line = (char *)malloc(sizeof(char));
	*line[0] = '\0';
	if (ft_strlen(data.buff + data.curs) != ft_strlenn(data.buff + data.curs))
	{
		/*je renvoie strjoin de line et ce qu'il faut du buffer puis j'exit*/
		*line = ft_strjoin(*line, data.buff + data.curs, &data);
		return (1);
	}
	/* on ne lit que si c'est le debut du fichier */
	if (data.ret == 0)
	{
		data.ret = read(fd, data.buff, BUFFER_SIZE);
		data.buff[data.ret] = '\0';
	}
//	printf("%s", data.buff);
//	printf("%d", data.ret);
	while (data.ret > 0)
	{
		if (/* il y a une newline sur le buffer */ft_strlen(data.buff + data.curs) != ft_strlenn(data.buff + data.curs))
		{
			/*je renvoie strjoin de line et ce qu'il faut du buffer puis j'exit*/
			*line = ft_strjoin(*line, data.buff + data.curs, &data);
			data.curs += 1;
			return (1);
		}
		if (/* il reste des char dans le buffer */data.curs < data.ret)
		{
			/*je strjoin a mon line */;
			*line = ft_strjoin(*line, data.buff + data.curs, &data);
		}
		data.ret = read(fd, data.buff, BUFFER_SIZE);
		data.buff[data.ret] = '\0';
		data.curs = 0;
//		printf("%s", data.buff);
	}
//	printf("%d\n", data.curs);
	return (0);
}
