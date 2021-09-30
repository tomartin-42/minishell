/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:51:06 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/30 09:51:09 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_lstlast_env(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back_env(t_env **env, t_env *new)
{
	if (!*env)
	{
		*env = new;
		return ;
	}
	if (!env)
		return ;
	new->prev = (ft_lstlast_env(*env));
	(ft_lstlast_env(*env))->next = new;
}

// Copy env var and add nodes to the m_emv list 
void	copy_env_to_list(t_env *m_env, char **env)
{
	int		i;
	t_env	*new;
	
	i = 0;
	m_env->next = NULL;
	m_env->prev = NULL;
	m_env->v_env = ft_strdup(env[0]);
	m_env->global = true;
	i++;
	while (env[i] != NULL)
	{
		new = malloc(sizeof(t_env));
		new->v_env = ft_strdup(env[i]);
		new->global = true;
		new->next = NULL;
		ft_lstadd_back_env(&m_env, new);
		new = NULL;
		i++;
	}
}

void print_env(t_env *env)
{
	while (env->next) 
	{
		printf("[%s]\n", env->v_env);
		env = env->next;
	}
	printf("[%s]\n", env->v_env);
}
