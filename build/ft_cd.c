/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:18:27 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/25 11:11:56 by dpuente-         ###   ########.fr       */
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
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void	remove_end_trash(t_command *command)
{
	t_command	*p_command;
	int			pos;

	p_command = command;
	pos = 0;
	while (p_command->cmd->arg[1][pos] && p_command->cmd->arg[1][pos] != '/')
	{
		pos++;
	}
	if (p_command->cmd->arg[1][pos] == '/')
		p_command->cmd->arg[1][pos] = '\0';
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void	example_name(t_env *env, char *pwd, int n_paths)
{
	char	*new_path;
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
	{
		new_path = malloc(sizeof(char) * (malloc_num));
		while (n < malloc_num - 1)
		{
			new_path[n] = pwd[n];
			n++;
		}
		new_path[n] = '\0';
		if (chdir(new_path) == 0)
		{
			//printf("parse");
			change_single_env_var(env, "OLDPWD", pwd);
			change_single_env_var(env, "PWD", new_path);
		}
		//chdir(new_path);
		free(new_path);
	}
	if (n_paths == 0)
	{
		new_path = NULL;
		change_single_env_var(env, "PWD", "/");
		chdir("/");
	}
}

void	back_path(int times, t_env *env)
{
	int		pos;			// 
	char	*current_path;	// pwd para manejarlo mejor
	//int		size_pwd;		// size para reservar memoria del nuevo path mas reducido
	int		number_paths;	// cantidad de / que hay en el PWD

	pos = 0;
	number_paths = 0;
	current_path = get_t_env(env, "PWD");
	//size_pwd = ft_strlen(current_path);
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
	example_name(env, current_path, number_paths);
}

static int	move_back(t_command *command, t_env *env)
{
	//t_env		*p_env;
	//t_command	*p_command;
	int			pos;
	int			dots;

	pos = 0;
	dots = 0;
	//p_env = env;
	//p_command = command;
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
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
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
	if (!check_oldpwd(env))//compureba que existe OLDPWD
		o_pwd = true;
	remove_end_trash(command);//////////////////////provando
	if (pos > 1)
	{
		if (o_pwd == true)
			change_single_env_var(env, "OLDPWD", get_t_env(env, "PWD"));
		if (!ft_strcmp(command->cmd->arg[1], "..")
			|| (command->cmd->arg[1][0] == '.' && command->cmd->arg[1][1] == '.'))
		{
			move_back(command, env);
		}
		else
		{
			if (chdir(command->cmd->arg[1]) == 0
				&& ft_strcmp(command->cmd->arg[1], ".")) // si habia un punto entraba y anadia . a pwd
			{
				//printf("cd1");
				if (command->cmd->arg[1][0] != '/')
					change_single_env_var(env, "PWD", join_paths(env, command->cmd->arg[1]));
				else if (command->cmd->arg[1][0] == '/')
					change_single_env_var(env, "PWD", command->cmd->arg[1]);
				//printf("[%d]\n", chdir(command->cmd->arg[1]));
			}
		}
	}
	else if (pos == 1)
	{
		if (chdir(home_path) == 0)
		{
			//printf("cd");
			if (o_pwd == true)
				change_single_env_var(env, "OLDPWD", get_t_env(env, "PWD"));
			change_single_env_var(env, "PWD", home_path);
			chdir(home_path);
		}
	}
	if (command->multi_cmd[1] == NULL) 
		return (0);
	else
		exit (0);
}
