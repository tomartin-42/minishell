/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 08:42:04 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/15 09:58:49 by tomartin         ###   ########.fr       */
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
