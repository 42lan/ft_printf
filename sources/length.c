/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:04:35 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/04 19:13:00 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			length_h(const char **format, t_info *info)
{
	if (*(*format + 1) == 'h') // hh
	{
		info->specs->length = BIT_2;  // BIT_2 = hh
		(*format)++;
	}
	else // h
	{
		info->specs->length = BIT_1; // BIT_1 = h
	}
	(*format)++;
}

void			length_l(const char **format, t_info *info)
{
	if (*(*format + 1) == 'l') // ll
	{
		info->specs->length = BIT_4; // BIT_4 = ll
		(*format)++;
	}
	else // l
	{
		info->specs->length = BIT_3; // BIT_3 = l
	}
	(*format)++;
}

void			length_L(const char **format, t_info *info)
{
	ft_putendl("Length -> L");
	info->specs->length = BIT_5; // BIT_5 = L
	(void)format;
	(void)info;
	(*format)++;
}
