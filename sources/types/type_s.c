/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:37:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/22 19:41:17 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			type_s(const char **format, t_info *info)
{
	t_data		data;
	int			i;

	i = -1;
	info->type = **format;
	info->specs->flags->hash = 0;
	data.str = va_arg(info->ap, char *);
	if (data.str == NULL)
	{
		data.str = "(null)";
		data.length = ft_strlen(data.str);
		if (info->specs->flags->minus == 1)
		{
			write_str(&info->buffer, data.str, data.length);
			put_width_s(info, &data);
		}
		else
		{
			put_width_s(info, &data);
			write_str(&info->buffer, data.str, data.length);
		}
		return ;
	}
	data.length = ft_strlen(data.str);
	if (data.str == "")
		data.length = 0;
	if (info->specs->width == 0
		&& (info->specs->flags->point == 1 && info->specs->precision == 0))
		return ;
	if (info->specs->width <= data.length && info->specs->flags->point == 0)
		write_str(&info->buffer, data.str, data.length);
	else if (info->specs->width > data.length && info->specs->flags->point == 0)
	{
		if (info->specs->flags->minus == 1)
		{
			write_str(&info->buffer, data.str, data.length);
			put_width_s(info, &data);
		}
		else
		{
			put_width_s(info, &data);
			write_str(&info->buffer, data.str, data.length);
		}
	}
	else if (info->specs->width != 0
			&& (info->specs->flags->point == 0 || info->specs->precision == 0))
		put_width_s(info, &data);
	else if (info->specs->width != 0 && info->specs->precision < data.length)
	{
		if (info->specs->flags->minus == 1)
		{
			write_str(&info->buffer, data.str, data.length
					- (data.length - info->specs->precision));
			put_width_s(info, &data);
		}
		else
		{
			put_width_s(info, &data);
			write_str(&info->buffer, data.str,
					data.length - (data.length - info->specs->precision));
		}
	}
	else if (info->specs->width == 0 && info->specs->precision <= data.length)
	{
		if (info->specs->flags->minus == 1)
		{
			write_str(&info->buffer, data.str,
					data.length - (data.length - info->specs->precision));
			put_width_s(info, &data);
		}
		else
		{
			put_width_s(info, &data);
			write_str(&info->buffer, data.str,
					data.length - (data.length - info->specs->precision));
		}
	}
	else if (info->specs->width == 0 && info->specs->precision > data.length)
	{
		if (info->specs->flags->minus == 1)
		{
			write_str(&info->buffer, data.str, data.length);
			put_width_s(info, &data);
		}
		else
		{
			put_width_s(info, &data);
			write_str(&info->buffer, data.str, data.length);
		}
	}
	else
	{
		if (info->specs->flags->minus == 1)
		{
			write_str(&info->buffer, data.str, data.length);
			put_width_s(info, &data);
		}
		else
		{
			put_width_s(info, &data);
			write_str(&info->buffer, data.str, data.length);
		}
	}
}
