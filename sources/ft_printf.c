/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 05:20:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/04 16:48:58 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *format, ...)
{
	// va_list			ap;
	t_info			*info;
	t_buffer		buffer;

	info = initialize_info();
	va_start(info->ap, format);
	initialize_buffer(&buffer);
	while (*format)
	{
		// if (buffer.index == BUFF_SIZE - 1) // When buffer is full, print it and reset
		//  	print_buffer(&buffer);
		if (*format == '%')
		{
			format++; // Пропустить и передать в parsing() строку после символа %
			parsing(&format, info, &buffer); // Запустить разбор (парсинг) строки
		}
		else
			buffer.content[buffer.index++] = *format; // Записать в буффер текущий символ
		format++;
	}
	// if (buffer.index != 0) // Если индекс буффера не равен нулю, то вывести оставшееся содержимое
	// 	print_buffer(&buffer);
	va_end(info->ap);
	return (buffer.length);
}
