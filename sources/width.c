/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:21:18 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/27 14:21:19 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			width(const char **format, t_placeholder *placeholder)
{
	int			nb;

	nb = 0;
	while (ft_isdigit(**format))
	{
		nb *= 10;
		nb = nb + (**format - '0');
		(*format)++;
	}
	placeholder->specs->width = nb;
}
