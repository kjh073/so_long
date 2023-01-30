#include <stdio.h>
#include <stdlib.h>
#include "mlx/mlx.h"

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		width;
	int		height;
}		t_data;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;


void	close_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
		player->y++;
	else if (keycode == KEY_A)
		x--;
	else if (keycode == KEY_S)
		y--;
	else if (keycode == KEY_D)
		x++;
	else if (keycode == KEY_ESC)
		close_game(vars);
	return (0);
}

int main()
{
	t_vars vars;
	t_data image;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hellow World!");
	image.img = mlx_xpm_file_to_image(vars.mlx, "textures/beach_ground.xpm", &image.width, &image.height);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars); // esc key press event
	mlx_loop(vars.mlx);
	return (0);
}
