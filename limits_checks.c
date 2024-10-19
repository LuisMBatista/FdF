#include "/home/ubuntu/Documents/FdF/fdf.h"

int check_lenght_min(float ***map)
{
    int y;
    int x;
    int min;

    y = 0;
    min = 999;
    while (y < height_check())
    {
        x = 0;
        while(x < lenght_validation())
        {
            if (map[y][x][0] < min)
                min = map[y][x][0];
        x++;
        }
    y++;
    }
    return (min);
}

int check_lenght_max (float ***map)
{
    int y;
    int x;
    int max;

    y = 0;
    max = 0;
    while (y < height_check())
    {
        x = 0;
        while(x < lenght_validation())
        {
            if (map[y][x][0] > max)
                max = map[y][x][0];
        x++;
        }
    y++;
    }
    return (max);
}

int check_height_min (float ***map)
{
    int y;
    int x;
    int min;

    y = 0;
    min = 0;
    while (y < height_check())
    {
        x = 0;
        while(x < lenght_validation())
        {
            if (map[y][x][1] < min)
                min = map[y][x][1];
        x++;
        }
    y++;
    }
    return (min);
}

int check_height_max (float ***map)
{
    int y;
    int x;
    int max;

    y = 0;
    max = 0;
    while (y < height_check())
    {
        x = 0;
        while(x < lenght_validation())
        {
            if (map[y][x][1] > max)
                max = map[y][x][1];
        x++;
        }
    y++;
    }
    return (max);
}

int lenght_multiplier(float ***map, int map_lenght)
{
    int min;
    int max;
    int size;
    float multiplier;

    multiplier = 1;
    min = check_lenght_min(map);
    max = check_lenght_max(map);
    size = abs (max - min);
    multiplier = (map_lenght / size);

    return(multiplier); 
}
int height_multiplier(float ***map, int map_height)
{
    int min;
    int max;
    int size;
    float multiplier;

    multiplier = 1;
    min = check_height_min(map);
    max = check_height_max(map);
    size = abs (max - min);
    multiplier = (map_height / size);

    return(multiplier); 
}

float ***zoom_multiplier(float ***map, int zoom)
{
    int y;
    int x;

    y = 0;
    while (y < height_check())
    {
        x = 0;
        while(x < lenght_validation())
        {
            map[y][x][0] = map[y][x][0] * (zoom / 2); //ARRANJAR ZOOM ORIGINAL 
            map[y][x][1] = map[y][x][1] * (zoom / 2);
            x++;
        }
        y++;
    }
    return (map);
}

