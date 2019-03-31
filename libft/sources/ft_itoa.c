/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 08:59:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/31 15:46:15 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	intmax_t	nbr;
	size_t		len;
	char		*str;

	nbr = n;
	len = ft_nblen(nbr);
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
