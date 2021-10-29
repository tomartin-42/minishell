/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:51:06 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/29 13:41:24 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "build.h"
///////ES POSIBLE NO SER NECESARIA//////////////////////
/*void	init_env_list(t_env **m_env, char *var)
{
	(*m_env) = malloc(sizeof(t_env));
	(*m_env)->v_env = ft_strdup(var);
	if (ft_strchr(var, '='))
		(*m_env)->var = separate_env_var(var);
	else
	{
		(*m_env)->var[0] = ft_strdup(var);
		(*m_env)->var[1] = NULL;
	}
	(*m_env)->global = true;
	(*m_env)->visible = true;
	(*m_env)->next = NULL;
}*/

t_env	*ft_lstlast_env(t_env *env_lst)
{
	if (!env_lst)
		return (NULL);
	while (env_lst->next)
		env_lst = env_lst->next;
	return (env_lst);
}
/*
t_env	*new_env_node_export(t_env *new, char *var)
{
	char	**sp_var;

	new = malloc(sizeof(t_env));
	new->v_env = ft_strdup(var);
	if (ft_strchr(var, '='))
	{
		sp_var = ft_split(var, '=');
		if (sp_var[1] == NULL)
			sp_var[1] = ft_strdup("");
		new->var[0] = ft_strdup(sp_var[0]);
		new->var[1] = ft_strdup(sp_var[1]);
		ft_free_dp(sp_var);
	}
	else
	{
		new->var[0] = ft_strdup(var);
		new->var[1] = NULL;
	}
	new->global = false;
	new->visible = false;
	new->next = NULL;
	return (new);
}
*/

t_env	*new_env_node_global(t_env *new, char *var)
{
	new = malloc(sizeof(t_env));
	new->v_env = ft_strdup(var);
	if (ft_strchr(var, '='))
		new->var = separate_env_var(var);
	else
	{
		new->var = malloc(sizeof(char *) * 2);
		new->var[0] = ft_strdup(var);
		new->var[1] = NULL;
	}
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
	{
		return ;
	}
	(ft_lstlast_env(*env_lst))->next = new;
}
