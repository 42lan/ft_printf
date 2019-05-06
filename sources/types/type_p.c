/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:48:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/06 10:39:10 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			type_p(const char **format, t_info *info)
{
	void		*number;
	t_data		data;

	info->type = **format;
	info->specs->flags->hash = 0;
	info->specs->flags->plus = 0;
	number = (void *)va_arg(info->ap, void *);
	data.str = ft_uitoa_base_static((uintmax_t)number, 16, ft_isupper(info->type));
	data.length = ft_strlen(data.str);
	data.prefix = "0x";
	data.negative = 0;
	apply_specs(info, &data);
}
