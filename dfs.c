/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooheekim <jooheekim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:29:20 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/06 02:10:11 by jooheekim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"
#include "so_long.h"

// #include "error_msg.c"
// #include "map_list.c"
// #include "check_map.c"
// #include "ft_printf.c"
// #include "ft_print_char.c"
// #include "ft_print_hex.c"
// #include "ft_print_nbr.c"
// #include "ft_print_str.c"
// #include "ft_split.c"
// #include "ft_strjoin.c"
// #include "ft_strdup.c"
// #include "ft_strlen.c"
// #include "ft_substr.c"
// #include "get_next_line.c"
// #include "get_next_line_utils.c"

// void	dfs(t_map_info *par, t_check *check, int x, int y)
// {
// 	int	i;
// 	int	nx;
// 	int	ny;
// 	const int	dx[4] = {0, 0, -1, 1};
// 	int	dy[4] = {1, -1, 0, 0};
// 	check->map[x][y] = 1;
// 	if (par->map[x][y] == 'C')
// 		check->item_cnt--;
// 	if (par->map[x][y] == 'E')
// 		check->exit = 1;
// 	i = 0;
// 	while (i < 4)
// 	{
// 		nx = x + dx[i];
// 		ny = y + dy[i];
// 		if (check->map[ny][nx] != '1')
// 			dfs(par, check, nx, ny);
// 		i++;
// 	}
// }

int	dfs(char **map, t_param *player)
{
	const int	dx[4] = {0, 0, -1, 1};
	const int	dy[4] = {1, -1, 0, 0};
	int			nx;
	int			ny;
	int			i;

	i = 0;
	while (i < 4)
	{
		nx = player->x + dx[i];
		ny = player->y + dy[i];
		if (map[nx][ny] == '0' || map[nx][ny] == 'C')
			dfs(map, player);
	}
	return (0);
}

t_param	*find_p(char **map)
{
	t_param	*player;
	int		i;
	int		j;

	i = 0;
	player = (t_param *)malloc(sizeof(t_param));
	if (!player)
		return (0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			player->x = i;
			player->y = j;
			if (map[i][j] == 'P')
				return (player);
		}
	}
	return (0);
}

//p 위치 저장, return 해서 dfs경로 끝나면 c의 개수는 어떻게 측정할건지

void	has_valid_path(char **map, t_param *player)
{
	int	cnt;

	cnt = dfs(map, player);
	if (cnt <= 0)
		print_err("Error\nThis map doesn't have a valid path.\n");
}

int main()
{
	t_components	*comp;
	
	comp = (t_components *)malloc(sizeof(t_components));
	if (!comp)
		return (0);
	char *result = map_join();
	char **map = map_split(result);
	check_map_rect(map);
	check_map_surround_1(map);
	check_map_valid_comp(map);
	check_map_comp_count(map, comp);
	printf("%d, %d, %d\n", comp->c, comp->e, comp->p);
	// system("leaks a.out");
}
