/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 00:02:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/06 02:36:54 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parsing(va_list ap, const char *restrict format)
{
	(void)ap;
	char	*s;
	char	c;
	char	d;

	while (*format)
	{
		if (*format == '%' && (*(format + 1) != '%' && *(format - 1) != '%'))
		{
			if (*(format + 1) == 's')
			{
				s = va_arg(ap, char *);
				ft_putstr(s);
			}
			if (*(format + 1) == 'c')
			{
				c = va_arg(ap, int);
				ft_putchar(c);
			}
			if (*(format + 1) == 'd')
			{
				d = va_arg(ap, int);
				ft_putnbr(d);
			}
		}
		format++;
	}
	return (1);
}
