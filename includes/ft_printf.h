/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 23:37:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/08 00:04:30 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ########################################################################## */
# include <stdio.h> /* ###################################################### */
/* ########################################################################## */
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_spec
{
	char		*flags;
	int			width;
	char		*precision;
	int			length;
}				t_spec;

typedef struct	s_type
{
	char		type;
	t_spec		*specifiers;
}				t_type;

int				ft_printf(const char *restrict format, ...);
int				parsing(va_list arg, const char *restrict str);

#endif
