/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:31:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/27 13:51:49 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			main(void)
{
	//printf("\n%d\n", printf("Hello, %.5s%c", "World#$%^&*786ef", '!'));
	//printf("\n%d\n", ft_printf("Hello, %-25%. %-10.5s%c", "World#$^&*786ef", '!'));
	// printf("\n%d\n", printf("Hello, %010d", 42));
	printf("\n%d\n", ft_printf("Hello, %010d", 42));
	return (0);
}
