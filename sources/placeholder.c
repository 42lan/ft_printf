/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeholder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 05:50:25 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/15 09:26:27 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_placeholder(const char **format)
{
	while (**format)
	{
		if (is_conversion_type(**format))
		{
			printf("%c", **format);
			return (1);
		}
		(*format)++;
	}
	return (1);
}
