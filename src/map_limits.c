/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_limits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:49:53 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/24 15:29:16 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_lenght_min(float ***map, t_data *img)
{
	int	y;
	int	x;
	int	min;

	y = 0;
	min = 999;
	while (y < img->map_height)
	{
		x = 0;
		while (x < img->map_length)
		{
			if (map[y][x][0] < min)
				min = map[y][x][0];
			x++;
		}
		y++;
	}
	return (min);
}

int	check_lenght_max(float ***map, t_data *img)
{
	int		y;
	int		x;
	int		max;

	y = 0;
	max = 0;
	while (y < img->map_height)
	{
		x = 0;
		while (x < img->map_length)
		{
			if (map[y][x][0] > max)
				max = map[y][x][0];
			x++;
		}
		y++;
	}
	return (max);
}

int	check_height_min(float ***map, t_data *img)
{
	int		y;
	int		x;
	int		min;

	y = 0;
	min = 999;
	while (y < img->map_height)
	{
		x = 0;
		while (x < img->map_length)
		{
			if (map[y][x][1] < min)
				min = map[y][x][1];
			x++;
		}
		y++;
	}
	return (min);
}

int	check_height_max(float ***map, t_data *img)
{
	int		y;
	int		x;
	int		max;

	y = 0;
	max = 0;
	while (y < img->map_height)
	{
		x = 0;
		while (x < img->map_length)
		{
			if (map[y][x][1] > max)
				max = map[y][x][1];
			x++;
		}
		y++;
	}
	return (max);
}
