/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:14:34 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/30 12:46:16 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static chat	**cont_visible_v_env(t_env *m_envi, chat **env_list)
{
	int		i;
	i = 0;
	while (m_env != NULL)
	{
		if (m_env->visible == true)
			i++;
		m_env = m_env->next
	}
	env_list = malloc(sizeof(chat *) * i);
	while (i > 0)
		env_list = ft
	return (env_list);
}

statuc void	copy_env_list(char **env_list)
{


void	ft_export(t_env *env, t_element *element)
{
	char	**env_list;
	if (ft_strlen(element->arg[0]))
		printf(" "); // codigo para pasar una variable statica a global
	else
	{
		env_list = cont_visible_v_env(env, env_list)
		copy_env_list(env_list);
		printf(" ");
	}
}

