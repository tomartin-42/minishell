/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:12:24 by tommy             #+#    #+#             */
/*   Updated: 2021/11/11 14:01:08 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	clear_space_in_list(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem)
	{
		if (ft_strlen(p_elem->str) == 1 && p_elem->str[0] == ' ')
			p_elem->type = 'X';
		p_elem = p_elem->next;
	}
	p_elem = element;
	while (p_elem)
	{
		if (ft_strlen(p_elem->str) == 0)
			p_elem->type = 'X';
		p_elem = p_elem->next;
	}
	ft_lst_del_all_x(element);
}

void	rutine_parse(char *str, t_element *element, t_env *m_env)
{
	main_parse(str, element);
	clear_space_in_list(element);
	expand_all(element, m_env, 1);
	clean_element(element);
	pre_procesing(element);
	ft_lst_del_all_x(element);
	expand_all(element, m_env, 2);
}

void	main_parse(char *str, t_element *element)
{
	t_mark	mk;

	ini_var(&mk);
	while (str[mk.i])
	{
		check_open_mark(str, &mk.mark_s, &mk.mark_d, &mk.i);
		if (ft_strchr("|<> ", str[mk.i]) && mk.mark_d == false
			&& mk.mark_s == false)
		{	
			if (ft_strchr("|<> ", str[mk.i]))
			{
				mk.i--;
				copy_to_word(str, &mk.i, &mk.j, element);
				mk.i++;
			}
			copy_to_word(str, &mk.i, &mk.j, element);
		}
		if (str[mk.i] != '\0')
			mk.i++;
		check_close_mark(str, &mk.mark_s, &mk.mark_d, &mk.i);
		if (str[mk.i] == '\0')
		{
			copy_to_word(str, &mk.i, &mk.j, element);
		}
	}
}
