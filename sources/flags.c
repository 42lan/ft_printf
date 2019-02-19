/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 05:00:15 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/18 08:08:51 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(const char c)
{
	return (c == ' ' || c == '#' || c == '+' || c == '-' || c == '0');
}

/*
** Checking if passed character in argument is one of the flags and
** setting up the corresponding bit to 1
*/

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
