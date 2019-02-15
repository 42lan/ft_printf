/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:37:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/14 06:02:06 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* -------------------------------------------------------------------------- */
# include <stdio.h> /* ------------------------------------------------------ */
/* -------------------------------------------------------------------------- */
# include <stdarg.h>
# include "../libft/libft.h"

# define BUFF_SIZE 32

/*
** Structure to store extracted data
*/

typedef struct	s_buffer
{
	int			index;
	int			length;
	char		string[BUFF_SIZE];
}				t_buffer;

/*
** Bit field
** Following group of fields will never exceed a limit. They can be only 0 or 1
** This aproach allow to optimize usage of memory
*/

typedef struct	s_flags
{
	unsigned	space	: 1;
	unsigned	hash	: 1;
	unsigned	plus	: 1;
	unsigned	minus	: 1;
	unsigned	zero	: 1;
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

typedef struct	s_placeholder
{
	t_spec		*specs;
	char		type;
}				t_placeholder;

int				ft_printf(const char *format, ...);
t_buffer		initialize_buffer(void);
void			print_buffer(t_buffer *buffer);
int				is_flag(const char c);
int				check_syntax(const char c, t_placeholder *placeholder);
int				is_placeholder(const char **format);
int				is_conversion_type(const char c);

/*int				parsing(va_list arg, const char *restrict str);


void			set_flag(const char c, t_flags *flags);
void			initialize_flags(t_flags *flags);

t_placeholder	*initialize_placeholder(void);
void			initialize_specifiers(t_spec *specs);
void			deallocate_placeholder(t_placeholder *placeholder);

int				check_type(const char c, t_placeholder *placeholder);

void			integer_conversion(const char c, t_placeholder *placeholder);
void			floating_point_conversion(t_placeholder *placeholder);

void			set_space(t_flags *flags);
void			set_hash(t_flags *flags);
void			set_plus(t_flags *flags);
void			set_minus(t_flags *flags);
void			set_zero(t_flags *flags);
void			g_set_flag()
{

}*/

void			print_placeholder(t_placeholder *placeholder);

#endif
