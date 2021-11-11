/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_dell_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:46:11 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 18:51:15 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	copy_arg_int_cmd(t_element *element)
{
	t_element	*p_elem;
	int			num_arg;

	num_arg = 0;
	p_elem = element;
	while (p_elem)
	{
		if (p_elem->type == 'C')
		{
			p_elem->arg[num_arg] = ft_strdup(p_elem->str);
			num_arg++;
		}
		else if (p_elem->type == 'A')
		{
			search_cmd_to_add(element, p_elem, num_arg);
			num_arg++;
		}
		if (p_elem->type == 'P' || p_elem->next == NULL)
		{
			search_cmd_to_add_end(element, p_elem, num_arg);
			num_arg = 0;
		}
		p_elem = p_elem->next;
	}
}

void	dell_all_arg(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem)
	{
		if (p_elem->type == 'A')
			p_elem->type = 'X';
		p_elem = p_elem->next;
	}
	ft_lst_del_all_x(element);
}

void	copy_arg_redir(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem)
	{
		if (p_elem->type == 'I' || p_elem->type == 'O'
			|| p_elem->type == 'T' || p_elem->type == 'H')
		{
			p_elem->arg = malloc(sizeof(char *) * 2);
			p_elem->arg[0] = ft_strdup(p_elem->str);
			p_elem->arg[1] = ft_strdup(p_elem->next->str);
			p_elem->hd_expand = p_elem->next->hd_expand;
		}
		p_elem = p_elem->next;
	}
}
