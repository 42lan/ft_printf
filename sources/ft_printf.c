/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 05:20:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/20 15:51:08 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	t_info		info;

	if (!format)
		return (-1);
	va_start(info.ap, format);
	initialize_buffer(&info.buffer);
	while (*format)
	{
		if (buffer_full(&info.buffer) == 1)
			print_buffer(&info.buffer);
		if (*format == '%')
		{
			format++;
			parsing(&format, &info);
			if (*format == 0)
				break ;
		}
		else
			write_char(&info.buffer, *format);
		++format;
	}
	if (info.buffer.index != 0)
		print_buffer(&info.buffer);
	va_end(info.ap);
	return (info.buffer.length);
}
