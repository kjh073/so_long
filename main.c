/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:09:27 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/17 17:18:42 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "libft/ft_printf.h"
#include "so_long.h"
#include <stdlib.h>
#include "mlx/mlx.h"

// #include "print_msg.c"
// #include "map_make.c"
// #include "map_check.c"
// #include "bfs.c"
// #include "move_p.c"
// #include "so_long_utils.c"
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

int	main(void)
{
	t_vars	vars;
	char	*result;

	vars.map_info = (t_map *)malloc(sizeof(t_map));
	if (vars.map_info == NULL)
		return (-1);
	if (make_map(&result, vars.map_info) == -1)
		return (-1);
	check_map(vars.map_info->map_check, vars.map_info);
	find_p(vars.map_info->map, vars.map_info);
	find_e(vars.map_info->map, vars.map_info);
	mlx_img_init(&vars, vars.map_info);
	set_img(vars.map_info->map, vars, 's');
	mlx_hook(vars.win, X_EVENT_KEY_EXIT, 0, close_game, &vars);
	mlx_hook(vars.win, X_EVENT_KEY_PRESS, 0, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
