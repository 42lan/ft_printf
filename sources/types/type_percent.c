/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:27:47 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/31 16:31:26 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			type_percent(const char **format, t_info *info)
{
	t_data		data;
	char		c;

	info->type = **format;
	c = '%';
	data.str = &c;
	data.length = 1;
	data.negative = 0;
	info->specs->flags->space = 0;
	apply_specs(info, &data);
}
