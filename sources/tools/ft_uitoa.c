/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:01:18 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/16 16:03:34 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_uitoa(uintmax_t n)
{
	uintmax_t		nbr;
	size_t			len;
	char			*str;

	nbr = n;
	len = ft_nblen(nbr);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (nbr == 0)
		str[len - 1] = nbr + '0';
	while (nbr != 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
