/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 08:41:08 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/10 10:10:42 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "errorlib.h"

static char	**put_bars_and_cmd_on_path(char **path, char *cmd)
{
	int		i;
	char	*aux_1;
	char	*aux_2;

	i = 0;
	while (path[i])
	{
		aux_1 = path[i];
		path[i] = ft_strjoin(path[i], "/");
		aux_2 = path[i];
		path[i] = ft_strjoin(path[i], cmd);
		free(aux_1);
		free(aux_2);
		i++;
	}
	return (path);
}

static char	**get_paths(char *path, char **env)
{
	int		i;
	char	*aux;
	char	*aux2;
	char	**paths_wo_bar;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			break ;
		i++;
	}
	if (!env[i])
		error_cmd_not_found(path);
	aux = env[i];
	while (*aux != '=')
		aux++;
	aux2 = ft_strdup(++aux);
	paths_wo_bar = ft_split(aux2, ':');
	free(aux2);
	return (put_bars_and_cmd_on_path(paths_wo_bar, path));
}

static int	check_if_path_absolute(char *cmd)
{
	char	*aux;

	aux = cmd;
	if (*aux == '/' || *aux == '.')
	{
		if (ft_access(aux))
			return (OK);
		else
			return (KO);
	}
	else
		return (KO);
}

char	*find_exec_path(char **cmd, char **env)
{
	char	**exec_paths;
	char	*path;
	int		i;

	path = *cmd;
	if (check_if_path_absolute(path))
		return (*cmd);
	exec_paths = get_paths(path, env);
	i = 0;
	while (exec_paths[i])
	{
		if (ft_access(exec_paths[i]))
		{
			free(*cmd);
			path = ft_strdup(exec_paths[i]);
			break ;
		}
		i++;
	}
	if (exec_paths[i] == NULL)
		error_cmd_not_found(path);
	ft_free_dp(exec_paths);
	if (!path)
		error_cmd_not_found("");
	return (path);
}
