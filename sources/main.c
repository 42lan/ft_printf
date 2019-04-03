/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:31:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/31 17:17:43 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main(void)
{
	 printf("\n[ PRINTF ]\t-> Return: %d\n",	      printf("Hello %.5d123%c", 42, 'z'));
	 printf("\n[ FT_PRINTF ]\t-> Return: %d\n",	   ft_printf("Hello %.5d123%c", 42, 'z'));
	return (0);
}
