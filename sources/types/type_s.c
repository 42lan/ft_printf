/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:37:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/16 15:07:08 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		write_order(t_info *info, t_data *data)
{
	if (info->minus == 0)
	{
		put_width_s(info, data);
		write_str(&info->buffer, data->str, data->length);
	}
	else
	{
		write_str(&info->buffer, data->str, data->length);
		put_width_s(info, data);
	}
}

static void		data_null(t_info *info, t_data *data)
{
	data->str = "(null)";
	info->width = 0;
	if (info->point == 1 && info->precision == 0)
		data->length = 0;
	else if (info->precision > 0)
		data->length = info->precision;
	else
		data->length = ft_strlen(data->str);
	write_order(info, data);
}

void			type_s(const char **format, t_info *info)
{
	t_data		data;

	info->type = **format;
	info->hash = 0;
	if (info->minus == 1)
		info->zero = 0;
	data.str = va_arg(info->ap, char *);
	if (data.str == NULL)
	{
		data_null(info, &data);
		return ;
	}
	data.length = ft_strlen(data.str);
	if (info->point == 1)
	{
		if (info->precision == 0)
			data.length = 0;
		else if (info->precision < data.length
				&& info->width != 0 && info->minus == 0)
			data.length = info->precision;
		else
			data.length -= ABS((data.length - info->precision));
	}
	write_order(info, &data);
}
