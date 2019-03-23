/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 10:21:36 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/23 10:42:17 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		digit(const char **format, t_info *info)
{
	if (*(*format - 1) != '.') // Если это не precision, то это width
		set_width(format, info);
}
