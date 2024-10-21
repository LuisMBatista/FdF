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
    int length;
    int height;
    int ***map;
    float ***new_map;
    void *mlx_win;
    void *mlx_connection;
    t_data img;
    int zoom;
    int fd;

    fd = open(argv[1], O_RDONLY);
    if (arg_validity(argv[1])== 0 || fd < -1 || argc != 2)
    {
        ft_printf("Error: Invalid file.\n");
        exit (0);
    }
    close (fd);
    zoom = 0;
    length = lenght_check(argv[1]);
    height = height_check(argv[1]);
    printf("length = %d\n", length);
    printf("height = %d\n", height);
    map = str_to_int(length, height,argv[1]);
    new_map = two_d_map(map, height, length);
    zoom = check_zoom(new_map, SCREEN_WIDTH, SCREEN_HEIGHT,argv[1]);
    printf("zoom = %d\n", zoom);
    new_map = zoom_multiplier(new_map, zoom,argv[1]);
    new_map = centralize_map(new_map, height, length);
    mlx_connection = mlx_init();
    if (!mlx_connection)
        {
        printf("Error: Failed to initialize mlx connection.\n");
        return (1);
        }

    mlx_win = mlx_new_window(mlx_connection, SCREEN_WIDTH, SCREEN_HEIGHT , "Quack");
    if (!mlx_win)
    {
        printf("Error: Failed to create window.\n");
        mlx_destroy_display(mlx_connection);
        free(mlx_connection);
        return (1);
    }

    img.img = mlx_new_image(mlx_connection, SCREEN_WIDTH, SCREEN_HEIGHT );
    if (!img.img)
    {
        printf("Error: Failed to create image.\n");
        mlx_destroy_window(mlx_connection, mlx_win);
        mlx_destroy_display(mlx_connection);
        free(mlx_connection);
        return (1);
    }
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    if (!img.addr)
    {
        printf("Error: Failed to get data address for image.\n");
        mlx_destroy_image(mlx_connection, img.img);
        mlx_destroy_window(mlx_connection, mlx_win);
        mlx_destroy_display(mlx_connection);
        free(mlx_connection);
        return (1);
    }
    // Draw the lines
    draw_map(img, new_map, height, length);
    mlx_put_image_to_window(mlx_connection, mlx_win, img.img, 0, 0);
    mlx_put_image_to_window(mlx_connection, mlx_win, img.img, 0, 0);
    mlx_loop(mlx_connection);
    mlx_destroy_window(mlx_connection, mlx_win);
    mlx_destroy_display(mlx_connection);
    free(mlx_connection);

    // Free new_map memory (if dynamically allocated)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            free(new_map[i][j]);
        }
        free(new_map[i]);
    }
    free(new_map);

    return (0);
}