/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:03:16 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 19:34:13 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

int	check_consec_dots(char *arg)
{
	int			pos;
	int			count;

	pos = 0;
	count = 0;
	while (arg[pos])
	{
		count++;
		if (arg[pos] != '.')
			count = 0;
		if (count > 2)
			return (1);
		pos++;
	}
	return (0);
}

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
