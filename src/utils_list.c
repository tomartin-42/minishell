/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2021/09/23 21:08:34 by tommy             #+#    #+#             */
/*   Updated: 2021/10/09 16:43:55 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_element	*ft_lstlast(t_element *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_element **lst, t_element *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!lst)
		return ;
	new->prev = (ft_lstlast(*lst));
	(ft_lstlast(*lst))->next = new;
}

static void	reorder_list(t_element *p_elem)
{
	p_elem->next->prev = p_elem->prev;
	p_elem->prev->next = p_elem->next;
}

//Clear all X types of the list.
void	ft_lst_del_all_x(t_element *element)
{
	t_element	*p_elem;
	t_element	*p_aux;

	p_elem = element;
	p_aux = NULL;
	while (p_elem)
	{
		if (p_elem->type == 'X')
		{
			p_aux = p_elem;
			if (p_elem->next == NULL)
				p_elem->prev->next = NULL;
			else
				reorder_list(p_elem);
		}
		p_elem = p_elem->next;
		if (p_aux != NULL)
		{
			free(p_aux->str);
			free(p_aux);
			p_aux = NULL;
		}
	}
}

void	print_list(t_element *element)
{
	while (element)
	{
		printf("[%s]\n", element->str);
		printf("type -> [%c]\n", element->type);
		if (element->type == 'H')
			printf("arg[0] -> [%s]\n", element->arg[0]);
	//	printf("arg[1] -> [%s]\n", element->arg[1]);
		printf("==================================\n");
		element = element->next;
	}
}
