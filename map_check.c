/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:30:45 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/17 18:24:18 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_rect(char **map)
{
	int	width;
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (i == 0)
			width = j;
		if (width != j)
			print_err("Error\nYou have to make a rectangle map.\n");
		i++;
	}
}

void	check_map_surround_1(char **map)
{
	int	width;
	int	height;

	height = 0;
	width = 0;
	while (map[height])
	{
		while (map[height][width])
			width++;
		if (map[height][0] != '1' || map[height][width - 1] != '1')
			print_err("Error\nMap has to be surrounded by '1'.\n");
		height++;
	}
	if (count_c(map[0], '1') != width || count_c(map[height - 1], '1') != width)
		print_err("Error\nMap has to be surrounded by '1'.\n");
}

void	check_map_valid_comp(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1')
				print_err("Error\nMap has to make with P, C, E, 1, 0.\n");
			j++;
		}
		i++;
	}
}

void	check_map_comp_count(char **map, t_map *map_info)
{
	int	i;

	i = 0;
	while (map[i])
	{
		map_info->p += count_c(map[i], 'P');
		map_info->e += count_c(map[i], 'E');
		map_info->c += count_c(map[i], 'C');
		i++;
	}
	while (map[map_info->hei])
	{
		map_info->wid = 0;
		while (map[map_info->hei][map_info->wid])
			map_info->wid++;
		map_info->hei++;
	}
	if (map_info->p != 1 || map_info->e != 1 || map_info->c < 1)
		print_err("Error\nMap has to have P = 1, E = 1, C >= 1.\n");
}

void	check_map(char **map, t_map *map_info)
{
	check_map_rect(map);
	check_map_surround_1(map);
	check_map_valid_comp(map);
	map_info_init(map_info);
	check_map_comp_count(map, map_info);
	find_p(map, map_info);
	has_valid_path(map_info);
	map_info_init(map_info);
	check_map_comp_count(map_info->map, map_info);
}
