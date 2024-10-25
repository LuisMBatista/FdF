/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_to_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:03:02 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/25 08:11:51 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	***two_d_map(int ***map, int height, int lenght)
{
	float	***new_map;
	int		x;
	int		y;

	y = 0;
	new_map = new_map_allocation(height, lenght);
	while (y < height)
	{
		x = 0;
		while (x < lenght)
		{
			new_map[y][x][0] = (map[y][x][0] * cos(DEGREE))
				- (map[y][x][1] * cos(DEGREE));
			new_map[y][x][1] = (map[y][x][0] * sin(DEGREE))
				+ (map[y][x][1] * sin(DEGREE)) - (map[y][x][2]);
			x++;
		}
		y++;
	}
	free_map(map, height, lenght);
	return (new_map);
}

int	base_value_central( int minimum)
{
	int		x;

	x = 0;
	while (minimum++ <= 0)
		x++;
	return (x);
}

float	***centralize_map(float ***map, t_data *img)
{
	int		x;
	int		y;
	int		lenght_min;
	int		height_min;

	y = 0;
	lenght_min = base_value_central(check_lenght_min(map, img));
	height_min = base_value_central(check_height_min(map, img));
	while (y < img->map_height)
	{
		x = 0;
		while (x < img->map_length)
		{
			map[y][x][0] = map[y][x][0] + (lenght_min + 10);
			map[y][x][1] = map[y][x][1] + (height_min + 10);
			x++;
		}
		y++;
	}
	return (map);
}
