/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_env2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:35:27 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/07 11:12:36 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "build.h"

static void	add_shlvl(t_env **env)
{
	t_env	*p_env;
	int		i;

	p_env = *env;
	while (p_env)
	{
		if (ft_strcmp(p_env, "SHLVL") == 0)
		{
			i = ft_atoi(p_env->var[1])
			i++;
			free(p_env->str);
			p_env->str = ft_strdup("SHLVL");
			p_env->str = ft_super_join(p_env->str, ft_itoa(i), 1);
			free(p_env->var[1]);
			p_env->var[1] = ft_strdup(ft_itoa(i));
		}
		p_env = p_env->next;
	}
}


void	change_shlvl(t_env *env)
{
	char	*value;
	int		check;
	t_env	aux_node;

	check = search_if_var(env, "SHLVL");
	if (check == 1)
		add_shlvl(&env);
	else if (check == -1)
	{
		new_env_node_global(aux_node, ft_strdup("SHLVL=1"));
		ft_lstadd_back_env(*env, aux_node);
	}
}
