/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:37:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/25 19:00:22 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		type_s(const char **format, t_info *info)
{
	t_data		data;
	int			i;

	i = -1;
	info->type = **format;
	data.str = va_arg(info->ap, char *);
	data.length = ft_strlen(data.str);
	if (info->specs->flags->minus == 1)
	{
		while (++i < info->specs->precision)
			write_char(&info->buffer, data.str[i]);
	}
	else
	{
		if (info->specs->precision == 0 && (info->specs->width < data.length && info->specs->width > data.length))
		{
			put_width_s(info, &data);
			while (++i < data.length)
				write_char(&info->buffer, data.str[i]);
			
		}
		else if (info->specs->width <= data.length)
		{
			put_width_s(info, &data);
			if (info->specs->precision < data.length)
				while (++i < info->specs->precision)
					write_char(&info->buffer, data.str[i]);
			else
				while (++i < data.length)
					write_char(&info->buffer, data.str[i]);
		}
		else
		{
			put_width_s(info, &data);
			if (info->specs->precision < data.length)
				while (++i < info->specs->precision)
					write_char(&info->buffer, data.str[i]);
			else
				while (++i < data.length)
					write_char(&info->buffer, data.str[i]);
		}
	}
}
