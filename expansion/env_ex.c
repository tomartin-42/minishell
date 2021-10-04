/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_ex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:12:15 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/04 20:16:56 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	not_ex(t_element *p_elem)
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
		if (p_elem->str[n] == '$' && p_elem->str[n] != ' ')
			return (1);
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

void	remove_marks(t_element *p_elem)
{
	int		n;
	int		x;
	char	mark;
	char	*new_str;

	n = 0;
	x = 0;
	mark = '"';
	new_str = malloc(sizeof(char) * ft_strlen(p_elem->str) - 1);
	if (search_marks(p_elem) == 2)
		mark = 39;
	while (p_elem->str[n] != '\0')
	{
		if (p_elem->str[n] == mark)
			n++;
		new_str[x] = p_elem->str[n];
		x++;
		if (p_elem->str[n] != '\0')
			n++;
	}
	p_elem->str = realloc(p_elem->str, ft_strlen(p_elem->str) - 1);
	ft_strlcpy(p_elem->str, new_str, ft_strlen(p_elem->str) + 1);
	free(new_str);
}

void	env_ex(t_element *element)
{
	t_element	*p_elem;
	int			not_expand;

	p_elem = element;
	not_expand = 0;
	while (p_elem)
	{
		if (p_elem->type != 'G')
		{
			if (search_env(p_elem) == 1)
			{
				not_expand = not_ex(p_elem);
				if (not_expand == 0)
					printf("\nExpando->%s\n\n", p_elem->str);
				else if (not_expand == 1)
					printf("\nNO expando->%s\n\n", p_elem->str);
				if (search_marks(p_elem) > 0)
					remove_marks(p_elem);
			}
		}
		p_elem = p_elem->next;
	}
}
