/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 05:20:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/18 08:08:58 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *format, ...)
{
	int				done;
	va_list			arg;
	t_buffer		buffer;
	t_placeholder	*placeholder;
	const char		*placeholder_position;

	done = 0;
	buffer = initialize_buffer();
	placeholder = initialize_placeholder();	// Можно в check_syntax() обявить и инициализировать
	va_start(arg, format);
	while (*format)
	{
		if (buffer.index == BUFF_SIZE - 1) // Для того чтобы не было ошибки ->  zsh: abort      ./a.out
			buffer = initialize_buffer();
		/*
		if (buffer.index == BUFF_SIZE - 1) // last line isn't print because < BUFF_SIZE. Need to be <= BUFF_SIZE?
			print_buffer(&buffer);
		*/
		while (*format && *format == '%' && *(format + 1) == '%')	// zsh: abort      ./a.out
		{
			buffer.string[buffer.index++] = *format;
			format = format + 2;
		}
		if (*format == '%')	// Вот так уже лучше, но не красиво  |
			placeholder_position = format + 1; //				 L > Не очень эффективно, так как каждый раз просто созраняю позицую
		if (*format == '%' && is_placeholder(&format))
		{
			check_syntax(placeholder_position, placeholder);
			print_placeholder(placeholder);
			placeholder = initialize_placeholder();		// Могу ли я просто вызвать функцию без присвоения?
		}
		else
			buffer.string[buffer.index++] = *format;
		format++;
	}
	va_end(arg);
	//deallocate_placeholder(placeholder);
	return (done);
}
