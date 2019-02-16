/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeholder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 05:50:25 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/16 05:39:29 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_placeholder(const char **format, t_placeholder *placeholder)
{
	if ((**format + 1) == '%')
		return (0);
	ft_putchar(**format);
	(*format)++;
	while (!is_conversion_type(**format))
	{
		ft_putchar(**format);
		check_syntax(**format, placeholder);
		(*format)++;
	}
	ft_putchar(**format);
	ft_putchar('\n');
	return (1);
}
