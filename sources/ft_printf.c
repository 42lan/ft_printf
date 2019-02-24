/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 05:20:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/24 13:15:07 by amalsago         ###   ########.fr       */
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
	initialization(&buffer, &placeholder);
	va_start(arg, format);
	while (*format)
	{
		//printf(">%c\n", *format);
		/*
		if (buffer.index <= BUFF_SIZE - 1)
		{
			//print_buffer(&buffer);
			buffer.index = 0;
		}
		*/
		/*
		while (*format == '%' && *(format + 1) == '%')
		{
			buffer.string[buffer.index++] = *format;
			//printf("%c", *format);
			format = format + 2;
			done++;
		}
		*/
		if (*format == '%')
		{
			//if (*format == '%' && is_placeholder(&format))
			if (is_placeholder(format++))
			{
				check_syntax(format, placeholder);
				print_placeholder(placeholder);
				placeholder = initialize_placeholder();
			}
		}
		else
		{
			buffer.string[buffer.index++] = *format;
			//printf("%c", *format);
			done++;
		}
		format++;
	}
	va_end(arg);
	//deallocate_placeholder(placeholder);
	return (done);
}
