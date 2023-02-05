/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:29:39 by joohekim          #+#    #+#             */
/*   Updated: 2022/11/27 17:09:08 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;

	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst <= src)
	{
		while (len--)
			*c_dst++ = *c_src++;
	}
	else
	{
		c_dst = c_dst + len - 1;
		c_src = c_src + len - 1;
		while (len--)
			*c_dst-- = *c_src--;
	}
	return (dst);
}
