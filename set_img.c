/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:04:46 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/17 17:21:09 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	mlx_img_init(t_vars *v, t_map *m)
{
	int	wid;
	int	hei;

	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, m->wid * 64, m->hei * 64, "so_long");
	v->ground = mlx_xpm_file_to_image(
			v->mlx, "textures/beach_ground.xpm", &wid, &hei);
	v->wall = mlx_xpm_file_to_image(
			v->mlx, "textures/bush.xpm", &wid, &hei);
	v->p_w = mlx_xpm_file_to_image(
			v->mlx, "textures/Haley_back.xpm", &wid, &hei);
	v->p_a = mlx_xpm_file_to_image(
			v->mlx, "textures/Haley_left.xpm", &wid, &hei);
	v->p_s = mlx_xpm_file_to_image(
			v->mlx, "textures/Haley_front.xpm", &wid, &hei);
	v->p_d = mlx_xpm_file_to_image(
			v->mlx, "textures/Haley_right.xpm", &wid, &hei);
	v->c = mlx_xpm_file_to_image(
			v->mlx, "textures/star.xpm", &wid, &hei);
	v->e = mlx_xpm_file_to_image(
			v->mlx, "textures/teleport.xpm", &wid, &hei);
}

void	set_img_p_on_e(t_vars v, char d)
{
	mlx_put_image_to_window(v.mlx, v.win, v.e,
		v.map_info->x * 64, v.map_info->y * 64);
	set_img_p(v, d, v.map_info->x, v.map_info->y);
}

void	set_img(char **map, t_vars v, char d)
{
	int	i;
	int	j;

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
				set_img_p(v, d, i, j);
			else if (map[j][i] == 'C')
				mlx_put_image_to_window(v.mlx, v.win, v.c, i * 64, j * 64);
			else if (map[j][i] == 'E')
				mlx_put_image_to_window(v.mlx, v.win, v.e, i * 64, j * 64);
			if (map[v.map_info->y][v.map_info->x]
				== map[v.map_info->ey][v.map_info->ex])
				set_img_p_on_e(v, d);
			i++;
		}
		j++;
	}
}

void	set_img_p(t_vars v, char d, int i, int j)
{
	if (d == 'w')
		mlx_put_image_to_window(v.mlx, v.win, v.p_w, i * 64, j * 64);
	else if (d == 'a')
		mlx_put_image_to_window(v.mlx, v.win, v.p_a, i * 64, j * 64);
	else if (d == 's')
		mlx_put_image_to_window(v.mlx, v.win, v.p_s, i * 64, j * 64);
	else if (d == 'd')
		mlx_put_image_to_window(v.mlx, v.win, v.p_d, i * 64, j * 64);
}
