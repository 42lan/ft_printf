/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:37:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/03 12:41:36 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		write_order(t_info *info, t_data *data)
{
	if (info->specs->flags->minus == 0)
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
	if (info->specs->flags->point == 1 && info->specs->precision == 0)
		data->length = 0;
	else if (info->specs->precision > 0)
		data->length = info->specs->precision;
	else
		data->length = ft_strlen(data->str);
	write_order(info, data);
}

void			type_s(const char **format, t_info *info)
{
	t_data		data;

	info->type = **format;
	info->specs->flags->hash = 0;
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
	if (info->specs->width <= data.length && info->specs->flags->point == 0)
		write_str(&info->buffer, data.str, data.length);
	else if (info->specs->width > data.length && info->specs->flags->point == 0)
		write_order(info, &data);
	else if (info->specs->width == 0)
	{
		if ((info->specs->flags->point == 1 && info->specs->precision == 0))
			return ;
		if (info->specs->precision <= data.length)
			data.length -= (data.length - info->specs->precision);
		write_order(info, &data);
	}
	else
	{
		if (info->specs->flags->point == 0 || info->specs->precision == 0)
			put_width_s(info, &data);
		if (info->specs->precision < data.length)
		{
			if (info->specs->flags->minus == 1)
			{
				write_str(&info->buffer, data.str,
						data.length - (data.length - info->specs->precision));
				put_width_s(info, &data);
				return ;
			}
		}
		else
		{
			data.length -= (data.length - info->specs->precision);
			write_order(info, &data);
		}
		if (info->specs->flags->minus == 0)
		{
			put_width_s(info, &data);
			write_str(&info->buffer, data.str, info->specs->precision);
		}
		else
		{
			write_str(&info->buffer, data.str, data.length);
			put_width_s(info, &data);
		}
	}
	free(data.str);
}
