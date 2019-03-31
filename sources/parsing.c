/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:25:40 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/31 11:15:39 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				parsing(const char **format, t_info *info)
{
	// if (**format == NULL)
	// 	exit (0) ;
	initialize_specifiers(info->specs);
	info->type = 0;
	while (**format && info->type == 0) // Пока читаю символы >>>ИИИ<<< пока не установлен тип плейсхолдера
	{
		if (ft_isprint(**format)) // Является текущий символ символом между ' ' и '~' (32 - 126 ascii)
			g_jump_table[**format - ' '](format, info); // Если да, то определить и вызвать отосящююся функцию передав строку и структуру плейсхолдера
	}
	//if (debug == 1)
	//	print_info(info);
}
