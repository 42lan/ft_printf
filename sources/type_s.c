/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:37:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/23 12:49:29 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		type_s(const char **format, t_info *info)
{
	t_data		data;

	info->type = **format;
	data.str = va_arg(info->ap, char *);
	data.length = ft_strlen(data.str);
	info->specs->flags->plus = 0;
	if (info->specs->precision > 0) // Укрощение строки
		// Невозможно перезаписать data.str так как она находится в RO части памяти
		// Можно создать новую строку маллоком?
	apply_specs(info, &data);
}
