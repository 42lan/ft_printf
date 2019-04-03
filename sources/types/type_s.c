/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:37:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/31 16:55:15 by amalsago         ###   ########.fr       */
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
		data.length = ft_strlen(data.str);												//		s = "World123"
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
	data.length = ft_strlen(data.str);												//		s = "World123"
	if (data.str == "")
		data.length = 0;
	if (info->specs->width == 0														// OK	width == Nan && precision ==.		%.s AND %-.s
			&& (info->specs->flags->point == 1 && info->specs->precision == 0))
		return ;
	if (info->specs->width <= data.length && info->specs->flags->point == 0)		// OK	width <= len (s)					%5s AND %-5s
		write_str(&info->buffer, data.str, data.length);
	else if (info->specs->width > data.length && info->specs->flags->point == 0)	// OK	width > len (s)						%15s AND %-15s
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
	else if (info->specs->width != 0												// width != 0 && precision == . || 0
			&& (info->specs->flags->point == 0 || info->specs->precision == 0))		// %15.s AND %15.0s AND  %-15.s AND %-15.0s
		put_width_s(info, &data);
	else if (info->specs->width != 0 && info->specs->precision < data.length)		// width != 0 && precision < len(s)
	{																				// %15.3s AND %-15.3s
		if (info->specs->flags->minus == 1)
		{
			write_str(&info->buffer, data.str, data.length - (data.length - info->specs->precision));
			put_width_s(info, &data);
		}
		else
		{
			put_width_s(info, &data);
			write_str(&info->buffer, data.str, data.length - (data.length - info->specs->precision));
		}
	}
	else if (info->specs->width == 0 && info->specs->precision <= data.length)		// width == 0 && precision <= len(s)
	{																				// %.3s AND %-.3s 
		if (info->specs->flags->minus == 1)
		{
			write_str(&info->buffer, data.str, data.length - (data.length - info->specs->precision));
			put_width_s(info, &data);
		}
		else
		{
			put_width_s(info, &data);
			write_str(&info->buffer, data.str, data.length - (data.length - info->specs->precision));
		}
	}
	else if (info->specs->width == 0 && info->specs->precision > data.length)		// width == 0 && preicison > len(s)
	{																				// %.13s AND %-.13s 
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
