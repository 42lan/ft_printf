/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 05:08:44 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/16 09:14:20 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** is_conversion_type() checks if given argument match integer conversion
** (diouxX), floating-point conversion (eEfgG) or a char/string (cs).
** If given argument doesn't match any of those function return 0
*/

int		is_conversion_type(const char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	else if (c == 'e' || c == 'E' || c == 'f' || c == 'g' || c == 'G')
		return (2);
	else if (c == 'c' || c == 's')
		return (3);
	return (0);
}

/*
** Depending what type is given argument integer_conversion() sets up
** type field of t_placeholder structure
*/

void	integer_conversion(const char c, t_placeholder *placeholder)
{
	if (c == 'd' || c == 'i')
		placeholder->type = 'd';
	else if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
		placeholder->type = 'u';
}

void	floating_point_conversion(t_placeholder *placeholder)
{
	placeholder->type = 'f';
}

/*void	integer_conversion(t_placeholder *placeholder)
{
	placeholder->type = 'd';
}*/
