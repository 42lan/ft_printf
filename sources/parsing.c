/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:25:40 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/28 10:34:15 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				parsing(const char **format, va_list *ap, t_buffer *buffer)
{
	(void)ap;
	(void)buffer;
	t_placeholder	*placeholder;

	placeholder = initialize_placeholder();
	while (**format && !(placeholder->type))
	{
		if (ft_isprint(**format))
			jump_table[**format - ' '](format, placeholder);
	}
	print_placeholder(placeholder);
}
