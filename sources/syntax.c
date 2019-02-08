/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 22:09:27 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/08 22:09:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		*check_syntax(const char *str)
{
	/*	%[parameter][flags][width][.precision][length]type	*/
	t_spec	*spec;
	
	if (!(spec = (t_spec *)ft_memalloc(sizeof(t_spec))))
		return (NULL);
	if (!(spec->flags = (t_flags *)ft_memalloc(sizeof(t_flags))))
		return (NULL);
	check_flags(str, spec->flags);
}

int			check_flags(const char *str, t_flags *flags)
{
	while (*str)
	{
		if (*str == '-')
			flags->minus = 1;
		else if (*str == '+')
			flags->plus = 1;
		else if (*str == ' ')
			flags->space = 1;
		else if (*str == '0')
			flags->zero = 1;
		else if (*str == '#')
			flags->hash = 1;
		str++;
	}
}