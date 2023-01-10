NAME = so_long
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra 
SRC = main.c get_next_line.c get_next_line_utils.c check.c ft_printf.c test.c ft_moves.c check_utils.c
all : 
	cc ${CFLAGS} -lmlx -framework OpenGL -framework AppKit ${SRC}