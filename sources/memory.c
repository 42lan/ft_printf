/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 03:13:21 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/24 13:15:12 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Deallocation of allocated memory for flags, specifiers and type
*/

void				deallocate_placeholder(t_placeholder *placeholder)
{
	free(placeholder->specs->flags);
	placeholder->specs->flags = NULL;
	free(placeholder->specs);
	placeholder->specs = NULL;
	free(placeholder);
	placeholder = NULL;
	//ft_memdel(placeholder->specs->flags);
	//ft_memdel(placeholder->specs);
	//ft_memdel(placeholder);
}
