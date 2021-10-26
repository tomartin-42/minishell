/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:18:27 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/25 12:09:08 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

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

char	*join_p(t_env *env, char *new_path)
{
	char	*f_path;
	char	*s_path;

	f_path = ft_strjoin(get_t_env(env, "PWD"), "/");
	s_path = ft_strjoin(f_path, new_path);
	return (s_path);
}

int	ft_cd(t_command *cmd, t_env *env)
{
	int				pos;
	char			*home_path;
	bool			o_pwd;

	o_pwd = false;
	pos = 0;
	home_path = get_t_env(env, "HOME");
	while (cmd->cmd->arg[pos])
		pos++;
	if (!check_oldpwd(env))
		o_pwd = true;
	remove_end_trash(cmd);
	if (pos > 1)
	{
		if (o_pwd == true)
			chg_env_var(env, "OLDPWD", get_t_env(env, "PWD"));
		if (!ft_strcmp(cmd->cmd->arg[1], "..")
			|| (cmd->cmd->arg[1][0] == '.' && cmd->cmd->arg[1][1] == '.'))
		{
			move_back(cmd, env);
		}
		else
		{
			if (chdir(cmd->cmd->arg[1]) == 0
				&& ft_strcmp(cmd->cmd->arg[1], "."))
			{
				if (cmd->cmd->arg[1][0] != '/')
					chg_env_var(env, "PWD", join_p(env, cmd->cmd->arg[1]));
				else if (cmd->cmd->arg[1][0] == '/')
					chg_env_var(env, "PWD", cmd->cmd->arg[1]);
			}
		}
	}
	else if (pos == 1)
	{
		if (chdir(home_path) == 0)
		{
			if (o_pwd == true)
				chg_env_var(env, "OLDPWD", get_t_env(env, "PWD"));
			chg_env_var(env, "PWD", home_path);
			chdir(home_path);
		}
	}
	if (cmd->multi_cmd[1] == NULL)
		return (0);
	else
		exit (0);
}
