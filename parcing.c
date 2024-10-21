#include "fdf.h"

int ft_strlen3(const char *s)
{
    int i = 0;
    int length = 0;

    while (s[i] != '\0')
    {
        if (s[i] != ' ' && s[i] != '\n' && s[i] != '-')
            length++;
        while (s[i] != '\0' && ft_isdigit(s[i]))
            i++;
        if (s[i] == ',')
            {
                i++;
                while (s[i] != ' ')
                    i++;
            }
        if (s[i] != '\0')
            i++;
    }
    return length;
}

int lenght_check(char *argv)
{
    char *str;
    int lenght;
    int fd;

    fd = open(argv, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error opening file");
        return -1;
    }
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
            int current_len = ft_strlen3(str);
            if (lenght != current_len)
            {
                free(str);
                close(fd);
                exit(printf("Error: Length invalid\n"));
            }
        }
    }
    close(fd);
    return lenght;
}

int height_check(char *argv)
{
    char *str;
    int height;
    int fd;

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


int check_zoom(float ***map, int img_lenght, int img_height, char *argv)
{
    int lenght;
    int height;

    lenght = lenght_multiplier(map, img_lenght, argv);
    height = height_multiplier(map, img_height, argv);
    if (lenght <= height)
        return(lenght);
    return(height);
}

int ***str_to_int (int length, int height, char *argv)
{
    int fd;
    char *str;
    int ***map;
    int i;
    int x;
    int y;

    y= 0;
    i = 0;
    fd = open(argv, O_RDONLY);
    str = get_next_line(fd);
    printf("str = %s\n", str);
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

