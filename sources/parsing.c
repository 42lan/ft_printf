/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:25:40 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/27 13:51:51 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				parsing(const char **format, va_list *ap, t_buffer *buffer)
{
	(void)ap;
	(void)buffer;
	/*
	int				nb = 0;
	*/
	t_placeholder	*placeholder;

	placeholder = initialize_placeholder();
	while (**format)
	{
		if (ft_isprint(**format))
			jump_table[**format - ' '](format, placeholder);
		(*format)++;
		/*
		// FLAGS
		if (is_flag(**format) && **format - 1 != '.')
			set_flag(**format, placeholder->specs->flags);
		// WIDTH
		else if (is_flag(*(*format - 1)) && (ft_isdigit(**format) || **format == '*'))
		{
			if (**format == '*')
			{
				ft_putendl("I'll take WIDTH from argument list");
				(*format)++;
			}
			else
			{
				while (ft_isdigit(**format))
				{
					nb *= 10;
					nb = nb + (**format - '0');
					(*format)++;
				}
				placeholder->specs->width = nb;
				nb = 0;
				(*format)--;
			}
		}
		// PRECISION
		else if (*(*format)++ == '.')
		{
			if (**format == '*')
			{
				ft_putendl("I'll take PRECISION from argument list");
			}
			else
			{		
				while (ft_isdigit(**format))
				{
					//nb = ft_atoi(*format);
					nb *= 10;
					nb = nb + (**format - '0');
					(*format)++;
				}
				placeholder->specs->precision = nb;
				nb = 0;
				(*format)--;
			}
		}
		// LENGTH
		else if (ft_isdigit(*(*format - 1)))
		{

		}
		// TYPE
		else if (**format == '%')
		{
			ft_putendl("HOHO");
			print_placeholder(placeholder);
		}
		(*format)++;
		*/
	}
}
