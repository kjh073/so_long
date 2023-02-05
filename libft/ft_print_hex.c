/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:01:19 by joohekim          #+#    #+#             */
/*   Updated: 2022/12/13 18:59:38 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_hex(unsigned long long num, char format, int *cnt)
{
	char	*base;

	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (num >= 0 && num <= 15)
	{
		*cnt += 1;
		if (write(1, &base[num % 16], 1) == -1)
			return (-1);
	}
	else
	{
		if (ft_print_hex(num / 16, format, cnt) == -1)
			return (-1);
		*cnt += 1;
		if (write(1, &base[num % 16], 1) == -1)
			return (-1);
	}
	return (0);
}
