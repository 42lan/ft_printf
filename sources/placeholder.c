/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeholder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 05:50:25 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/16 09:09:18 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_placeholder(const char **format)//, t_placeholder *placeholder)
{
	//placeholder = initialize_placeholder();
	if ((**format + 1) == '%')
		return (0);
	while (**format)
	{
		if (is_conversion_type(**format))
		{
			//ft_putchar(**format);
			//ft_putchar('\n');
			return (1);
		}
		(*format)++;
	}
	//ft_putchar(**format);
	//ft_putchar('\n');
	/*
	ft_putchar(**format);
	(*format)++;
	while (!is_conversion_type(**format))
	{
		ft_putchar(**format);
		check_syntax(**format, placeholder);
		(*format)++;
	}
	ft_putchar(**format);
	ft_putchar('\n');
	print_placeholder(placeholder);
	ft_putchar('\n');
	*/
	return (0);
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

