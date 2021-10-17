/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:18:27 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/14 21:19:01 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

//opendir, readdir, closedi
void	ft_cd(char **args, char **envs)
{
	int				pos;
	DIR				*pdir;
	struct dirent	*pdir_content;

	///////////////////////////parse cd
	pos = 0;
	if (envs)
		;
	while (args[pos])
	{
		pos++;
	}
	//printf("\n\n\n\n%d\n\n\n\n", pos);
	if (pos > 1)
	{
		printf("-=%s=-\n", args[1]);
		pos = 1;// we dont want to see cd wich is the first argument

		pdir = opendir(args[pos]);
		if(pdir!=NULL)
		{
			while((pdir_content=readdir(pdir))!=NULL)
				printf("[%s]\n", pdir_content->d_name);
		}
		//dir_content = readdir(dir);
		//printf("-->%s<--\n", dir_content->d_name);
		if (pdir)
			closedir(pdir);
	}
	if (pos == 1)
	{
		chdir(get_env(envs, "HOME"));
		//printf("**%s**\n", getcwd(get_env(envs, "PWD"), 100));
		//getcwd(char *donde_alamcenar_ruta, buffer_size_char);
	}
}
