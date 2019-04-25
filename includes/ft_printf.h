/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:37:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/25 20:51:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** УБРАТЬ stdio.h УБРАТЬ stdio.h УБРАТЬ stdio.h УБРАТЬ stdio.h УБРАТЬ stdio.h
** УБРАТЬ stdio.h УБРАТЬ stdio.h УБРАТЬ stdio.h УБРАТЬ stdio.h УБРАТЬ stdio.h
*/
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/include/libft.h"

# define BUFF_SIZE 32
# define LENGTH_H	0x01
# define LENGTH_HH	0x02
# define LENGTH_L	0x04
# define LENGTH_LL	0x08
# define LENGTH_J	0x10
# define LENGTH_Z	0x20
# define LENGTH_T	0x40
# define LENGTH_LLL 0x80

typedef struct		s_data
{
	char			*str;
	int				length;
	unsigned		negative : 1;
	char			*prefix;
}					t_data;

/*
** Structure to store extracted data
*/

typedef struct		s_buffer
{
	int				index;
	int				length;
	char			content[BUFF_SIZE];
}					t_buffer;

/*
** Bit field
** Following group of fields will never exceed a limit. They can be only 0 or 1
** This aproach allow to optimize usage of memory
*/

typedef struct		s_flags
{
	unsigned		space	: 1;
	unsigned		hash	: 1;
	unsigned		plus	: 1;
	unsigned		minus	: 1;
	unsigned		zero	: 1;
	unsigned		point	: 1;
}					t_flags;

/*
** Structure of the syntax for a format fields
*/

typedef struct		s_spec
{
	int				parameter;
	t_flags			*flags;
	int				width;
	int				precision;
	char			length;
}					t_spec;

/*
** Structure of the syntax for a format placeholder
*/

typedef struct		s_info
{
	t_spec			*specs;
	char			type;
	va_list			ap;
	t_buffer		buffer;
}					t_info;

int					ft_printf(const char *format, ...);
void				parsing(const char **format, t_info *info);
t_info				*initialize_info(void);
void				initialize_buffer(t_buffer *buffer);
void				initialize_specifiers(t_spec *specs);
void				initialize_flags(t_flags *flags);
void				set_flag(const char c, t_flags *flags);
int					buffer_full(t_buffer *buffer);
void				print_buffer(t_buffer *buffer);
void				write_char(t_buffer *buffer, char c);
void				write_str(t_buffer *buffer, char *str, int length);
void				apply_specs(t_info *info, t_data *data);
void				put_width(t_info *info, t_data *data);
void				put_width_s(t_info *info, t_data *data);
void				put_precision(t_info *info, t_data *data);
void				put_prefix(t_info *info, t_data *data);
char				*ft_litoa(intmax_t n);
char				*ft_uitoa(uintmax_t n);

/*
** A pointer to a handler function
*/

typedef void		(*t_handler)(const char **format, t_info *info);

void				unknown(const char **format, t_info *info);
void				flag_space(const char **format, t_info *info);
void				flag_hash(const char **format, t_info *info);
void				flag_plus(const char **format, t_info *info);
void				flag_minus(const char **format, t_info *info);
void				flag_zero(const char **format, t_info *info);
void				length_h(const char **format, t_info *info);
void				length_l(const char **format, t_info *info);
void				length_j(const char **format, t_info *info);
void				length_z(const char **format, t_info *info);
void				length_t(const char **format, t_info *info);
void				type_percent(const char **format, t_info *info);
void				type_c(const char **format, t_info *info);
void				type_di(const char **format, t_info *info);
void				type_f(const char **format, t_info *info);
void				type_o(const char **format, t_info *info);
void				type_p(const char **format, t_info *info);
void				type_s(const char **format, t_info *info);
void				type_u(const char **format, t_info *info);
void				type_x(const char **format, t_info *info);
void				asterisk(const char **format, t_info *info);
void				set_precision(const char **format, t_info *info);
void				set_width(const char **format, t_info *info);
void				digit(const char **format, t_info *info);

static t_handler	g_jump_table[] = {
	flag_space, unknown, unknown, flag_hash, unknown, type_percent, unknown,
	unknown, unknown, unknown, asterisk, flag_plus, unknown, flag_minus,
	set_precision, unknown, flag_zero, digit, digit, digit, digit, digit,
	digit, digit, digit, digit, unknown, unknown, unknown, unknown, unknown,
	unknown, unknown, unknown, unknown, unknown, unknown, unknown, unknown,
	unknown, unknown, unknown, unknown, unknown, length_l, unknown, unknown,
	unknown, unknown, unknown, unknown, unknown, unknown, type_u, unknown,
	unknown, type_x, unknown, unknown, unknown, unknown, unknown, unknown,
	unknown, unknown, unknown, unknown, type_c, type_di, unknown, type_f,
	unknown, length_h, type_di, length_j, unknown, length_l, unknown, unknown,
	type_o, type_p, unknown, unknown, type_s, length_t, type_u, unknown,
	unknown, type_x, unknown, length_z, unknown, unknown, unknown, unknown
};

#endif
