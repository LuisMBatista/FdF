#include "/home/ubuntu/Documents/FdF/fdf.h"
#include <math.h>

float ***centralize_map(float ***map, int height, int lenght)
{
    int x;
    int y;

    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < lenght)
        {
            map[y][x][0] = map[y][x][0] + (SCREEN_WIDTH / 2);
            map[y][x][1] = map[y][x][1] + (SCREEN_HEIGHT / 2);
            x++;
        }
        y++;
    }
    return (map);
}
float ***two_d_map(int ***map, int height, int lenght)
{
    float ***new_map;
    int x;
    int y;

    y = 0;
    new_map = new_map_allocation(height, lenght);
    while ( y < height)
    {
        x = 0;
        while (x < lenght)
        {
            new_map[y][x][0] = (map[y][x][0] * cos(0.5235987755982989)) - (map[y][x][1] * cos(0.5235987755982989));
            new_map[y][x][1] = (map[y][x][0] * sin(0.5235987755982989)) + (map[y][x][1] * sin(0.5235987755982989)) - (map[y][x][2]); 
            x++;
        }
        y++;
    }
    free(map);
    return (new_map);
}