/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 05:20:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/26 14:55:55 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	int			done;
	va_list		ap;
	t_buffer	buffer;

	done = 0;
	va_start(ap, format);
	initialize_buffer(&buffer);
	while (*format)
	{
		if (buffer.index == BUFF_SIZE - 1)
		{
			ft_putendl("YOP!");
		}
		while (*format && *format != '%')
		{
			buffer.string[buffer.index] = *format;
			//ft_putchar(buffer.string[buffer.index]);
			buffer.index++;
			done++;
			format++;
		}
		if (*format++ == '%')
		{
			parsing(&format, &ap, &buffer);
			return 666;
		}
		format++;
	}
	return (done);
}
