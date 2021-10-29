/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:05:35 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/29 14:05:38 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_element(t_element *element)
{
	t_element	*aux;

	while (element)
	{
		aux = element;
		element = element->next;
		free(aux->str);
		if (aux->arg)
			ft_free_dp(aux->arg);
		free(aux);
	}
}

void	free_env_list(t_env *env)
{
	t_env	*aux;

	while (env)
	{
		aux = env;
		env = env->next;
		free(aux->v_env);
		free(aux->var[0]);
		free(aux->var[1]);
		free(aux);
	}
}
