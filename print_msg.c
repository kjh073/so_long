/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:53:53 by joohekim          #+#    #+#             */
/*   Updated: 2023/02/17 18:24:32 by joohekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include <stdlib.h>

void	print_err(char *str)
{
	ft_printf(str);
	exit(0);
}

void	game_clear(void)
{
	ft_printf("GAME CLEAR!\n");
	exit(0);
}
