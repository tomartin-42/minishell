/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:57:10 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 14:06:21 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

//Asig Trunc or output file to the nodes
void	get_trunk_file(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem)
	{
		if (p_elem->str[0] == '>' && p_elem->type == '?')
		{
			change_truck(p_elem);
			ft_lst_del_all_x(element);
			if (p_elem->next != NULL)
				p_elem->next->type = 'F';
		}
		p_elem = p_elem->next;
	}
}

//Asig Hered or input file to the nodes
void	get_hered_file(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem)
	{
		if (p_elem->str[0] == '<' && p_elem->type == '?')
		{	
			change_heredoc(p_elem);
			ft_lst_del_all_x(element);
			if (p_elem->next != NULL)
				p_elem->next->type = 'F';
		}
		p_elem = p_elem->next;
	}
}

//Asit cmd and arg in the nodes
void	get_cmd_and_args(t_element *element)
{
	t_element	*p_elem;
	bool		cmd_state;

	cmd_state = false;
	p_elem = element;
	while (p_elem)
	{
		if (p_elem->type == 'P')
			cmd_state = false;
		if ((p_elem->type == '?' || p_elem->type == 'S')
			&& cmd_state == false)
		{
			p_elem->type = 'C';
			cmd_state = true;
		}
		else if ((p_elem->type == '?' || p_elem->type == 'S')
			&& cmd_state == true)
			p_elem->type = 'A';
		p_elem = p_elem->next;
	}
}

void	clean_spaces_in_str(t_element *element)
{
	t_element	*p_elem;
	char		*aux;

	p_elem = element;
	while (p_elem)
	{
		aux = ft_strtrim(p_elem->str, " \t");
		free (p_elem->str);
		p_elem->str = ft_strdup(aux);
		free(aux);
		p_elem = p_elem->next;
	}
}

t_element	*add_do_nothing_node(void)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	new->str = ft_strdup("do_nothing");
	new->arg = malloc(sizeof(char *) * 2);
	new->arg[0] = ft_strdup("do_nothing");
	new->arg[1] = NULL;
	new->type = 'C';
	new->cmd_num = 1;
	new->next = NULL;
	return (new);
}
