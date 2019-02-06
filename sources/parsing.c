/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 00:02:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/06 02:10:23 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parsing(va_list ap, const char *restrict format)
{
	(void)ap;
	int		percent;

	percent = 0;
	while (*format)
	{
		if (*format == '%' && (*(format + 1) != '%' && *(format - 1) != '%'))
		{
			if (*(format + 1) == 's')
		}
			percent++;
		printf("+");
		format++;
	}
	return (percent);
}
