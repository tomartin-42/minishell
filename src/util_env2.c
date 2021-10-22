/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_env2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:35:27 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/22 12:27:54 by tomartin         ###   ########.fr       */
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
			p_env->v_env = ft_super_strjoin(p_env->v_env, "=", 1);
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
		free(aux);
	}
}

//This function get a env_var name and change the value
void	change_single_env_var(t_env *env, char *var, char *n_value)
{
	t_env	*p_env;
	char	*aux;

	p_env = env;
	while (env)
	{
		//printf("%s<-->%s\n", p_env->var[0], var);
		if (ft_strcmp(env->var[0], var) == 0)
		{
			//printf("%s<-->%s\n", p_env->var[0], var);
			free(env->var[1]);
			env->var[1] = ft_strdup(n_value);
			free(env->v_env);
			env->v_env = ft_strdup(env->var[0]);
			aux = ft_strdup("=");
			env->v_env = ft_super_strjoin(env->v_env, aux, 3);
			env->v_env = ft_super_strjoin(env->v_env, env->var[1], 1);
			ft_super_strjoin(env->var[0], env->var[1], 0);
		//	printf("++%s--%s++\n", p_env->var[0], p_env->var[1]);////////////////
		}
		//printf("++%s--%s++\n", env->var[0], env->var[1]);
		env = env->next;
	}
	env = p_env;
}
