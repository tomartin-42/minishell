/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommy <tommy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:51:06 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/01 16:18:48 by tommy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_local_to_env(t_env *m_env, char *new_var)
{
	int	i;
	t_env	*aux_env;

	i = 0;
	while(m_env[i].end == false)
		i++;
	aux_env = malloc(sizeof(t_env) * (i + 2));
	aux_env[i].v_env = ft_strdup(new_var);
	//aux_env[i].var = ft_split(aux_env[i + 1].v_env, '=');
	aux_env[i].global = false;
	aux_env[i].visible = false;
	aux_env[i].del = false;
	aux_env[i].end = false;
	aux_env[i + 1].end = true;
	ft_memcpy(aux_env, m_env, sizeof(t_env) * i);
	i = 0;
}

