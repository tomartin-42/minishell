/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:07:52 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/13 16:43:05 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	search_cmd_to_add(t_element *element, t_element *p_elem, int i)
{
	t_element	*aux_elem;

	aux_elem = element;
	while (aux_elem)
	{
		if (aux_elem->type == 'C' && (aux_elem->cmd_num == p_elem->cmd_num))
		{
			aux_elem->arg[i] = ft_strdup(p_elem->str);
			break ;
		}
		aux_elem = aux_elem->next;
	}
}

void	search_cmd_to_add_end(t_element *element, t_element *p_elem, int i)
{
	t_element	*aux_elem;

	aux_elem = element;
	while (aux_elem)
	{
		if (aux_elem->type == 'C' && (aux_elem->cmd_num == p_elem->cmd_num))
		{
			aux_elem->arg[i] = NULL;
			break ;
		}
		aux_elem = aux_elem->next;
	}
}

void	add_args(t_element *element)
{
	int	memory_cmd[MAX_PIPE];

	str_ex(element);
	init_memory_cmd(memory_cmd);
	count_memory_need(memory_cmd, element);
	reservate_memory(memory_cmd, element);
	copy_arg_int_cmd(element);
	dell_all_arg(element);
	copy_arg_redir(element);
}
