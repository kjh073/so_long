/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooheekim <jooheekim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:28:39 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/05 16:14:54 by jooheekim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"
#include "so_long.h"

char	*map_join(void)
{
	int		fd;
	char	*result;
	char	*s1;
	char	*temp;

	s1 = "";
	fd = open("maps/map.ber", O_RDONLY);
	result = get_next_line(fd);
	while (result != NULL && s1 != NULL)
	{
		s1 = get_next_line(fd);
		temp = ft_strjoin(result, s1);
		if (temp == NULL)
			return (NULL);
		free(s1);
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
	// free(map);
	return (result);
}
