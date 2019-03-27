/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_specs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 09:45:05 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/27 15:37:21 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

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
