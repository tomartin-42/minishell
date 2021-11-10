/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:51:06 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/11 10:14:55 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "build.h"

t_env	*ft_lstlast_env(t_env *env_lst)
{
	if (!env_lst)
		return (NULL);
	while (env_lst->next)
		env_lst = env_lst->next;
	return (env_lst);
}

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
