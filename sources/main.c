/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:31:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/16 15:21:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main(void)
{
	//printf("\n%d\n", printf("Hello, %.5s%c", "World#$%^&*786ef", '!'));
	//printf("\n%d\n", ft_printf("Hello, %-25%. %-10.5s%c", "World#$^&*786ef", '!'));
	//printf("\n%d\n", printf("Hello, %010.8f%%. My name is%6.5s%c Temperature is %+d°C.", 42.1, "Aslan)@$!", '!', 32));
	//printf("\n%d\n", printf("My name is%6.5s%c Hello, %+010.8f%%. Temperature is %+d°C.", "Aslan:@$!", '!', 42.1, -2));
	// printf("\n%d\n", ft_printf("My name is%6.5s%c Hello, %+010.8f%%. Temperature is %+d°C.", "Aslan:@$!", '!', 42.1, -2));
	// printf("\n->%d\n",  printf("HelloHelloHelloHelloHelloHelloHelloHello %-d", 42));
	printf("\n\033[35m[ PRINTF ]\t-> Return: %d\033[0m\n",		 printf("Hello! Here is %0+10d.", 214748));
	printf("\n\033[36m[ FT_PRINTF ]\t-> Return: %d\033[0m\n", ft_printf("Hello! Here is %0+10d.", 214748));
	printf("\n\033[35m[ PRINTF ]\t-> Return: %d\033[0m\n",		 printf("Hello! Here is %0+10d.", -214748));
	printf("\n\033[36m[ FT_PRINTF ]\t-> Return: %d\033[0m\n", ft_printf("Hello! Here is %0+10d.", -214748));
	return (0);
}
