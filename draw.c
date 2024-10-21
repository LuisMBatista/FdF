# include "/home/ubuntu/Documents/FdF/fdf.h"

void draw_map(t_data img, float ***new_map,  int height, int length)
{
    int x;
    int y;

    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < length)
        {
            if (x < length - 1)
                draw_line(&img, new_map[y][x][0], new_map[y][x][1], new_map[y][x + 1][0], new_map[y][x + 1][1], 0x00FF00);
            if (y < height - 1)
                draw_line(&img, new_map[y][x][0], new_map[y][x][1], new_map[y + 1][x][0], new_map[y + 1][x][1], 0x00FF00);
            x++;
        }
        y++;
    }
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    // Calculate the memory address for the pixel (x, y) in the image's buffer
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    
    // Place the color at the calculated address
    *(unsigned int*)dst = color;
}