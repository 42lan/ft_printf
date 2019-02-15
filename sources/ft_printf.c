/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 05:20:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/15 09:26:22 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	int			done;
	va_list		arg;
	t_buffer	buffer;

	done = 0;
	buffer = initialize_buffer();
	va_start(arg, format);
	while (*format)
	{
		//if (buffer.index == BUFF_SIZE - 1) // last line isn't print because < BUFF_SIZE
		//	print_buffer(&buffer);
		if (*format == '%' && is_placeholder(&format))
		{
			//ft_putendl(format);
		}
		else
		{
			buffer.string[buffer.index++] = *format;
			//buffer.string[buffer.index++] = *format;
		}
		format++;
	}
	va_end(arg);
	return (done);
}
