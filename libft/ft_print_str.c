/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:55:56 by joohekim          #+#    #+#             */
/*   Updated: 2022/12/13 16:03:11 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_str(char *s, int *cnt)
{
	if (!s)
	{
		*cnt += 6;
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (0);
	}
	while (*s)
	{
		if (write(1, s, 1) == -1)
			return (-1);
		*cnt += 1;
		s++;
	}
	return (0);
}
