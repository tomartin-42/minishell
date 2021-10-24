/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:31:56 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/24 21:13:06 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

int	ft_exit(t_command *command, t_env *env)
{
	int ret_error;
	int	pos;
	
	ret_error = 0;
	pos = 0;
	if (env)
	;
	while (command->cmd->arg[1][pos])
	{
		if (command->cmd->arg[1][pos] < '0'
			|| command->cmd->arg[1][pos] > '9')
		{
			printf("exit\n🔥ShellFromHell🔥: exit: %s: numeric argument required\n", command->cmd->arg[1]);
			return (0);
		}
		pos++;
	}
	if (command->cmd->arg[1])
	{
		if (ft_strlen(command->cmd->arg[1]) <= 3)
		{
			ret_error = ft_atoi(command->cmd->arg[1]);
			if (ret_error > 246)
				ret_error = 246;
		}
		else
			ret_error = 246;
	}
	if (command->cmd->arg[2])
		printf("exit\n🔥ShellFromHell🔥: exit: too many arguments\n");
	else
	{
		printf("exit\n");
		exit (ret_error);	
	}
	return (0);
}
