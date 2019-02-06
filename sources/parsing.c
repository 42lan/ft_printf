/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 00:02:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/06 22:42:05 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parsing(va_list ap, const char *restrict str)
{
	(void)ap;
	char	*s;
	char	c;
	int		d;

	while (*str)
	{
		if (*str == '%' && (*(str + 1) != '%' && *(str - 1) != '%'))
		{
			if (*(str + 1) == 's')
			{
				s = va_arg(ap, char *);
				ft_putstr(s);
			}
			if (*(str + 1) == 'c')
			{
				c = va_arg(ap, int);
				ft_putchar(c);
			}
			if (*(str + 1) == 'd')
			{
				d = va_arg(ap, int);
				ft_putnbr(d);
			}
		}
		str++;
	}
	return (1);
}
