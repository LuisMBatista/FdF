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

CFLAGS = -g3 -Wall -Wextra -Werror\
         -I$(MLX_DIR) \
         -I$(FT_PRINTF_DIR) \
         -I$(FT_GET_NEXT_LINE_DIR) \
         -I$(FT_LIBFT_DIR)

LDFLAGS = $(MLX) $(FT_PRINTF) $(FT_GET_NEXT_LINE) $(FT_LIBFT)

SRC_DIR = src
OBJ_DIR = obj
SRC = 3d_to_2d.c allocation_img.c allocations.c draw.c \
      file_validation.c key_presses.c limits_checks.c main.c \
      map_limits.c mlx_activity.c parcing_components.c parcing.c \
      support.c zooms.c
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
