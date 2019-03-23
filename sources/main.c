/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:31:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/23 16:46:17 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main(void)
{
	printf("\n\033[35m[ PRINTF ]\t-> Return: %d\033[0m\n",	  printf("Hello % 15.d.", 2147483647));
	printf("\n\033[35m[ FT_PRINTF ]\t-> Return: %d\033[0m\n",	  ft_printf("Hello % 15.d.", 2147483647));
	printf("\n\033[35m[ PRINTF ]\t-> Return: %d\033[0m\n",	  printf("Hello % 15.d.", -2147483647));
	printf("\n\033[35m[ FT_PRINTF ]\t-> Return: %d\033[0m\n",	  ft_printf("Hello % 15.d.", -2147483647));
	return (0);
}
