/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:31:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/07 04:08:54 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char	*world = "World";
	char	exclam = '!';
	int		nb = 42;

	printf("Hello, %s%c Ingore following % d%%\n", world, exclam, nb);
	ft_printf("Hello, %s%c Ingore following % d%%\n", world, exclam, nb);
	return (0);
}
