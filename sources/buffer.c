/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 04:48:44 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/16 05:39:20 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buffer		initialize_buffer(void)
{
	t_buffer	buffer;

	buffer.index = 0;
	buffer.length = 0;
	ft_bzero(buffer.string, BUFF_SIZE);	// Ca allege? -> buffer.string[BUFF_SIZE] = '\0';
	return (buffer);
}

void		print_buffer(t_buffer *buffer)
{
	ft_putstr(buffer->string);
	buffer->index = 0;
}
