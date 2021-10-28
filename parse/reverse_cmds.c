/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:48:42 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/27 18:48:04 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	cmd_rotate(t_element *elem)
{
	t_element *tmp;
	tmp = elem;
	
	elem = elem->next->next;
	elem->next = tmp;
	elem->next->next = elem->next->next;
	
	//element->next = tmp;
	//element->next = element->next->next->next;//si
	//element->next->next->next = element;//si
	//element = tmp;
	//tmp = element->next->next;//
	//element->next->next->prev = element->prev;//si
	//element->prev = tmp;//si
	printf("HOLA->%s | %s | %s\n", elem->str, elem->next->str, elem->next->next->str);
	//printf("HOLA->%p->%p->%p\n", elem->next, elem->next->next, elem->next->next->next);
}

void	change_order_cmds(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem)
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
	}
}

/*
elem | elem->next | elem->next->next

elem->next->next | elem | elem->next

*/