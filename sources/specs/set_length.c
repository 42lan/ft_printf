/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:04:35 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/21 09:52:27 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	length_h(const char **format, t_info *info)
{
	info->specs->length = LENGTH_H;
	if (*(*format + 1) == 'h')
	{
		info->specs->length = LENGTH_HH;
		(*format)++;
	}
	(*format)++;
}

void	length_l(const char **format, t_info *info)
{
	if (**format == 'L')
		info->specs->length = LENGTH_LLL;
	else
	{
		info->specs->length = LENGTH_L;
		if (*(*format + 1) == 'l')
		{
			info->specs->length = LENGTH_LL;
			(*format)++;
		}
	}
	(*format)++;
}

void	length_j(const char **format, t_info *info)
{
	info->specs->length = LENGTH_J;
	(*format)++;
}

void	length_z(const char **format, t_info *info)
{
	info->specs->length = LENGTH_Z;
	(*format)++;
}

void	length_t(const char **format, t_info *info)
{
	info->specs->length = LENGTH_T;
	(*format)++;
}
