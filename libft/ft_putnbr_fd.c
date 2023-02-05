/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:32:46 by joohekim          #+#    #+#             */
/*   Updated: 2022/11/19 20:24:45 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	abs;
	char			c;

	if (n < 0)
	{
		abs = (unsigned int)(n * -1);
		write(fd, "-", 1);
	}
	else
		abs = n;
	if (abs >= 0 && abs <= 9)
	{
		c = abs + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(abs / 10, fd);
		c = (abs % 10) + '0';
		write(fd, &c, 1);
	}
}
