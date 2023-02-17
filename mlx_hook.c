/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:06:19 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/17 18:50:27 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"
#include <stdlib.h>

int	close_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
	{
		if (keycode == KEY_W)
			move_w(*vars, vars->map_info);
		else if (keycode == KEY_A)
			move_a(*vars, vars->map_info);
		else if (keycode == KEY_S)
			move_s(*vars, vars->map_info);
		else if (keycode == KEY_D)
			move_d(*vars, vars->map_info);
	}
	return (0);
}
