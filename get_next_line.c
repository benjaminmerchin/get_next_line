#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char *buff;
	int ret;
	int i;

	i = 0;
	buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
	
	ret = read(fd, buff, BUFF_SIZE);
	buff[ret + 1] = '\0';
	
	
	







}
