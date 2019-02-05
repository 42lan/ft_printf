/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:31:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/05 23:42:11 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main(int ac, char **av)
{
	int		i;

	if (ac < 2)
		return (1);
	i = 1;
	while (av[i])
	{
		if (ft_printf(av[i]) > 0)
			i++;
		else
			ft_putstr("ft_printf() return a negative value");
	}
	return (0);
}
