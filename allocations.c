/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:48:04 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/24 15:22:04 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	***map_allocation(int lenght, int height)
{
	int		***map;
	int		i;
	int		x;

	i = 0;
	x = 0;
	map = (int ***)malloc(sizeof(int **) * height);
	while (i < height)
	{
		map[i] = (int **)malloc(sizeof(int *) * (lenght));
		while (x < lenght)
		{
			map[i][x] = (int *)malloc(sizeof(int) * 3);
			x++;
		}
		x = 0;
		i++;
	}
	return (map);
}

float	***new_map_allocation(int height, int length)
{
	float	***new_map;
	int		i;
	int		x;

	i = 0;
	new_map = (float ***)malloc(sizeof(float **) * height);
	while (i < height)
	{
		new_map[i] = (float **)malloc(sizeof(float *) * length);
		x = 0;
		while (x < length)
		{
			new_map[i][x] = (float *)malloc(sizeof(float) * 2);
			x++;
		}
		i++;
	}
	return (new_map);
}

void	free_map(int ***map, int height, int length)
{
	int		i;
	int		j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < length)
		{
			free(map[i][j]);
			j++;
		}
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map_allocation(float ***map, int height, int length)
{
	int		i;
	int		j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < length)
		{
			free(map[i][j]);
			j++;
		}
		free(map[i]);
		i++;
	}
	free(map);
}
