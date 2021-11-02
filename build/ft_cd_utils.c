/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:03:16 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/01 12:15:17 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

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
