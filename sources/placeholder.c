/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeholder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 05:50:25 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/17 07:49:52 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_placeholder(const char **format)
{
	if ((**format + 1) == '%')
		return (0);
	while (**format)
	{
		if (is_conversion_type(**format))
			return (1);
		(*format)++;
	}
	return (0);
}

int		is_flag(const char c)
{
	return (c == ' ' || c == '#' || c == '+' || c == '-' || c == '0');
}

int		is_width(const char **str)
{
	while (**str && **str != '.') // while (*str && !is_precision(str))
	{
		if (ft_isdigit(**str))
			(*str)++;
		else
			return (0);
	}
	return (1);
}


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
	printf("%s]%c\n", placeholder->specs->length, placeholder->type);
}

void				set_width(int width, t_spec *specs)
{
	specs->width = width;
}
