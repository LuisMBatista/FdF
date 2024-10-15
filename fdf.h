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

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int ***map_allocation(int length, int height);
int	ft_strlen3(const char *s);
int length_validation(void);
int height_check(void);
int	ft_atoi2(char str);
int ***str_to_int (int length, int height);
float ***new_map_allocation(int height, int length);
float ***two_d_map(int ***map, int height, int length);
void	his_mlx_pixel_put(t_data *data, int x, int y, int color);
float sin_adapted(int angle);
float cos_adapted(int angle);
int check_zoom(float ***map, int img_length, int img_height);
int lenght_multiplier(float ***map, int map_length);
int height_multiplier(float ***map, int map_height);
int check_length_min(float ***map);
int check_length_max(float ***map);
int check_height_min(float ***map);
int check_height_max(float ***map);
float ***zoom_multiplier(float ***map, int zoom);

#endif