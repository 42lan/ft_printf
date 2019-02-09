/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 05:08:44 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/09 02:36:38 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** conversion_type() checks if given argument match integer conversion (diouxX)
** or floating-point conversion (eEfgG). If given argument doesn't match any
** of those function return 0
*/

int     check_conversion_type(const char c)
{
    if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
        return (1);
    else if (c == 'e' || c == 'E' || c == 'f' || c == 'g' || c == 'G')
        return (2);
    return (0);
}

void    integer_conversion(const char c, t_type *type)
{
    if (c == 'd' || c == 'i')
        type->type = 'd';
    else if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
        type->type = 'u';
}
