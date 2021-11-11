/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:03:16 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 10:48:25 by dpuente-         ###   ########.fr       */
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
	if (p_command->cmd->arg[1][pos] == '/')
		p_command->cmd->arg[1][pos] = '\0';
}
