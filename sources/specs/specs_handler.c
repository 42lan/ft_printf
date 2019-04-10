/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 11:24:59 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/10 16:52:11 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		apply_specs(t_info *info, t_data *data)
{
	if (info->specs->flags->minus != 1)
	{
		if (info->specs->flags->plus == 1)
		{
			put_prefix(info, data);
			put_width(info, data);
		}
		else
		{
			if (data->negative == 1 && info->specs->flags->zero)
			{
				put_prefix(info, data);
				put_width(info, data);
			}
			else
			{
				put_width(info, data);
				put_prefix(info, data);
			}
		}
		put_precision(info, data);
		write_str(&info->buffer, data->str, data->length);
	}
	else
	{
		put_prefix(info, data);
		put_precision(info, data);
		write_str(&info->buffer, data->str, data->length);
		put_width(info, data);
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
	else
		return ;
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
	if (info->specs->flags->zero == 1 && info->specs->flags->minus == 0)
		while (width-- > 0)
			write_char(&info->buffer, '0');
	else
		while (width-- > 0)
			write_char(&info->buffer, ' ');
}

void		put_width_s(t_info *info, t_data *data)
{
	int		width;

	if (info->specs->width > data->length && info->specs->flags->point == 0)
		width = info->specs->width - data->length;
	else if (info->specs->width != 0 && (info->specs->flags->point == 0 || info->specs->precision == 0))
		width = info->specs->width;
	else if (info->specs->width != 0 && info->specs->precision < data->length)
		width = info->specs->width - info->specs->precision;
	else if (info->specs->width == 0 && info->specs->precision <= data->length)
		width = 0;
	else if (info->specs->width == 0 && info->specs->precision > data->length)
		width = 0;
	else
		width = 0;
	while (width-- > 0)
		write_char(&info->buffer, ' ');
}
