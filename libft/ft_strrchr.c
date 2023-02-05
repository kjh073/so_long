/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:31:29 by joohekim          #+#    #+#             */
/*   Updated: 2022/11/29 18:19:38 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	char	ch;

	s_len = ft_strlen(s);
	s = s + s_len;
	ch = (char)c;
	while ((int)s_len > -1)
	{
		if (*s == ch)
			return ((char *)s);
		s--;
		s_len--;
	}
	return (0);
}
