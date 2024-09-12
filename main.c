#include "/home/ubuntu/Documents/FdF/minilibx-linux/mlx.h"
#include "/home/ubuntu/Documents/FdF/minilibx-linux/mlx_int.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	his_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int draw_line (void *mlx_connection, void *mlx_win, int beginX, int beginY, int endX, int endY, int color, t_data img)
{

    int dx = endX - beginX;
    int dy = endY - beginY;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    float X = beginX;
    float Y = beginY;
    for (int i = 0; i <= steps; i++)
    {
        his_mlx_pixel_put(&img, X, Y, color);
        X += Xinc;
        Y += Yinc;
    }
    return (0);
}

int main(void)
{
    void *mlx_win;
    void *mlx_connection;
    t_data img;

    mlx_connection= mlx_init();
    if(!mlx_connection)
        return (1);  
    mlx_win = mlx_new_window(mlx_connection, 800, 800, "Quack"); 
    img.img = mlx_new_image(mlx_connection, 700, 700);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    draw_line(mlx_connection, mlx_win, 10, 10, 20, 10, 0xFFFFFF, img);
    draw_line(mlx_connection, mlx_win, 20, 10, 20, 20, 0xFFFFFF, img);
    draw_line(mlx_connection, mlx_win, 20, 20, 10, 20, 0xFFFFFF, img);
    draw_line(mlx_connection, mlx_win, 10, 20, 10, 10, 0xFFFFFF, img);

    mlx_put_image_to_window(mlx_connection, mlx_win, img.img, 0, 0);
    if(!mlx_win)
    {
        mlx_destroy_display(mlx_connection);
        free(mlx_connection);
        return(1);
    }
    mlx_loop(mlx_connection);
    mlx_destroy_window(mlx_connection,mlx_win);
    mlx_destroy_display(mlx_connection);
    free(mlx_connection);
    
    return (0);
}