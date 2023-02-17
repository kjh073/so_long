/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:29:20 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/17 18:24:09 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs(int x, int y, t_map *map_info)
{
	const int	dx[4] = {0, 0, -1, 1};
	const int	dy[4] = {-1, 1, 0, 0};
	int			nx;
	int			ny;
	int			i;

	i = 0;
	map_info->map_check[y][x] = '3';
	while (i < 4)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (map_info->map_check[ny][nx] != '1'
			&& map_info->map_check[ny][nx] != '3')
		{
			if (map_info->map_check[ny][nx] == 'C')
				map_info->c--;
			if (map_info->map_check[ny][nx] == 'E')
				map_info->e--;
			dfs(nx, ny, map_info);
			if (map_info->c == 0 && map_info->e == 0)
				return ;
		}
		i++;
	}
}

void	has_valid_path(t_map *map_info)
{
	dfs(map_info->x, map_info->y, map_info);
	if (map_info->c != 0 || map_info->e != 0)
		print_err("Error\nThis map doesn't have a valid path.\n");
}
