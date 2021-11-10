/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builds_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:48:31 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/19 13:38:35 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	is_build(t_element *p_elem)
{
	p_elem->str	= super_tolower(p_elem->str);
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
	else if (ft_strcmp(p_elem->str, "env") == 0
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
