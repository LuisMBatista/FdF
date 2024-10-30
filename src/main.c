/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:43:54 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/30 15:19:13 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char**argv)
{
	int		***map;
	float	***new_map;
	t_data	*img;
	float	zoom;

	arg_validation(argc, argv);
	img = allocation_img();
	img->map_length = lenght_check(argv[1], img);
	img->map_height = height_check(argv[1]);
	map = str_to_int(img->map_length, img->map_height, argv[1]);
	new_map = two_d_map(map, img->map_height, img->map_length);
	zoom = check_zoom(new_map, SCREEN_WIDTH, SCREEN_HEIGHT, img);
	new_map = zoom_multiplier(new_map, zoom, img);
	new_map = centralize_map(new_map, img);
	mlx_creation(img);
	draw_map(*img, new_map, img->map_height, img->map_length);
	free_map_allocation(new_map, img->map_height, img->map_length);
	mlx_put_image_to_window(img->mlx_connection, img->mlx_win, img->img, 0, 0);
	mlx_key_hook(img->mlx_win, key_press, img);
	mlx_hook(img->mlx_win, 17, 0, close_window, img);
	mlx_loop(img->mlx_connection);
	free(img);
	return (0);
}
