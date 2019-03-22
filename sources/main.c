/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:31:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/22 18:50:41 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main(void)
{
	printf("\n\033[35m[ PRINTF ]\t-> Return: %d\033[0m\n",	  printf("Hello %--10c.", '!'));
	printf("\n\033[35m[ PRINTF ]\t-> Return: %d\033[0m\n",	  ft_printf("Hello %--10c.", '!'));
	printf("\n\033[35m[ PRINTF ]\t-> Return: %d\033[0m\n",	  printf("Hello %--10.3s.", "WORLD123"));
	printf("\n\033[35m[ PRINTF ]\t-> Return: %d\033[0m\n",	  ft_printf("Hello %--10.3s.", "WORLD123"));
	printf("\n\033[35m[ PRINTF ]\t-> Return: %d\033[0m\n",	  printf("Hello %---10.3d.", -42));
	printf("\n\033[35m[ PRINTF ]\t-> Return: %d\033[0m\n", ft_printf("Hello %---10.3d.", -42));
	return (0);
}
