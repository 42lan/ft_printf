/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:25:40 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/02 14:41:59 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				parsing(const char **format, va_list *ap, t_buffer *buffer)
{
	(void)ap;
	(void)buffer;
	t_placeholder	*placeholder;

	placeholder = initialize_placeholder(); // Инициализация плэйсхолдера
	while (**format && !(placeholder->type)) // Пока читаю символы И пока не устоновлен тип плейсхолдера
	{
		if (ft_isprint(**format)) // Является текущий символ символом между ' ' и '~'
			jump_table[**format - ' '](format, placeholder); // Если да, то определить и вызвать отосящююся функцию передав строку и структуру плейсхолдера
	}
	print_placeholder(placeholder);
}
