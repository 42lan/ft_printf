/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:27:47 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/11 19:36:05 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			percent(const char **format, t_info *info)
{
	t_data		data;

	info->type = **format;
	info->space = 0;
	data.str = "%";
	data.length = 1;
	data.negative = 0;
	apply_specs(info, &data);
}
