/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:48:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/28 16:33:13 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		specs_handler(t_info *info, t_data *data, uintmax_t *number)
{
	if (info->specs->flags->hash == 1 && *number == 0
		&& info->specs->precision != 0)
		data->prefix = ft_strdup("");
	else if (info->specs->flags->hash == 1)
		data->prefix = "0";
	if (info->specs->flags->point == 1 && info->specs->precision == 0
		&& *number == 0)
	{
		if (info->specs->width == 0)
			data->str = ft_strdup("");
		else
			data->str = (info->specs->flags->hash == 1)
						? ft_strdup("0") : ft_strdup(" ");
		data->length = 1;
	}
}

void			type_p(const char **format, t_info *info)
{
	uintmax_t	number;
	t_data		data;

	info->type = **format;
	number = (void *)va_arg(info->ap, void *);
	data.negative = 0;
	info->specs->flags->zero = 0;
	info->specs->flags->hash = 0;
	info->specs->flags->plus = 0;
	data.str = ft_uitoa_base(number, 16, ft_isupper(info->type));
	data.prefix = "0x";
	data.length = ft_strlen(data.str);
	specs_handler(info, &data, &number);
	apply_specs(info, &data);
	free(data.str);
}
