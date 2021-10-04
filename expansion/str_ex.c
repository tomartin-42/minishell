/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:37:34 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/04 20:15:04 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	str_ex(t_element *element)
{
	t_element	*p_elem;
	char		mark;
	int			n;
	int			ret_search;
	int			not_expand;

	n = 0;
	mark = '"';
	not_expand = 0;
	p_elem = element;
	while (p_elem)
	{
		ret_search = search_marks(p_elem);
		if (p_elem->type != 'G' && ret_search > 0)
		{
			if (ret_search == 1)
				mark = '"';
			else if (ret_search == 2)
				mark = 39;
			while (p_elem->str[n] != mark)
				n++;
			n++;
			while (p_elem->str[n] != mark)
			{
				if (p_elem->str[n] == ' ')
					not_expand = 1;
				n++;
			}
			if (not_expand == 0)
				printf("\nExpando->%s\n\n", p_elem->str);
			else if (not_expand == 1)
				printf("\nNO expando->%s\n\n", p_elem->str);
		}
		p_elem = p_elem->next;
	}
}
