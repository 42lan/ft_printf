/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:04:35 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/31 16:50:58 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	length_h(const char **format, t_info *info)
{
	info->specs->length = BIT_1; // BIT_1 = h
	if (*(*format + 1) == 'h') // hh
	{
		info->specs->length = BIT_2;  // BIT_2 = hh
		(*format)++;
	}
	(*format)++;
}

void	length_l(const char **format, t_info *info)
{
	info->specs->length = BIT_3; // BIT_3 = l
	if (*(*format + 1) == 'l') // ll
	{
		info->specs->length = BIT_4; // BIT_4 = ll
		(*format)++;
	}
	(*format)++;
}

void	length_L(const char **format, t_info *info)
{
	ft_putendl("Length -> L");
	info->specs->length = BIT_5; // BIT_5 = L
	(*format)++;
}
