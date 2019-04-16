/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:39:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/12 10:15:54 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		ft_lnblen(long long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_litoa(long long n)
{
	intmax_t	nbr;
	size_t		len;
	char		*str;

	nbr = n;
	len = ft_lnblen(nbr);
	/* VERIFIER SI N > LONG_MAX
	if (n > 9223372036854775807)
	{
		n = 
		len++;
	}
	*/
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (nbr == 0)
		str[len - 1] = nbr + '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr != 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
