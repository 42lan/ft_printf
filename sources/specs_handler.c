/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 11:24:59 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/25 18:59:29 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		apply_specs(t_info *info, t_data *data)
{
	if (info->specs->flags->minus == 1)
	{
		put_prefix(info, data);
		put_precision(info, data);
		write_str(&info->buffer, data->str, data->length);
		put_width(info, data);
	}
	else
	{
		put_width(info, data);
		put_prefix(info, data);
		put_precision(info, data);
		write_str(&info->buffer, data->str, data->length);
	}
}

void		put_prefix(t_info *info, t_data *data)
{
	if (info->specs->flags->plus == 1 && data->negative == 0)
		write_char(&info->buffer, '+');
	else if (data->negative == 1)
		write_char(&info->buffer, '-');
	else if (info->specs->flags->space == 1)
		write_char(&info->buffer, ' ');
}

void		put_width(t_info *info, t_data *data)
{
	int		width;

	if (info->specs->width < data->length)
		width = 0;
	else if (info->specs->precision > data->length)
		width = info->specs->width - info->specs->precision;
	else
		width = info->specs->width - data->length;
	if ((info->specs->flags->plus == 1 || info->specs->flags->space == 1) && data->negative == 0)
		width--;
	while (width-- > 0)
		write_char(&info->buffer, ' ');
}

void		put_width_s(t_info *info, t_data *data)
{
	int		width;

	width = 0;
	if (info->specs->width > data->length)
	{
		if (info->specs->precision == 0)
			width = info->specs->width;
		else
			width = info->specs->width - info->specs->precision;
	}
	else
	{
		if (info->specs->precision != 0)
			width = info->specs->width - info->specs->precision;
	}
	while (width-- > 0)
		write_char(&info->buffer, ' ');
}

void		put_precision(t_info *info, t_data *data)
{
	int		precision;

	precision = info->specs->precision - data->length;
	if (data->negative == 1)
		precision++;
	while (precision-- > 0)
		write_char(&info->buffer, '0');
}
