/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:35:22 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/17 16:48:59 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memfree(char **result, int k)
{
	while (k >= 0)
	{
		free(result[k]);
		result[k] = NULL;
		k--;
	}
	free(result);
	result = NULL;
	return (0);
}

static int	is_word(char c, char del)
{
	if (c == del)
		return (0);
	return (1);
}

static int	word_count(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (is_word(s[i], c) == 0 && s[i])
			i++;
		if (s[i] == '\0')
			break ;
		if ((i == 0 && is_word(s[i], c) == 1)
			|| (is_word(s[i - 1], c) == 0 && is_word(s[i], c) == 1))
			cnt++;
		while (is_word(s[i], c) == 1 && s[i])
			i++;
	}
	return (cnt);
}

static char	allocate_each_word(char const *s, char c, char **result)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (is_word(s[i], c) == 0 && s[i])
			i++;
		if (s[i] == '\0')
			break ;
		j = 0;
		while (is_word(s[i + j], c) == 1 && s[i + j])
			j++;
		result[k] = ft_substr(s, i, j);
		if (result[k] == NULL)
			return (ft_memfree(result, k));
		k++;
		i += j;
	}
	result[k] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (result == NULL)
		return (NULL);
	if (allocate_each_word(s, c, result) != 1)
		return (NULL);
	return (result);
}
