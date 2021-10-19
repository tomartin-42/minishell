/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:43:43 by davyd11           #+#    #+#             */
/*   Updated: 2021/10/19 13:35:04 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "build.h"

void	build_filt(t_command *command) 
{
	//printf("Cmd-> %s", command->cmd->arg[0]);
	command->cmd->arg[0] = super_tolower(command->cmd->arg[0]);
	if (!ft_strcmp(command->cmd->arg[0], "echo"))
		ft_echo(command->cmd->arg);
	else if (!ft_strcmp(command->cmd->arg[0], "env"))
		ft_env(command->env);
	else if (!ft_strcmp(command->cmd->arg[0], "pwd"))
		ft_pwd(command->env);
	else if (!ft_strcmp(command->cmd->arg[0], "export"))
		printf("export √\n");
		//ft_export(command->env, command->cmd->arg);//problemas con env, de t_env tiene que ser char **env
	else if (!ft_strcmp(command->cmd->arg[0], "cd"))
		ft_cd(command);
		//printf("cd √\n");
	
}

void	cmd_execution(t_command *command)
{
	if (command->cmd->type == 'B')
		build_filt(command);
	else if (command->cmd->type == 'C')
		execut_cmd(command->cmd->arg, command->env, command);
}
