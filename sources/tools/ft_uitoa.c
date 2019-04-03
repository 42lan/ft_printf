/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:01:18 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/31 19:16:57 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*ft_uitoa(unsigned n)
{
	unsigned long	nbr;
	size_t			len;
	char			*str;

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
