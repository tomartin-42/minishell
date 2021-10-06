/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:37:34 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/05 16:44:02 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	remove_marks(t_element *p_elem)
{
	t_element	*copy_point;
	int			n;
	int			x;
	char		mark;
	int			string_len;

	copy_point = p_elem;
	n = 0;
	x = 0;
	mark = '"';
	string_len = ft_strlen(p_elem->str);
	if (search_marks(p_elem) == 2)
		mark = 39;
	while (p_elem->str[n] != '\0' && string_len > 2)
	{
		if (copy_point->str[n] == mark)
			n++;
		p_elem->str[x] = copy_point->str[n];
		x++;
		if (copy_point->str[n] != '\0')
			n++;
	}
	if (string_len == 2)
	{
		p_elem->str[x] = '\0';
		p_elem->str[x + 1] = '\0';
	}
}

void	str_ex(t_element *element)
{
	t_element	*p_elem;
	char		mark;
	int			n;
	int			ret_search;
	int			env_no;
	int			not_expand;

	p_elem = element;
	while (p_elem)
	{
		n = 0;
		not_expand = 0;
		mark = '"';
		ret_search = search_marks(p_elem);
		env_no = search_env(p_elem);
		if (p_elem->type != 'G' && ret_search > 0 && env_no != 1)
		{
			if (ret_search == 1)
				mark = '"';
			else if (ret_search == 2)
				mark = 39;
			while (p_elem->str[n] != mark)
				n++;
			n++;
			while (p_elem->str[n] != mark || p_elem->str[n] == '\0')
			{
				if (p_elem->str[n] == ' ')
					not_expand = 1;
				n++;
			}
			if (not_expand == 1 && p_elem->type != 'C')
				not_expand = 0;
			if (not_expand == 0)
			{
				printf("\nExpando->%s", p_elem->str);
				remove_marks(p_elem);
				printf("\nExpandido->%s\n\n", p_elem->str);
			}
			else if (not_expand == 1)
			{
				printf("\nNO expando, pero lo hago->%s\n\n", p_elem->str);
				remove_marks(p_elem);
			}
		}
		p_elem = p_elem->next;
	}
}