/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:31:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/14 04:54:28 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main(void)
{
	char	*world = "World[THIS IS GARBAGE]";
	char	c = '!';
	int		pos = 99;
	int		fah = 451;
	int		neg = -42;
	float	pi = 3.141592;

	printf("----------printf----------\n");
	printf("Hello, %.5s%c\n[% 4d%% ] Loading...\nPi number %+3f\nFahrenheit %d\n%dºC\n", world, c, pos, pi, fah, neg);
	printf("----------ft_printf-------\n");
	ft_printf("Hello, %.5s%c\n[% 4d%% ] Loading...\nPi number %+3f\nFahrenheit %d\n%dºC\n", world, c, pos, pi, fah, neg);
	return (0);
}
