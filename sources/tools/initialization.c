/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:22:50 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/15 14:01:05 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_buffer(t_buffer *buffer)
{
	buffer->index = 0;
	buffer->length = 0;
	ft_bzero(buffer->content, BUFF_SIZE);
}

void	initialize_info(t_info *info)
{
	info->type = 0;
	initialize_specifiers(info);
	initialize_buffer(&info->buffer);
}

void	initialize_specifiers(t_info *info)
{
	info->width = 0;
	info->precision = 0;
	info->length = 0;
	initialize_flags(info);
}

void	initialize_flags(t_info *info)
{
	info->space = 0;
	info->hash = 0;
	info->plus = 0;
	info->minus = 0;
	info->zero = 0;
	info->point = 0;
}
