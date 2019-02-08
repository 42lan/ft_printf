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
	if (!(x->flag = (t_flags *)malloc(sizeof(t_flags))))
		return (1);
	x->flag->minus = 1;
	printf("%d\n\n", x->flag->minus);
	printf("Hello, %s%c Ingore following % d%%\n", world, exclam, nb);
	ft_printf("Hello, %s%c Ingore following % d%%\n", world, exclam, nb);
	return (0);
}
