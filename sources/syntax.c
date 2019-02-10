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
	/* 		%[parameter][flags][width][.precision][length]type 		*/

	//check_parameter();
	if (is_flag(c))
	{
		set_flag(c, type->specifiers->flags);
		return (1);
	//check_width();
	//check_precision();
	//check_length();
	}
	else if (conversion_type(c) > 0)
		check_type(c, type);
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
