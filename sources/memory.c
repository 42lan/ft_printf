/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 03:13:21 by amalsago          #+#    #+#             */
/*   Updated: 2019/02/11 03:32:07 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
