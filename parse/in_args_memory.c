/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_args_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:42:42 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 19:17:56 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	init_memory_cmd(int *memory)
{
	int	i;

	i = 0;
	while (i < MAX_PIPE)
	{
		memory[i] = 1;
		i++;
	}
}	

void	count_memory_need(int *m_c, t_element *element)
{
	t_element	*p_el;

	p_el = element;
	while (p_el)
	{
		if (p_el->type == 'C' || p_el->type == 'A')
			m_c[p_el->cmd_num] += 1;
		p_el = p_el->next;
	}
}

void	reservate_memory(int *m_c, t_element *element)
{
	t_element	*p_el;

	(void)m_c;
	p_el = element;
	while (p_el)
	{
		if (p_el->type == 'C')
		{
			p_el->arg = (char **)malloc(sizeof(char *) * (m_c[p_el->cmd_num]));
		}
		p_el = p_el->next;
	}
}
