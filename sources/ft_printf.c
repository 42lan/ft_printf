/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 05:20:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/16 05:39:24 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *format, ...)
{
	int				done;
	va_list			arg;
	t_buffer		buffer;
	t_placeholder	*placeholder;

	done = 0;
	buffer = initialize_buffer();
	placeholder = initialize_placeholder();
	va_start(arg, format);
	while (*format)
	{
		//if (buffer.index == BUFF_SIZE - 1) // last line isn't print because < BUFF_SIZE
		//	print_buffer(&buffer);
		if (*format == '%' && *(format + 1) == '%')
			format = format + 2;
		if (*format == '%' && is_placeholder(&format, placeholder))
		{
			//ft_putendl(format);
			//return (1);
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
