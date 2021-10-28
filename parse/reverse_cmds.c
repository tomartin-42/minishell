/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:48:42 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/28 10:56:11 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	cmd_rotate(t_element *element)
{
	t_element *tmp;
	tmp = element;	
	//elemenet->type = 'C';
	//elemenet->prev->type = 'O';
	//elemenet = elemenet->prev;
	
//	printf("HOLA->%s\n", elemenet->arg);
}

void	change_order_cmds(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	/*while (p_elem)
	{
		if (p_elem->type == 'C')
		{
			if (p_elem->str[0] == '<' || p_elem->str[0] == '>')
			{
				if (p_elem->next && p_elem->next->type == 'A'
					&& p_elem->next->next)
					cmd_rotate(p_elem);
			}
		}
		p_elem = p_elem->next;
	}*/
}

/*
elem | elem->next | elem->next->next

elem->next->next | elem | elem->next

*/