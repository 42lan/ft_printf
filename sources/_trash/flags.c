/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:42:43 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/13 23:45:05 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Checking if given char is one of the flags
*/

int			is_flag_(const char c)
{
	return (c == ' ' || c == '#' || c == '+' || c == '-' || c == '0');
}

/*
** Checking if passed character in argument is one of the flags and
** setting up the corresponding bit to 1
*/

void		set_flag_(const char c, t_flags *flags)
{
	if (c == ' ')
		set_space(flags);
	else if (c == '#')
		set_hash(flags);
	else if (c == '+')
		set_plus(flags);
	else if (c == '-')
		set_minus(flags);
	else if (c == '0')
		set_zero(flags);
}

void		set_space_(t_flags *flags)
{
	flags->space = 1;
}

void		set_hash_(t_flags *flags)
{
	flags->hash = 1;
}

void		set_plus_(t_flags *flags)
{
	flags->plus = 1;
}

void		set_minus_(t_flags *flags)
{
	flags->minus = 1;
}

void		set_zero_(t_flags *flags)
{
	flags->zero = 1;
}
