/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:31:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/08 01:00:38 by amalsago         ###   ########.fr       */
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
	t_spec	*x;
	
	if (!(x = (t_spec *)malloc(sizeof(t_spec))))
		return (1);
	if (!(x->flags = (t_flags *)malloc(sizeof(t_flags))))
		return (1);
	x->flags->minus = 1;
	printf("%lu\n\n", sizeof(x->flags));
	printf("Hello, %s%c Ingore following % d%%\n", world, exclam, nb);
	ft_printf("Hello, %s%c Ingore following % d%%\n", world, exclam, nb);
	return (0);
}
