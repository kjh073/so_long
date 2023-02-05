/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:29:23 by joohekim          #+#    #+#             */
/*   Updated: 2022/11/29 17:55:46 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;

	if (!dst && !src)
		return (NULL);
	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	while (n--)
		*c_dst++ = *c_src++;
	return (dst);
}
