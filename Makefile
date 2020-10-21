NAME	=	gnl
CC		=	gcc
OBJ		=	get_next_line.c get_next_line_utils.c
COMP 	=	$(OBJ:.c=.o)
BUFFER	=	-D BUFFER_SIZE=10
CFLAGS	=	-Wall -Wextra -Werror $(BUFFER)
HEADERS	=	includes

all: $(NAME)

$(NAME): $(COMP)
	$(CC) -o $@ $(COMP)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(HEADERS)

clean:
	rm -f $(COMP)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re test
