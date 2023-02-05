/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:55:02 by joohekim          #+#    #+#             */
/*   Updated: 2022/12/13 19:06:35 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char format, va_list ap, int *cnt)
{
	if (format == 'd' || format == 'i')
		return (ft_print_nbr(va_arg(ap, int), format, cnt));
	else if (format == 'u')
		return (ft_print_nbr(va_arg(ap, unsigned int), format, cnt));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), format, cnt));
	else if (format == 'c')
		return (ft_print_char(va_arg(ap, int), cnt));
	else if (format == 's')
		return (ft_print_str(va_arg(ap, char *), cnt));
	else if (format == 'p')
	{
		if (ft_print_str("0x", cnt) == -1)
			return (-1);
		if (ft_print_hex(va_arg(ap, unsigned long long), format, cnt) == -1)
			return (-1);
	}
	else if (format == '%')
		return (ft_print_char(format, cnt));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cnt;

	va_start(ap, format);
	cnt = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (check_format(*format, ap, &cnt) == -1)
				return (-1);
		}
		else
		{
			if (ft_print_char(*format, &cnt) == -1)
				return (-1);
		}
		format++;
	}
	va_end(ap);
	return (cnt);
}
