# include "fdf.h"

int key_press(int keycode, t_data *img)
{
    if (keycode == 65307)
    {
        mlx_destroy_image(img->mlx_connection, img->img);
        mlx_destroy_window(img->mlx_connection, img->mlx_win);
        mlx_destroy_display(img->mlx_connection);
        free(img->mlx_connection);
        free(img);
        exit(0);
    }
    return (0);
}