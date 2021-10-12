/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:02:31 by davyd11           #+#    #+#             */
/*   Updated: 2021/10/12 18:47:08 by davyd11          ###   ########.fr       */
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

	n = 1;
	p_elem_arg = p_elem;
	p_elem->arg[0] = ft_strdup(p_elem->str);//anade cmd al arg[0] para ejecuccion
	while (n <= size_arg)//para quitar cmd from arg quitar =
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
	int			size_arg;

	p_elem = element;
	while (p_elem)
	{
		size_arg = 0;
		if (p_elem->type == 'C' && p_elem->next != NULL)
		{
			size_arg = count_args(p_elem);
			if (size_arg > 0)
			{
				p_elem->arg = malloc(sizeof(char *) * (size_arg + 2));
				arg_input(p_elem, size_arg);
			}
			else
				p_elem->arg = NULL;
		}
		else if (p_elem->type == 'I' || p_elem->type == 'H'
			|| p_elem->type == 'T' || p_elem->type == 'O')
		{
			size_arg = count_args(p_elem);
			if (size_arg > 0)
			{
				p_elem->arg = malloc(sizeof(char *) * (size_arg + 2));
				arg_input(p_elem, size_arg);
			}
			else
			{
				p_elem->arg = malloc(sizeof(char *) * 1);
				p_elem->arg[0] = NULL;
			}
		}
		else
		{
			p_elem->arg = malloc(sizeof(char *) * 1);
			p_elem->arg[0] = NULL;
		}
		///printf("%s", p_elem->arg[0]);
		p_elem = p_elem->next;
	}
}
