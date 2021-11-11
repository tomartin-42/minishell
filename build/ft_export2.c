/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 08:42:04 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/11 19:38:49 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

// Search in env list and return 1 if had a global var, 0 locat var
// and -1 if don't had
int	search_if_var(t_env *env, char *arg)
{
	t_env	*p_env;

	p_env = env;
	while (p_env)
	{
		if (ft_strcmp(p_env->var[0], arg) == 0 && (p_env->global == true))
			return (1);
		else if (ft_strcmp(p_env->var[0], arg) == 0
			&& (p_env->global == false))
			return (0);
		p_env = p_env->next;
	}
	return (-1);
}

/*static void	promotion_local_to_global(t_env *env, char *arg)
{
	t_env	*p_env;

	p_env = env;
	while (p_env)
	{
		if (ft_strcmp(p_env->var[0], arg) == 0)
		{
			p_env->global = true;
			p_env->visible = true;
			break ;
		}
		p_env = p_env->next;
	}
}*/

/*void	without_equal_export(t_env *env, char *arg)
{
	int		i;
	t_env	*new;

	new = NULL;
	i = search_if_var(env, arg);
	if (i == 0)
		promotion_local_to_global(env, arg);
	else if (i == -1)
	{
		new = new_env_node_global(new, arg);
		ft_lstadd_back_env(&env, new);
	}
}*/

void	without_equal_export(t_env *env, char *arg)
{
	int		i;
	t_env	*new;

	new = NULL;
	i = search_if_var(env, arg);
	if (i == 1 || i == 0)
		;
	else
	{
		new = new_env_node_global(new, arg);
		ft_lstadd_back_env(&env, new);
	}
}

/*
//Funtion to chang value in global env var. Need past the line
//with equal, search and sustitute the value
static void	change_env_value(t_env **env, char *arg)
{
	t_env	*p_env;
	char	**values;

	p_env = (*env);
	values = separate_env_var(arg);
	while (p_env)
	{
		if (ft_strcmp(values[0], p_env->var[0]) == 0)
		{
			free(p_env->v_env);
			p_env->v_env = ft_strdup(arg);
			free(p_env->var[0]);
			free(p_env->var[1]);
			p_env->var = separate_env_var(arg);
			p_env = p_env->next;
		}
	}
}*/

void	with_equal_export(t_env *env, char *arg)
{
	int		i;
	char	**sp_arg;
	t_env	*new;

	new = NULL;
	sp_arg = ft_split(arg, '=');
	i = search_if_var(env, sp_arg[0]);
	if (i == 1 || i == 0)
	{
		ch_env_var(env, sp_arg[0], sp_arg[1]);
		ft_free_dp(sp_arg);
	}
	else
	{
		new = new_env_node_global(new, arg);
		ft_lstadd_back_env(&env, new);
		ft_free_dp(sp_arg);
	}
}
