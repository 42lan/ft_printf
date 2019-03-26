/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:37:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/26 19:14:25 by amalsago         ###   ########.fr       */
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
	//if (info->specs->width == 0 && info->specs->precision == 0)
	//	return ;
	if ((info->specs->width == 0 && info->specs->precision == 0) || (info->specs->width <= data.length) || (info->specs->width == 0 && info->specs->precision > data.length))
		write_str(&info->buffer, data.str, data.length);
	if (info->specs->flags->minus == 1)
	{
	}
	else
	{
	}
}
