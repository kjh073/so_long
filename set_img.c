/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:04:46 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/17 17:09:58 by joohekim         ###   ########.fr       */
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
	v->p = mlx_xpm_file_to_image(
			v->mlx, "textures/Haley_front.xpm", &wid, &hei);
	v->c = mlx_xpm_file_to_image(
			v->mlx, "textures/star.xpm", &wid, &hei);
	v->e = mlx_xpm_file_to_image(
			v->mlx, "textures/teleport.xpm", &wid, &hei);
}

void	set_img_p_on_e(t_vars v)
{
	mlx_put_image_to_window(v.mlx, v.win, v.e,
		v.map_info->x * 64, v.map_info->y * 64);
	mlx_put_image_to_window(v.mlx, v.win, v.p,
		v.map_info->x * 64, v.map_info->y * 64);
}

void	set_img(char **map, t_vars v)
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
				mlx_put_image_to_window(v.mlx, v.win, v.p, i * 64, j * 64);
			else if (map[j][i] == 'C')
				mlx_put_image_to_window(v.mlx, v.win, v.c, i * 64, j * 64);
			else if (map[j][i] == 'E')
				mlx_put_image_to_window(v.mlx, v.win, v.e, i * 64, j * 64);
			if (map[v.map_info->y][v.map_info->x]
				== map[v.map_info->ey][v.map_info->ex])
				set_img_p_on_e(v);
			i++;
		}
		j++;
	}
}
