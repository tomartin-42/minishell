/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:18:57 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/29 16:19:29 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	close_forks(t_element *element)
{
	int			i;
	t_element	*p_elem;
	int			error;

	p_elem = element;
	i = 1;
	while (p_elem)
	{
		if (p_elem->type == 'P')
			i++;
		p_elem = p_elem->next;
	}
	while (i != 0)
	{
		waitpid(-1, &error, 0);
		g_state = WEXITSTATUS(error);
		i--;
	}
}
