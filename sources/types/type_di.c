/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:03:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/10 17:44:48 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** get_number() receive  an addresse of a number and info structure.
** It retrieve an integer from arguments then depending on what type of length
** was specified (which bit is setted to 1) it cast retrieved integer.
*/

static void		get_number(int *number, t_info *info)
{
	if (info->specs->length == 0)
		*number = va_arg(info->ap, int);
	else if(info->specs->length == BIT_1)
		*number = (short int)va_arg(info->ap, int);
	else if (info->specs->length == BIT_2)
		*number = (signed char)va_arg(info->ap, int);
}

void			type_di(const char **format, t_info *info)
{
	int			number;
	t_data		data;

	info->type = **format;
	get_number(&number, info);
	info->specs->flags->hash = 0;
	if (number == INT_MIN)
		data.str = "2147483648";
	else
	{
		if (number > INT_MAX)
			data.str = ft_litoa(ABS(number));
		else
			data.str = ft_itoa(ABS(number));
	}
	data.length = ft_nblen(number);
	data.negative = 0;
	if (number < 0)
		data.negative = 1;
	apply_specs(info, &data);
}
