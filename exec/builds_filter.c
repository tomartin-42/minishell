/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builds_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:48:31 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/13 10:07:24 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	exec_build(char **command, char **env)
{
	printf("ES BUILD->%s, %s", command[0], env[0]);
}

int	is_build(t_element *p_elem)
{
	if (ft_strcmp(p_elem->str, "echo") == 0
		|| ft_strcmp(p_elem->str, "cd") == 0)
	{
		printf("\nES BUILD->%s\n\n", p_elem->str);
		p_elem->type = 'B';
		return (1);
	}
	else if (ft_strcmp(p_elem->str, "export") == 0
		|| ft_strcmp(p_elem->str, "unset") == 0)
	{
		printf("\nES BUILD->%s\n\n", p_elem->str);
		p_elem->type = 'B';
		return (1);
	}
	else if (ft_strcmp(p_elem->str, "env") == 0
		|| ft_strcmp(p_elem->str, "exit") == 0)
	{
		printf("\nES BUILD->%s\n\n", p_elem->str);
		p_elem->type = 'B';
		return (1);
	}
	return (0);
}

void	main_build_filt(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem)
	{
		if (p_elem->type == 'C')
			is_build(p_elem);
		else if (p_elem->type == 'A' || p_elem->type == 'E'
			|| p_elem->type == 'F')
		{
			p_elem->type = 'X';
		}
		p_elem = p_elem->next;
	}
}
