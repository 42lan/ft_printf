/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:20:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/13 21:25:10 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			unknown(const char **format, t_info *info)
{
	info->type = **format;
}

void			type_percent(const char **format, t_info *info)
{
	info->type = **format;
}

void			asterisk(const char **format, t_info *info)
{
	info->type = **format;
}
void			type_c(const char **format, t_info *info)
{
	info->type = **format;
}

void			type_di(const char **format, t_info *info)
{
	int			number;
	char		*s;

	info->type = **format;
	number = va_arg(info->ap, int);
	s = ft_itoa(number);
	if (info->specs->width > (int)ft_nofdig(number))
	{
		if (info->specs->flags->minus == 1)
		{
			if (number > 0 && info->specs->flags->plus)
				fill_buffer(&info->buffer, '+');
			while (*s)
				fill_buffer(&info->buffer, *s++);
			specs_handle(info, number, number < 0 ? ft_nofdig(number) + 1 : ft_nofdig(number));
		}
		else
		{
			specs_handle(info, number, number < 0 ? ft_nofdig(number) + 1 : ft_nofdig(number));
			if (number > 0 && info->specs->flags->plus)
				fill_buffer(&info->buffer, '+');
			while (*s)
				fill_buffer(&info->buffer, *s++);
		}
	}
	else
	{
		if (info->specs->flags->minus == 1)
		{
			if (number > 0 && info->specs->flags->plus)
				fill_buffer(&info->buffer, '+');
			while (*s)
				fill_buffer(&info->buffer, *s++);
		}
		else
		{
			if (number > 0 && info->specs->flags->plus)
				fill_buffer(&info->buffer, '+');
			while (*s)
				fill_buffer(&info->buffer, *s++);
		}
	}
}

void			type_f(const char **format, t_info *info)
{
	info->type = **format;
}

/*
void			type_i(const char **format, t_info *info)
{
	info->type = **format;
}
*/

void			type_o(const char **format, t_info *info)
{
	info->type = **format;
}

void			type_p(const char **format, t_info *info)
{
	info->type = **format;
}

void			type_s(const char **format, t_info *info)
{
	info->type = **format;
}

void			type_u(const char **format, t_info *info)
{
	info->type = **format;
}

void			type_x(const char **format, t_info *info)
{
	info->type = **format;
}

void			type_X(const char **format, t_info *info)
{
	info->type = **format;
}
