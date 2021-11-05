/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:07:52 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/05 11:55:16 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void init_memory_cmd(int *memory)
{
	int	i;

	i = 0;
	while (i < MAX_PIPE)
	{
		memory[i] = 1;
		i++;
	}
}	

static void	count_memory_need(int *memory_cmd, t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem)
	{
		if (p_elem->type == 'C' || p_elem->type == 'A')
			memory_cmd[p_elem->cmd_num] += 1;
		p_elem = p_elem->next;
	}
}

static void	reservate_memory(int *memory_cmd, t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem)
	{
		if (p_elem->type == 'C')
			p_elem->arg = malloc((sizeof(char *) 
				* memory_cmd[p_elem->cmd_num]) + 1);
		p_elem = p_elem->next;
	}
}

static void	search_cmd_to_add(t_element *element, t_element *p_elem, int i)
{
	t_element	*aux_elem;

	aux_elem = element;
	while(aux_elem)
	{
		if (aux_elem->type == 'C' && (aux_elem->cmd_num == p_elem->cmd_num))
		{
			aux_elem->arg[i] = ft_strdup(p_elem->str);
			break ;
		}
		aux_elem = aux_elem->next;
	}
}

static void	copy_arg_int_cmd(t_element *element)
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
		else if (p_elem->type == 'P')
		{
			p_elem->arg[num_arg] = ft_strdup("\0");
			num_arg = 0;
		}
		p_elem = p_elem->next;
	}
}

void dell_all_arg(t_element *element)
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

void add_args(t_element *element)
{
	int	memory_cmd[MAX_PIPE];

	init_memory_cmd(memory_cmd);
	count_memory_need(memory_cmd, element);
	reservate_memory(memory_cmd, element);
	copy_arg_int_cmd(element);
	dell_all_arg(element);
	print_list(element);
}
