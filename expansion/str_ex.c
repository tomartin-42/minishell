/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:37:34 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/01 12:29:32 by davyd11          ###   ########.fr       */
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
	//printf("[%s]\n", p_elem->str);
	while (p_elem->str[n] != '\0' && string_len > 2)
	{
		//printf("SIU[%c]\n", mark);
		if (copy_point->str[n] == mark)
			n++;
		p_elem->str[x] = copy_point->str[n];
		x++;
		if (copy_point->str[n] != '\0')
			n++;
	}
	//printf("[%s]\n", p_elem->str);
	if (string_len == 2)
	{
		p_elem->str[x] = '\0';
		p_elem->str[x + 1] = '\0';
	}
}

void	str_expansion(int ret_search, char mark, int not_expand, t_element	*p_elem, int n)
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
	if (not_expand == 0 || not_expand == 1)
	{
		remove_marks(p_elem);
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
			//str_expansion(ret_search, mark, not_expand, p_elem, n);
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
			if (not_expand == 0 || not_expand == 1)
			{
				remove_marks(p_elem);
				//printf("[%s]\n", p_elem->str);
			}
		}
		p_elem = p_elem->next;
	}
}
