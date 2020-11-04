/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 02:02:12 by bmerchin          #+#    #+#             */
/*   Updated: 2020/11/04 02:02:50 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_struct
{
	char	buff[BUFFER_SIZE + 1];
	int		ret;
	int		curs;
}				t_struct;

int				get_next_line(int fd, char **line);
int				ft_strlen(char *str);
int				ft_strlenn(char *str);
char			*ft_strjoin(char *s1, char *s2, t_struct *data);

#endif
