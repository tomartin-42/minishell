/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:37:34 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 20:04:57 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	remove_marks(t_element *p_elem)
{
	char		mark;
	int			string_len;

	mark = '"';
	string_len = ft_strlen(p_elem->str);
	if (search_marks(p_elem) == 2)
		mark = 39;
	remove_marks_loop(p_elem, string_len, mark);
}

static void	str_ex_if(t_element *p_elem, char mark, int n, int ret_search)
{
	int			not_expand;

	not_expand = 0;
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

	p_elem = element;
	while (p_elem)
	{
		n = 0;
		mark = '"';
		ret_search = search_marks(p_elem);
		env_no = search_env(p_elem);
		if (p_elem->type != 'G' && ret_search > 0 && env_no != 1)
		{
			str_ex_if(p_elem, mark, n, ret_search);
		}
		p_elem = p_elem->next;
	}
}
