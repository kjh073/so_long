/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:32:01 by joohekim          #+#    #+#             */
/*   Updated: 2022/11/29 17:48:00 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*arr;
	size_t			i;

	ch = (unsigned char)c;
	arr = (unsigned char *)s;
	i = n;
	while (n > 0)
	{
		if (*arr == ch)
			return ((void *)(s + (i - n)));
		arr++;
		n--;
	}
	return (0);
}
