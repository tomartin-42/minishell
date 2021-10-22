/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:18:27 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/22 13:18:21 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

//opendir, readdir, closedi
int	check_oldpwd(t_env *env)
{
	t_env	*p_env;

	p_env = env;
	while (p_env)
	{
		if (!ft_strcmp("OLDPWD", p_env->var[0]))
		{
			if (p_env->var[0] && p_env->var[1])
				return (0);
		}
		p_env = p_env->next;
	}
	return (1);
}

char	*join_paths(t_env *env, char *new_path)
{
	char	*f_path;
	char	*s_path;

	f_path = ft_strjoin(get_t_env(env, "PWD"), "/");
	s_path = ft_strjoin(f_path, new_path);
	return (s_path);
}

char	*back_path(int times, t_env *env)
{
	char	*new_path;
	int		size_pwd;

	size_pwd = ft_strlen() get_t_env(env, "PWD")
}

static int	move_back(t_command *command, t_env *env)
{
	t_env		*p_env;
	t_command	*p_command;
	int			pos;
	int			dots;

	pos = 0;
	dots = 0;
	p_env = env;
	p_command = command;
	while (command->cmd->arg[1][pos] != '\0')
	{
		if (command->cmd->arg[1][pos] != '/')
			dots++;
		pos++;
	}
	if (dots % 2 != 0)
		dots--;
	printf("NUMERO->[%d]\n", dots);
	back_path(dots / 2, env);
	return (0);
}

int	ft_cd(t_command *command, t_env *env)
{
	int				pos;
	char			*home_path;
	bool			o_pwd;

	o_pwd = false;
	pos = 0;
	home_path = get_t_env(env, "HOME");
	while (command->cmd->arg[pos])
		pos++;
	if (!check_oldpwd(env))//compureba que existe OLDPWD
		o_pwd = true;
	if (pos > 1)
	{
		if (o_pwd == true)
			change_single_env_var(env, "OLDPWD", get_t_env(env, "PWD"));
		if (!ft_strcmp(command->cmd->arg[1], "..")
			|| (command->cmd->arg[1][0] == '.' && command->cmd->arg[1][1] == '.'))
		{
			move_back(command, env);
		}
		else if (command->cmd->arg[1][0] != '/')
			change_single_env_var(env, "PWD", join_paths(env, command->cmd->arg[1]));
		else if (command->cmd->arg[1][0] != '/')
			change_single_env_var(env, "PWD", command->cmd->arg[1]);
		chdir(command->cmd->arg[1]);
	}
	else if (pos == 1)
	{
		if (o_pwd == true)
			change_single_env_var(env, "OLDPWD", get_t_env(env, "PWD"));
		change_single_env_var(env, "PWD", home_path);
		chdir(home_path);
	}
	if (command->multi_cmd[1] == NULL) 
		return (0);
	else
		exit (0);
}
