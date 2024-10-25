/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:14:46 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/24 16:51:30 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	check_zoom(float ***map, int img_lenght, int img_height, t_data *img)
{
	float	lenght;
	float	height;

	lenght = lenght_multiplier(map, img_lenght, img);
	height = height_multiplier(map, img_height, img);
	if (lenght <= height)
		return (lenght);
	return (height);
}

float	***zoom_multiplier(float ***map, float zoom, t_data *img)
{
	int		y;
	int		x;

	y = 0;
	while (y < img->map_height)
	{
		x = 0;
		while (x < img->map_length)
		{
			map[y][x][0] = map[y][x][0] * (zoom - 0.1);
			map[y][x][1] = map[y][x][1] * (zoom - 0.1);
			x++;
		}
		y++;
	}
	return (map);
}
