/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builds_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:48:31 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/12 19:12:58 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	exec_build(char **command, char **env)
{
	printf("ES BUILD->%s, %s", command[0], env[0]);
}

int	is_build(t_element *p_elem)
{
	int	n;

	n = 0;
	if (ft_strcmp(p_elem->str, "echo") == 0 || ft_strcmp(p_elem->str, "cd") == 0)
	{
		printf("\nES BUILD->%s\n\n", p_elem->str);
		p_elem->type = 'B';
		return (1);
	}
	else if (ft_strcmp(p_elem->str, "export") == 0 || ft_strcmp(p_elem->str, "unset") == 0)
	{
		printf("\nES BUILD->%s\n\n", p_elem->str);
		p_elem->type = 'B';
		return (1);
	}
	else if (ft_strcmp(p_elem->str, "env") == 0 || ft_strcmp(p_elem->str, "exit") == 0)
	{
		printf("\nES BUILD->%s\n\n", p_elem->str);
		p_elem->type = 'B';
		return (1);
	}
	return (0);
}

void	main_build_filt(t_element *element)
{
	t_element *p_elem;

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
