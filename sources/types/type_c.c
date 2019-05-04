/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 10:26:29 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/04 11:34:52 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		specs_handler(t_info *info, t_data *data, char c)
{
	info->specs->flags->plus = 0;
	info->specs->flags->hash = 0;
}

void			type_c(const char **format, t_info *info)
{
	char		c;
	t_data		data;

	info->type = **format;
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
	data.length = 1;
	data.negative = 0;
	specs_handler(info, &data, c);
	apply_specs(info, &data);
}
