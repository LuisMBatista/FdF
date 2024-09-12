#include <stdlib.h>
#include <stdio.h>
#include "//home/ubuntu/Documents/FdF/minilibx-linux/mlx.h"
#include "/home/ubuntu/Documents/FdF/minilibx-linux/mlx_int.h"
#include "/home/ubuntu/Documents/FdF/libft/libft.h"
#include "/home/ubuntu/Documents/FdF/getnext/get_next_line.h"


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
