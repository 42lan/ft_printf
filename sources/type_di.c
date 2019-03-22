/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:03:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/22 16:45:06 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		type_di(const char **format, t_info *info)
{
	int		number;
	t_data	data;

	info->type = **format;
	number = va_arg(info->ap, int);
	data.str = ft_itoa(number);
	data.length = number < 0 ? ft_nblen(number) + 1 : ft_nblen(number);
	apply_specs(info, &data);
}
