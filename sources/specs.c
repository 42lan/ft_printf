/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:40:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/13 21:24:58 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        specs_handle(t_info *info, int number, unsigned nb_digits)
{
    int		nb_spaces;

	nb_spaces = info->specs->width - nb_digits;
	// printf(">%d - %d = %d<\n", info->specs->width, nb_digits, info->specs->width - nb_digits);
	if (number > 0 && info->specs->flags->plus)
		nb_spaces--;
	while (nb_spaces--)
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
