/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:29:20 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/07 20:31:01 by joohekim         ###   ########.fr       */
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

// void	dfs(t_map_info *par, t_check *check, int x, int y)
// {
// 	int			i;
// 	int			nx;
// 	int			ny;
// 	const int	dx[4] = {0, 0, -1, 1};
// 	const int	dy[4] = {1, -1, 0, 0};
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

void	dfs(char **map, int x, int y, t_components *comp, int *result)
{
	const int	dx[4] = {0, 0, -1, 1};
	const int	dy[4] = {-1, 1, 0, 0};
	int			i;
	int nx;
	int ny;

	i = 0;
	// if (comp->c == 0 && map[y][x] == 'E')
	// {
	// 	*result += 1;
	// 	printf("FIND PATH!!!!!!!!!!init dfs!!!!!!!!! RESULT : %d\n",*result);
	// 	return ;
	// }
	// if (*result > 0)
	// 	return ;
	if (map[y][x] != 'E')
		map[y][x] = '1';
	while (i < 4)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (map[ny][nx] != '1' && map[ny][nx])
		{
			if (map[ny][nx] == 'C')
				comp->c--;
			else if (map[ny][nx] != 'E')
				map[ny][nx] = '1';
			dfs(map, nx, ny, comp, result);
			if (comp->c == 0 && (map[y][x] == 'E' || map[ny][nx] == 'E'))
			{
				// if (*result <= 0)
				*result += 1;
				printf("FIND PATH!!!!!!!!!after dfs!!!!!!!!!!!!!!! RESULT : %d\n",*result);
				return ;
			}
			printf("x: %d, y: %d\n", x, y);
			if (map[ny][nx] != 'E')
				map[ny][nx] = '0';
		}
		i++;
	}
	return ;
}

t_param	*find_p(char **map)
{
	t_param	*pos;
	int		i;
	int		j;

	j = 1;
	pos = (t_param *)malloc(sizeof(t_param));
	if (!pos)
		return (NULL);
	while (map[j])
	{
		i = 1;
		while (map[j][i])
		{
			pos->x = i;
			pos->y = j;
			if (map[j][i] == 'P')
				return (pos);
			i++;
		}
		j++;
	}
	return (0);
}

//p 위치 저장, return 해서 dfs경로 끝나면 c의 개수는 어떻게 측정할건지

void	has_valid_path(char **map, t_param *pos, t_components *comp)
{
	int	cnt;
	int x = pos->x;
	int y = pos->y;

	cnt = 0;
	dfs(map, x, y, comp, &cnt);
	printf("%d\n", cnt);
	if (cnt <= 0)
		print_err("Error\nThis map doesn't have a valid path.\n");
	else
		printf("has path");
}

void	param_init(t_param *param)
{
	param->x = 0;
	param->y = 0;
	param->steps = 0;
}

void	components_init(t_components *comp)
{
	comp->p = 0;
	comp->e = 0;
	comp->c = 0;
}
