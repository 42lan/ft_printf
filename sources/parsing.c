/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:25:40 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/03 10:50:52 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				parsing(const char **format, t_info *info)
{
	if (*(*format) == 0)
		return ;
	initialize_specifiers(info->specs);
	info->type = 0;
	while (**format && info->type == 0)
	{
		if (ft_isprint(**format))
			g_jump_table[**format - ' '](format, info);
	}
}
