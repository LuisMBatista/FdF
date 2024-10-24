/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:48:51 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/24 12:06:56 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "/home/ubuntu/Documents/FdF/fdf.h"

void draw_map(t_data img, float ***new_map,  int height, int length)
{
    int x;
    int y;

    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < length)
        {
            if (x < length - 1)
                draw_line(&img, new_map[y][x][0], new_map[y][x][1], new_map[y][x + 1][0], new_map[y][x + 1][1], 0x00FF00);
            if (y < height - 1)
                draw_line(&img, new_map[y][x][0], new_map[y][x][1], new_map[y + 1][x][0], new_map[y + 1][x][1], 0x00FF00);
            x++;
        }
        y++;
    }
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    // Calculate the memory address for the pixel (x, y) in the image's buffer
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    
    // Place the color at the calculated address
    *(unsigned int*)dst = color;
}
void draw_line(t_data *img, int x0, int y0, int x1, int y1, int color)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float x_increment = dx / (float)steps;
    float y_increment = dy / (float)steps;
    int i = 0;

    float x = x0;
    float y = y0;
    while (i <= steps) 
    {
        if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
        {
            my_mlx_pixel_put(img, (int)x, (int)y, color);
        }
        x += x_increment;
        y += y_increment;
        i++;
    }
}
