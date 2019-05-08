/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_specs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 11:24:59 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/08 18:54:14 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		apply_specs(t_info *info, t_data *data)
{
	if (info->minus == 0)
	{
		if (info->zero == 1)
		{
			put_prefix(info, data);
			put_width(info, data);
		}
		else
		{
			put_width(info, data);
			put_prefix(info, data);
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
	if (info->type == 'u')
		return ;
	else if (info->hash == 1 || info->type == 'p')
		write_str(&info->buffer, data->prefix, ft_strlen(data->prefix));
	else if (info->plus == 1 && data->negative == 0)
		write_char(&info->buffer, '+');
	else if (data->negative == 1 && data->str[0] != '-')
		write_char(&info->buffer, '-');
	else if (info->space == 1)
		(data->str[0] == '\0')
			? info->buffer.length++ : write_char(&info->buffer, ' ');
}

void		put_precision(t_info *info, t_data *data)
{
	int		precision;

	precision = info->precision - data->length;
	while (precision-- > 0 && data->str[0] != '\0')
		write_char(&info->buffer, '0');
}

void		put_width(t_info *info, t_data *data)
{
	int		width;

	if (info->type == 'p')
	{
		width = info->width - ft_strlen(data->prefix);
		width -= (info->precision >= data->length)
					? info->precision : data->length;
	}
	else if (info->width < data->length)
		width = 0;
	else if (info->precision > data->length)
		width = info->width - info->precision;
	else if (info->hash == 1)
		width = info->width - data->length - ft_strlen(data->prefix);
	else
		width = info->width - data->length;
	if ((info->plus == 1 || info->space == 1) && data->negative == 0)
		width--;
	while (width-- > 0)
		(info->zero == 1 && info->minus == 0 && data->length > 1)
		? write_char(&info->buffer, '0') : write_char(&info->buffer, ' ');
}

void		put_width_s(t_info *info, t_data *data)
{
	int		width;

	if (info->width > data->length && info->point == 0)
		width = info->width - data->length;
	else if ((data->length == 0)
			|| (info->width != 0 && (info->point == 0 || info->precision == 0)))
		width = info->width;
	else if (info->width != 0 && info->precision <= data->length)
		width = info->width - info->precision;
	else
		width = 0;
	while (width-- > 0)
		write_char(&info->buffer, (info->zero == 0) ? ' ' : '0');
}
