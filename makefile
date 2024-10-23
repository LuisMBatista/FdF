# Variables
NAME = fdf
CC = cc

# Library Directories
MLX_DIR = ./minilibx-linux
FT_PRINTF_DIR = ./ft_printf
FT_GET_NEXT_LINE_DIR = ./getnext
FT_LIBFT_DIR = ./libft

# Libraries and Flags
MLX = -L$(MLX_DIR) -lmlx -lGL -lGLU -lX11 -lXext -lm  
FT_PRINTF = -L$(FT_PRINTF_DIR) -lftprintf
FT_GET_NEXT_LINE = -L$(FT_GET_NEXT_LINE_DIR) -lgetnext
FT_LIBFT = -L$(FT_LIBFT_DIR) -lft

CFLAGS = -g3 -Wall -Wextra -Werror \
         -I$(MLX_DIR) \
         -I$(FT_PRINTF_DIR) \
         -I$(FT_GET_NEXT_LINE_DIR) \
         -I$(FT_LIBFT_DIR)

LDFLAGS = $(MLX) $(FT_PRINTF) $(FT_GET_NEXT_LINE) $(FT_LIBFT)

SRC_DIR = src
OBJ_DIR = obj
SRC = parcing.c  3d_to_2d.c limits_checks.c allocations.c draw.c main.c \
	  key_presses.c file_validation.c 
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
