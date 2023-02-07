#include <stdio.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "libft/ft_printf.h"
#include "so_long.h"
#include <stdlib.h>
#include "mlx/mlx.h"
// #include <fcntl.h>

// #include "error_msg.c"
// #include "map_list.c"
// #include "check_map.c"
// #include "dfs.c"
// #include "libft/ft_printf.c"
// #include "libft/ft_print_char.c"
// #include "libft/ft_print_hex.c"
// #include "libft/ft_print_nbr.c"
// #include "libft/ft_print_str.c"
// #include "libft/ft_split.c"
// #include "libft/ft_strjoin.c"
// #include "libft/ft_strdup.c"
// #include "libft/ft_strlen.c"
// #include "libft/ft_substr.c"
// #include "libft/get_next_line.c"
// #include "libft/get_next_line_utils.c"

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_EXIT		17 //exit key code

int	close_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_param *param)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
	{
		param->steps++;
		if (keycode == KEY_W)
			param->y++;
		else if (keycode == KEY_A)
			param->x--;
		else if (keycode == KEY_S)
			param->y--;
		else if (keycode == KEY_D)
			param->x++;
	}
	// else if (keycode == KEY_ESC)
	// 	exit(0);
	printf("x: %d, y: %d\n", param->x, param->y);
	printf("steps: %d\n", param->steps);
	return (0);
}

int main()
{
	t_vars vars;
	t_data image;
	t_data wall;
	t_data p;
	t_data c;
	t_data e;
	t_components	*comp;
	t_param			*pos;

	comp = (t_components *)malloc(sizeof(t_components));
	pos = (t_param *)malloc(sizeof(t_param));
	if (!comp || !pos)
		return (0);
	char *result = map_join();
	char **map = map_split(result);
	// char **map_to_check;
	check_map_rect(map);
	check_map_surround_1(map);
	check_map_valid_comp(map);
	components_init(comp);
	check_map_comp_count(map, comp);
	param_init(pos);
	// pos = find_p(map);
	int width = 0;
	int height = 0;
	while (map[height])
	{
		width = 0;
		while (map[height][width])
			width++;
		height++;
	}
	// printf("%d, %d\n", width, height);
	// has_valid_path(map_to_check, pos, comp);
	// printf("x: %d, y: %d, s: %d\n", pos->x, pos->y, pos->steps);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width * 64, height * 64, "so_long");
	image.img = mlx_xpm_file_to_image(vars.mlx, "textures/beach_ground.xpm", &image.width, &image.height);
	wall.img = mlx_xpm_file_to_image(vars.mlx, "textures/bush copy.xpm", &wall.width, &wall.height);
	p.img = mlx_xpm_file_to_image(vars.mlx, "textures/Haley_front.xpm", &p.width, &p.height);
	c.img = mlx_xpm_file_to_image(vars.mlx, "textures/star.xpm", &c.width, &c.height);
	e.img = mlx_xpm_file_to_image(vars.mlx, "textures/teleport.xpm", &e.width, &e.height);
	int i = 0;
	int j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			mlx_put_image_to_window(vars.mlx, vars.win, image.img, i * 64, j * 64);
			if (map[j][i] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, wall.img, i * 64, j * 64);
			else if (map[j][i] == 'P')
				mlx_put_image_to_window(vars.mlx, vars.win, p.img, i * 64, j * 64);
			else if (map[j][i] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.win, c.img, i * 64, j * 64);
			else if (map[j][i] == 'E')
				mlx_put_image_to_window(vars.mlx, vars.win, e.img, i * 64, j * 64);
			i++;
		}
		j++;
	}
	// mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, X_EVENT_KEY_EXIT, 0, close_game, &vars);
	mlx_hook(vars.win, X_EVENT_KEY_PRESS, 0, key_hook, pos);
	mlx_loop(vars.mlx);
	return (0);
}

// int main()
// {
// 	t_components	*comp;
// 	t_param			*pos;

// 	comp = (t_components *)malloc(sizeof(t_components));
// 	pos = (t_param *)malloc(sizeof(t_param));
// 	if (!comp || !pos)
// 		return (0);
// 	char *result = map_join();
// 	char **map = map_split(result);
// 	check_map_rect(map);
// 	check_map_surround_1(map);
// 	check_map_valid_comp(map);
// 	components_init(comp);
// 	check_map_comp_count(map, comp);
// 	param_init(pos);
// 	pos = find_p(map);
// 	has_valid_path(map, pos, comp);
// 	// system("leaks a.out");
// }
