/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 00:39:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/22 17:51:42 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_silen(intmax_t number, unsigned base)
{
	size_t		length;

	length = 0;
	if (number == 0)
		return (1);
	else if (number < 0)
		length = 1;
	while (number != 0)
	{
		number /= base;
		++length;
	}
	return (length);
}

char			*ft_sitoa_base(intmax_t number, unsigned base, int uppercase)
{
	char		*str;
	size_t		length;

	if (base < 2 || base > 36)
		exit(0);
	length = ft_silen(number, base);
	if (!(str = ft_strnew(length)))
		return (NULL);
	if (number < 0)
	{
		--length;
		str[0] = '-';
		number *= -1;
	}
	if (uppercase == 0)
	{
		while (length != 0)
		{
			if (number < 0)
				str[length--] = BASE_LOWER[number % base];
			else
				str[--length] = BASE_LOWER[number % base];
			number /= base;
		}
	}
	else
	{
		while (length != 0)
		{
			if (number < 0)
				str[length--] = BASE_UPPER[number % base];
			else
				str[--length] = BASE_UPPER[number % base];
			number /= base;
		}
	}
	return (str);
}
