NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRCS =	*.c 
OBJS = $(SRCS:.c=.o)
LIBFT = ../libft/libft.a
FT_PRINTF = ../ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/home/quack/Documents/FdF/mlx_linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/home/quack/Documents/FdF/FdF -Imlx_linux -O3 -c $< -o $@

$(LIBFT):
	@make -C ../libft

$(FT_PRINTF):
	@make -C ../ft_printf

clean:
	@make -C ../libft clean
	@make -C ../ft_printf clean
	rm -f $(OBJS)

fclean: clean
	@make -C ../libft fclean
	@make -C ../ft_printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
