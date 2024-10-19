#include </home/ubuntu/Documents/FdF/fdf.h>

int ***map_allocation (int lenght, int height)
{
    int ***map;
    int i;
    int x;

    i = 0;
    x = 0;
    map = (int ***)malloc(sizeof(int **) * height);
    if (!map)
    {
        perror("Error allocating memory for map rows");
        return NULL;
    }
    while (i < height)
    {
        map[i] = (int **)malloc(sizeof(int*) * (lenght));
        while (x < lenght)
        {
            map[i][x] = (int *)malloc(sizeof(int) * 3);
            if (!map[i][x])
            {
                perror("Error allocating memory for map columns");
                while (--x >= 0)
                    free(map[i][x]);
                free(map[i]);
                return NULL;
            }
            x++;
        }
        x = 0;
        i++;
    }
    return (map);
}

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
