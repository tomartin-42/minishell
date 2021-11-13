/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:43:43 by davyd11           #+#    #+#             */
/*   Updated: 2021/11/13 12:43:17 by tomartin         ###   ########.fr       */
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
	exp_cmd = NULL;
	if (ft_strcmp(command->cmd->arg[0], "export"))
	{
		exp_cmd = cmd_exp(command->cmd->arg[0]);
		command->cmd->arg[0] = super_tolower(command->cmd->arg[0]);
		if (!ft_strcmp(command->cmd->arg[0], "export"))
		{
			printf("🔥ShellFromHell🔥: %s: command not found\n", exp_cmd);
			return (error_num);
		}
	}
	error_num = cmd_exec_build_filt(command, env);
	free (exp_cmd);
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
	pipe = check_pipes_in_line(element);
	if (command->cmd->type == 'B' && pipe == true)
		execut_cmd_build(env, command);
	else if (command->cmd->type == 'B' && pipe == false)
	{
		execut_cmd_build_np(env, command);
	}
	else if (command->cmd->type == 'C')
		execut_cmd(command->env, command);
}
