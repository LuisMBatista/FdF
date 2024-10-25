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
SRC = $(SRC_DIR)/3d_to_2d.c $(SRC_DIR)/allocation_img.c $(SRC_DIR)/allocations.c $(SRC_DIR)/draw.c \
      $(SRC_DIR)/file_validation.c $(SRC_DIR)/key_presses.c $(SRC_DIR)/limits_checks.c $(SRC_DIR)/main.c \
      $(SRC_DIR)/map_limits.c $(SRC_DIR)/mlx_activity.c $(SRC_DIR)/parcing_components.c $(SRC_DIR)/parcing.c \
      $(SRC_DIR)/support.c $(SRC_DIR)/zooms.c
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
