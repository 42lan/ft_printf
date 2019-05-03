/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 05:20:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/03 12:29:22 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		free_mem(t_info *info)
{
	free(info->specs->flags);
	free(info->specs);
	free(info);
}

int				ft_printf(const char *format, ...)
{
	t_info		*info;

	if (!format || !(info = initialize_info()))
		return (-1);
	va_start(info->ap, format);
	while (*format)
	{
		if (buffer_full(&info->buffer) == 1)
			print_buffer(&info->buffer);
		if (*format == '%')
		{
			format++;
			parsing(&format, info);
			if (*format == 0)
				return (0);
		}
		else
			write_char(&info->buffer, *format);
		format++;
	}
	if (info->buffer.index != 0)
		print_buffer(&info->buffer);
	va_end(info->ap);
	free_mem(info);
	return (info->buffer.length);
}
