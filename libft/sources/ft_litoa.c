/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:00:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/06 08:58:25 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_litoa(intmax_t number)
{
	size_t		len;
	char		*str;

	len = ft_silen(number, 10);
	if (number <= LLONG_MIN)
	{
		str = ft_strdup("-9223372036854775808");
		return (str);
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (number == 0)
		str[len - 1] = number + '0';
	else if (number < 0)
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
