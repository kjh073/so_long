/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:27:57 by joohekim          #+#    #+#             */
/*   Updated: 2022/12/13 16:13:34 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(char c, int *cnt);
int	ft_print_hex(unsigned long long num, char format, int *cnt);
int	ft_print_nbr(int n, char format, int *cnt);
int	ft_print_str(char *s, int *cnt);

#endif