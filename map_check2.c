/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooheekim <jooheekim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 01:51:51 by jooheekim         #+#    #+#             */
/*   Updated: 2023/02/19 01:52:00 by jooheekim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char **map, t_map *map_info, t_vars vars)
{
	check_map_rect(map);
	check_map_surround_1(map);
	check_map_valid_comp(map);
	map_info_init(map_info);
	check_map_comp_count(map, map_info);
	check_map_max(vars);
	find_p(map, map_info);
	has_valid_path(map_info);
	map_info_init(map_info);
	check_map_comp_count(map_info->map, map_info);
}
