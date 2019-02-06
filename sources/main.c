/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:31:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/06 02:22:02 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char	*world = "World";
	char	exclam = '!';

	printf("Hello, %s%c Ingore following %%\n", world, exclam);
	ft_printf("Hello, %s%c Ingore following %%\n", world, exclam);
	return (0);
}
