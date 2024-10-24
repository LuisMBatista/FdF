/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_presses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:49:08 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/24 13:13:37 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int key_press(int keycode, t_data *img)
{
    if (keycode == 65307 || keycode == 17)
    {
        mlx_destroy_image(img->mlx_connection, img->img);
        mlx_destroy_window(img->mlx_connection, img->mlx_win);
        mlx_destroy_display(img->mlx_connection);
        free(img->mlx_connection);
        free(img);
        exit(0);
    }
    return (0);
}

int close_window(t_data *img) 
{
    mlx_destroy_image(img->mlx_connection, img->img);
    mlx_destroy_window(img->mlx_connection, img->mlx_win);
    mlx_destroy_display(img->mlx_connection);
    free(img->mlx_connection);
    free(img);
    exit(0);
}
