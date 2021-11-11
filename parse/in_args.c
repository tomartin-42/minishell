/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:07:52 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/11 10:35:34 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static	void init_memory_cmd(int *memory)
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

	(void)memory_cmd;
	p_elem = element;
	while (p_elem)
	{
		if (p_elem->type == 'C')
			p_elem->arg = (char **)malloc(sizeof(char *)
				* (memory_cmd[p_elem->cmd_num]));
		p_elem = p_elem->next;
	}
}

static void	search_cmd_to_add(t_element *element, t_element *p_elem, int i)
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

static void	search_cmd_to_add_end(t_element *element, t_element *p_elem, int i)
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
		if (p_elem->type == 'P' || p_elem->next == NULL)
		{
			search_cmd_to_add_end(element, p_elem, num_arg);
			num_arg = 0;
		}
		p_elem = p_elem->next;
	}
}

static void dell_all_arg(t_element *element)
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

static void	copy_arg_redir(t_element *element)
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

void add_args(t_element *element)
{
	int	memory_cmd[MAX_PIPE];

	//print_list(element);///////////////////expand strings
	str_ex(element);
	init_memory_cmd(memory_cmd);
	count_memory_need(memory_cmd, element);
	reservate_memory(memory_cmd, element);
	copy_arg_int_cmd(element);
	dell_all_arg(element);
	copy_arg_redir(element);
}
