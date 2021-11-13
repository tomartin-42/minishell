/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procesing_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:07:23 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/13 16:43:38 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	add_do_nothing(t_element *p_elem)
{
	t_element	*new;

	new = add_do_nothing_node();
	new->next = p_elem;
	new->prev = p_elem->prev;
	p_elem->prev->next = new;
	p_elem->prev = new;
}

void	check_if_add_do_nothing(t_element *element)
{
	t_element	*p_elem;
	bool		cmd;
	t_element	*new;

	p_elem = element;
	cmd = false;
	while (p_elem)
	{
		if (p_elem->type == 'C')
			cmd = true;
		if (p_elem->type == 'P')
		{
			if (cmd == false)
				add_do_nothing(p_elem);
			else
				cmd = false;
		}
		p_elem = p_elem->next;
	}
	if (!p_elem && cmd == false)
	{
		new = add_do_nothing_node();
		ft_lstadd_back(&element, new);
	}
}

/* remove form first line str_ex(element); */
void	pre_procesing(t_element *element)
{
	clean_spaces_in_str(element);
	get_string(element);
	get_pipes_and_cmd_num(element);
	get_trunk_file(element);
	get_hered_file(element);
	get_cmd_and_args(element);
	add_args(element);
	check_if_add_do_nothing(element);
}
