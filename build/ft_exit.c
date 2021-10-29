/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:31:56 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/29 18:26:57 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

int	exit_numeric_arg(t_command *command, int pos)
{
	while (command->cmd->arg[1][pos])
	{
		if (command->cmd->arg[1][pos] < '0'
			|| command->cmd->arg[1][pos] > '9')
		{
			printf("exit\n🔥ShellFromHell🔥: exit: ");
			printf("%s: numeric argument required\n", command->cmd->arg[1]);
			return (0);
		}
		pos++;
	}
	return (1);
}

int	exit_max_arg(t_command *command, int ret_error)
{
	if (ft_strlen(command->cmd->arg[1]) <= 3)
	{
		ret_error = ft_atoi(command->cmd->arg[1]);
		if (ret_error > 246)
			ret_error = 246;
	}
	else
		ret_error = 246;
	return (ret_error);
}

int	ft_exit(t_command *command, t_env *env)
{
	int	ret_error;
	int	pos;

	ret_error = 0;
	pos = 0;
	(void)env;
	if (command->cmd->arg[1])
	{
		if (!exit_numeric_arg(command, pos))
			return (0);
		if (command->cmd->arg[1])
			ret_error = exit_max_arg(command, ret_error);
		if (command->cmd->arg[1] && command->cmd->arg[2] != NULL)
			printf("exit\n🔥ShellFromHell🔥: exit: too many arguments\n");
		else
			ret_error = 246;
	}
	if (command->cmd->arg[1] && command->cmd->arg[2])
		printf("exit\n🔥ShellFromHell🔥: exit: too many arguments\n");
	else
	{
		printf("exit\n");
		exit (ret_error);
	}
	return (0);
}
