/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:29:20 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/17 15:37:38 by joohekim         ###   ########.fr       */
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

void	bfs(char **map, int x, int y, t_map *map_info)
{
	const int	dx[4] = {0, 0, -1, 1};
	const int	dy[4] = {-1, 1, 0, 0};
	int			nx;
	int			ny;
	int			i;

	i = 0;
	map[y][x] = '3';
	while (i < 4)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (map[ny][nx] != '1' && map[ny][nx] != '3')
		{
			if (map[ny][nx] == 'C')
				map_info->c--;
			if (map[ny][nx] == 'E')
				map_info->e--;
			bfs(map, nx, ny, map_info);
			if (map_info->c == 0 && map_info->e == 0)
				return ;
		}
		i++;
	}
}

void	has_valid_path(char **map, t_map *map_info)
{
	bfs(map, map_info->x, map_info->y, map_info);
	if (map_info->c != 0 || map_info->e != 0)
		print_err("Error\nThis map doesn't have a valid path.\n");
	else
		printf("has path\n");
}
