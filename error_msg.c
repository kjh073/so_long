/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooheekim <jooheekim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:53:53 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/06 19:37:12 by jooheekim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
// #include "libft/ft_printf.h"
// #include "libft/ft_printf.c"
// #include "libft/ft_print_char.c"
// #include "libft/ft_print_hex.c"
// #include "libft/ft_print_nbr.c"
// #include "libft/ft_print_str.c"
#include <stdlib.h>

// void	error_not_rectangle(void)
// {
// 	ft_printf("Error\nYou have to make a rectangle map.\n");
// 	exit(0);
// }

// void	error_not_surround_1(void)
// {
// 	ft_printf("Error\nMap has to be surrounded by '1'.\n");
// 	exit(0);
// }

// void	error_invalid_map_component(void)
// {
// 	ft_printf("Error\nMap has to make with P, C, E, 1, 0.\n");
// 	exit(0);
// }

// void	error_invalid_map_component_count(void)
// {
// 	ft_printf("Error\nMap has to have P = 1, E = 1, C >= 1.\n");
// 	exit(0);
// }

void	print_err(char *str)
{
	ft_printf(str);
	exit(0);
}
