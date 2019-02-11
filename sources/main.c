/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:31:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/11 03:32:00 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	/*char	*world = "World";
	char	exclam = '!';*/
	float	nb = 42.68;

	/* 		%[parameter][flags][width][.precision][length]type 		*/
	//printf("%%_%+f ", nb);
	if (ft_printf("%%_%0+.f= %d", nb, nb/2) < 0)
		return (1);
	/*printf("Hello, %s%c %+.2f%%\n", world, exclam, nb);
	if (ft_printf("Hello, %s%c %+.2f%%\n", world, exclam, nb) < 0)
		return (1);*/
	return (0);
}
