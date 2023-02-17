/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:12:12 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/17 15:12:12 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/* ===============.=============== */

void	bfs(int x, int y, t_map *map_info);
void	has_valid_path(char **map, t_map *map_info);
int		close_game(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	mlx_img_init(t_vars *v, t_map *m);
void	set_img_p_on_e(t_vars v);
void	set_img(char **map, t_vars v);
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
void	find_p(char **map, t_map *map_info);
void	find_e(char **map, t_map *map_info);

/* ===============./libft=============== */

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
int		ft_print_char(char c, int *cnt);
int		ft_print_hex(unsigned long long num, char format, int *cnt);
int		ft_print_nbr(int n, char format, int *cnt);
int		ft_print_str(char *s, int *cnt);
int		ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*get_next_line(int fd);
void	null_free(char **str);

/* ===============./mlx=============== */

int		mipng_is_type(unsigned char *ptr, char *type);
int		mipng_fill_img(void *img, unsigned char *buf, png_info_t *pi);
int		mipng_data(void *img, unsigned char *dat, png_info_t *pi);
int		mipng_magic(unsigned char *ptr, int size);
int		mipng_crc(unsigned char *ptr, int len);
int		mipng_structure(unsigned char *ptr, int size, unsigned char **hdr, unsigned char **dat);
int		mipng_verif_hdr(unsigned char *hdr, png_info_t *pi);
void	*mlx_int_parse_png(void *xvar, unsigned char *fptr, int size, int *width, int *height);
void	*mlx_png_file_to_image(void *xvar, char *file, int *width, int *height);
int		mlx_int_str_str(char *str,char *find,int len);
int		mlx_int_str_str_cote(char *str,char *find,int len);
char	**mlx_int_str_to_wordtab(char *str);
char	*mlx_int_get_line(char *ptr,int *pos,int size);
char	*mlx_int_static_line(char **xpm_data,int *pos,int size);
int		mlx_int_get_col_name(char *str,int size);
int		mlx_int_get_text_rgb(char *name, char *end);
void	mlx_int_xpm_set_pixel(char *data, int opp, int col, int x);
void	*mlx_int_parse_xpm(void *xvar,void *info,int info_size,char *(*f)(), int *width, int *height);
void	mlx_int_file_get_rid_comment(char *ptr, int size);
void	*mlx_xpm_file_to_image(void *xvar,char *file,int *width,int *height);
void	*mlx_xpm_to_image(void *xvar,char **xpm_data,int *width,int *height);

#endif
