/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:20:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/04 19:13:06 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			unknown(const char **format, t_info *info)
{
	info->type = **format;
}

void			type_percent(const char **format, t_info *info)
{
	ft_putendl("type %");
	info->type = **format;
}

void			type_c(const char **format, t_info *info)
{
	int			c;

	info->type = **format;
	c = va_arg(info->ap, int);
}

void			type_d(const char **format, t_info *info)
{
	int			c;

	info->type = **format;
	c = va_arg(info->ap, int);
	// ft_strcat(info->buffer.content, ft_itoa(c));
	// ft_putendl(info->buffer.content);
}

void			type_f(const char **format, t_info *info)
{
	info->type = **format;
}

void			type_i(const char **format, t_info *info)
{
	int			c;

	info->type = **format;
	c = va_arg(info->ap, int);
}

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
	char		*s;

	info->type = **format;
	s = va_arg(info->ap, char *);
	ft_putendl(s);
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
