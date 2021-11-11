/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:03:16 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 20:51:09 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

//opendir, readdir, closedi
int	check_var(t_env *env, char *env_var)
{
	t_env	*p_env;

	p_env = env;
	while (p_env)
	{
		if (!ft_strcmp(env_var, p_env->var[0]))
		{
			if (p_env->var[0] && p_env->var[1])
				return (0);
		}
		p_env = p_env->next;
	}
	return (1);
}

void	back_path(int times, t_env *env)
{
	int		pos;
	char	*current_path;
	int		number_paths;

	pos = 0;
	number_paths = 0;
	current_path = get_t_env(env, "PWD");
	while (current_path[pos] != '\0')
	{
		if (current_path[pos] == '/')
			number_paths++;
		pos++;
	}
	if (number_paths <= times)
		number_paths = 0;
	else
		number_paths = number_paths - times;
	back_path_edit(env, current_path, number_paths);
}

int	move_back(t_command *command, t_env *env)
{
	int			pos;
	int			dots;

	pos = 0;
	dots = 0;
	while (command->cmd->arg[1][pos] != '\0')
	{
		if (command->cmd->arg[1][pos] != '/')
			dots++;
		pos++;
	}
	if (dots % 2 != 0)
		dots--;
	back_path(dots / 2, env);
	return (0);
}

int	check_consec_dots(char *arg)
{
	int			pos;
	int			count;

	pos = 0;
	count = 0;
	while (arg[pos])
	{
		count++;
		if (arg[pos] != '.')
			count = 0;
		if (count > 2)
			return (1);
		pos++;
	}
	return (0);
}

void	remove_end_trash(t_command *command)
{
	t_command	*p_cmd;
	int			pos;

	p_cmd = command;
	pos = 0;
	while (p_cmd->cmd->arg[1][pos])
		pos++;
	if (p_cmd->cmd->arg[1][pos - 1] == '/')
	{
		pos = 0;
		while (p_cmd->cmd->arg[1][pos])
		{
			if (p_cmd->cmd->arg[1][pos] == '/' && p_cmd->cmd->arg[1][pos + 1]
				&& p_cmd->cmd->arg[1][pos + 1] == '/')
				break ;
			else if (p_cmd->cmd->arg[1][pos] == '/'
				&& p_cmd->cmd->arg[1][pos + 1] == '\0')
				break ;
			pos++;
		}
		if (p_cmd->cmd->arg[1][pos] == '/')
		{
			p_cmd->cmd->arg[1][pos] = '\0';
		}
	}
}
