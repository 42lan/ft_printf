/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:11:50 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/31 18:59:46 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			type_u(const char **format, t_info *info)
{
	info->specs->flags->hash = 0;
	info->type = **format;
	unsigned	number;
	t_data		data;

	info->type = **format;
	number = va_arg(info->ap, unsigned int);
	info->specs->flags->hash = 0;
	data.str = ft_itoa(ABS(number));
	data.length = ft_nblen(number);
	data.negative = 0;
	if (number < 0)
		data.negative = 1;
	apply_specs(info, &data);
}
