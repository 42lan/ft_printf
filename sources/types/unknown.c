/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknown.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:35:14 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/11 18:15:35 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			unknown(const char **format, t_info *info)
{
	char		*types;
	t_data		data;

	types = "cspdiouxXfBCDIOUX";
	info->type = **format;
	info->hash = 0;
	va_arg(info->ap, int);
	data.str = (char *)*format;
	if (ft_strchr(types, **format) == NULL)
		info->space = 0;
	data.length = 1;
	data.negative = 0;
	apply_specs(info, &data);
}
