/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:31:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/13 18:17:17 by amalsago         ###   ########.fr       */
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
	printf("\n->Total length: %d\n\n",    printf("Heloo %+-5d.", +42));
	printf("\n->Total length: %d\n", ft_printf("Heloo %+-5d.", +42));
	return (0);
}
