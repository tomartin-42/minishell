/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:53:45 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 21:18:09 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

void	cd_pos_more_than_one(t_command *cmmd, t_env *env, bool o_pwd)
{
	remove_end_trash(cmmd);
	if (o_pwd == true)
		ch_env_var(env, "OLDPWD", get_t_env(env, "PWD"));
	if (!ft_strcmp(cmmd->cmd->arg[1], "..")
		|| (cmmd->cmd->arg[1][0] == '.' && cmmd->cmd->arg[1][1] == '.'))
	{
		if (check_consec_dots(cmmd->cmd->arg[1]))
		{
			printf("🔥🔥:> cd: %s:", cmmd->cmd->arg[1]);
			printf(" No such file or directory\n");
		}
		else
			move_back(cmmd, env);
	}
	else
	{
		if (chdir(cmmd->cmd->arg[1]) == 0
			&& ft_strcmp(cmmd->cmd->arg[1], "."))
		{
			if (cmmd->cmd->arg[1][0] != '/')
				ch_env_var(env, "PWD", join_paths(env, cmmd->cmd->arg[1]));
			else if (cmmd->cmd->arg[1][0] == '/')
				ch_env_var(env, "PWD", cmmd->cmd->arg[1]);
		}
	}
}

void	cd_pos_cero(t_env *env, char *home_path, bool o_pwd)
{
	if (chdir(home_path) == 0)
	{
		if (o_pwd == true)
			ch_env_var(env, "OLDPWD", get_t_env(env, "PWD"));
		ch_env_var(env, "PWD", home_path);
		chdir(home_path);
	}
}
