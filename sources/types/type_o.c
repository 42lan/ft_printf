/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 10:54:51 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/19 18:54:44 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_ui(uintmax_t *number, t_info *info)
{
	if (ft_isupper(info->type))
		*number = (uintmax_t)va_arg(info->ap, uintmax_t);
	else if (info->length == 0)
		*number = (unsigned int)va_arg(info->ap, unsigned int);
	else if (info->length == LENGTH_H)
		*number = (unsigned short int)va_arg(info->ap, int);
	else if (info->length == LENGTH_HH)
		*number = (unsigned char)va_arg(info->ap, int);
	else if (info->length == LENGTH_L)
		*number = (unsigned long int)va_arg(info->ap, unsigned long int);
	else if (info->length == LENGTH_LL)
		*number = (unsigned long long int)
					va_arg(info->ap, unsigned long long int);
	else if (info->length == LENGTH_J)
		*number = (uintmax_t)va_arg(info->ap, uintmax_t);
	else if (info->length == LENGTH_Z)
		*number = (size_t)va_arg(info->ap, size_t);
	else if (info->length == LENGTH_T)
		*number = (unsigned int)va_arg(info->ap, unsigned int);
}

static void		specs_handler(t_info *info, uintmax_t number)
{
	info->plus = 0;
	info->space = 0;
	if (number == 0 && info->point == 0)
		info->hash = 0;
}

void			type_o(const char **format, t_info *info)
{
	uintmax_t	number;
	t_data		data;

	info->type = **format;
	get_ui(&number, info);
	data.str = ft_uitoa_base_static(number, 8, 0);
	data.length = ft_strlen(data.str);
	data.negative = 0;
	if (data.length == 1 && info->hash == 1)
		info->precision--;
	if (number == 0 && info->point == 1 && info->precision == 0)
	{
		if (info->width == 0)
			data.str = "\0";
		else
			data.str = (info->hash == 1) ? "0" : " ";
	}
	if (info->hash == 1)
		data.prefix = (number == 0 && info->precision != 0) ? "\0" : "0";
	specs_handler(info, number);
	apply_specs(info, &data);
}
