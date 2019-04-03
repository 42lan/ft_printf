/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeholder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 05:50:25 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/31 16:54:43 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_bit_state(unsigned char c)
{
	printf("%i", (c & BIT_8) ? 1 : 0);
	printf("%i", (c & BIT_7) ? 1 : 0);
	printf("%i", (c & BIT_6) ? 1 : 0);
	printf("%i", (c & BIT_5) ? 1 : 0);
	printf("%i", (c & BIT_4) ? 1 : 0);
	printf("%i", (c & BIT_3) ? 1 : 0);
	printf("%i", (c & BIT_2) ? 1 : 0);
	printf("%i", (c & BIT_1) ? 1 : 0);
}

void	print_info(t_info *info)
{
	ft_putstr("%[");ft_putnbr(info->specs->parameter);
	ft_putstr("][");ft_putnbr(info->specs->flags->space);
	ft_putnbr(info->specs->flags->hash);
	ft_putnbr(info->specs->flags->plus);
	ft_putnbr(info->specs->flags->minus);
	ft_putnbr(info->specs->flags->zero);
	ft_putstr("][");ft_putnbr(info->specs->width);
	ft_putstr("].[");ft_putnbr(info->specs->precision);
	ft_putstr("][");print_bit_state(info->specs->length);
	printf("]%c\n", info->type);
	printf("{{{  %d  }}}\n", info->specs->flags->point);
}
