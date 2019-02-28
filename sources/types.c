/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:20:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/28 14:46:13 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			unknown(const char **format, t_placeholder *placeholder)
{
	placeholder->type = **format;
}

void			type_d(const char **format, t_placeholder *placeholder)
{
	placeholder->type = **format;
}

void			type_c(const char **format, t_placeholder *placeholder)
{
	placeholder->type = **format;
}

void	type_f(const char **format, t_placeholder *placeholder)
{
	placeholder->type = **format;
}

void			type_s(const char **format, t_placeholder *placeholder)
{
	placeholder->type = **format;
}

void			percent(const char **format, t_placeholder *placeholder)
{
	placeholder->type = **format;
}
