/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooheekim <jooheekim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:09:27 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/19 02:57:51 by jooheekim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include "mlx/mlx.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	char	*result;

	if (ac == 2)
	{
		vars.map_info = (t_map *)malloc(sizeof(t_map));
		if (vars.map_info == NULL)
			return (1);
		if (make_map(&result, vars.map_info, av[1]) == -1)
			return (1);
		check_map(vars.map_info->map_check, vars.map_info, vars);
		find_p(vars.map_info->map, vars.map_info);
		find_e(vars.map_info->map, vars.map_info);
		mlx_img_init(&vars, vars.map_info);
		set_img(vars.map_info->map, vars, 's');
		mlx_hook(vars.win, X_EVENT_KEY_EXIT, 0, close_game, &vars);
		mlx_hook(vars.win, X_EVENT_KEY_PRESS, 0, key_hook, &vars);
		mlx_loop(vars.mlx);
		return (0);
	}
	return (1);
}
