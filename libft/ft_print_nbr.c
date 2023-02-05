/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:22:58 by joohekim          #+#    #+#             */
/*   Updated: 2022/12/13 16:11:10 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	set_abs(int n, char format, int *cnt, unsigned int *abs)
{
	if (format != 'u' && n < 0)
	{
		*abs = (unsigned int)(n * -1);
		*cnt += 1;
		if (write(1, "-", 1) == -1)
			return (-1);
	}
	else
		*abs = n;
	return (0);
}

int	ft_print_nbr(int n, char format, int *cnt)
{
	unsigned int	abs;
	char			c;

	if (set_abs(n, format, cnt, &abs) == -1)
		return (-1);
	if (abs >= 0 && abs <= 9)
	{
		c = abs + '0';
		*cnt += 1;
		if (write(1, &c, 1) == -1)
			return (-1);
	}
	else
	{
		if (ft_print_nbr(abs / 10, format, cnt) == -1)
			return (-1);
		c = (abs % 10) + '0';
		*cnt += 1;
		if (write(1, &c, 1) == -1)
			return (-1);
	}
	return (0);
}
