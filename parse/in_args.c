/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:02:31 by davyd11           #+#    #+#             */
/*   Updated: 2021/10/11 22:54:24 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	file_input(t_element *p_elem)
{
	if (p_elem != NULL && p_elem->next != NULL
		&& p_elem->next->type == 'F')
	{
		p_elem->arg[0] = p_elem->next->str;
		return (0);
	}
	p_elem->arg[1] = NULL;
	return (-1);
}

void	arg_input(t_element *p_elem, int size_arg)
{
	int			n;
	t_element	*p_elem_arg;

	n = 0;
	p_elem_arg = p_elem;
	while (n < size_arg)
	{
		if (p_elem_arg != NULL)
			p_elem_arg = p_elem_arg->next;
		p_elem->arg[n] = ft_strdup(p_elem_arg->str);
		n++;
	}
	p_elem->arg[n] = NULL;
}

int	count_args(t_element *p_elem)
{
	int	n;

	n = 0;
	if (p_elem)
		p_elem = p_elem->next;
	while (p_elem && (p_elem->type == 'A' || p_elem->type == 'E'
			|| p_elem->type == '$' || p_elem->type == 'F'))
	{
		p_elem = p_elem->next;
		n++;
	}
	return (n);
}

void	add_args(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem->next)
	{
		if (p_elem->type == 'I' || p_elem->type == 'O' || p_elem->type == 'T'
			|| p_elem->type == 'H')
		{
			p_elem->arg = malloc(sizeof(char *) * 2);
			p_elem->arg[0] = ft_strdup(p_elem->next->str);
			p_elem->arg[1] = NULL;
			p_elem->next->type = 'X';
			ft_lst_del_all_x(element);
			p_elem = element;
		}
		p_elem = p_elem->next;
	}
}
