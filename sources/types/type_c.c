/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 10:26:29 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/24 17:41:55 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			type_c(const char **format, t_info *info)
{
	char		c;
	t_data		data;

	info->type = **format;
	c = (char)va_arg(info->ap, int);
	if (c == NULL)
	{
		data.str = "";
		info->buffer.length++;
	}
	else if (c == 0)
		data.str = "";
	else
		data.str = &c;
	data.length = 1;
	data.negative = 0;
	info->specs->flags->hash = 0;
	apply_specs(info, &data);
}
