#include "get_next_line.h"








int get_next_line(int fd, char **line)
{
	static char *buff = NULL;
	int ret;
	static int curs = 0;
	int v_bool;
	int v_b_1;

	v_bool = 0;
	v_b_1 = 1;
	*line = NULL;
	if (read(fd, buff, 0) < 0 || fd < 0 || fd > 10240)
    	return (-1);
	if (!buff)
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));	
	if (!buff)
		return (-1);
	while (v_bool != 1)
	{
		if (curs == 0)
		{
			ret = read(fd, buff, BUFFER_SIZE);
			if (ret == 0)
			{
				free(buff);
				return (0);
			}
			if (ret == -1)
				return (-1);
			buff[ret + 1] = '\0';
		}
		if ((*line = ft_strjoin(*line, buff, &v_bool, &curs, &v_b_1)) == NULL)
			return (-1);
		if (curs == BUFFER_SIZE)
			curs = 0;
	}
	return (1);
}


// questions a elucider : free les lignes ?
// free le buff si ret = 0 ?
