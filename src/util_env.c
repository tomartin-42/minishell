/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:51:06 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/01 12:41:21 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_local_to_env(t_env **m_env, char *new_var)
{
	int	i;
	t_env	**aux_env;

	i = 0;
	while(m_env[i])
		i++;
	aux_env = malloc(sizeof(t_env *) * (i + 1));
	aux_env[i + 1]->v_env = ft_strdup(new_var);
	aux_env[i + 1]->v_var = ft_split(aux_env[i + 1]->v_env, "=");
	aux_env[i + 1]->global = false;
	aux_env[i + 1]->visible = false;
	aux_env[i + 1]->del = false;
	ft_memcpy(aux_env, m_env, sizeof(t_env) * i);
	i = 0;
	while(aux_env[i])
	{
		printf("[[[%s]]]\n", aux_env[i]->v_env);
		i++;
	}
}

