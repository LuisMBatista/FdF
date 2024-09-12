# Variables
NAME = fdf
CC = cc
MLX_DIR = /home/ubuntu/Documents/FdF/minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lGL -lGLU -lX11
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lmlx -lGL -lGLU -lX11
SRC_DIR = src
OBJ_DIR = obj
SRC = main.c 
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all