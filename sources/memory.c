/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 03:13:21 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/11 03:13:26 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_placeholder		*initialize_placeholder(void)
{
	t_placeholder	*placeholder;

	if (!(placeholder = (t_placeholder *)ft_memalloc(sizeof(t_placeholder))))
		return (NULL);
	if (!(placeholder->specifiers = (t_spec *)ft_memalloc(sizeof(t_spec))))
		return (NULL);
	initialize_specifiers(placeholder->specifiers);
	if (!(placeholder->specifiers->flags = (t_flags *)ft_memalloc(sizeof(t_flags))))
		return (NULL);
	initialize_flags(placeholder->specifiers->flags);
	return (placeholder);
}

/*
** Deallocation of allocated memory for flags, specifiers and type
*/

void				deallocate_placeholder(t_placeholder *placeholder)
{
	free(placeholder->specifiers->flags);
	placeholder->specifiers->flags = NULL;
	free(placeholder->specifiers);
	placeholder->specifiers = NULL;
	free(placeholder);
	placeholder = NULL;
	//ft_memdel(placeholder->specifiers->flags);
	//ft_memdel(placeholder->specifiers);
	//ft_memdel(placeholder);
}
