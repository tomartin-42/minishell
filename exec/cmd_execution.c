/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:43:43 by davyd11           #+#    #+#             */
/*   Updated: 2021/10/25 10:57:15 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "build.h"

char	*cmd_exp(char *old_exp)
{
	char	*exp_cmd;
	int		pos;

	pos = 0;
	exp_cmd = malloc(sizeof(char) * (ft_strlen(old_exp) + 1));
	while (pos < (int)ft_strlen(old_exp))
	{
		exp_cmd[pos] = old_exp[pos];
		pos++;
	}
	exp_cmd[pos] = '\0';
	return (exp_cmd);
}

int	build_filt(t_command *command, t_env *env) 
{
	int		error_num;
	char	*exp_cmd;

	error_num = 0;
	if (ft_strcmp(command->cmd->arg[0], "export"))
	{
		exp_cmd = cmd_exp(command->cmd->arg[0]);
		command->cmd->arg[0] = super_tolower(command->cmd->arg[0]);
		if (!ft_strcmp(command->cmd->arg[0], "export"))//si entra es que habia un cmd export
		{
			printf("🔥ShellFromHell🔥: %s: command not found\n", exp_cmd);
			return (error_num);
		}
	}
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
	else if (!ft_strcmp(command->cmd->arg[0], "exit"))
		ft_exit(command, env);// cambiar para devolve error value
	//exit (error_num);
	return (error_num);
}

static bool	check_pipes_in_line(t_element *element)
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
	pipe = check_pipes_in_line(element);
	if (command->cmd->type == 'B' && pipe == true)
		execut_cmd_build(env, command);
	else if (command->cmd->type == 'B' && pipe == false)
		execut_cmd_build_np(env, command);
	else if (command->cmd->type == 'C')
		execut_cmd(command->cmd->arg, command->env, command);
}
