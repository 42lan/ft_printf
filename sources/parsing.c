/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:25:40 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/03 17:27:03 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				parsing(const char **format, va_list *ap, t_buffer *buffer)
{
	(void)ap;
	(void)buffer;
	t_info	*info;

	info = initialize_info(); // Инициализация плэйсхолдера
	while (**format && !(info->type)) // Пока читаю символы И пока не устоновлен тип плейсхолдера
	{
		if (ft_isprint(**format)) // Является текущий символ символом между ' ' и '~'
			jump_table[**format - ' '](format, info); // Если да, то определить и вызвать отосящююся функцию передав строку и структуру плейсхолдера
	}
	print_info(info);
}
