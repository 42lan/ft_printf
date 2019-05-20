/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:25:40 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/20 15:44:33 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				parsing(const char **format, t_info *info)
{
	info->type = 0;
	initialize_specs(info);
	while (**format && info->type == 0)
		if (ft_isprint(**format))
			g_jump_table[**format - ' '](format, info);
}
