/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 05:20:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/22 11:10:23 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *format, ...)
{
	t_info			*info;

	if (!format || !(info = initialize_info()))
		return (-1);
	va_start(info->ap, format);
	while (*format)
	{
		if (buffer_full(&info->buffer) == 1) // If buffer is full, print it and reset
			print_buffer(&info->buffer);
		if (*format == '%')
		{
			format++; // Пропустить и передать в parsing() строку после символа %
			parsing(&format, info); // Запустить рабор (парсинг) строки
		}
		else
			write_char(&info->buffer, *format); //info->buffer.content[info->buffer.index++] = *format; // Записать в буффер текущий символ
		format++;
	}
	if (info->buffer.index != 0) // Если индекс буффера не равен нулю, то вывести оставшееся содержимое
		print_buffer(&info->buffer);
	va_end(info->ap);
	return (info->buffer.length);
}
