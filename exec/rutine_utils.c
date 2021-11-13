/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:51:18 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/13 12:59:47 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "build.h"
#include "hered.h"

void	extract_cmd_and_arg(t_command *command)
{
	t_element	*p_elem;

	p_elem = command->multi_cmd[0];
	while (p_elem != command->multi_cmd[1])
	{
		if (p_elem->type == 'C' || p_elem->type == 'B')
		{
			command->cmd = p_elem;
			break ;
		}
		p_elem = p_elem->next;
	}	
}

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

void	execut_cmd_build_np(t_env *env, t_command *command)
{
	redir_files_np(command);
	g_state = build_filt(command, env);
}
