/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:11:50 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/15 10:14:03 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** get_ui() receive  an addresse of a number and info structure.
** It retrieve an integer from arguments then depending on what type of length
** was specified (which bit is setted to 1) it cast retrieved integer.
*/

static void		get_ui(uintmax_t *number, t_info *info)
{
	if (ft_isupper(info->type))
		*number = (uintmax_t)va_arg(info->ap, uintmax_t);
	else if (info->length == 0)
		*number = (unsigned int)va_arg(info->ap, unsigned int);
	else if (info->length == LENGTH_H)
		*number = (unsigned short int)va_arg(info->ap, int);
	else if (info->length == LENGTH_HH)
		*number = (unsigned char)va_arg(info->ap, int);
	else if (info->length == LENGTH_L)
		*number = (unsigned long int)va_arg(info->ap, unsigned long int);
	else if (info->length == LENGTH_LL)
		*number = (unsigned long long int)
					va_arg(info->ap, unsigned long long int);
	else if (info->length == LENGTH_J)
		*number = (uintmax_t)va_arg(info->ap, uintmax_t);
	else if (info->length == LENGTH_Z)
		*number = (size_t)va_arg(info->ap, size_t);
	else if (info->length == LENGTH_T)
		*number = (unsigned int)va_arg(info->ap, unsigned int);
}

void			type_u(const char **format, t_info *info)
{
	uintmax_t	number;
	t_data		data;

	info->type = **format;
	info->hash = 0;
	get_ui(&number, info);
	data.str = ft_uitoa_base_static(number, 10, 0);
	if (number == 0 && info->width == 0 && info->point == 1 && info->precision == 0)
		data.length = 0;
	else
		data.length = ft_strlen(data.str);
	data.negative = 0;
	apply_specs(info, &data);
}
