/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:02:31 by davyd11           #+#    #+#             */
/*   Updated: 2021/10/08 12:48:31 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
