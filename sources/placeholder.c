/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeholder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 05:50:25 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/02 14:42:00 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int		is_placeholder(const char *format)
{
	while (*format)
	{
		//if (!is_conversion_type(*format) && *(format + 1) == '%')
		//	return (0);

		if (is_conversion_type(*format))
			return (1);
		format++;
	}
	return (0);	// Нужно ли это ?
}


int		is_width(const char *str)
{
	while (*str && *str != '.') // while (*str && !is_precision(str)) OR while (*str != '.')
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

int		is_precision(const char *str)
{
	while (*str && !is_conversion_type(*str))// && !is_length(str)) au lieu de && !is_conversion_type()
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

void				set_precision(int precision, t_spec *specs)
{
	specs->precision = precision;
}

void				set_width(int width, t_spec *specs)
{
	specs->width = width;
}
*/

void				print_placeholder(t_placeholder *placeholder)
{
	ft_putstr("%[");
	ft_putnbr(placeholder->specs->parameter);
	ft_putstr("][");
	ft_putnbr(placeholder->specs->flags->space);
	ft_putnbr(placeholder->specs->flags->hash);
	ft_putnbr(placeholder->specs->flags->plus);
	ft_putnbr(placeholder->specs->flags->minus);
	ft_putnbr(placeholder->specs->flags->zero);
	ft_putstr("][");
	ft_putnbr(placeholder->specs->width);
	ft_putstr("].[");
	ft_putnbr(placeholder->specs->precision);
	ft_putstr("][");
	printf("%c]%c\n", placeholder->specs->length, placeholder->type);
}
