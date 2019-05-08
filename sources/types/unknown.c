/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknown.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:35:14 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/08 16:45:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			unknown(const char **format, t_info *info)
{
	t_data		data;
	char		*types;

	types = "cspdiouxXf";
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
