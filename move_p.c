/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:22:08 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/16 15:49:51 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	move_w(t_vars v, t_map *m)
{
	if (m->map[m->y + 1][m->x] != '1' || m->map[m->y + 1][m->x])
	{
		if (m->map[m->y + 1][m->x] == 'C')
			m->c--;
		if (m->map[m->y + 1][m->x] == 'E' || m->c == 0)
			game_clear();
		m->steps++;
		printf("steps: %d\n", m->steps);
		set_img(v, m, 'w');
	}
}

void	move_a(t_vars v, t_map *m)
{
	if (m->map[m->x - 1][m->x] != '1' || m->map[m->x - 1][m->x])
	{
		if (m->map[m->x - 1][m->x] == 'C')
			m->c--;
		if (m->map[m->x - 1][m->x] == 'E' || m->c == 0)
			game_clear();
		m->steps++;
		printf("steps: %d\n", m->steps);
		set_img(v, m, 'a');
	}
}

void	move_s(t_vars v, t_map *m)
{
	if (m->map[m->y - 1][m->x] != '1' || m->map[m->y - 1][m->x])
	{
		if (m->map[m->y - 1][m->x] == 'C')
			m->c--;
		if (m->map[m->y - 1][m->x] == 'E' || m->c == 0)
			game_clear();
		m->steps++;
		printf("steps: %d\n", m->steps);
		set_img(v, m, 's');
	}
}

void	move_d(t_vars v, t_map *m)
{
	printf("key_hook : %d %d\n", v.map_info->x, v.map_info->y);
	if (m->map[m->x + 1][m->x] != '1' || m->map[m->x + 1][m->x])
	{
		if (m->map[m->x + 1][m->x] == 'C')
			m->c--;
		if (m->map[m->x + 1][m->x] == 'E' || m->c == 0)
			game_clear();
		m->steps++;
		printf("steps: %d\n", m->steps);
		set_img(v, m, 'd');
	}
}
