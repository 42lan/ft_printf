/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:18:09 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/23 10:18:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_number(const char **format)
{
	int		number;

	number = 0;
	while (ft_isdigit(**format)) // Пока текущий символ это цифра то определить значение числа
	{
		number *= 10;
		number = number + (**format - '0');
		(*format)++;
	}
	return (number);
}
