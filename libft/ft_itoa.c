/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:57:09 by joohekim          #+#    #+#             */
/*   Updated: 2022/11/29 13:26:21 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	allocate_len(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static char	*putnbr(int num, char *arr, int len)
{
	int				i;
	unsigned int	abs;
	int				end_index;

	i = 0;
	end_index = len - 1;
	abs = (unsigned int)num;
	if (num < 0)
	{
		arr[0] = '-';
		i++;
		abs = (unsigned int)(num * -1);
	}
	while (i++ < len)
	{
		arr[end_index--] = (abs % 10) + '0';
		abs /= 10;
	}
	arr[len] = '\0';
	return (arr);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*arr;

	len = allocate_len(n);
	arr = (char *)malloc((len + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	return (putnbr(n, arr, len));
}
