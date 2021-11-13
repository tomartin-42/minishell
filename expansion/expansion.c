/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:34:47 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/13 14:22:30 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	insert_list_str(t_element *p_elem, char *ret_expan)
{
	int	char_len;
	int	n;

	n = 0;
	char_len = ft_strlen(ret_expan);
	if (search_env(p_elem) == 1)
	{
		free(p_elem->str);
		p_elem->str = malloc(sizeof(char) * (char_len + 1));
		while (n < char_len)
		{
			p_elem->str[n] = ret_expan[n];
			n++;
		}
		p_elem->str[n] = '\0';
		free(ret_expan);
	}
}

void	expand_all(t_element *element, t_env *m_env, int option)
{
	if (option == 1)
		env_ex(element, m_env);
	else if (option == 2)
		str_ex(element);
	else
	{
		env_ex(element, m_env);
		str_ex(element);
	}
}
