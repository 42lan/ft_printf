/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:32:44 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/23 16:08:36 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


/*
int		is_length(const char *str)
{
 // hh h l ll L
}
*/

int		is_length(const char **format)
{
	if ((**format == 'h' && **(format + 1) == 'h') && is_conversion_type(**(format + 2)))
		return (1);
	else if ((**format == 'l'  && **(format + 1) == 'l') && is_conversion_type(**(format + 2)))
	{
		*format += 2;
		return (2);
	}
	else if ((**format == 'h') && is_conversion_type(**(format + 1)))
		return (3);
	else if ((**format == 'l') && is_conversion_type(**(format + 1)))
		return (4);
	else if ((**format == 'L') && is_conversion_type(**(format + 1)))
		return (5);
	else
		return (0);
}


void				set_length(int l, t_spec *specs)
{
	if (l == 1)
		specs->length = "hh";
	else if (l == 2)
		specs->length = "ll";
	else if (l == 3)
		specs->length = "h";
	else if (l == 4)
		specs->length = "l";
	else if (l == 5)
		specs->length = "L";
}

