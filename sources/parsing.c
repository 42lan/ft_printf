/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 00:02:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/09 03:38:06 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Initialization of type pointer to t_type structure
*/

t_type		*initialize_type(void)
{
	t_type	*type;

	if (!(type = (t_type *)ft_memalloc(sizeof(t_type))))
		return (NULL);
	if (!(type->specifiers = (t_spec *)ft_memalloc(sizeof(t_spec))))
		return (NULL);
	if (!(type->specifiers->flags = (t_flags *)ft_memalloc(sizeof(t_flags))))
		return (NULL);
	initialize_flags(type->specifiers->flags);
	return (type);
}

/*
** Deallocation of allocated memory for flags, specifiers and type
*/

void		deallocate_type(t_type *type)
{
	free(type->specifiers->flags);
	type->specifiers->flags = NULL;
	free(type->specifiers);
	type->specifiers = NULL;
	free(type);
	type = NULL;
	//ft_memdel(type->specifiers->flags);
	//ft_memdel(type->specifiers);
	//ft_memdel(type);
}

/*
** Parsing function to set up fields of t_type structure
*/

int			parsing(va_list arg, const char *restrict str)
{
	(void)arg;
	int		i;
	t_type	*type;
	char	buffer[BUFF_SIZE];

	if (!str)
		return (0);
	i = -1;
	if (!(type = initialize_type()))
		return (0);
	while (*str)
	{
		if (*str == '%' && *(str + 1) == '%')
		{
			str++;
			if (++i < BUFF_SIZE)
				buffer[i] = *str;
		}
		else if (*str == '%' && is_flag(*(str + 1)))
		{
			str++;
			while (!conversion_type(*str))
			{
				if (check_syntax(*str, type))
					ft_putchar(*str);
				str++;
			}
		}
		else
			if (++i < BUFF_SIZE)
				buffer[i] = *str;
		str++;
	}
	ft_putendl(buffer);
	deallocate_type(type);
	return (1);
}

/*
char	*s;
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
}
*/
