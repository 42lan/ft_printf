/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:31:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/27 19:02:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			main(void)
{
	int		a;

	a = 42;
	printf("\t[ PRINTF ]\t-> Return: %d\n", printf("%p", &a));
	printf("\t[ FT_PRINTF ]\t-> Return: %d\n", ft_printf("%p", &a));
	//printf("\t[ PRINTF ]\t-> Return: %d\n", printf("%ld\n", 2147483647));
	//printf("\t[ FT_PRINTF ]\t-> Return: %d\n", ft_printf("%ld\n", 2147483647));
	/*
	printf("\t[ PRINTF ]\t-> Return: %d\n",		  printf("|%5.2s is a string|", ""));
	printf("\t[ FT_PRINTF ]\t-> Return: %d\n", ft_printf("|%5.2s is a string|", ""));
	printf("\t[ PRINTF ]\t-> Return: %d\n",		  printf("|%-5.2s is a string|", ""));
	printf("\t[ FT_PRINTF ]\t-> Return: %d\n", ft_printf("|%-5.2s is a string|", ""));
	printf("\t[ PRINTF ]\t-> Return: %d\n",		  printf("|%.2c|", NULL));
	printf("\t[ FT_PRINTF ]\t-> Return: %d\n", ft_printf("|%.2c|", NULL));
	printf("\t[ PRINTF ]\t-> Return: %d\n",		  printf("|@moulitest: %c|", 0));
	printf("\t[ FT_PRINTF ]\t-> Return: %d\n", ft_printf("|@moulitest: %c|", 0));
	printf("\t[ PRINTF ]\t-> Return: %d\n",		  printf("|%2c|", 0));
	printf("\t[ FT_PRINTF ]\t-> Return: %d\n", ft_printf("|%2c|", 0));
	printf("\t[ PRINTF ]\t-> Return: %d\n",		  printf("|null %c and text|", 0));
	printf("\t[ FT_PRINTF ]\t-> Return: %d\n", ft_printf("|null %c and text|", 0));
	printf("\t[ PRINTF ]\t-> Return: %d\n",		  printf("|% c|", 0));
	printf("\t[ FT_PRINTF ]\t-> Return: %d\n", ft_printf("|% c|", 0));
	printf("\t[ PRINTF ]\t-> Return: %d\n",		  printf("|%03.2|d", -1));
	printf("\t[ FT_PRINTF ]\t-> Return: %d\n", ft_printf("|%03.2|d", -1));
	printf("\t[ PRINTF ]\t-> Return: %d\n",		  printf("|%lu|", -42));
	printf("\t[ FT_PRINTF ]\t-> Return: %d\n", ft_printf("|%lu|", -42));
	*/
	return (0);
}
