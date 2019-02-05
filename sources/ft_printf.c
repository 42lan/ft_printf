/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:43:59 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/06 00:10:18 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *restrict format, ...)
{
	int			returned;
	va_list		ap;

	va_start(ap, format);
	returned = parsing(ap, format);
	va_end(ap);
	return (returned);
}
