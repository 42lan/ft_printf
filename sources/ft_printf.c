/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 05:20:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/03 17:26:57 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *format, ...)
{
	// va_list			ap;
	t_info	info;

	va_start(info.ap, format);
	initialize_buffer(&info.buffer);
	while (*format)
	{
		// if (info.buffer.index == BUFF_SIZE - 1) // When buffer is full, print it and reset
		// 	print_buffer(&info.buffer);
		if (*format == '%')
		{
			format++; // Пропустить и передать в parsing() строку после символа %
			parsing(&format, &info.ap, &info.buffer); // Запустить рабор (парсинг) строки
		}
		else
			info.buffer.content[info.buffer.index++] = *format; // Записать в буффер текущий символ
		format++;
	}
	// if (info.buffer.index != 0) // Если индекс буффера не равен нулю, то вывести оставшееся содержимое
	// 	print_buffer(&info.buffer);
	va_end(info.ap);
	return (info.buffer.length);
}
