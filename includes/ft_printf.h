/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:37:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/04 16:48:46 by amalsago         ###   ########.fr       */
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
# define BIT_8 0x80
# define BIT_7 0x40
# define BIT_6 0x20
# define BIT_5 0x10		// L
# define BIT_4 0x08		// ll
# define BIT_3 0x04		// l
# define BIT_2 0x02		// hh
# define BIT_1 0x01		// h

/*
** Structure to store extracted data
*/

typedef struct	s_buffer
{
	int			index;
	int			length;
	char		content[BUFF_SIZE];
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
	char		length;	//битовая маска вместо char* h hh l ll L
}				t_spec;

/*
** Structure of the syntax for a format placeholder
*/

typedef struct	s_info
{
	t_spec		*specs;
	char		type; // не нужно? НУЖНО Я ЖЕ ИСПОЛЬЗУЮ ЭТО ЧТОБЫ ВЫЙТИ ИЗ ЦИКЛА в parsing.c
	va_list		ap;
	t_buffer	buffer;
}				t_info;

int				ft_printf(const char *format, ...);
void			parsing(const char **format, t_info *info);

void			initialize_buffer(t_buffer *buffer);
t_info			*initialize_info(void);
void			initialize_specifiers(t_spec *specs);
void			initialize_flags(t_flags *flags);

int				is_flag(const char c);
void			set_flag(const char c, t_flags *flags);

void			print_info(t_info *info);
void			print_buffer(t_buffer *buffer);


/* A pointer to a handler function */
typedef void	(*Handler)(const char **format, t_info *info);

void			unknown(const char **format, t_info *info);
void			flag_space(const char **format, t_info *info);
void			flag_hash(const char **format, t_info *info);
void			flag_plus(const char **format, t_info *info);
void			flag_minus(const char **format, t_info *info);
void			flag_zero(const char **format, t_info *info);
void			get_int(const char **format, t_info *info);
void			length_h(const char **format, t_info *info);
void			length_l(const char **format, t_info *info);
void			length_L(const char **format, t_info *info);
void			type_percent(const char **format, t_info *info);
void			type_c(const char **format, t_info *info);
void			type_d(const char **format, t_info *info);
void			type_f(const char **format, t_info *info);
void			type_i(const char **format, t_info *info);
void			type_o(const char **format, t_info *info);
void			type_p(const char **format, t_info *info);
void			type_s(const char **format, t_info *info);
void			type_u(const char **format, t_info *info);
void			type_x(const char **format, t_info *info);
void			type_X(const char **format, t_info *info);
/* ************************************************************************** */

static Handler	jump_table[] = {
	flag_space,	unknown,	unknown, flag_hash,	unknown,	type_percent,	unknown,	unknown,
	unknown,	unknown,	unknown, flag_plus,	unknown,	flag_minus,		get_int,	unknown,
	flag_zero,	get_int,	get_int, get_int,	get_int,	get_int,		get_int,	get_int,
	get_int,	get_int,	unknown, unknown, 	unknown,	unknown, 		unknown,	unknown,
	unknown,	unknown,	unknown, unknown, 	unknown,	unknown, 		unknown,	unknown,
	unknown,	unknown,	unknown, unknown,	length_L,	unknown,		unknown,	unknown,
	unknown,	unknown,	unknown, unknown,	unknown,	unknown,		unknown,	unknown,
	type_X,		unknown,	unknown, unknown,	unknown,	unknown,		unknown,	unknown,
	unknown,	unknown,	unknown, type_c,	type_d,		unknown,		type_f,		unknown,
	length_h,	type_i,		unknown, unknown,	length_l,	unknown,		unknown,	type_o,
	type_p,		unknown,	unknown, type_s,	unknown,	type_u,			unknown,	unknown,
	type_x,		unknown,	unknown, unknown,	unknown,	unknown,		unknown
/* ************************************************************************** */
/* 	csp diouxX f 
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

#endif
