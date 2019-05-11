/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:14:26 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/11 13:37:19 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			wildcard(const char **format, t_info *info)
{
	if (*(*format - 1) != '.')
	{
		info->width = va_arg(info->ap, int);
		if (info->width < 0)
		{
			info->minus = 1;
			info->width *= -1;
		}
	}
	else
		info->precision = va_arg(info->ap, int);
	(*format)++;
}
