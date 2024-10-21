#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <math.h>
# include "/home/ubuntu/Documents/FdF/minilibx-linux/mlx.h"
# include "/home/ubuntu/Documents/FdF/minilibx-linux/mlx_int.h"
# include "/home/ubuntu/Documents/FdF/libft/libft.h"
# include "/home/ubuntu/Documents/FdF/getnext/get_next_line.h"
# include "/home/ubuntu/Documents/FdF/ft_printf/ft_printf.h"

# define DEG_TO_RAD(angle_in_degrees) ((angle_in_degrees) * M_PI / 180.0)

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 800

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int ***map_allocation(int length, int height);
int	ft_strlen3(const char *s);
int lenght_check(char *argv);
int height_check(char *argv);
int	ft_atoi2(char str);
int ***str_to_int (int length, int height, char *argv);
float ***new_map_allocation(int height, int length);
float ***two_d_map(int ***map, int height, int length);
int check_zoom(float ***map, int img_length, int img_height, char *argv);
int lenght_multiplier(float ***map, int map_lenght, char *argv);
int height_multiplier(float ***map, int map_height, char *argv);
int check_lenght_min(float ***map, char *argv);
int check_lenght_max(float ***map, char *argv);
int check_height_min(float ***map, char *argv);
int check_height_max(float ***map, char *argv);
float ***zoom_multiplier(float ***map, int zoom, char* argv);
float ***centralize_map(float ***map, int height, int lenght);
void draw_map(t_data img, float ***new_map,  int height, int length);
void draw_line(t_data *img, int x0, int y0, int x1, int y1, int color);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	arg_validity(char *argv);
void	free_str_array(char **array);
int	ft_strcmp(char *s1, char *s2);

#endif