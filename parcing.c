#include "fdf.h"

int	ft_strlen3(const char *s)
{
	int	i;
    int lenght;

	i = 0;
    lenght = 0;
    while (s[i] != '\0')
    {
        if (s[i] != ' ' && s[i] != '\n' && s[i] != '\0')
            lenght++;
        i++;
    }
	return (lenght);
}
int lenght_validation(void)
{
    char *str;
    int lenght;
    int i;
    int fd;

    fd = open("42.fdf", O_RDONLY);
    i = 0;
    lenght = 0;
    str = get_next_line(fd);
    while (str[i] != '\0' && str[i] != '\n')
    {
        if (str[i] != ' ')
            lenght++;
        i++;
    }
    while (str !=NULL)
    {
        if (lenght != ft_strlen3(str))
            return (ft_printf("Error: Lenght invalide\n"),0);
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
    return (lenght);
}

int height_check(void)
{
    char *str;
    int height;
    int fd;

    height = 0;
    fd = open("42.fdf", O_RDONLY);
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

int	ft_atoi2(char str)
{
	int	nbr;

	nbr = 0;

	if (str != '\0' && ft_isdigit(str))
    {
		nbr = str - '0';
	    return (nbr);
    }
    return (0);
}


int check_zoom(float ***map, int img_lenght, int img_height)
{
    int lenght;
    int height;

    lenght = lenght_multiplier(map, img_lenght);
    height = height_multiplier(map, img_height);
    if (lenght <= height)
        return(lenght);
    return(height);
}

int ***str_to_int (int length, int height)
{
    int fd;
    char *str;
    int ***map;
    int i;
    int x;
    int y;

    y= 0;
    i = 0;
    fd = open("42.fdf", O_RDONLY);
    str = get_next_line(fd);
    map = map_allocation(length, height);
    while (1)
    {
        x= 0;
        while (str[i] && str[i] != '\n' && x < length)
        {
            if (str[i] != ' ')
            {
                map[y][x][0] = x;
                map[y][x][1] = y;
                map[y][x][2] = ft_atoi2(str[i]);  
                x++;
            }
            i++;
        }
        i = 0;
        y++;
        free(str);
        str = get_next_line(fd);
        if (!str)
            break;
    }
    close(fd);
    return (map);
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

int main(void)
{
    int length;
    int height;
    int ***map;
    float ***new_map;
    void *mlx_win;
    void *mlx_connection;
    t_data img;
    int zoom;

    zoom = 0;
    length = lenght_validation();
    height = height_check();
    map = str_to_int(length, height);
    new_map = two_d_map(map, height, length);
    zoom = check_zoom(new_map, SCREEN_WIDTH, SCREEN_HEIGHT);
    printf("zoom = %d\n", zoom);
    new_map = zoom_multiplier(new_map, zoom);
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