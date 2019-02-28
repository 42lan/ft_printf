/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:37:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/27 16:58:13 by amalsago         ###   ########.fr       */
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


/* A pointer to a handler function */
typedef void	(*Handler)(const char **format, t_placeholder *placeholder);

void			unknown(const char **format, t_placeholder *placeholder);
void			flag_space(const char **format, t_placeholder *placeholder);
void			flag_hash(const char **format, t_placeholder *placeholder);
void			flag_plus(const char **format, t_placeholder *placeholder);
void			flag_minus(const char **format, t_placeholder *placeholder);
void			flag_zero(const char **format, t_placeholder *placeholder);
void			width(const char **format, t_placeholder *placeholder);
void			precision(const char **format, t_placeholder *placeholder);
void			type_f(const char **format, t_placeholder *placeholder);


static Handler jump_table[] = {
	flag_space, unknown,  unknown, flag_hash, unknown, unknown, unknown, unknown,
	unknown, unknown,  unknown, flag_plus, unknown, flag_minus, precision, unknown,
	flag_zero, width,  width, width, width, width, width, width,
	width, width,  unknown, unknown, unknown, unknown, unknown, unknown,
	unknown, unknown,  unknown, unknown, unknown, unknown, unknown, unknown,
	unknown, unknown,  unknown, unknown, unknown, unknown, unknown, unknown,
	unknown, unknown,  unknown, unknown, unknown, unknown, unknown, unknown,
	unknown, unknown,  unknown, unknown, unknown, unknown, unknown, unknown,
	unknown, unknown,  unknown, unknown, unknown, unknown, type_f, unknown,
	unknown, unknown,  unknown, unknown, unknown, unknown, unknown, unknown,
	unknown, unknown,  unknown, unknown, unknown, unknown, unknown, unknown,
	unknown, unknown,  unknown, unknown, unknown, unknown, unknown, unknown
/*
      32 sp    33  !    34  "    35  #    36  $    37  %    38  &    39  '
      40  (    41  )    42  *    43  +    44  ,    45  -    46  .    47  /
      48  0    49  1    50  2    51  3    52  4    53  5    54  6    55  7
      56  8    57  9    58  :    59  ;    60  <    61  =    62  >    63  ?
      64  @    65  A    66  B    67  C    68  D    69  E    70  F    71  G
      72  H    73  I    74  J    75  K    76  L    77  M    78  N    79  O
      80  P    81  Q    82  R    83  S    84  T    85  U    86  V    87  W
      88  X    89  Y    90  Z    91  [    92  \    93  ]    94  ^    95  _
      96  `    97  a    98  b    99  c   100  d   101  e   102  f   103  g
     104  h   105  i   106  j   107  k   108  l   109  m   110  n   111  o
     112  p   113  q   114  r   115  s   116  t   117  u   118  v   119  w
     120  x   121  y   122  z   123  {   124  |   125  }   126  ~   127 del
*/
};

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
