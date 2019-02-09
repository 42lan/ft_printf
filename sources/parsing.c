/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 00:02:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/07 23:08:51 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parsing(va_list arg, const char *restrict str)
{
	//		ft_printf("Hello, %s%c Ingore following %	d%%\n", world, exclam, nb);
	(void)arg;
	int		i;
	t_type	*type;
	//char	buffer[BUFF_SIZE];

	i = -1;
	if (!str)
		return (-1);
	if (!(type = (t_type *)ft_memalloc(sizeof(t_type))))
		return (0);
	if (!(type->specifiers = (t_spec *)ft_memalloc(sizeof(t_spec))))
		return (0);
	if (!(type->specifiers->flags = (t_flags *)ft_memalloc(sizeof(t_flags))))
		return (0);
	reset_flags(type->specifiers->flags);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '%')
		{
			str++;
			while (!ft_isalpha(*str))
			{
				if (check_syntax(*str, type))
				{
					ft_putendl("OK");
				}
				str++;
			}
			ft_putnbr(type->specifiers->flags->minus);
			ft_putnbr(type->specifiers->flags->plus);
			ft_putnbr(type->specifiers->flags->space);
			ft_putnbr(type->specifiers->flags->zero);
			ft_putnbr(type->specifiers->flags->hash);
		}
		str++;
	}
	/*char	*s;
	int		c;
	int		d;

	while (*str)
	{
		if (*str == '%' && (*(str + 1) != '%' && *(str - 1) != '%'))
		{
			if (*(str + 1) == 's')
			{
				s = va_arg(arg, char *);
				ft_putstr(s);
			}
			if (*(str + 1) == 'c')
			{
				c = va_arg(arg, int);
				ft_putchar(c);
			}
			if (*(str + 1) == 'd')
			{
				d = va_arg(arg, int);
				ft_putnbr(d);
			}
		}
		str++;
	}*/
	return (1);
}
