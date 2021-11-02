/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:03:16 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/02 11:07:18 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

int	check_pwd(t_env	*env)
{
	t_env	*p_env;

	p_env = env;
	while (p_env)
	{
		if (!ft_strcmp("PWD", p_env->var[0]))
		{
			if (p_env->var[0] && p_env->var[1])
				return (0);
		}
		p_env = p_env->next;
	}
	return (1);
}

void	remove_end_trash(t_command *command)
{
	t_command	*p_command;
	int			pos;

	p_command = command;
	pos = 0;
	while (p_command->cmd->arg[1][pos])
		pos++;
	pos--;
	if (p_command->cmd->arg[1][pos] == '/' && (!p_command->cmd->arg[1][pos + 1]
		|| p_command->cmd->arg[1][pos + 1] == '/'))
		p_command->cmd->arg[1][pos] = '\0';
}
