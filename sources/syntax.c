/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 22:09:27 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/24 13:15:16 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** check_syntax() call other functions to check specifiers and type
*/

int					check_syntax(const char *str, t_placeholder *placeholder)
{
	int				l;

	while (!is_conversion_type(*str))						// Я здесь блокируюсь. Нужно быть на позиции +1
	{
		// if (is_parameter(*str))									// Mettre en place
		if (is_flag(*str) && *(str - 1) != '.')						// Pas tres propre ca 
			set_flag(*str, placeholder->specs->flags);
		else if (is_width(str) && *(str - 1) != '.') // Pas tres propres la premiere expression
		{
			set_width(ft_atoi(str), placeholder->specs);
			while (ft_isdigit(*str))
				str++;
		}
		else if (is_precision(str) && *(str - 1) == '.')
		{
			set_precision(ft_atoi(str), placeholder->specs);
			while (ft_isdigit(*str))
				str++;
			str--;
		}
		else if ((l = is_length(&str)) > 0)
		{
			set_length(l, placeholder->specs);
		}
		str++;
	}
	//ft_putchar(*str);
	check_type(*str, placeholder);
	return (0);
}

/*
** check_type() determin data type and make call other functions to convert
** one data type to another
*/

int					check_type(const char c, t_placeholder *placeholder)
{
	int				type;

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
