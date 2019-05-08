/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:37:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/06 18:05:20 by amalsago         ###   ########.fr       */
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
	data.str = va_arg(info->ap, char *);
	if (data.str == NULL || data.str[0] == 0)
	{
		if (data.str == NULL)
			data_null(info, &data);
		else
		{
			data.length = 0;
			put_width_s(info, &data);
		}
		return ;
	}
	data.length = ft_strlen(data.str);
	if (info->width <= data.length && info->point == 0)
		write_str(&info->buffer, data.str, data.length);
	else if (info->width > data.length && info->point == 0)
		write_order(info, &data);
	else if (info->width == 0)
	{
		if ((info->point == 1 && info->precision == 0))
			return ;
		if (info->precision <= data.length)
			data.length -= (data.length - info->precision);
		write_order(info, &data);
	}
	else
	{
		if (info->point == 0 || info->precision == 0)
			put_width_s(info, &data);
		if (info->precision < data.length)
		{
			if (info->minus == 1)
			{
				write_str(&info->buffer, data.str,
						data.length - (data.length - info->precision));
				put_width_s(info, &data);
				return ;
			}
		}
		else
		{
			data.length -= (data.length - info->precision);
			write_order(info, &data);
		}
		if (info->minus == 0)
		{
			put_width_s(info, &data);
			write_str(&info->buffer, data.str, info->precision);
		}
		else
		{
			write_str(&info->buffer, data.str, data.length);
			put_width_s(info, &data);
		}
	}
}
