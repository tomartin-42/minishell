/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_build_filt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:26:07 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/12 12:12:37 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "build.h"

int	cmd_exec_build_filt(t_command *command, t_env *env)
{
	int	error_num;

	error_num = 0;
	if (!ft_strcmp(command->cmd->arg[0], "echo"))
		error_num = ft_echo(command->cmd->arg);
	else if (!ft_strcmp(command->cmd->arg[0], "env"))
		error_num = ft_env(env);
	else if (!ft_strcmp(command->cmd->arg[0], "pwd"))
		error_num = ft_pwd(env);
	else if (!ft_strcmp(command->cmd->arg[0], "export"))
		ft_export(env, command->cmd->arg);
	else if (!ft_strcmp(command->cmd->arg[0], "cd"))
		error_num = ft_cd(command, env);
	else if (!ft_strcmp(command->cmd->arg[0], "unset"))
		error_num = ft_unset(command, env);
	else if (!ft_strcmp(command->cmd->arg[0], "exit"))
		ft_exit(command, env);
	else if (!ft_strcmp(command->cmd->arg[0], "do_nothing"))
		error_num = ft_do_nothing(g_state);
	return (error_num);
}
