/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 10:26:29 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/04 16:07:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			type_c(const char **format, t_info *info)
{
	char		c;
	t_data		data;

	info->type = **format;
	info->specs->flags->plus = 0;
	info->specs->flags->hash = 0;
	c = (char)va_arg(info->ap, int);
	if (c == 0)
	{
		while (info->specs->width-- > 1)
			(info->specs->flags->zero == 0)
			? write_char(&info->buffer, ' ')
			: write_char(&info->buffer, '0');
		write_char(&info->buffer, c);
		return ;
	}
	data.str = (ft_isprint(c) == 1) ? &c : '\0';
	data.negative = 0;
	data.length = 1;
	apply_specs(info, &data);
}
