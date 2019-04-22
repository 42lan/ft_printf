/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:22:50 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/22 16:52:05 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		initialize_buffer(t_buffer *buffer)
{
	buffer->index = 0;
	buffer->length = 0;
	ft_bzero(buffer->content, BUFF_SIZE);
}

/*
** Allocation of memory for info and it fields
*/

t_info		*initialize_info(void)
{
	t_info	*info;

	if (!(info = (t_info *)ft_memalloc(sizeof(t_info))))
		return (NULL);
	if (!(info->specs = (t_spec *)ft_memalloc(sizeof(t_spec))))
		return (NULL);
	if (!(info->specs->flags = (t_flags *)ft_memalloc(sizeof(t_flags))))
		return (NULL);
	info->type = 0;
	initialize_buffer(&info->buffer);
	return (info);
}

/*
** Initialization of type pointer to t_info structure
*/

void		initialize_specifiers(t_spec *specifiers)
{
	specifiers->parameter = 0;
	initialize_flags(specifiers->flags);
	specifiers->width = 0;
	specifiers->precision = 0;
	specifiers->length = 0;
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
	flags->point = 0;
}
