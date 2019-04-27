/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:48:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/27 19:02:52 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			type_p(const char **format, t_info *info)
{
	uintmax_t	number;
	t_data		data;

	info->type = **format;
	number = (void *)va_arg(info->ap, void *);
	data.negative = 0;
	data.str = ft_uitoa_base(number, 16, ft_isupper(info->type));
	data.prefix = "0x";
	data.length = ft_strlen(data.str);
	apply_specs(info, &data);
	free(data.str);
}
