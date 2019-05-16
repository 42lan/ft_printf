/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 19:37:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/16 12:29:42 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			get_f(long double *number, t_info *info)
{
	if (info->length == LENGTH_LLL)
		*number = (long double)va_arg(info->ap, long double);
	else
		*number = (double)va_arg(info->ap, double);
}

void				type_f(const char **format, t_info *info)
{
	long double		number;
	t_data			data;

	get_f(&number, info);
	info->type = **format;
	info->hash = 0;
	info->plus = 0;
	data.str = ft_ftoa_static(number, info->precision);
	data.negative = 0;
	data.length = ft_strlen(data.str);
	apply_specs(info, &data);
}
