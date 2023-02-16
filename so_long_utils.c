/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:37:33 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/16 20:08:55 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_c(char *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == c)
			cnt++;
		i++;
	}
	return (cnt);
}

void	map_info_init(t_map *map_info)
{
	map_info->p = 0;
	map_info->e = 0;
	map_info->c = 0;
	map_info->wid = 0;
	map_info->hei = 0;
	map_info->x = 0;
	map_info->y = 0;
	map_info->ex = 0;
	map_info->ey = 0;
	map_info->steps = 0;
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
