/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:49:15 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/24 10:51:09 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/ubuntu/Documents/FdF/fdf.h"

float lenght_multiplier(float ***map, int map_lenght, t_data *img)
{
    int min;
    int max;
    float size;
    float multiplier;

    multiplier = 1;
    min = check_lenght_min(map, img);
    max = check_lenght_max(map, img);
    size = abs (max - min);
    multiplier = (map_lenght / size);

    return(multiplier); 
}
float height_multiplier(float ***map, int map_height, t_data *img)
{
    int min;
    int max;
    int size;
    float multiplier;

    multiplier = 1;
    min = check_height_min(map, img);
    max = check_height_max(map, img);
    size = abs (max - min);
    multiplier = (map_height / size);

    return(multiplier); 
}

float ***zoom_multiplier(float ***map, float zoom, t_data *img)
{
    int y;
    int x;

    y = 0;
    while (y < img->map_height)
    {
        x = 0;
        while(x < img->map_length)
        {
            map[y][x][0] = map[y][x][0] * (zoom - 0.1); //ARRANJAR ZOOM ORIGINAL 
            map[y][x][1] = map[y][x][1] * (zoom - 0.1);
            x++;
        }
        y++;
    }
    return (map);
}

