/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:20:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/27 16:48:32 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	asterisk(const char **format, t_info *info)
{
	info->type = **format;
}

void	type_f(const char **format, t_info *info)
{
	info->type = **format;
}
