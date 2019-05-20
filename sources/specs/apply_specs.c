/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_specs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 11:24:59 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/20 16:14:53 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		put_prefix(t_info *info, t_data *data)
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
		write_char(&info->buffer, ' ');
}

static void		put_precision(t_info *info, t_data *data)
{
	int		precision;

	precision = info->precision - data->length;
	while (precision-- > 0 && data->str != NULL)
		write_char(&info->buffer, '0');
}

static void		put_width(t_info *info, t_data *data)
{
	if (info->width < data->length)
		info->width = 0;
	else if (info->precision > data->length)
		info->width -= info->precision;
	else if (info->hash == 1 || info->type == 'p')
		info->width = info->width - data->length - ft_strlen(data->prefix);
	else
		info->width -= data->length;
	if ((info->plus == 1 || info->space == 1) && data->negative == 0)
		info->width--;
	if (info->zero == 1 && info->minus == 0 && data->length > 0)
		while (info->width-- > 0)
			write_char(&info->buffer, '0');
	else
		while (info->width-- > 0)
			write_char(&info->buffer, ' ');
}

void			apply_specs(t_info *info, t_data *data)
{
	if (info->minus == 0)
	{
		if (info->zero == 0)
		{
			put_width(info, data);
			put_prefix(info, data);
		}
		else
		{
			put_prefix(info, data);
			put_width(info, data);
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
