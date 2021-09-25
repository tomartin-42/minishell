/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommy <tommy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:08:34 by tommy             #+#    #+#             */
/*   Updated: 2021/09/25 18:11:37 by tomartin         ###   ########.fr       */
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

void	print_list(t_element *element)
{
	while (element->next)
	{
		printf("[%s]\n", element->str);
		printf("type -> [%c]\n", element->type);
		printf("==================================\n");
		element = element->next;
	}
		printf("[%s]\n", element->str);
		printf("type -> [%c]\n", element->type);
		printf("==================================\n");
}
