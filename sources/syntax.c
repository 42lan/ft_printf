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
	}
	/*
	else if (is_width(c)){}
	else if (is_precision(c)){}
	else if (is_length(c)){}
	*/
	else if (conversion_type(c) > 0)
		check_type(conversion_type(c), type);
			return (1);
	return (0);
}



/*
** check_type() determin data type and make call other functions to convert
** one data type to another
*/

//int			check_type(const char c, t_type *type)
int			check_type(unsigned n_type, t_type *type)
{
	if (n_type == 1)
	{
		//integer_conversion(c, type);
		ft_putendl("integer_conversion");
	}
	else if (n_type == 2)
	{
		floating_point_conversion(type);
		ft_putendl("floating_point_conversion");
	}
	return (1);
}

void		floating_point_conversion(t_type *type)
{
	type->type = 'f';
}