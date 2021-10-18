/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:18:27 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/18 20:17:08 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

//opendir, readdir, closedi
int	ft_cd(t_command *command, t_env *env)
{
	int				pos;
	char			*home_path;
	//DIR			*pdir;
	//struct dirent	*pdir_content;
	///////////////////////////parse cd
	pos = 0;
	home_path = get_env(command->env, "HOME");
	while (command->cmd->arg[pos])
		pos++;
	if (pos > 1)
	{
		//change_single_env_var(env, "OLDPWD", getcwd("PWD", 256));
		//change_single_env_var(env, "PWD", command->cmd->arg[1]);
		printf("%s\n", command->cmd->arg[1]);
		printf("%d\n", chdir("build"));
	}
	else if (pos == 1)
	{
		//printf("%s\n", home_path);
		change_single_env_var(env, "OLDPWD", getcwd("PWD", 256));
		change_single_env_var(env, "PWD", home_path);
		chdir(home_path);
		//change_single_env_var(env, "PWD", home_path);
		//printf("**%s**\n", getcwd(get_env(envs, "PWD"), 100));
		//getcwd(char *donde_alamcenar_ruta, buffer_size_char);
	}
	return (0);
}

		/*pos = 1;// we don't want to see cd wich is the first argument

		pdir = opendir(command->cmd->arg[pos]);
		if(pdir!=NULL)
		{
			while((pdir_content=readdir(pdir))!=NULL)
				printf("[%s]\n", pdir_content->d_name);
		}
		if (pdir)
			closedir(pdir);*/