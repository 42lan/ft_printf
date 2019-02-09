/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:37:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/08 00:40:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* -------------------------------------------------------------------------- */
# include <stdio.h> /* ------------------------------------------------------ */
/* -------------------------------------------------------------------------- */
# include <stdarg.h>
# include "../libft/libft.h"

# define BUFF_SIZE 5

/*
** Bit field
** Following group of fields will never exceed a limit. They can be only 0 or 1
** This aproach allow to optimize usage of memory 
*/

typedef struct	s_flags
{
	unsigned	minus	: 1;
	unsigned	plus	: 1;
	unsigned	space	: 1;
	unsigned	zero	: 1;
	unsigned	hash	: 1;
}				t_flags;

/*
** Structure of the syntax for a format fields
*/

typedef struct	s_spec
{
	int			parameter;
	t_flags		*flags;
	int			width;
	int			precision;
	char		*length;
}				t_spec;

/*
** Structure of the syntax for a format placeholder
*/

typedef struct	s_type
{
	t_spec		*specifiers;
	char		type;
}				t_type;

int				ft_printf(const char *restrict format, ...);
int				parsing(va_list arg, const char *restrict str);

int				check_syntax(const char c, t_type *type);

int				check_flags(const char c, t_flags *flags);
int				isflag(const char c);
void			reset_flags(t_flags *flags);

int				check_type(const char *str, t_type *type);

int				conversion_type(const char c);

#endif
