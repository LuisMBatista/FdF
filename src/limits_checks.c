/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:49:15 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/24 15:25:35 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	lenght_multiplier(float ***map, int map_lenght, t_data *img)
{
	int		min;
	int		max;
	float	size;
	float	multiplier;

	multiplier = 1;
	min = check_lenght_min(map, img);
	max = check_lenght_max(map, img);
	size = abs (max - min);
	multiplier = (map_lenght / size);
	return (multiplier);
}

float	height_multiplier(float ***map, int map_height, t_data *img)
{
	int		min;
	int		max;
	int		size;
	float	multiplier;

	multiplier = 1;
	min = check_height_min(map, img);
	max = check_height_max(map, img);
	size = abs (max - min);
	multiplier = (map_height / size);
	return (multiplier);
}

int	lenght_check(char *argv)
{
	char	*str;
	int		lenght;
	int		fd;

	fd = open(argv, O_RDONLY);
	lenght = 0;
	str = get_next_line(fd);
	if (str != NULL)
		lenght = ft_strlen3(str);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		if (str != NULL)
		{
			if (lenght != ft_strlen3(str))
			{
				free(str);
				close(fd);
				exit(ft_printf("Error: Length invalid\n"));
			}
		}
	}
	close(fd);
	return (lenght);
}

int	height_check(char *argv)
{
	char	*str;
	int		height;
	int		fd;

	height = 0;
	fd = open(argv, O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		height++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (height);
}
