/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:31:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/26 19:12:07 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main(void)
{
	 printf("\n[ PRINTF ]\t-> Return: %d\n",	      printf("Hello %s!", "World123"));
	 printf("\n[ FT_PRINTF ]\t-> Return: %d\n", ft_printf("Hello %s!", "World123"));
	printf("\n[ PRINTF ]\t-> Return: %d\n",	      printf("Hello %-s!", "World123"));
	printf("\n[ FT_PRINTF ]\t-> Return: %d\n", ft_printf("Hello %-s!", "World123"));
	return (0);
}
