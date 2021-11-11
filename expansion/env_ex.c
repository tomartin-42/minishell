/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_ex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:12:15 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 19:55:24 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	dont_ex(t_element *p_elem)
{
	int	n;
	int	d_com;

	d_com = 0;
	n = 0;
	while (p_elem->str[n] != '\0')
	{
		if (p_elem->str[n] == 39 && d_com == 0)
			return (1);
		else if (p_elem->str[n] == '"' && d_com == 0)
			return (0);
		n++;
	}
	return (0);
}

int	search_env(t_element *p_elem)
{
	int	n;

	n = 0;
	while (p_elem->str[n] != '\0')
	{
		if (p_elem->str[n] == '$')
		{
			if (p_elem->str[n + 1] == ' ')
				return (-1);
			return (1);
		}	
		n++;
	}
	return (0);
}

int	search_marks(t_element *p_elem)
{
	int	n;

	n = 0;
	while (p_elem->str[n] != '\0')
	{
		if (p_elem->str[n] == '"')
			return (1);
		else if (p_elem->str[n] == 39)
			return (2);
		n++;
	}
	return (0);
}

char	*remove_dollar(char *string)
{
	int		n;
	int		x;
	char	*env_str;

	x = 0;
	env_str = malloc(sizeof(char) * ft_strlen(string));
	if (string[0] == '$')
	{
		n = 1;
		while (n < (int)ft_strlen(string))
		{
			env_str[x] = string[n];
			n++;
			x++;
		}
		env_str[x] = '\0';
	}
	return (env_str);
}

void	env_ex(t_element *element, t_env *m_env)
{
	t_element	*p_elem;
	int			not_expand;
	char		*ret_expan;

	p_elem = element;
	not_expand = 0;
	while (p_elem)
	{
		ret_expan = p_elem->str;
		if (search_env(p_elem) == 1)
		{
			not_expand = dont_ex(p_elem);
			if (not_expand == 0)
			{
				ret_expan = ft_expand(m_env, p_elem->str);
				insert_list_str(p_elem, ret_expan);
				dollar_mark(p_elem);
			}
			if (search_marks(p_elem) > 0)
				remove_marks(p_elem);
		}
		p_elem = p_elem->next;
	}
}
