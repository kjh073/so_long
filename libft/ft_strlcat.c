/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:30:14 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/01 18:33:54 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	j = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (dstsize > d_len)
	{
		while (dst[i])
			i++;
		while (dstsize > i + 1 && src[j])
			dst[i++] = src[j++];
		dst[i] = '\0';
		return (s_len + d_len);
	}
	else
		return (s_len + dstsize);
}
