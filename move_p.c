/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:22:08 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/16 18:47:30 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	move_w(t_vars v, t_map *m)
{
	if (m->map[m->y - 1][m->x] != '1')
	{
		if (m->map[m->y - 1][m->x] == 'C')
			m->c--;
		if (m->map[m->y - 1][m->x] == 'E' && m->c == 0)
			game_clear();
		if (m->map[m->y - 1][m->x] != 'E')
			m->map[m->y - 1][m->x] = 'P';
		m->map[m->y][m->x] = '0';
		m->y--;
		m->steps++;
		printf("steps: %d\n", m->steps);
		printf("steps: %d\n", v.map_info->x);
		printf("c: %d\n", v.map_info->c);
		set_init_img(m->map, v);
	}
}

void	move_a(t_vars v, t_map *m)
{
	if (m->map[m->y][m->x - 1] != '1')
	{
		if (m->map[m->y][m->x - 1] == 'C')
			m->c--;
		if (m->map[m->y][m->x - 1] == 'E' && m->c == 0)
			game_clear();
		if (m->map[m->y][m->x - 1] != 'E')
			m->map[m->y][m->x - 1] = 'P';
		m->map[m->y][m->x] = '0';
		m->x--;
		m->steps++;
		printf("steps: %d\n", m->steps);
		printf("c: %d\n", v.map_info->c);
		set_init_img(m->map, v);
	}
}

void	move_s(t_vars v, t_map *m)
{
	if (m->map[m->y + 1][m->x] != '1')
	{
		if (m->map[m->y + 1][m->x] == 'C')
			m->c--;
		if (m->map[m->y + 1][m->x] == 'E' && m->c == 0)
			game_clear();
		if (m->map[m->y + 1][m->x] != 'E')
			m->map[m->y + 1][m->x] = 'P';
		m->map[m->y][m->x] = '0';
		m->y++;
		m->steps++;
		printf("steps: %d\n", m->steps);
		printf("c: %d\n", v.map_info->c);
		set_init_img(m->map, v);
	}
}

void	move_d(t_vars v, t_map *m)
{
	printf("key_hook : %d %d\n", v.map_info->x, v.map_info->y);
	if (m->map[m->y][m->x + 1] != '1')
	{
		if (m->map[m->y][m->x + 1] == 'C')
			m->c--;
		if (m->map[m->y][m->x + 1] == 'E' && m->c == 0)
			game_clear();
		// if (m->map[m->y][m->x + 1] != 'E')
		// {
		// 	m->map[m->y][m->x + 1] = 'P';
		// 	m->map[m->y][m->x] = '0';
		// }
		// else
		m->map[m->y][m->x + 1] = 'P';
		m->map[m->y][m->x] = '0';
		m->x++;
		m->steps++;
		printf("steps: %d\n", m->steps);
		printf("c: %d\n", v.map_info->c);
		set_init_img(m->map, v);
	}
}
