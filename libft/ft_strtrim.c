/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:34:52 by joohekim          #+#    #+#             */
/*   Updated: 2022/11/29 18:47:09 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	trim_len(char const *s1, char const *set)
{
	int		i;
	int		j;
	size_t	cnt;

	i = 0;
	j = ft_strlen(s1) - 1;
	cnt = 0;
	while (s1[i] && is_set(s1[i], set) == 1)
		i++;
	while (j >= 0 && is_set(s1[j], set) == 1)
		j--;
	while (i++ <= j)
		cnt++;
	return (cnt);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	cnt;
	char	*arr;

	if (s1 == NULL || set == NULL)
		return (NULL);
	cnt = trim_len(s1, set);
	i = 0;
	while (is_set(s1[i], set) == 1)
		i++;
	arr = ft_substr(s1, i, cnt);
	if (arr == NULL)
		return (NULL);
	return (arr);
}
