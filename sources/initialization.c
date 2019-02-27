/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:22:50 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/27 13:51:47 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void			initialization(t_buffer *buffer, t_placeholder **placeholder)
{
	*buffer = initialize_buffer();
	*placeholder = initialize_placeholder();
}
*/
void			initialize_buffer(t_buffer *buffer)
{
	buffer->index = 0;
	buffer->length = 0;
	ft_bzero(buffer->string, BUFF_SIZE);	// Ca allege? -> buffer.string[BUFF_SIZE] = '\0';
}

/*
** Allocation of memory for placeholder and it fields
*/

t_placeholder		*initialize_placeholder(void)
{
	t_placeholder	*placeholder;

	if (!(placeholder = (t_placeholder *)ft_memalloc(sizeof(t_placeholder))))
		return (NULL);
	if (!(placeholder->specs = (t_spec *)ft_memalloc(sizeof(t_spec))))
		return (NULL);
	initialize_specifiers(placeholder->specs);
	if (!(placeholder->specs->flags = (t_flags *)ft_memalloc(sizeof(t_flags))))
		return (NULL);
	initialize_flags(placeholder->specs->flags);
	return (placeholder);
}

/*
** Initialization of type pointer to t_placeholder structure
*/

void	initialize_specifiers(t_spec *specifiers)
{
	specifiers->parameter = 0;
	specifiers->width = 0;
	specifiers->precision = 0;
	specifiers->length = 0;
}

/*
** Setting up all fields of t_flags structure to 0
*/

void	initialize_flags(t_flags *flags)
{
	flags->space = 0;
	flags->hash = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
}
