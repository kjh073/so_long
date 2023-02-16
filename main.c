/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:09:27 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/16 15:56:04 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "libft/ft_printf.h"
#include "so_long.h"
#include <stdlib.h>
#include "mlx/mlx.h"
// #include <fcntl.h>

#include "print_msg.c"
#include "map_make.c"
#include "map_check.c"
#include "dfs_copy.c"
#include "move_p.c"
#include "so_long_utils.c"
#include "libft/ft_printf.c"
#include "libft/ft_print_char.c"
#include "libft/ft_print_hex.c"
#include "libft/ft_print_nbr.c"
#include "libft/ft_print_str.c"
#include "libft/ft_split.c"
#include "libft/ft_strjoin.c"
#include "libft/ft_strdup.c"
#include "libft/ft_strlen.c"
#include "libft/ft_substr.c"
#include "libft/get_next_line.c"
#include "libft/get_next_line_utils.c"

int	close_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_vars vars)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
	{
		printf("key_hook : %d %d\n", vars.map_info->x, vars.map_info->y);
		if (keycode == KEY_W)
			move_w(vars, vars.map_info);
		else if (keycode == KEY_A)
			move_a(vars, vars.map_info);
		else if (keycode == KEY_S)
			move_s(vars, vars.map_info);
		else if (keycode == KEY_D)
			move_d(vars, vars.map_info);
	}
	printf("x: %d, y: %d\n", vars.map_info->x, vars.map_info->y);
	printf("steps: %d\n", vars.map_info->steps);
	return (0);
}

void	set_img(t_vars v, t_map *m, char c)
{
	mlx_put_image_to_window(v.mlx, v.win, v.ground, m->x * 64, m->y * 64);
	if (c == 'w')
		m->y++;
	else if (c == 'a')
		m->x--;
	else if (c == 's')
		m->y--;
	else if (c == 'd')
		m->x++;
	mlx_put_image_to_window(v.mlx, v.win, v.ground, m->x * 64, m->y * 64);
	if (m->map[m->y][m->x] == 'E')
		mlx_put_image_to_window(v.mlx, v.win, v.e, m->x * 64, m->y * 64);
	mlx_put_image_to_window(v.mlx, v.win, v.p, m->x * 64, m->y * 64);
}

void	mlx_img_init(t_vars *v, t_map *m)
{
	int	wid;
	int	hei;

	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, m->wid * 64, m->hei * 64, "so_long");
	v->ground = mlx_xpm_file_to_image(
			v->mlx, "textures/beach_ground.xpm", &wid, &hei);
	v->wall = mlx_xpm_file_to_image(
			v->mlx, "textures/bush copy.xpm", &wid, &hei);
	v->p = mlx_xpm_file_to_image(
			v->mlx, "textures/Haley_front.xpm", &wid, &hei);
	v->c = mlx_xpm_file_to_image(
			v->mlx, "textures/star.xpm", &wid, &hei);
	v->e = mlx_xpm_file_to_image(
			v->mlx, "textures/sign.xpm", &wid, &hei);
}

void	set_init_img(char **map, t_vars v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			mlx_put_image_to_window(v.mlx, v.win, v.ground, i * 64, j * 64);
			if (map[j][i] == '1')
				mlx_put_image_to_window(v.mlx, v.win, v.wall, i * 64, j * 64);
			else if (map[j][i] == 'P')
				mlx_put_image_to_window(v.mlx, v.win, v.p, i * 64, j * 64);
			else if (map[j][i] == 'C')
				mlx_put_image_to_window(v.mlx, v.win, v.c, i * 64, j * 64);
			else if (map[j][i] == 'E')
				mlx_put_image_to_window(v.mlx, v.win, v.e, i * 64, j * 64);
			i++;
		}
		j++;
	}
}

int	main(void)
{
	t_vars	vars;
	char	*result;
	char	**map_check;

	vars.map_info = (t_map *)malloc(sizeof(t_map));
	if (!vars.map_info)
		return (0);
	result = map_join();
	vars.map_info->map = map_split(result);
	map_check = map_split(result);
	check_map(map_check, vars.map_info);
	map_info_init(vars.map_info);
	check_map_comp_count(vars.map_info->map, vars.map_info);
	find_p(vars.map_info->map, vars.map_info);
	printf("e: %d, c: %d, p: %d, wid: %d, hei: %d, x: %d, y: %d, s: %d\n",
		vars.map_info->e, vars.map_info->c, vars.map_info->p, vars.map_info->wid, vars.map_info->hei,
		vars.map_info->x, vars.map_info->y, vars.map_info->steps);
	//map_check free
	mlx_img_init(&vars, vars.map_info);
	set_init_img(vars.map_info->map, vars);
	printf("main : %d %d\n", vars.map_info->x, vars.map_info->y);
	mlx_hook(vars.win, X_EVENT_KEY_EXIT, 0, close_game, &vars);
	mlx_hook(vars.win, X_EVENT_KEY_PRESS, 0, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

// int main()
// {
// 	t_map	*map_info;
// 	t_pos			*pos;

// 	map_info = (t_map *)malloc(sizeof(t_map));
// 	pos = (t_pos *)malloc(sizeof(t_pos));
// 	if (!map_info || !pos)
// 		return (0);
// 	char *result = map_join();
// 	char **map = map_split(result);
// 	check_map_rect(map);
// 	check_map_surround_1(map);
// 	check_map_valid_map_info(map);
// 	map_infoonents_init(map_info);
// 	check_map_map_info_count(map, map_info);
// 	pos_init(pos);
// 	pos = find_p(map);
// 	has_valid_path(map, pos, map_info);
// 	// system("leaks a.out");
// }
