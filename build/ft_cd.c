/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:51:20 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/15 09:53:40 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

static void	change_cd_pwd(t_env *env, char *old_pwd)
{
	char	*new_pwd;

	new_pwd = NULL;
	if (search_if_var(env, "OLDPWD") != -1)
	{
		old_pwd = ft_super_strjoin("OLDPWD=", old_pwd, 2);
		with_equal_export(env, old_pwd);
	}
	if (search_if_var(env, "PWD") != -1)
	{
		new_pwd = getcwd(NULL, 0);
		new_pwd = ft_super_strjoin("PWD=", new_pwd, 2);
		with_equal_export(env, new_pwd);
		free (new_pwd);
	}
	free (old_pwd);
}

static void	error_pwd_args(t_command *command, char *old_pwd)
{
	free (old_pwd);
	ft_putstr_fd("cd: string not in pwd: ", 2);
	ft_putstr_fd(command->cmd->arg[1], 2);
	ft_putstr_fd("\n", 2);
	g_state = 1;
}

static int	error_cd(t_command *command)
{
	g_state = errno;
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(strerror(g_state), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(command->cmd->arg[1], 2);
	ft_putstr_fd("\n", 2);
	return (g_state);
}

int	ft_cd(t_command *command, t_env *env)
{
	int		n_param;
	int		ret;
	char	*old_pwd;

	n_param = 0;
	ret = 0;
	old_pwd = getcwd(NULL, 0);
	while (command->cmd->arg[n_param] != NULL)
		n_param++;
	if (n_param > 2)
	{
		error_pwd_args(command, old_pwd);
		return (g_state);
	}
	ret = chdir(command->cmd->arg[1]);
	if (ret == 0)
		change_cd_pwd(env, old_pwd);
	else
	{
		ret = error_cd(command);
		free (old_pwd);
	}
	return (ret);
}
