/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 09:25:40 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/26 15:22:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				parsing(const char **format, va_list *ap, t_buffer *buffer)
{
	(void)ap;
	(void)buffer;
	int				nb;
	t_placeholder	*placeholder;

	nb = 0;
	placeholder = initialize_placeholder();
	while (**format)
	{
		/* FLAGS */
		if (is_flag(**format) && **format - 1 != '.')
			set_flag(**format, placeholder->specs->flags);
		/* WIDTH */
		else if (is_flag(*(*format - 1)) && ft_isdigit(**format))
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
		/* PRECISION */
		else if (**format == '.')
		{
			(*format)++;
			if (**format == '*')
			{
				// take from arg list
				ft_putendl("I'll take from arg list");
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
			}
		}
		/* LENGTH */
		else if (ft_isdigit(*(*format - 1)))
		{

		}
		(*format)++;
	}
	print_placeholder(placeholder);
}
