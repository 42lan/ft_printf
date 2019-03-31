/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:03:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/29 10:18:00 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			type_di(const char **format, t_info *info)
{
	int			number;
	t_data		data;

	info->type = **format;
	number = va_arg(info->ap, int);
	info->specs->flags->hash = 0;
	data.str = ft_itoa(ABS(number));
	data.length = ft_nblen(number);
	data.negative = 0;
	if (number < 0)
		data.negative = 1;
	apply_specs(info, &data);
}
