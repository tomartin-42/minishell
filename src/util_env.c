/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommy <tommy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:51:06 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/04 18:11:15 by tommy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env_list(t_env **m_env, char *var)
{
	(*m_env) = malloc(sizeof(t_env));
	(*m_env)->v_env = ft_strdup(var);
	(*m_env)->var = ft_split(var, '=');
	(*m_env)->global = true;
	(*m_env)->visible = true;
	(*m_env)->next = NULL;
}

t_env	*ft_lstlast_env(t_env *env_lst)
{
	if (!env_lst)
		return (NULL);
	while (env_lst->next)
	{
		env_lst = env_lst->next;
	}
	return (env_lst);
}

t_env	*new_env_node(t_env *new, char *var)
{
	new = malloc(sizeof(t_env));
	new->v_env = ft_strdup(var);
	new->var = ft_split(var, '=');
	new->global = true;
	new->visible = true;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_env(t_env **env_lst, t_env *new)
{
	if (!*env_lst)
	{
		*env_lst = new;
		return ;
	}
	if (!env_lst)
		return ;
	(ft_lstlast_env(*env_lst))->next = new;
}

