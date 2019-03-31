/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_specs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 09:45:05 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/31 11:30:48 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void		digit(const char **format, t_info *info)
{
	if (*(*format - 1) != '.') // Если это не precision, то это width
		set_width(format, info);
}

void		set_width(const char **format, t_info *info)
{
	info->specs->width = get_number(format);
}

void		set_precision(const char **format, t_info *info)
{
	(*format)++;
	info->specs->flags->point = 1;
	info->specs->precision = get_number(format);
}
