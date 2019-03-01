/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:18:09 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/01 01:51:21 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			get_int(const char **format, t_placeholder *placeholder)
{
	int			nb;
	int			precision;

	nb = 0;
	precision = 0;
	if (**format == '.')
	{
		precision = 1;
		(*format)++;
	}
	while (ft_isdigit(**format))
	{
		nb *= 10;
		nb = nb + (**format - '0');
		(*format)++;
	}
	if (precision)
		placeholder->specs->precision = nb;
	else
		placeholder->specs->width = nb;
}
