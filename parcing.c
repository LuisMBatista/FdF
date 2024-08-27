#include "/home/quack/Documents/FdF/minilibx-linux/mlx.h"
#include "/home/quack/Documents/FdF/minilibx-linux/mlx_int.h"
#include "/home/quack/Documents/FdF/libft/libft.h"
#include "/home/quack/Documents/FdF/getnext/get_next_line.h"

// - parsing
//    - check if map is valid
//    - check the map width
//    - check the map height
//    - allocate data for height
//    - allocate data for width
//    - fill map arrays

// arr = [
//     [0, 0, 3, 0, NULL],
//     [1, 3, 1, 2, NULL],
//     [2, 3, 1, 3, NULL],
//     NULL
// ]

// while (i)
//     While (j)
//         make_line(i, j, arr[i][j], i, j + 1, arr[i][j + 1])
int main (void)
{
    int fd;
	char *str;
    int size;
    
    size = 0;
	fd = open("42.fdf", O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
        size += ft_strlen2(str);
        free(str);
        str = get_next_line(fd);
    }
    if (size <= 1)
    {   
        puts("Map is invalid");
        return (0);
    }
    puts("Map is valid");
    return (0);
}