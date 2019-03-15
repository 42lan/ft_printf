/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:40:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/15 10:42:40 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        width_handler(t_info *info, int number, int nb_len)
{
    int		nb_spaces;

	if (info->specs->precision > nb_len)
	{
		if (number > 0)
			nb_spaces = info->specs->width - info->specs->precision;
		else
			nb_spaces = info->specs->width - info->specs->precision - 1;
	}
	else
		nb_spaces = info->specs->width - nb_len;
	if (number > 0)
		if (info->specs->flags->plus)
			nb_spaces--;
	while (nb_spaces-- > 0)
	{
		if (buffer_full(&info->buffer) == 0)
			fill_buffer(&info->buffer, ' ');
		else
		{
			print_buffer(&info->buffer);
			nb_spaces++;
		}
	}
}
