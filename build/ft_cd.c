/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:18:27 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/21 11:45:38 by tomartin         ###   ########.fr       */
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
			if (p_env->var[1])
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
	if (!check_oldpwd(env))
		o_pwd = true;
	if (pos > 1)
	{
		if (o_pwd == true)
			change_single_env_var(env, "OLDPWD", get_t_env(env, "PWD"));
		if (command->cmd->arg[1][0] != '/')
			change_single_env_var(env, "PWD", join_paths(env, command->cmd->arg[1]));
		else
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

	//DIR			*pdir;
	//struct dirent	*pdir_content;
	///////////////////////////parse cd
	/*pos = 1;// we don't want to see cd wich is the first argument

	pdir = opendir(command->cmd->arg[pos]);
	if(pdir!=NULL)
	{
		while((pdir_content=readdir(pdir))!=NULL)
			printf("[%s]\n", pdir_content->d_name);
	}
	if (pdir)
		closedir(pdir);*/
