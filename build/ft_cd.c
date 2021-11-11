/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:18:27 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 21:15:26 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

char	*join_paths(t_env *env, char *new_path)
{
	char	*f_path;
	char	*s_path;

	f_path = ft_strjoin(get_t_env(env, "PWD"), "/");
	s_path = ft_strjoin(f_path, new_path);
	return (s_path);
}

void	n_path_true(t_env *env, char *pwd, int malloc_num)
{
	int		n;
	char	*new_path;

	n = 0;
	new_path = malloc(sizeof(char) * (malloc_num));
	while (n < malloc_num - 1)
	{
		new_path[n] = pwd[n];
		n++;
	}
	new_path[n] = '\0';
	if (chdir(new_path) == 0)
	{
		ch_env_var(env, "OLDPWD", pwd);
		ch_env_var(env, "PWD", new_path);
	}
	free(new_path);
}

void	back_path_edit(t_env *env, char *pwd, int n_paths)
{
	int		malloc_num;
	int		n;

	malloc_num = 0;
	n = 0;
	while (n != n_paths + 1 && pwd[malloc_num] && n <= n_paths)
	{
		if (pwd[malloc_num] == '/')
			n++;
		malloc_num++;
	}
	n = 0;
	if (n_paths != 0)
		n_path_true(env, pwd, malloc_num);
	if (n_paths == 0)
	{
		ch_env_var(env, "PWD", "/");
		chdir("/");
	}
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
	if (!check_var(env, "OLDPWD"))
		o_pwd = true;
	if (check_var(env, "PWD"))
		return (0);
	if (pos > 1)
		cd_pos_more_than_one(command, env, o_pwd);
	else if (pos == 1)
		cd_pos_cero(env, home_path, o_pwd);
	if (command->multi_cmd[1] == NULL)
		return (0);
	else
		exit (0);
}
