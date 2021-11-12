/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:31:56 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 20:40:37 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static int	more_one_arg(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->cmd->arg[i] != NULL)
		i++;
	return (i);
}

static int	exit_else_no_pipe(t_command *command, t_env *env)
{
	int	i;

	i = 1;
	g_state = ft_atoi(command->cmd->arg[i]);
	free_element(command->p_elem);
	free_env_list(env);
	ft_putstr_fd("exit\n", 1);
	exit(g_state);
}

static int	exit_else(t_command *command, t_env *env)
{
	int	i;

	i = 1;
	if (command->cmd->arg[1] && command->multi_cmd[0]->type == 'P')
	{
		g_state = ft_atoi(command->cmd->arg[i]);
		free_element(command->p_elem);
		exit(g_state);
	}
	else if (command->cmd->arg[1] && command->multi_cmd[0]->type != 'P')
		exit_else_no_pipe(command, env);
	else if (!command->cmd->arg[1] && command->multi_cmd[0]->type == 'P')
	{
		free_element(command->p_elem);
		exit(0);
	}
	else
	{
		free_element(command->p_elem);
		free_env_list(env);
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
	return (0);
}

int	ft_exit(t_command *command, t_env *env)
{
	(void)env;
	if (more_one_arg(command) >= 3)
	{
		ft_putstr_fd("SFH: exit: too many arguments\n", 2);
		g_state = 2;
		return (g_state);
	}
	if (command->cmd->arg[1] && is_number(command->cmd->arg[1]))
	{
		ft_putstr_fd("SFH: exit: ", 2);
		ft_putstr_fd(command->cmd->arg[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		g_state = 2;
		exit (g_state);
	}
	else
		exit(exit_else(command, env));
}
