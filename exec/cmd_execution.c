/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:43:43 by davyd11           #+#    #+#             */
/*   Updated: 2021/10/24 16:38:13 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "build.h"

int	build_filt(t_command *command, t_env *env) 
{
	int	error_num;
	
	error_num = 0;
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
	else if (!ft_strcmp(command->cmd->arg[0], "unset"))
		error_num = ft_unset(command, env);
	return (error_num);
}

bool	check_pipes_or_cmd(t_element *element)
{
	t_element	*aux;

	aux = element;
	while (aux)
	{
		if (aux->type == 'P' || aux->type == 'C')
			return (true);
		aux = aux->next;
	}
	return (false);
}

bool	check_pipes_in_line(t_element *element)
{
	t_element	*aux;

	aux = element;
	while (aux)
	{
		if (aux->type == 'P')
			return (true);
		aux = aux->next;
	}
	return (false);
}


void	cmd_execution(t_element *element, t_command *command, t_env *env)
{
	bool	pipe;

	pipe = false;

/*	printf("cmd %s\n", command->cmd->str);
	printf("arg1 %s\n", command->cmd->arg[0]);
	printf("arg2 %s\n", command->cmd->arg[1]);
	printf("type %c\n", command->cmd->type);
*/
	pipe = check_pipes_in_line(element);
	if (command->cmd->type == 'B' && pipe == true)
		execut_cmd_build(env, command);
	else if (command->cmd->type == 'B' && pipe == false)
		execut_cmd_build_np(env, command);
	else if (command->cmd->type == 'C')
		execut_cmd(command->env, command);
}
