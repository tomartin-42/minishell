/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:43:43 by davyd11           #+#    #+#             */
/*   Updated: 2021/10/20 11:22:13 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "build.h"

int	build_filt(t_command *command, t_env *env) 
{
	int	error_num;
	
	error_num = 0;
	//Funcion para hacer que comando sea minusculas
	command->cmd->arg[0] = super_tolower(command->cmd->arg[0]);
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
	//exit (error_num);
	return (0);
}

void	cmd_execution(t_command *command, t_env *env)
{
	if (command->cmd->type == 'B')
		execut_cmd_build(command->cmd->arg, env, command);
	else if (command->cmd->type == 'C')
		execut_cmd(command->cmd->arg, command->env, command);
}
