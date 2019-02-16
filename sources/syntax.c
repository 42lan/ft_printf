/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 22:09:27 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/16 09:09:16 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** check_syntax() call other functions to check specifiers and type
*/

int			check_syntax(const char *str, t_placeholder *placeholder)
{
	while (!is_conversion_type(*str))			// Я здесь блокируюсь. Нужно быть на позиции +1
	{
		if (is_flag(*str))
			set_s_flag(*str, placeholder->specs->flags);
		/*
		else if (is_precision(c)){}
		else if (is_length(c)){}
		*/
		//ft_putchar(*str);
		str++;
	}
	//ft_putchar(*str);
	check_type(*str, placeholder);
/*
	//if (is_parameter(c)){}
	if (is_flag(c))
	{
		set_flag(c, placeholder->specs->flags);
		return (1);
	}
	else if (is_width(c)){}
	else if (is_precision(c)){}
	else if (is_length(c)){}
	else if (is_conversion_type(c) > 0)
		check_type(c, placeholder);
			return (1);
*/
	return (0);
}

/*
** check_type() determin data type and make call other functions to convert
** one data type to another
*/

int			check_type(const char c, t_placeholder *placeholder)
{
	int		type;

	type = is_conversion_type(c);
	if (type == 1)
	{
		integer_conversion(c, placeholder);
		//ft_putendl("integer_conversion");
	}
	else if (type == 2)
	{
		floating_point_conversion(placeholder);
		//ft_putendl("floating_point_conversion");
	}
	else if (type == 3)
	{
		placeholder->type = c;
	}
	return (1);
}
