/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builds_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:48:31 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/12 11:45:06 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	is_build_more(t_element *p_elem)
{
	if (ft_strcmp(p_elem->str, "env") == 0
		|| ft_strcmp(p_elem->str, "exit") == 0)
	{
		p_elem->type = 'B';
		return (1);
	}
	else if (ft_strcmp(p_elem->str, "pwd") == 0
		|| ft_strcmp(p_elem->str, "do_nothing") == 0)
	{
		p_elem->type = 'B';
		return (1);
	}
	return (0);
}

int	is_build(t_element *p_elem)
{
	p_elem->str = super_tolower(p_elem->str);
	if (ft_strcmp(p_elem->str, "echo") == 0
		|| ft_strcmp(p_elem->str, "cd") == 0)
	{
		p_elem->type = 'B';
		return (1);
	}
	else if (ft_strcmp(p_elem->str, "export") == 0
		|| ft_strcmp(p_elem->str, "unset") == 0)
	{
		p_elem->type = 'B';
		return (1);
	}
	return (is_build_more(p_elem));
}

void	main_build_filt(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem)
	{
		if (p_elem->type == 'C')
			is_build(p_elem);
		else if (p_elem->type == 'A' || p_elem->type == 'E'
			|| p_elem->type == 'F')
		{
			p_elem->type = 'X';
		}
		p_elem = p_elem->next;
	}
}
