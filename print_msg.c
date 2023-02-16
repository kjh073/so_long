/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:53:53 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/16 19:11:13 by joohekim         ###   ########.fr       */
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

void	print_err(char *str)
{
	ft_printf(str);
	exit(0);
}

int	game_clear(void)
{
	ft_printf("GAME CLEAR!\n");
	exit(0);
	return (0);
}
