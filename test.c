#include <stdio.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "libft/ft_printf.h"
#include "so_long.h"
#include <stdlib.h>
#include "mlx/mlx.h"

int main()
{
	void *mlx;
	void *win;
	void *img;
	void *img2;
	int img_width;
	int img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "textures/beach_ground.xpm", &img_width, &img_height);
	printf("wid: %d, hei: %d\n", img_width, img_height);
	img2 = mlx_xpm_file_to_image(mlx, "textures/bush copy.xpm", &img_width, &img_height);
	printf("wid: %d, hei: %d\n", img_width, img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 64, 0);
	mlx_loop(mlx);
	return (0);
}