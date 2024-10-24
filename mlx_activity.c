/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_activity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:28:17 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/24 10:42:09 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void mlx_creation(t_data *img)
{
    img->mlx_connection = mlx_init();
    if (!img->mlx_connection)
    {
        printf("Error: Failed to initialize mlx_connection.\n");
        free(img);
        exit (0);
    }

    img->mlx_win = mlx_new_window(img->mlx_connection, SCREEN_WIDTH, SCREEN_HEIGHT , "Quack");
    if (!img->mlx_win)
    {
        printf("Error: Failed to create window.\n");
        mlx_destroy_display(img->mlx_connection);
        free(img->mlx_connection);
        free(img);
        exit (0);
    }
    mlx_creation2(img);
}

void mlx_creation2(t_data *img)
{

    img->img = mlx_new_image(img->mlx_connection, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!img->img)
    {
        printf("Error: Failed to create image.\n");
        mlx_destroy_window(img->mlx_connection, img->mlx_win);
        mlx_destroy_display(img->mlx_connection);
        free(img->mlx_connection);
        free(img);
        exit (0);
    }
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    if (!img->addr)
    {
        printf("Error: Failed to get data address for image.\n");
        mlx_destroy_image(img->mlx_connection, img->img);
        mlx_destroy_window(img->mlx_connection, img->mlx_win);
        mlx_destroy_display(img->mlx_connection);
        free(img->mlx_connection);
        free(img);
        exit (0);
    }
}
