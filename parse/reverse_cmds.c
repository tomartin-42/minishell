/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:48:42 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/26 17:48:39 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	cmd_rotate(t_element *element)
{
	t_element *tmp;
	tmp = element->next->next;
	//element->next = tmp;
	element->next->next = element->next->next->next;//si
	element->next->next->next = element;//si
	element = tmp;
	//tmp = element->next->next;//
	//element->next->next->prev = element->next;//si
	//element->prev = tmp;//si
	printf("HOLA->%s->%s->%s\n", element->str, element->next->str, element->next->next->str);
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
				if (p_elem->next && p_elem->next->type == 'A')
					cmd_rotate(p_elem);
			}
		}
		p_elem = p_elem->next;
	}
}
