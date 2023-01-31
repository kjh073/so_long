#include <stdio.h>
#include <stdlib.h>
#include "mlx/mlx.h"
#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <fcntl.h>
#include <stdio.h>

// #define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_EXIT		17 //exit key code

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

typedef struct s_param
{
	int	x;
	int	y;
}	t_param;

typedef struct s_components
{
	int	p;
	int	e;
	int	c;
}	t_components;

void	param_init(t_param *param)
{
	param->x = 0;
	param->y = 0;
}

void	components_init(t_components *comp)
{
	comp->p = 0;
	comp->e = 0;
	comp->c = 0;
}

int	close_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	t_param *player;

	if (keycode == KEY_W)
		player->y++;
	else if (keycode == KEY_A)
		player->x--;
	else if (keycode == KEY_S)
		player->y--;
	else if (keycode == KEY_D)
		player->x++;
	else if (keycode == KEY_ESC)
		close_game(vars);
	return (0);
}

// char *read_map(void)
// {
// 	int fd;
// 	char *result;
// 	fd = open("maps/map.ber", O_RDONLY);
// 	result = get_next_line(fd);
// 	return (result);
// }

// int check_map()
// {

// }

int main()
{
	t_vars vars;
	t_data image;
	t_param *param;
	char *map_oneline;

	// map_oneline = read_map();
	
	vars.mlx = mlx_init();
	// param_init(param); //얘 때문에 bus error 나는디;
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hellow World!");
	image.img = mlx_xpm_file_to_image(vars.mlx, "textures/beach_ground.xpm", &image.width, &image.height);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, X_EVENT_KEY_EXIT, 0, close_game, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
