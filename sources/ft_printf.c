/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 05:20:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/27 13:51:46 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_buffer	buffer;

	va_start(ap, format);
	initialize_buffer(&buffer);
	while (*format)
	{
		while (*format && *format != '%')
		{
			buffer.string[buffer.index] = *format;
			buffer.index++;
			format++;
		}
		if (*format++ == '%')
			parsing(&format, &ap, &buffer);
		/*
		else
			buffer.string[buffer.index++] = *format;
		*/
		format++;
	}
	return (buffer.length);
}
