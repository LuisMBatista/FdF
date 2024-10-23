#include "/home/ubuntu/Documents/FdF/fdf.h"

int check_lenght_min(float ***map, t_data *img)
{
    int y;
    int x;
    int min;

    y = 0;
    min = 999;
   while (y < img->map_height)
    {
        x = 0;
        while(x < img->map_length)
        {
            if (map[y][x][0] < min)
                min = map[y][x][0];
        x++;
        }
    y++;
    }
    return (min);
}

int check_lenght_max (float ***map, t_data *img)
{
    int y;
    int x;
    int max;

    y = 0;
    max = 0;
  while (y < img->map_height)
    {
        x = 0;
        while(x < img->map_length)
        {
            if (map[y][x][0] > max)
                max = map[y][x][0];
        x++;
        }
    y++;
    }
    return (max);
}

int check_height_min (float ***map, t_data *img)
{
    int y;
    int x;
    int min;

    y = 0;
    min = 999;
   while (y < img->map_height)
    {
        x = 0;
        while(x < img->map_length)
        {
            if (map[y][x][1] < min)
                min = map[y][x][1];
        x++;
        }
    y++;
    }
    return (min);
}

int check_height_max (float ***map, t_data *img)
{
    int y;
    int x;
    int max;

    y = 0;
    max = 0;
   while (y < img->map_height)
    {
        x = 0;
        while(x < img->map_length)
        {
            if (map[y][x][1] > max)
                max = map[y][x][1];
        x++;
        }
    y++;
    }
    return (max);
}

float lenght_multiplier(float ***map, int map_lenght, t_data *img)
{
    int min;
    int max;
    float size;
    float multiplier;

    multiplier = 1;
    min = check_lenght_min(map, img);
    max = check_lenght_max(map, img);
    size = abs (max - min);
    multiplier = (map_lenght / size);

    return(multiplier); 
}
float height_multiplier(float ***map, int map_height, t_data *img)
{
    int min;
    int max;
    int size;
    float multiplier;

    multiplier = 1;
    min = check_height_min(map, img);
    max = check_height_max(map, img);
    size = abs (max - min);
    multiplier = (map_height / size);

    return(multiplier); 
}

float ***zoom_multiplier(float ***map, float zoom, t_data *img)
{
    int y;
    int x;

    y = 0;
    while (y < img->map_height)
    {
        x = 0;
        while(x < img->map_length)
        {
            map[y][x][0] = map[y][x][0] * (zoom - 0.1); //ARRANJAR ZOOM ORIGINAL 
            map[y][x][1] = map[y][x][1] * (zoom - 0.1);
            x++;
        }
        y++;
    }
    return (map);
}

