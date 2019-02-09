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

int			check_syntax(const char c, t_type *type)
{
	/*	%[parameter][flags][width][.precision][length]type	*/
	
	//check_parameter();
	check_flags(c, type->specifiers->flags);
	//check_width();
	//check_precision();
	//check_length();
	//check_type(str, type);
	return (1);
}

void		reset_flags(t_flags *flags)
{
	flags->minus	= 0;
	flags->plus		= 0;
	flags->space	= 0;
	flags->zero		= 0;
	flags->hash		= 0;
}

int			isflag(const char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#');
}

int			check_flags(const char c, t_flags *flags)
{
	//	printf("%-#10x \n", number)		Correct
	//	printf("%-*10x \n", number)		Incorrect
	//	"+f \n"							Correct TEST
	while (isflag(c))
	{
		if (c == '-')
		{
			flags->minus = 1;
			return (1);		
		}
		else if (c == '+')
		{
			flags->plus = 1;
			return (1);		
		}
		else if (c == ' ')
		{
			flags->space = 1;
			return (1);		
		}
		else if (c == '0')
		{
			flags->zero = 1;
			return (1);		
		}
		else if (c == '#')
		{
			flags->hash = 1;
			return (1);		
		}
		else
		{
			reset_flags(flags);
			return (0);
		}
	}
	return (0);
}

int			check_type(const char *str, t_type *type)
{
	(void)str; (void)type;
	return (1);
}