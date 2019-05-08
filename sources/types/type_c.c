/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 10:26:29 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/08 16:40:25 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			type_c(const char **format, t_info *info)
{
	char		c;
	t_data		data;

	info->type = **format;
	info->plus = 0;
	info->hash = 0;
	c = (char)va_arg(info->ap, int);
	if (c == 0)
	{
		while (info->width-- > 1)
			write_char(&info->buffer, (info->zero == 0) ? ' ' : '0');
		write_char(&info->buffer, c);
		return ;
	}
	data.str = &c;
	data.negative = 0;
	data.length = 1;
	apply_specs(info, &data);
}
