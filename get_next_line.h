#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int get_next_line(int fd, char **line);
int ft_strlen(char *str);
char *ft_strjoin(char *s1, char *s2, int *v_bool, int *curs, int *v_b_1);

#endif
