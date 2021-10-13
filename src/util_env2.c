/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_env2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:35:27 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/11 10:16:52 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "build.h"

static void	add_shlvl(t_env *env)
{
	t_env	*p_env;
	int		i;

	p_env = env;
	while (p_env)
	{
		if (search_if_var(p_env, "SHLVL") == 0)
		{
			i = ft_atoi(p_env->var[1]);
			i++;
			free(p_env->v_env);
			p_env->v_env = ft_strdup("SHLVL");
			p_env->v_env = ft_super_strjoin(p_env->v_env, ft_itoa(i), 1);
			free(p_env->var[1]);
			p_env->var[1] = ft_strdup(ft_itoa(i));
		}
		p_env = p_env->next;
	}
}

void	change_shlvl(t_env *env)
{
	int		check;
	t_env	aux_node;
	char	*aux;

	check = search_if_var(env, "SHLVL");
	if (check == 1)
		add_shlvl(env);
	else if (check == -1)
	{
		aux = ft_strdup("SHLVL=1");
		new_env_node_global(&aux_node, aux);
//		ft_lstadd_back_env(&env, aux_node);
		free(aux);
	}
}

//This function get a env var name and change the value
void	change_single_env_var(t_env *env, char *var, char *n_value)
{
	t_env	*p_env;

	p_env = env;
	while (p_env)
	{
		if (ft_strcmp(p_env->var[0], var) == 0)
		{
			free(p_env->var[1]);
			p_env->var[1] = ft_strdup(n_value);
			free(p_env->v_env);
			ft_super_strjoin(p_env->var[0], p_env->var[1], 0);
		}
		p_env = p_env->next;
	}
}