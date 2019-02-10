/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 22:09:27 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/09 04:31:48 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** check_syntax() call other functions to check specifiers and type
*/

int			check_syntax(const char c, t_type *type)
{
	/* %[parameter][flags][width][.precision][length]type */

	if (c && type)
	{
		//check_parameter();
		if (is_flag(c))
			if (check_flags(c, type->specifiers->flags))
				return (1);
		//check_width();
		//check_precision();
		//check_length();
		ft_putendl("HERE");
		if (conversion_type(c) > 0)
			check_type(c, type);
		return (1);
	}
	return (0);
}

/*
** Setting up all fields of t_flags structure to 0
*/

void		initialize_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->hash = 0;
}

/*
** Checking if given char is one of the flags
*/

int			is_flag(const char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#');
}

/*
** Checking if passed character in argument is one of the flags and
** setting up the corresponding bit to 1
*/

/*
? void ?????
  |
  V       */
int			check_flags(const char c, t_flags *flags)
{
	if (c == '-')
		flags->minus = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '0')
		flags->zero = 1;
	else if (c == '#')
		flags->hash = 1;
	else
		return (0);
	return (1);
}

/*
** check_type() determin data type and make call other functions to convert
** one data type to another
*/

int			check_type(const char c, t_type *type)
{
	(void)type;
	ft_putendl("----");
	if (conversion_type(c) == 1)
	{
		//integer_conversion(c, type);
		ft_putendl("integer_conversion");
	}
	else if (conversion_type(c) == 2)
	{
		//floating_point_conversion(c, type);
		ft_putendl("floating_point_conversion");
	}
	else
		return (0);
	return (1);
}
