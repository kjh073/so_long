/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:29:20 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/16 18:26:51 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "libft/ft_printf.h"
#include "so_long.h"

// #include "error_msg.c"
// #include "map_list.c"
// #include "check_map.c"
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


int	dfs(char **map, int x, int y, t_map *map_info)
{
	int i = 0;
	int nx;
	int ny;
	
	nx = x;
	while (1)
	{
		nx += 1;
		if (map[y][nx] == '1' || map[y][nx] == '3')
			break ;
		if (map[y][nx] == 'C')
			map_info->c--;
		if (map[y][nx] == 'E')
			map_info->e--;
		map[y][nx] = '3';
		i++;
	}
	nx = x;
	while (1)
	{
		nx -= 1;
		if (map[y][nx] == '1' || map[y][nx] == '3')
			break ;
		if (map[y][nx] == 'C')
			map_info->c--;
		if (map[y][nx] == 'E')
			map_info->e--;
		map[y][nx] = '3';
		i++;
	}
	ny = y;
	while (1)
	{
		ny += 1;
		if (map[ny][x] == '1' || map[ny][x] == '3')
			break ;
		if (map[ny][x] == 'C')
			map_info->c--;
		if (map[ny][x] == 'E')
			map_info->e--;
		map[ny][x] = '3';
		i++;
	}
	ny = y;
	while (1)
	{
		ny -= 1;
		if (map[ny][x] == '1' || map[ny][x] == '3')
			break ;
		if (map[ny][x] == 'C')
			map_info->c--;
		if (map[ny][x] == 'E')
			map_info->e--;
		map[ny][x] = '3';
		i++;
	}
	return (i);
}

void	change(char **map, t_map *map_info)
{
	int	n;
	int	m;
	int	i;

	while (1)
	{
		i = 0;
		m = 0;
		while (map[m])
		{
			n = 0;
			while (map[m][n])
			{
				if (map[m][n] == '3' || map[m][n] == 'P')
				{
					if (dfs(map, n, m, map_info) > 0)
						i++;
				}
				n++;
			}
			m++;
		}
		if (i == 0)
			break ;
	}
}

void	find_p(char **map, t_map *map_info)
{
	int		i;
	int		j;

	j = 1;
	while (map[j])
	{
		i = 1;
		while (map[j][i])
		{
			map_info->x = i;
			map_info->y = j;
			if (map[j][i] == 'P')
				return ;
			i++;
		}
		j++;
	}
}

void	find_e(char **map, t_map *map_info)
{
	int		i;
	int		j;

	j = 1;
	while (map[j])
	{
		i = 1;
		while (map[j][i])
		{
			map_info->ex = i;
			map_info->ey = j;
			if (map[j][i] == 'E')
				return ;
			i++;
		}
		j++;
	}
}

void	has_valid_path(char **map, t_map *map_info)
{
	int	x;
	int	y;

	x = map_info->x;
	y = map_info->y;
	change(map, map_info);
	if (map_info->c != 0 || map_info->e != 0)
		print_err("Error\nThis map doesn't have a valid path.\n");
	else
		printf("has path\n");
}

