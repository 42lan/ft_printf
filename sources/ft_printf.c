/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:43:59 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/06 00:21:44 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** nopc - number of printed characers
** ap	- argument parameter
*/

int				ft_printf(const char *restrict format, ...)
{
	int			nopc;
	va_list		ap;

	va_start(ap, format);
	nopc = parsing(ap, format);
	va_end(ap);
	return (nopc);
}
