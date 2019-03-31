/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknown.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:35:14 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/28 12:41:18 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void			unknown(const char **format, t_info *info)
{
	t_data		data;
	char		unknown;

	info->type = **format;
	unknown = (char)va_arg(info->ap, int);
	ft_putchar(unknown);
	data.str = &unknown;
	data.length = 1;
	apply_specs(info, &data);
}
