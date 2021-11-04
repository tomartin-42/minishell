/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:03:16 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/04 17:46:14 by dpuente-         ###   ########.fr       */
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
	t_command	*p_command;
	int			pos;

	p_command = command;
	pos = 0;
	while (p_command->cmd->arg[1][pos] && p_command->cmd->arg[1][pos] != '/')
	{
		pos++;
	}
	if (p_command->cmd->arg[1][pos] == '/' && (!p_command->cmd->arg[1][pos + 1]
		|| p_command->cmd->arg[1][pos + 1] == '/'))
		p_command->cmd->arg[1][pos] = '\0';
}
