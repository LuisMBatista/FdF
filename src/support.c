/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:13:32 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/24 18:17:25 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen3(const char *s)
{
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\n' && ft_isdigit(s[i]))
			length++;
		while (s[i] != '\0' && ft_isdigit(s[i]))
			i++;
		if (s[i] == ',')
		{
			i++;
			while (s[i] != ' ' && s[i] != '\n')
				i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (length);
}

t_increment	calculate_increments(int dx, int dy, int steps)
{
	t_increment		inc;

	inc.x_increment = dx / (float)steps;
	inc.y_increment = dy / (float)steps;
	return (inc);
}

int	calculate_steps(int dx, int dy)
{
	if (abs(dx) > abs(dy))
		return (abs(dx));
	return (abs(dy));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
