/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:18:09 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/28 14:46:12 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		precision(const char **format, t_placeholder *placeholder)
{
	int			nb;

	nb = 0;
	(*format)++;
	while (ft_isdigit((**format)))
	{
		nb *= 10;
		nb = nb + (**format - '0');
		(*format)++;
	}
	placeholder->specs->precision = nb;
}
