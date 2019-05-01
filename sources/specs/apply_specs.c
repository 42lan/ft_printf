/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_specs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 11:24:59 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/01 20:08:43 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		apply_specs(t_info *info, t_data *data)
{
	if (info->specs->flags->minus == 0)
	{
		if (info->specs->flags->zero == 1)
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
	else if (info->specs->flags->hash == 1 || info->type == 'p')
		write_str(&info->buffer, data->prefix, ft_strlen(data->prefix));
	else if (info->specs->flags->plus == 1 && data->negative == 0)
		write_char(&info->buffer, '+');
	else if (data->negative == 1 && data->str[0] != '-')
		write_char(&info->buffer, '-');
	else if (info->specs->flags->space == 1)
	{
		if (data->str[0] == '\0')
			info->buffer.length++;
		else
			write_char(&info->buffer, ' ');
	}
}

void		put_precision(t_info *info, t_data *data)
{
	int		precision;

	precision = info->specs->precision - data->length;
	while (precision-- > 0 && data->str[0] != '\0')
		write_char(&info->buffer, '0');
}

void		put_width(t_info *info, t_data *data)
{
	int		width;

	if (info->type == 'p')
	{
		width = info->specs->width - ft_strlen(data->prefix);
		width -= (info->specs->precision >= data->length)
				? info->specs->precision : data->length;
		//if (info->specs->precision >= data->length)
		//	width = info->specs->width - info->specs->precision - ft_strlen(data->prefix);
		//else
		//	width = info->specs->width - data->length - ft_strlen(data->prefix);
	}
	else if (info->specs->width < data->length)
		width = 0;
	else if (info->specs->precision > data->length)
		width = info->specs->width - info->specs->precision;
	else if (info->specs->flags->hash == 1)
		width = info->specs->width - data->length - ft_strlen(data->prefix);
	else
		width = info->specs->width - data->length;
	if ((info->specs->flags->plus == 1 || info->specs->flags->space == 1)
		&& data->negative == 0)
		width--;
	while (width-- > 0)
		(info->specs->flags->zero == 1 && info->specs->flags->minus == 0)
		? write_char(&info->buffer, '0') : write_char(&info->buffer, ' ');
}

void		put_width_s(t_info *info, t_data *data)
{
	int		width;

	if (info->specs->width > data->length && info->specs->flags->point == 0)
		width = info->specs->width - data->length;
	else if (data->length == 0)
		width = info->specs->width;
	else if (info->specs->width != 0 &&
			(info->specs->flags->point == 0 || info->specs->precision == 0))
		width = info->specs->width;
	else if (info->specs->width != 0 && info->specs->precision < data->length)
		width = info->specs->width - info->specs->precision;
	else
		width = 0;
	while (width-- > 0)
		write_char(&info->buffer, ' ');
}
