/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 10:54:51 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/06 10:38:10 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_ui(uintmax_t *number, t_info *info)
{
	if (ft_isupper(info->type))
		*number = (uintmax_t)va_arg(info->ap, uintmax_t);
	else if (info->specs->length == 0)
		*number = (unsigned int)va_arg(info->ap, unsigned int);
	else if (info->specs->length == LENGTH_H)
		*number = (unsigned short int)va_arg(info->ap, int);
	else if (info->specs->length == LENGTH_HH)
		*number = (unsigned char)va_arg(info->ap, int);
	else if (info->specs->length == LENGTH_L)
		*number = (unsigned long int)va_arg(info->ap, unsigned long int);
	else if (info->specs->length == LENGTH_LL)
		*number = (unsigned long long int)
					va_arg(info->ap, unsigned long long int);
	else if (info->specs->length == LENGTH_J)
		*number = (uintmax_t)va_arg(info->ap, uintmax_t);
	else if (info->specs->length == LENGTH_Z)
		*number = (size_t)va_arg(info->ap, size_t);
	else if (info->specs->length == LENGTH_T)
		*number = (unsigned int)va_arg(info->ap, unsigned int);
}

static void		specs_handler(t_info *info, t_data *data, uintmax_t *number)
{
	info->specs->flags->space = 0;
	info->specs->flags->plus = 0;
	if (info->specs->flags->hash == 1)
		data->prefix = (*number == 0 && info->specs->precision != 0)
						? "\0" : "0";
	if (*number == 0
		&& info->specs->flags->point == 1 && info->specs->precision == 0)
	{
		if (info->specs->width == 0)
			data->str[0] = '\0';
		else
			data->str[0] = (info->specs->flags->hash == 1) ? '0' : ' ';
		data->length = 1;
	}
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
	specs_handler(info, &data, &number);
	apply_specs(info, &data);
}
