/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 12:16:17 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/19 13:52:30 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_ui(uintmax_t *number, t_info *info)
{
	if (info->length == 0)
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

static void		specs_handler(t_info *info, uintmax_t number)
{
	info->plus = 0;
	info->space = 0;
	if (number == 0)
		info->hash = 0;
	info->precision = 0;
}

void			type_b(const char **format, t_info *info)
{
	uintmax_t	number;
	t_data		data;

	info->type = **format;
	get_ui(&number, info);
	specs_handler(info, number);
	if (number == 0)
		data.str = "0";
	else
		data.str = ft_sitoa_base_static(number, 2, ft_isupper(info->type));
	if (info->hash == 1)
		data.prefix = ft_isupper(info->type) ? "0B" : "0b";
	data.negative = 0;
	data.length = ft_strlen(data.str);
	apply_specs(info, &data);
}
