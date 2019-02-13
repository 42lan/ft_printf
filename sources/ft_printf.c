/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:43:59 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/13 23:45:10 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Declaration of va_list and initialisation with va_start()
*/

int				ft_printf(const char *restrict format, ...)
{
	va_list		arg;
	int			done;

	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
			parsing(arg, &format);
		else
			buffer[i] = *format;
		format++;
	//	done = parsing(arg, format);
	}
	va_end(arg);
	return (done);
}
