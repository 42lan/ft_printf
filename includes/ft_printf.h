/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:37:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/26 15:08:24 by amalsago         ###   ########.fr       */
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
	char		length;	//битовая маска вместо char*
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
void			parsing(const char **format, va_list *ap, t_buffer *buffer);

void			initialize_buffer(t_buffer *buffer);
t_placeholder	*initialize_placeholder(void);
void			initialize_specifiers(t_spec *specs);
void			initialize_flags(t_flags *flags);


int				is_flag(const char c);
void			set_flag(const char c, t_flags *flags);

void			print_placeholder(t_placeholder *placeholder);

/*
void			print_buffer(t_buffer *buffer);
int				check_syntax(const char *str, t_placeholder *placeholder);
int				is_placeholder(const char *format);//, t_placeholder *placeholder);
int				is_conversion_type(const char c);

void			initialization(t_buffer *buffer, t_placeholder **placeholder);

int				check_type(const char c, t_placeholder *placeholder);

int				is_width(const char *str);
int				is_precision(const char *str);
int				is_length(const char **str);

void			set_width(int width, t_spec *specs);
void			set_precision(int precision, t_spec *specs);
void			set_length(int l, t_spec *specs);

void			integer_conversion(const char c, t_placeholder *placeholder);
void			floating_point_conversion(t_placeholder *placeholder);



void			deallocate_placeholder(t_placeholder *placeholder);
*/


#endif
