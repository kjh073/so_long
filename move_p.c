/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:22:08 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/17 18:59:46 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/ft_printf.h"

void	move_w(t_vars v, t_map *m)
{
	if (m->map[m->y - 1][m->x] != '1')
	{
		m->steps++;
		ft_printf("%d steps\n", m->steps);
		if (m->map[m->y - 1][m->x] == 'C')
			m->c--;
		if (m->map[m->y - 1][m->x] == 'E' && m->c == 0)
			game_clear();
		m->map[v.map_info->ey][v.map_info->ex] = 'E';
		m->map[m->y - 1][m->x] = 'P';
		if (m->map[m->y][m->x] != 'E')
			m->map[m->y][m->x] = '0';
		m->y--;
		set_img(m->map, v, 'w');
	}
}

void	move_a(t_vars v, t_map *m)
{
	if (m->map[m->y][m->x - 1] != '1')
	{
		m->steps++;
		ft_printf("%d steps\n", m->steps);
		if (m->map[m->y][m->x - 1] == 'C')
			m->c--;
		if (m->map[m->y][m->x - 1] == 'E' && m->c == 0)
			game_clear();
		m->map[v.map_info->ey][v.map_info->ex] = 'E';
		m->map[m->y][m->x - 1] = 'P';
		if (m->map[m->y][m->x] != 'E')
			m->map[m->y][m->x] = '0';
		m->x--;
		set_img(m->map, v, 'a');
	}
}

void	move_s(t_vars v, t_map *m)
{
	if (m->map[m->y + 1][m->x] != '1')
	{
		m->steps++;
		ft_printf("%d steps\n", m->steps);
		if (m->map[m->y + 1][m->x] == 'C')
			m->c--;
		if (m->map[m->y + 1][m->x] == 'E' && m->c == 0)
			game_clear();
		m->map[v.map_info->ey][v.map_info->ex] = 'E';
		m->map[m->y + 1][m->x] = 'P';
		if (m->map[m->y][m->x] != 'E')
			m->map[m->y][m->x] = '0';
		m->y++;
		set_img(m->map, v, 's');
	}
}

void	move_d(t_vars v, t_map *m)
{
	if (m->map[m->y][m->x + 1] != '1')
	{
		m->steps++;
		ft_printf("%d steps\n", m->steps);
		if (m->map[m->y][m->x + 1] == 'C')
			m->c--;
		if (m->map[m->y][m->x + 1] == 'E' && m->c == 0)
			game_clear();
		m->map[v.map_info->ey][v.map_info->ex] = 'E';
		m->map[m->y][m->x + 1] = 'P';
		if (m->map[m->y][m->x] != 'E')
			m->map[m->y][m->x] = '0';
		m->x++;
		set_img(m->map, v, 'd');
	}
}
