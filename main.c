/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:43:54 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/23 15:45:23 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"


void	free_str_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	arg_validity(char *argv)
{
	char	**file;
	int		i;

	file = ft_split(argv, '.');
	i = 0;
	while (file[i])
		i++;
	if (!file[1] || i > 2)
		return (free_str_array(file), 0);
	if (ft_strcmp(file[1], "fdf") == 0)
		return (free_str_array(file), 1);
	return (free_str_array(file), 0);
}

int main(int argc, char **argv)
{
    int ***map;
    float ***new_map;
    t_data *img;
    float zoom;
    int fd;

    fd = open(argv[1], O_RDONLY);
    if (arg_validity(argv[1]) == 0 || fd < 0 || argc != 2)
    {
        ft_printf("Error: Invalid file.\n");
        exit (0);
    }
    close(fd);

    img = malloc(sizeof(t_data));
    if (!img)
    {
        ft_printf("Error: Failed to allocate memory for img.\n");
        exit (0);
    }
    zoom = 0;
    img->map_length = lenght_check(argv[1]);
    img->map_height = height_check(argv[1]);
    map = str_to_int(img->map_length, img->map_height, argv[1]);
    new_map = two_d_map(map, img->map_height, img->map_length);
    zoom = check_zoom(new_map, SCREEN_WIDTH, SCREEN_HEIGHT, img);
    new_map = zoom_multiplier(new_map, zoom, img);
    new_map = centralize_map(new_map, img);
    img->mlx_connection = mlx_init();
    if (!img->mlx_connection)
    {
        printf("Error: Failed to initialize mlx_connection.\n");
        free(img);
        return (1);
    }

    img->mlx_win = mlx_new_window(img->mlx_connection, SCREEN_WIDTH, SCREEN_HEIGHT , "Quack");
    if (!img->mlx_win)
    {
        printf("Error: Failed to create window.\n");
        mlx_destroy_display(img->mlx_connection);
        free(img->mlx_connection);
        free(img);
        return (1);
    }

    img->img = mlx_new_image(img->mlx_connection, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!img->img)
    {
        printf("Error: Failed to create image.\n");
        mlx_destroy_window(img->mlx_connection, img->mlx_win);
        mlx_destroy_display(img->mlx_connection);
        free(img->mlx_connection);
        free(img);
        return (1);
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
        return (1);
    }
    draw_map(*img, new_map, img->map_height, img->map_length);
    free_map_allocation(new_map, img->map_height, img->map_length); 
    mlx_put_image_to_window(img->mlx_connection, img->mlx_win, img->img, 0, 0);
    mlx_key_hook(img->mlx_win, key_press, img);
    mlx_loop(img->mlx_connection);
    free(img);

    return (0);
}