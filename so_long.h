/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:54:30 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/16 15:05:31 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_ESC			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	void			*wall;
	void			*ground;
	void			*p;
	void			*c;
	void			*e;
	struct s_map	*map_info;
}	t_vars;

typedef struct s_map
{
	char	**map;
	int		p;
	int		e;
	int		c;
	int		wid;
	int		hei;
	int		x;
	int		y;
	int		steps;
}	t_map;

// void	dfs(char **map, int x, int y, t_map *map_info, int *result);
int		dfs(char **map, int x, int y, t_map *map_info);
void	change(char **map, t_map *map_info);
void	find_p(char **map, t_map *map_info);
void	has_valid_path(char **map, t_map *map_info);
int		close_game(t_vars *vars);
int		key_hook(int keycode, t_vars vars);
void	set_img(t_vars v, t_map *m, char c);
void	mlx_img_init(t_vars *v, t_map *m);
void	set_init_img(char **map, t_vars v);
void	check_map_rect(char **map);
void	check_map_surround_1(char **map);
void	check_map_valid_comp(char **map);
void	check_map_comp_count(char **map, t_map *map_info);
void	check_map(char **map, t_map *map_info);
char	*map_join(void);
char	**map_split(char *map);
void	move_w(t_vars v, t_map *m);
void	move_a(t_vars v, t_map *m);
void	move_s(t_vars v, t_map *m);
void	move_d(t_vars v, t_map *m);
void	print_err(char *str);
int		game_clear(void);
int		count_c(char *str, char c);
void	map_info_init(t_map *map_info);

#endif