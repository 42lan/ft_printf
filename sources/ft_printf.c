/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 05:20:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/02 14:41:45 by amalsago         ###   ########.fr       */
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
		// if (buffer.index == BUFF_SIZE - 1) // When buffer is full, print it and reset
		// 	print_buffer(&buffer);
		if (*format == '%')
		{
			format++; // Пропустить и передать в parsing() строку после символа %
			parsing(&format, &ap, &buffer); // Запустить рабор (парсинг) строки
		}
		else
			buffer.content[buffer.index++] = *format; // Записать в буффер текущий символ
		format++;
	}
	// if (buffer.index != 0) // Если индекс буффера не равен нулю, то вывести оставшееся содержимое
	// 	print_buffer(&buffer);
	va_end(ap);
	return (buffer.length);
}
