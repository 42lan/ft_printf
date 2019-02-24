/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:31:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/24 13:17:02 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main(void)
{
	char	*world = "World[*&.-+^$#@!THIS IS GARBAGE^)*&&*()";
	char	c = '!';
	int		pos = 99;
	int		fah = 451;
	int		neg = -232;
	float	pi = 3.141592;

	//printf("Hello, %16.5s%c\n[% 9d%% ] Loading...\nPi number %+14.4f\nFahrenheit %d -(%.2d°C)\nInvalid placeholder %%.5R\n", world, c, pos, pi, fah, neg);
	ft_printf("Hello, %16.5s%c\n[% 9d%% ] Loading...\nPi number %+14.4f\nFahrenheit %d -(%.2d°C)\nInvalid placeholder %%.5R\n", world, c, pos, pi, fah, neg);
	return (0);
}