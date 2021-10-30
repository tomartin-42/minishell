/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:34:47 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/30 16:43:00 by tomartin         ###   ########.fr       */
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
