/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:18:27 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/17 19:44:38 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

//opendir, readdir, closedi
void	ft_cd(t_command *command)
{
	int				pos;
	//DIR				*pdir;
	//struct dirent	*pdir_content;

	///////////////////////////parse cd
	pos = 0;
	while (command->cmd->arg[pos])
		pos++;
	if (pos > 1)
	{
		chdir(command->cmd->arg[1]);
	}
	else if (pos == 1)
	{
		chdir(get_env(command->env, "HOME"));
		//printf("**%s**\n", getcwd(get_env(envs, "PWD"), 100));
		//getcwd(char *donde_alamcenar_ruta, buffer_size_char);
	}
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