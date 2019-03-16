/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:20:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/16 11:44:10 by amalsago         ###   ########.fr       */
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
	char		*s;
	int			number;
	unsigned	nb_len;
	unsigned	precision;

	info->type = **format;
	number = va_arg(info->ap, int);
	nb_len = ft_nblen(number);
	s = ft_itoa(number);
	precision = info->specs->precision;

//	if (number < 0)
//		set_prefix(info);


	if (info->specs->width > nb_len)
	{
		if (info->specs->flags->minus)
		{
			if (number > 0)
			{
				if (info->specs->flags->plus)
					fill_buffer(&info->buffer, '+');
				if (info->specs->precision > nb_len)
					while (precision-- - nb_len)
						fill_buffer(&info->buffer, '0');
			}
			else
			{
				if (info->specs->precision > nb_len)
				{
					s = ft_itoa(-number);
					fill_buffer(&info->buffer, '-');
					while (precision-- - nb_len)
						fill_buffer(&info->buffer, '0');
				}
			}
			while (*s)
				fill_buffer(&info->buffer, *s++);
			width_handler(info, number, number < 0 ? nb_len + 1 : nb_len);
		}
		else
		{
			width_handler(info, number, number < 0 ? nb_len + 1 : nb_len);
			if (number > 0)
			{
				if (info->specs->flags->plus)
					fill_buffer(&info->buffer, '+');
			}
			else
			{
				s = ft_itoa(-number);
				fill_buffer(&info->buffer, '-');
			}
			if (info->specs->precision > nb_len)
				while (precision-- - nb_len)
					fill_buffer(&info->buffer, '0');
			while (*s)
				fill_buffer(&info->buffer, *s++);
		}
	}
	else
	{
		if (info->specs->flags->minus == 1)
		{
			if (number > 0)
			{
				if (info->specs->flags->plus)
					fill_buffer(&info->buffer, '+');
				if (info->specs->precision > nb_len)
					while (precision-- - nb_len)
						fill_buffer(&info->buffer, '0');
			}
			else
			{
				if (info->specs->precision > nb_len)
				{
					s = ft_itoa(-number);
					fill_buffer(&info->buffer, '-');
					while (precision-- - nb_len)
						fill_buffer(&info->buffer, '0');
				}
			}
			while (*s)
				fill_buffer(&info->buffer, *s++);
		}
		else
		{
			if (number > 0)
			{
				if (info->specs->flags->plus)
					fill_buffer(&info->buffer, '+');
			}
			else
			{
				s = ft_itoa(-number);
				fill_buffer(&info->buffer, '-');
			}
			if (info->specs->precision > nb_len)
				while (precision-- - nb_len)
					fill_buffer(&info->buffer, '0');
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
