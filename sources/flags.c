/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 05:00:15 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/27 13:51:44 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int		is_flag(const char c)
{
	return (c == ' ' || c == '#' || c == '+' || c == '-' || c == '0');
}
*/
/*
** Checking if passed character in argument is one of the flags and
** setting up the corresponding bit to 1
*/
/*
void		set_flag(const char c, t_flags *flags)	// Может быть второй аргумент будет сразу флагом?
{
	if (c == ' ')
		flags->space = 1;
	else if (c == '#')
		flags->hash = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == '-')
		flags->minus = 1;
	else if (c == '0')
		flags->zero = 1;
}
*/

void			flag_space(const char **format, t_placeholder *placeholder)
{
	(*format)++;
	placeholder->specs->flags->space = 1;
}

void			flag_hash(const char **format, t_placeholder *placeholder)
{
	(*format)++;
	placeholder->specs->flags->hash = 1;
}

void			flag_plus(const char **format, t_placeholder *placeholder)
{
	(*format)++;
	placeholder->specs->flags->plus = 1;
}

void			flag_minus(const char **format, t_placeholder *placeholder)
{
	(*format)++;
	placeholder->specs->flags->minus = 1;
}

void			flag_zero(const char **format, t_placeholder *placeholder)
{
	(*format)++;
	placeholder->specs->flags->zero = 1;
}

void			unknown(const char **format, t_placeholder *placeholder)
{
	(void)format;
	(void)placeholder;
	ft_putendl("Sorry, I don't know it...");
}
