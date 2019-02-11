/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 00:02:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/11 03:54:56 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Parsing function to set up fields of t_placeholder structure
*/

int					parsing(va_list arg, const char *restrict str)
{
	(void)arg;
	int				i;
	t_placeholder	*placeholder;
	char			buffer[BUFF_SIZE];
	double			f;

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
			{
				check_syntax(*str, placeholder);
				{
					f = va_arg(arg, double);
					ft_putnbr(f);
				}
			}/*
			while (is_width){}
			*/
		}
		else
			if (++i < BUFF_SIZE)
				buffer[i] = *str;
		str++;
	}
	print_placeholder(placeholder);
	deallocate_placeholder(placeholder);
	return (1);
}

void				print_placeholder(t_placeholder *placeholder)
{
	ft_putstr("%[");
	ft_putnbr(placeholder->specs->parameter);
	ft_putstr("][");
	ft_putnbr(placeholder->specs->flags->space);
	ft_putnbr(placeholder->specs->flags->hash);
	ft_putnbr(placeholder->specs->flags->plus);
	ft_putnbr(placeholder->specs->flags->minus);
	ft_putnbr(placeholder->specs->flags->zero);
	ft_putstr("][");
	ft_putnbr(placeholder->specs->width);
	ft_putstr("].[");
	ft_putnbr(placeholder->specs->precision);
	ft_putstr("][");
	printf("%s]%c\n", placeholder->specs->length, placeholder->type);
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
