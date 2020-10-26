#include "get_next_line.h"

char    *ft_strjoin(char *s1, char *s2, int *v_bool, int *curs, int *v_b_1, int *ret)
{
    int i;
	int j;
    char *str;

    i = 0;
	j = 0;
	(void)ret;  // remove
    if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2 + *curs) + 1))))
        return (NULL);
    while (s1 && s1[i] && *v_b_1 == 0)
    {
        str[i] = s1[i];
        i++;
    }
    while (*curs < BUFFER_SIZE/* && *curs <= *ret*/)
    {
        str[i + j] = s2[*curs];
		j++;
//		write(1, "u", 1);
        *curs = *curs + 1;
//		printf("curs:%d  i:%d  j:%d  ret:%d  buff:%d\n", *curs, i, j, *ret, BUFFER_SIZE);
		if (s2[*curs - 1] == '\n')
        {
            *v_bool = 1;
            break ;
        }
		if (*curs - 2 == *ret)
		{
			*v_bool = 1;
			j--;
			break ;
		}
    }
    str[i + j - *v_bool] = '\0';
	*v_b_1 = 0;
    if (s1)
        free(s1);
    return (str);
}

int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}
