/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:18:27 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/29 18:14:39 by dpuente-         ###   ########.fr       */
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

void	cd_pos_mas(bool o_pwd, t_command *command, t_env *env)
{
	if (o_pwd == true)
		chg_env_var(env, "OLDPWD", get_t_env(env, "PWD"));
	if (!ft_strcmp(command->cmd->arg[1], "..")
		|| (command->cmd->arg[1][0] == '.' && command->cmd->arg[1][1] == '.'))
	{
		move_back(command, env);
	}
	else
	{
		if (chdir(command->cmd->arg[1]) == 0
			&& ft_strcmp(command->cmd->arg[1], "."))
		{
			if (command->cmd->arg[1][0] != '/')
				chg_env_var(env, "PWD", join_paths(env, command->cmd->arg[1]));
			else if (command->cmd->arg[1][0] == '/')
				chg_env_var(env, "PWD", command->cmd->arg[1]);
		}
	}
}

void	cd_pos_igual(bool o_pwd, t_env *env)
{
	char	*home_path;

	home_path = get_t_env(env, "HOME");
	if (chdir(home_path) == 0)
	{
		if (o_pwd == true)
			chg_env_var(env, "OLDPWD", get_t_env(env, "PWD"));
		chg_env_var(env, "PWD", home_path);
		chdir(home_path);
	}
}

int	ft_cd(t_command *command, t_env *env)
{
	int				pos;
	bool			o_pwd;

	o_pwd = false;
	pos = 0;
	while (command->cmd->arg[pos])
		pos++;
	if (!check_oldpwd(env))
		o_pwd = true;
	if (command->cmd->arg[1])
		remove_end_trash(command);
	if (pos > 1)
		cd_pos_mas(o_pwd, command, env);
	else if (pos == 1)
		cd_pos_igual(o_pwd, env);
	if (command->multi_cmd[1] == NULL)
		return (0);
	else
		exit (0);
}
