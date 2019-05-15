/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_static.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:36:24 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/15 10:05:45 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_ftoa_static(double number, unsigned int precision)
{
	static char		str[10];
	int				i;
	int				i_part;
	float			f_part;

	i_part = (int)number;
	f_part = number - (i_part);
	ft_strcpy(str, ft_itoa_static(i_part));
	str[ft_nblen(i_part)] = '.';
	i = ft_nblen(i_part) + 1;
	if (number < 0)
		f_part *= -1;
	while (precision-- != 0)
	{
		f_part *= 10;
		str[i++] = ((int)f_part % 10) + '0';
	}
	str[(number > 0) ? 8 : 9] = '\0';
	return (str);
}
