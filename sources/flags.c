/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 05:00:15 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/17 07:49:48 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Checking if passed character in argument is one of the flags and
** setting up the corresponding bit to 1
*/

void		set_flag(const char c, t_flags *flags)
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

void		set_space(t_flags *flags)
{
	flags->space = 1;
}

void		set_hash(t_flags *flags)
{
	flags->hash = 1;
}

void		set_plus(t_flags *flags)
{
	flags->plus = 1;
}

void		set_minus(t_flags *flags)
{
	flags->minus = 1;
}

void		set_zero(t_flags *flags)
{
	flags->zero = 1;
}


/*
** Initialization of type pointer to t_placeholder structure
*/

void	initialize_specifiers(t_spec *specifiers)
{
	specifiers->parameter = 0;
	specifiers->width = 0;
	specifiers->precision = 6;
	specifiers->length = NULL;
}

/*
** Setting up all fields of t_flags structure to 0
*/

void	initialize_flags(t_flags *flags)
{
	flags->space = 0;
	flags->hash = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
}
