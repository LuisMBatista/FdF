#include "/home/ubuntu/Documents/FdF/fdf.h"

int check_lenght_min(float ***map, char *argv)
{
    int y;
    int x;
    int min;

    y = 0;
    min = 999;
   while (y < height_check(argv))
    {
        x = 0;
        while(x < lenght_check(argv))
        {
            if (map[y][x][0] < min)
                min = map[y][x][0];
        x++;
        }
    y++;
    }
    return (min);
}

int check_lenght_max (float ***map, char *argv)
{
    int y;
    int x;
    int max;

    y = 0;
    max = 0;
   while (y < height_check(argv))
    {
        x = 0;
        while(x < lenght_check(argv))
        {
            if (map[y][x][0] > max)
                max = map[y][x][0];
        x++;
        }
    y++;
    }
    return (max);
}

int check_height_min (float ***map, char *argv)
{
    int y;
    int x;
    int min;

    y = 0;
    min = 0;
   while (y < height_check(argv))
    {
        x = 0;
        while(x < lenght_check(argv))
        {
            if (map[y][x][1] < min)
                min = map[y][x][1];
        x++;
        }
    y++;
    }
    return (min);
}

int check_height_max (float ***map, char *argv)
{
    int y;
    int x;
    int max;

    y = 0;
    max = 0;
   while (y < height_check(argv))
    {
        x = 0;
        while(x < lenght_check(argv))
        {
            if (map[y][x][1] > max)
                max = map[y][x][1];
        x++;
        }
    y++;
    }
    return (max);
}

int lenght_multiplier(float ***map, int map_lenght, char *argv)
{
    int min;
    int max;
    int size;
    float multiplier;

    multiplier = 1;
    min = check_lenght_min(map, argv);
    max = check_lenght_max(map, argv);
    size = abs (max - min);
    multiplier = (map_lenght / size);

    return(multiplier); 
}
int height_multiplier(float ***map, int map_height, char *argv)
{
    int min;
    int max;
    int size;
    float multiplier;

    multiplier = 1;
    min = check_height_min(map, argv);
    max = check_height_max(map, argv);
    size = abs (max - min);
    multiplier = (map_height / size);

    return(multiplier); 
}

float ***zoom_multiplier(float ***map, int zoom, char *argv)
{
    int y;
    int x;

    y = 0;
    while (y < height_check(argv))
    {
        x = 0;
        while(x < lenght_check(argv))
        {
            map[y][x][0] = map[y][x][0] * (zoom / 2); //ARRANJAR ZOOM ORIGINAL 
            map[y][x][1] = map[y][x][1] * (zoom / 2);
            x++;
        }
        y++;
    }
    return (map);
}

