/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:14:25 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/01 13:20:38 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	count_args()
{
	
}

void	add_args(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem)
	{
		if (p_elem->type == 'C')
			
		p_elem = p_elem->next;
	}
}
