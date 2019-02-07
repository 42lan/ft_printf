/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 00:02:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/07 04:47:22 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parsing(va_list arg, const char *restrict str)
{
	(void)ap;
	char	*s;
	int		c;
	int		d;

	while (*str)
	{
		if (*str != '%')
			ft_putchar(*str);
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
