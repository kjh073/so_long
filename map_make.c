/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:28:39 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/17 17:00:49 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "so_long.h"

int	cnt_map_hei(t_map *map_info)
{
	int	i;

	i = 0;
	while (map_info->map[i])
		i++;
	return (i);
}

char	*map_join(void)
{
	int		fd;
	char	*result;
	char	*s1;
	char	*temp;

	s1 = "";
	fd = open("maps/map.ber", O_RDONLY);
	result = get_next_line(fd);
	if (result == NULL)
		return (NULL);
	while (result != NULL && s1 != NULL)
	{
		s1 = get_next_line(fd);
		temp = ft_strjoin(result, s1);
		if (temp == NULL)
			return (NULL);
		free(s1);
		if (s1 != NULL)
			free(result);
		result = temp;
	}
	return (result);
}

char	**map_split(char *map)
{
	char	**result;

	result = ft_split(map, '\n');
	if (result == NULL)
		return (NULL);
	return (result);
}

int	make_map(char **result, t_map *map_info)
{
	*result = map_join();
	if (*result == NULL)
		return (-1);
	map_info->map = map_split(*result);
	if (map_info->map == NULL)
	{
		free(*result);
		return (-1);
	}
	map_info->map_check = map_split(*result);
	if (map_info->map_check == NULL)
	{
		ft_memfree(map_info->map, cnt_map_hei(map_info) - 1);
		free(*result);
		return (-1);
	}
	return (0);
}
