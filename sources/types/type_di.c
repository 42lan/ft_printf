/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:03:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/19 17:41:30 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** get_si() receive  an addresse of a number and info structure.
** It retrieve an integer from arguments then depending on what type of length
** was specified (which bit is setted to 1) it cast retrieved integer.
*/

static void		get_si(intmax_t *number, t_info *info)
{
	if (ft_isupper(info->type))
		*number = (intmax_t)va_arg(info->ap, intmax_t);
	else if (info->length == 0)
		*number = (int)va_arg(info->ap, int);
	else if (info->length == LENGTH_H)
		*number = (short int)va_arg(info->ap, int);
	else if (info->length == LENGTH_HH)
		*number = (signed char)va_arg(info->ap, int);
	else if (info->length == LENGTH_L)
		*number = (long int)va_arg(info->ap, long int);
	else if (info->length == LENGTH_LL)
		*number = (long long int)va_arg(info->ap, long long int);
	else if (info->length == LENGTH_J)
		*number = (intmax_t)va_arg(info->ap, intmax_t);
	else if (info->length == LENGTH_Z)
		*number = (size_t)va_arg(info->ap, size_t);
	else if (info->length == LENGTH_T)
		*number = (int)va_arg(info->ap, int);
}

static void		specs_handler(t_info *info, t_data *data, intmax_t number)
{
	if ((data->length == 1 && info->space == 0 && info->plus == 0)
		|| info->hash == 1)
		info->zero = 0;
	info->hash = 0;
	if (number < 0)
		info->width--;
}

void			type_di(const char **format, t_info *info)
{
	intmax_t	number;
	t_data		data;

	info->type = **format;
	get_si(&number, info);
	if (number == 0 && info->point == 1 && info->precision == 0)
		data.str = (info->width != 0) ? " " : "\0";
	else
		data.str = (ft_islower(info->type) && info->length == 0)
					? ft_sitoa_base_static(ABS(number), 10, 0)
					: ft_uitoa_base_static(ABS(number), 10, 0);
	data.length = ft_strlen(data.str);
	data.negative = (number < 0) ? 1 : 0;
	specs_handler(info, &data, number);
	apply_specs(info, &data);
}
