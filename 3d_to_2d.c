#include "/home/ubuntu/Documents/FdF/fdf.h"
#include <math.h>

float ***new_map_allocation(int height, int length)
{
    float ***new_map;
    int i, x;

    i = 0;
    new_map = (float ***)malloc(sizeof(float **) * height);
    if (!new_map)
    {
        perror("Error allocating memory for new_map rows");
        return NULL;
    }

    while (i < height)
    {
        new_map[i] = (float **)malloc(sizeof(float *) * length);
        if (!new_map[i])
        {
            perror("Error allocating memory for new_map columns");
            while (--i >= 0)
                free(new_map[i]);
            free(new_map);
            return NULL;
        }
        x = 0;
        while (x < length)
        {
            new_map[i][x] = (float *)malloc(sizeof(float) * 2);
            if (!new_map[i][x])
            {
                perror("Error allocating memory for new_map column content");
                while (--x >= 0)
                    free(new_map[i][x]);
                while (--i >= 0)
                    free(new_map[i]);
                free(new_map);
                return NULL;
            }
            x++;
        }
        i++;
    }

    return new_map;
}

float ***two_d_map(int ***map, int height, int lenght)
{
    float ***new_map;
    int x;
    int y;

    x = 0;
    y = 0;
    new_map = new_map_allocation(height, lenght);
    while ( y < height)
    {
        while (x < lenght)
        {
            new_map[y][x][0] = (map[y][x][0] * cos(0.5235987755982989)) - (map[y][x][1] * cos(0.5235987755982989));
            new_map[y][x][1] = (map[y][x][0] * sin(0.5235987755982989)) + (map[y][x][1] * sin(0.5235987755982989)) - (map[y][x][2]); 
            x++;
        }
        x = 0;
        y++;
    }
    free(map);
    return (new_map);
}


/* float ***two_d_map(int **map, int map_height, int map_lenght)
{
    float ***new_map;
    int x;
    int y;
    int lenght;
    int height;
    float x_spacing;
    float y_spacing;
    float iso_angle = isometric_angle * M_PI / 180.0;

    lenght = lenght_validation();
    height = height_check();
    x = 0;
    y = 0;
    new_map = new_map_allocation(lenght, height);
    x_spacing = (float)map_lenght / (lenght - 1);
    y_spacing = (float)map_height / (height - 1);
    while ( y < height)
    {
        while (x < lenght)
        {
            float x_3d = x * x_spacing;
            float y_3d = y * y_spacing;
            float z_3d = map[y][x];
            new_map[y][x][0] = (x_3d - y_3d) * cos(iso_angle);
            new_map[y][x][1] = (x_3d + y_3d) * sin(iso_angle) - z_3d;
            //printf("new_map[%d][%d][0] = %f\n", y, x, new_map[y][x][0]);
            //printf("new_map[%d][%d][1] = %f\n", y, x, new_map[y][x][1]);   
            x++;
        }
        x = 0;
        y++;
    }
    free(map);
    return (new_map);
} */