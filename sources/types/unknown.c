/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknown.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:35:14 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/03 12:51:44 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			unknown(const char **format, t_info *info)
{
	t_data		data;
	char		*types;

	types = "cspdiouxXf";
	info->type = **format;
	va_arg(info->ap, int);
	data.str = (char *)*format;
	if (ft_strchr(types, **format) == NULL)
		info->specs->flags->space = 0;
	data.length = 1;
	data.negative = 0;
	info->specs->flags->hash = 0;
	apply_specs(info, &data);
}
