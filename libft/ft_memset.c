/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:28:48 by joohekim          #+#    #+#             */
/*   Updated: 2022/11/19 15:28:54 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	set;
	unsigned char	*arr;

	set = (unsigned char)c;
	arr = (unsigned char *)b;
	while (len--)
		*arr++ = set;
	return (b);
}
