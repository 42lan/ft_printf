/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 00:39:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/29 19:18:30 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_silen(intmax_t number, int base)
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

static void		check_sign(char **str, intmax_t *number, size_t *length)
{
	if (*number < 0)
	{
		--(*length);
		*str[0] = '-';
		*number *= -1;
	}
}

char			*ft_sitoa_base(intmax_t number, int base, int uppercase)
{
	char		*str;
	size_t		length;

	if (base < 2 || base > 36)
		exit(0);
	length = ft_silen(number, base);
	if (!(str = ft_strnew(length)))
		return (NULL);
	check_sign(&str, &number, &length);
	while (length != 0)
	{
		if (number < 0)
			str[length--] = BASE_LOWER[number % base];
		else
			str[--length] = BASE_LOWER[number % base];
		number /= base;
	}
	if (uppercase == 1)
		while (*str)
			ft_toupper(*str++);
	return (str);
}
