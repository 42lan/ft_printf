/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:39:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/01 14:12:33 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lnblen(intmax_t number)
{
	size_t		length;

	length = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		length++;
	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

char			*ft_litoa(intmax_t number)
{
	size_t		len;
	char		*str;

	len = ft_lnblen(number);
	if (number <= LLONG_MIN)
	{
		str = ft_strdup("-9223372036854775808");
		return (str);
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (number == 0)
		str[len - 1] = number + '0';
	if (number < 0)
	{
		str[0] = '-';
		number *= -1;
	}
	while (number != 0)
	{
		str[--len] = (number % 10) + '0';
		number /= 10;
	}
	return (str);
}
