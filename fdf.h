/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:51:51 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/24 18:26:41 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define M_PI 3.14159265358979323846
#define FDF_H
#include <fcntl.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <math.h>
#include "mlx.h"
#include "mlx_int.h"
#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx_win;
	void	*mlx_connection;
	int		map_height;
	int		map_length;
}				t_data;

typedef struct s_point
{
    int x;
    int y;
} t_point;

typedef struct s_increment {
    float x_increment;
    float y_increment;
} t_increment;

typedef struct s_draw{
    float x_draw;
    float y_draw;
} t_draw;

t_data		*allocation_img(void);
int			***map_allocation(int length, int height);
int			ft_strlen3(const char *s);
int			lenght_check(char *argv);
int			height_check(char *argv);
int			***str_to_int(int length, int height, char *argv);
int			check_lenght_min(float ***map, t_data *img);
int			check_lenght_max(float ***map, t_data *img);
int			check_height_min(float ***map, t_data *img);
int			check_height_max(float ***map, t_data *img);
int			arg_validity(char *argv);
int			ft_strcmp(char *s1, char *s2);
int			key_press(int keycode, t_data *img);
int			base_value_central(int minimum);
int			close_window(t_data *img);
float		***new_map_allocation(int height, int length);
float		***two_d_map(int ***map, int height, int length);
float		check_zoom(float ***map, int img_length,
				int img_height, t_data *img);
float		lenght_multiplier(float ***map, int map_lenght, t_data *img);
float		height_multiplier(float ***map, int map_height, t_data *img);
float		***zoom_multiplier(float ***map, float zoom, t_data *img);
float		***centralize_map(float ***map, t_data *img);
void		draw_map(t_data img, float ***new_map, int height, int length);
void		draw_line(t_data *img, t_point p0, t_point p1, int color);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		free_str_array(char **array);
void		free_map_allocation(float ***map, int height, int lenght);
void		free_map(int ***map, int height, int lenght);
void		arg_validation(int argc, char **argv);
void		mlx_creation(t_data *img);
void		mlx_creation2(t_data *img);
void		read_and_fill_map(int fd, int ***map, int length, int height);
void		process_line(char *str, int ***map, int y, int length);
void		skip_comma(char *str, int *i);
void		skip_to_next_value(char *str, int *i);
void		draw_vertical_lines(t_data *img, float ***new_map, int x, int height);
void		draw_horizontal_lines(t_data *img, float ***new_map, int y, int length);
int	calculate_steps(int dx, int dy);
 t_increment	calculate_increments(int dx, int dy, int steps);

#endif
