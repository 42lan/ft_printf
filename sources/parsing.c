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
** Initialization of type pointer to t_placeholder structure
*/

void				initialize_specifiers(t_spec *specifiers)
{
	specifiers->parameter = 0;
	specifiers->width = 0;
	specifiers->precision = 6;
	specifiers->length = NULL;
}

t_placeholder		*initialize_placeholder(void)
{
	t_placeholder	*placeholder;

	if (!(placeholder = (t_placeholder *)ft_memalloc(sizeof(t_placeholder))))
		return (NULL);
	if (!(placeholder->specifiers = (t_spec *)ft_memalloc(sizeof(t_spec))))
		return (NULL);
	initialize_specifiers(placeholder->specifiers);
	if (!(placeholder->specifiers->flags = (t_flags *)ft_memalloc(sizeof(t_flags))))
		return (NULL);
	initialize_flags(placeholder->specifiers->flags);
	return (placeholder);
}

/*
** Deallocation of allocated memory for flags, specifiers and type
*/

void				deallocate_placeholder(t_placeholder *placeholder)
{
	free(placeholder->specifiers->flags);
	placeholder->specifiers->flags = NULL;
	free(placeholder->specifiers);
	placeholder->specifiers = NULL;
	free(placeholder);
	placeholder = NULL;
	//ft_memdel(placeholder->specifiers->flags);
	//ft_memdel(placeholder->specifiers);
	//ft_memdel(placeholder);
}

/*
** Parsing function to set up fields of t_placeholder structure
*/

int					parsing(va_list arg, const char *restrict str)
{
	(void)arg;
	int				i;
	t_placeholder	*placeholder;
	char			buffer[BUFF_SIZE];

	if (!str)
		return (0);
	i = -1;
	if (!(placeholder = initialize_placeholder()))
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
				if (check_syntax(*str, placeholder))
					//ft_putchar(*str);
				str++;
			}
			if (conversion_type(*str))
				check_syntax(*str, placeholder);
			/*while (is_width)
			{

			}*/
		}
		else
			if (++i < BUFF_SIZE)
				buffer[i] = *str;
		str++;
	}
	ft_putstr("\nSpecifiers:\n%[");
	ft_putnbr(placeholder->specifiers->parameter);
	ft_putstr("][");
	ft_putnbr(placeholder->specifiers->flags->space);
	ft_putnbr(placeholder->specifiers->flags->hash);
	ft_putnbr(placeholder->specifiers->flags->plus);
	ft_putnbr(placeholder->specifiers->flags->minus);
	ft_putnbr(placeholder->specifiers->flags->zero);
	ft_putstr("][");
	ft_putnbr(placeholder->specifiers->width);
	ft_putstr("].[");
	ft_putnbr(placeholder->specifiers->precision);
	ft_putstr("][");
	printf("%s", placeholder->specifiers->length);
	ft_putchar(']');
	ft_putchar(placeholder->type);
	//ft_putstr("\nbuffer[BUFF_SIZE] -> ");
	//printf("|%s|\n", buffer);
	deallocate_placeholder(placeholder);
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
