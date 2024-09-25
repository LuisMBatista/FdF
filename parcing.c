#include <stdlib.h>
#include <stdio.h>
#include "/home/ubuntu/Documents/FdF/minilibx-linux/mlx.h"
#include "/home/ubuntu/Documents/FdF/minilibx-linux/mlx_int.h"
#include "/home/ubuntu/Documents/FdF/libft/libft.h"
#include "/home/ubuntu/Documents/FdF/getnext/get_next_line.h"
#include "/home/ubuntu/Documents/FdF/ft_printf/ft_printf.h"

int **map_allocation (int lenght, int height)
{
    int **map;
    int i;

    i = 0;
    map = (int **)malloc(sizeof(int *) * height);
    if (!map)
    {
        perror("Error allocating memory for map rows");
        return NULL;
    }
    for (i = 0; i < height; i++)
    {
        map[i] = (int *)malloc(sizeof(int) * (lenght + 1));
        if (!map[i])
        {
            perror("Error allocating memory for map columns");
            while (--i >= 0)
                free(map[i]);
            free(map);
            return NULL;
        }
    }
    return (map);
}

int	ft_strlen3(const char *s)
{
	int	i;
    int lenght;

	i = 0;
    while (s[i] != '\0' && s[i] != '\n')
    {
        if ('0' >= s[i] <= '9')
        {
            lenght++;
            i++;
        }    
        if (s[i] == ' ')
            i++;
    }
	return (lenght);
}
int lenght_validation()
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
        if ('0' >= str[i++] <= '9')
            lenght++;  
        if (str[i] == ' ')
            i++;
    }
    while (str !=NULL)
    {
        if (lenght != ft_strlen3(str))
            return (ft_printf("Error: Lenght invalido\n"),0);
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
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;

	if (str != '\0' && ft_isdigit(str))
    {
		nbr = str - '0';
	    return (nbr);
    }
}

int **str_to_int (int length, int height)
{
    int fd;
    char *str;
    int **map;
    int i;
    int x;
    int y;

    x = 0;
    y= 0;
    i = 0;
    fd = open("42.fdf", O_RDONLY);
    str = get_next_line(fd);
    map = map_allocation(length, height);
    while (str != NULL)
    {
        while (str[i] != '\n' && str[i] != '\0')
        {
            if (str[i] == ' ')
                i++;
            map[y][x] = ft_atoi2(str[i]);
            printf("map[%d][%d] = %d\n", y, x, map[y][x]); 
            i++;
            x++;
        }
        map[y][x] = '\0';
        printf("map[%d][%d] = %d\n", y, x, map[y][x]);
        free(str);
        str = get_next_line(fd);
        y++;
        i = 0;
        x = 0;
    }
    close(fd);
    return (map);
}

int	main(void)
{
    int length;
    int height;
    int **map;

    length = 0;
    height = 0;
    length = lenght_validation();
    height = height_check();
    printf("length: %d\n", length);
    printf("height: %d\n", height);
    map = str_to_int(length, height);
    return (0);
}
