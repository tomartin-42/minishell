/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:31:56 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/31 17:22:00 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

/*int	ft_exit(t_command *command, t_env *env)
{
	int ret_error;
	int	pos;
	
	ret_error = 0;
	pos = 0;
	(void)env;
	if (command->cmd->arg[1])
	{
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
		if (command->cmd->arg[1] && command->cmd->arg[2] != NULL)
			printf("exit\n🔥ShellFromHell🔥: exit: too many arguments\n");
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
}*/
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

int	ft_exit (t_command *command, t_env *env)
{
	int	i;

	i = 1;
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
	{
		if (command->cmd->arg[1] && command->multi_cmd[0]->type == 'P')
		{
			g_state = ft_atoi(command->cmd->arg[i]); 
			free_element(command->p_elem);
			exit(g_state);
		}
		else if (command->cmd->arg[1] && command->multi_cmd[0]->type != 'P')
		{
			g_state = ft_atoi(command->cmd->arg[i]); 
			free_element(command->p_elem);
			free_env_list(env); 
			ft_putstr_fd("exit\n", 1);
			exit(g_state);
		}
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
	}
}

