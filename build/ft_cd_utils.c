/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:03:16 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 11:41:35 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

void	remove_end_trash(t_command *command)
{
	t_command	*p_cmd;
	int			pos;

	p_cmd = command;
	pos = 0;
	while (p_cmd->cmd->arg[1][pos])
		pos++;
	if (p_cmd->cmd->arg[1][pos - 1] == '/')
	{
		pos = 0;
		while (p_cmd->cmd->arg[1][pos])
		{
			if (p_cmd->cmd->arg[1][pos] == '/' && p_cmd->cmd->arg[1][pos + 1]
				&& p_cmd->cmd->arg[1][pos + 1] == '/')
				break ;
			else if (p_cmd->cmd->arg[1][pos] == '/'
				&& p_cmd->cmd->arg[1][pos + 1] == '\0')
				break ;
			pos++;
		}
		if (p_cmd->cmd->arg[1][pos] == '/')
		{
			p_cmd->cmd->arg[1][pos] = '\0';
		}
	}
}
