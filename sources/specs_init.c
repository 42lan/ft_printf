/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 03:28:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/11 03:33:55 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Initialization of type pointer to t_placeholder structure
*/

void				initialize_specifiers(t_spec *specifiers)
{
	specifiers->parameter = 0;
	specifiers->width = 0;
	specifiers->precision = 6;
	specifiers->length = NULL;
}

/*
** Setting up all fields of t_flags structure to 0
*/

void		initialize_flags(t_flags *flags)
{
	flags->space = 0;
	flags->hash = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
}
