/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:54:30 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/17 19:32:20 by joohekim         ###   ########.fr       */
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
	void			*ground_b;
	void			*p_w;
	void			*p_a;
	void			*p_s;
	void			*p_d;
	void			*c;
	void			*e;
	struct s_map	*map_info;
}	t_vars;

typedef struct s_map
{
	char	**map;
	char	**map_check;
	int		p;
	int		e;
	int		c;
	int		wid;
	int		hei;
	int		x;
	int		y;
	int		ex;
	int		ey;
	int		steps;
}	t_map;

void	dfs(int x, int y, t_map *map_info);
void	has_valid_path(t_map *map_info);
int		close_game(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	mlx_img_init(t_vars *v, t_map *m);
void	set_img_p_on_e(t_vars v, char d);
void	set_img(char **map, t_vars v, char d);
void	check_map_rect(char **map);
void	check_map_surround_1(char **map);
void	check_map_valid_comp(char **map);
void	check_map_comp_count(char **map, t_map *map_info);
void	check_map(char **map, t_map *map_info);
char	*map_join(char *file_name);
char	**map_split(char *map);
void	move_w(t_vars v, t_map *m);
void	move_a(t_vars v, t_map *m);
void	move_s(t_vars v, t_map *m);
void	move_d(t_vars v, t_map *m);
void	print_err(char *str);
void	game_clear(void);
int		count_c(char *str, char c);
void	map_info_init(t_map *map_info);
void	find_p(char **map, t_map *map_info);
void	find_e(char **map, t_map *map_info);
int		make_map(char **result, t_map *map_info, char *file_name);
int		cnt_map_hei(t_map *map_info);
void	set_img_p(t_vars v, char d, int i, int j);
void	set_img_ground(t_vars v, int i, int j);
char	*make_file_name(char *file_name);

#endif