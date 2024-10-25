/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:48:51 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/24 18:29:36 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_horizontal_lines(t_data *img, float ***new_map, int y, int length)
{
	t_point		p1;
	t_point		p2;
	int			x;

	x = 0;
	while (x < length - 1)
	{
		p1.x = new_map[y][x][0];
		p1.y = new_map[y][x][1];
		p2.x = new_map[y][x + 1][0];
		p2.y = new_map[y][x + 1][1];
		draw_line(img, p1, p2, 0x00FF00);
		x++;
	}
}

void	draw_vertical_lines(t_data *img, float ***new_map, int x, int height)
{
	t_point		p1;
	t_point		p2;
	int			y;

	y = 0;
	while (y < height - 1)
	{
		p1.x = new_map[y][x][0];
		p1.y = new_map[y][x][1];
		p2.x = new_map[y + 1][x][0];
		p2.y = new_map[y + 1][x][1];
		draw_line(img, p1, p2, 0x00FF00);
		y++;
	}
}

void	draw_map(t_data img, float ***new_map, int height, int length)
{
	int		x;
	int		y;

	y = 0;
	while (y < height)
	{
		draw_horizontal_lines(&img, new_map, y, length);
		y++;
	}
	x = 0;
	while (x < length)
	{
		draw_vertical_lines(&img, new_map, x, height);
		x++;
	}
}

void	draw_line(t_data *img, t_point p0, t_point p1, int color)
{
	t_draw		draw;
	int			steps;
	t_increment	inc;
	float		x;
	float		y;

	draw.x_draw = p1.x - p0.x;
	draw.y_draw = p1.y - p0.y;
	steps = calculate_steps(draw.x_draw, draw.y_draw);
	inc = calculate_increments(draw.x_draw, draw.y_draw, steps);
	x = p0.x;
	y = p0.y;
	while (steps >= 0)
	{
		if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put(img, (int)x, (int)y, color);
		}
		x += inc.x_increment;
		y += inc.y_increment;
		steps--;
	}
}
