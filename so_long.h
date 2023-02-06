/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooheekim <jooheekim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:54:30 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/07 02:52:56 by jooheekim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

typedef struct s_vars
{
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
}		t_data;

typedef struct s_param
{
	int	x;
	int	y;
}	t_param;

typedef struct s_components
{
	int	p;
	int	e;
	int	c;
}	t_components;

char	*map_join(void);
char	**map_split(char *map);
int		count_c(char *str, char c);
void	check_map_rect(char **map);
void	check_map_surround_1(char **map);
void	check_map_valid_comp(char **map);
void	check_map_comp_count(char **map, t_components *comp);
void	print_err(char *str);
void	dfs(char **map, int x, int y, t_components *comp, int *result);
t_param	*find_p(char **map);
void	has_valid_path(char **map, t_param *pos, t_components *comp);

#endif