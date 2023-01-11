NAME = so_long

SRC=  ft_printf.c get_next_line.c moves.c check.c ft_split.c get_next_line_utils.c print_errs.c check_utils.c game_display.c so_long.c player_move.c

OBJ= $(SRC:.c=.o)

CC = cc

CFLAGS=  -Wall -Wextra -Werror 

MLX = -lmlx -framework OpenGL -framework AppKit

$(RM) = rm -f 
  
all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(MLX) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all