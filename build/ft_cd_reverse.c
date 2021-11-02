/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:53:45 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/29 18:47:34 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

void	n_paths_notzero(int malloc_num, char *new_path, char *pwd, t_env *env)
{
	int	n;

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
		chg_env_var(env, "OLDPWD", pwd);
		chg_env_var(env, "PWD", new_path);
	}
	free(new_path);
}

void	chg_mv_env(t_env *env, char *pwd, int n_paths)
{
	char	*new_path;
	int		malloc_num;
	int		n;

	malloc_num = 0;
	n = 0;
	new_path = NULL;
	while (n != n_paths + 1 && pwd[malloc_num] && n <= n_paths)
	{
		if (pwd[malloc_num] == '/')
			n++;
		malloc_num++;
	}
	n = 0;
	if (n_paths != 0)
		n_paths_notzero(malloc_num, new_path, pwd, env);
	if (n_paths == 0)
	{
		chg_env_var(env, "PWD", "/");
		chdir("/");
	}
}

void	back_path(int times, t_env *env)
{
	int		pos;
	char	*current_path;
	int		size_pwd;
	int		number_paths;

	pos = 0;
	number_paths = 0;
	current_path = get_t_env(env, "PWD");
	size_pwd = ft_strlen(current_path);
	while (current_path[pos] != '\0')
	{
		if (current_path[pos] == '/')
			number_paths++;
		pos++;
	}
	if (number_paths <= times)
		number_paths = 0;
	else
		number_paths = number_paths - times;
	chg_mv_env(env, current_path, number_paths);
}

int	move_back(t_command *command, t_env *env)
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
	back_path(dots / 2, env);
	return (0);
}
