/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 05:20:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/14 06:03:15 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_buffer(t_buffer *buffer)
{
	ft_putstr(buffer->string);
	buffer->index = 0;
}

int				ft_printf(const char *format, ...)
{
	int			done;
	va_list		arg;
	t_buffer	buffer;

	done = 0;
	buffer.index = 0;
	buffer.length = 0;
	ft_bzero(buffer.string, BUFF_SIZE);
	//Ca allege? -> buffer.string[BUFF_SIZE] = '\0';
	va_start(arg, format);
	while (*format)
	{
		if (buffer.index <= BUFF_SIZE - 1)
			print_buffer(&buffer);
		if (*format != '%')
			buffer.string[buffer.index++] = *format;
		else
		{
			buffer.string[buffer.index++] = *format;
		}
		format++;
	}
	//print_buffer(&buffer);
	va_end(arg);
	return (done);
}
