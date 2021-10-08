/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_env2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:35:27 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/08 11:25:10 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "build.h"

<<<<<<< HEAD
static void	add_shlvl(t_env *env)
=======
static void	add_shlvl(t_env **env)
>>>>>>> 1108f725ad55259276d1fee86cb4cf7a405e65a1
{
	t_env	*p_env;
	int		i;

	p_env = env;
	while (p_env)
	{
<<<<<<< HEAD
		if (search_if_var(p_env, "SHLVL") == 0)
		{
			i = ft_atoi(p_env->var[1]);
			i++;
			free(p_env->v_env);
			p_env->v_env = ft_strdup("SHLVL");
			p_env->v_env = ft_super_strjoin(p_env->v_env, ft_itoa(i), 1);
=======
		if (ft_strcmp(p_env, "SHLVL") == 0)
		{
			i = ft_atoi(p_env->var[1])
			i++;
			free(p_env->str);
			p_env->str = ft_strdup("SHLVL");
			p_env->str = ft_super_join(p_env->str, ft_itoa(i), 1);
>>>>>>> 1108f725ad55259276d1fee86cb4cf7a405e65a1
			free(p_env->var[1]);
			p_env->var[1] = ft_strdup(ft_itoa(i));
		}
		p_env = p_env->next;
	}
}
<<<<<<< HEAD
=======

>>>>>>> 1108f725ad55259276d1fee86cb4cf7a405e65a1

void	change_shlvl(t_env *env)
{
	int		check;
	t_env	aux_node;
	char	*aux;

	check = search_if_var(env, "SHLVL");
	if (check == 1)
<<<<<<< HEAD
		add_shlvl(env);
=======
		add_shlvl(&env);
>>>>>>> 1108f725ad55259276d1fee86cb4cf7a405e65a1
	else if (check == -1)
	{
		aux = ft_strdup("SHLVL=1");
		new_env_node_global(&aux_node, aux);
//		ft_lstadd_back_env(&env, aux_node);
		free(aux);
	}
}
