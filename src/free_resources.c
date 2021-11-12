/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:07:33 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/11 14:01:32 by dpuente-         ###   ########.fr       */
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
		{
			if (aux->type == 'C' || aux->type == 'B')
				ft_free_dp(aux->arg);
			else if (aux->type == 'I' || aux->type == 'O' || aux->type == 'T'
				|| aux->type == 'H')
			{
				free(aux->arg[0]);
				free(aux->arg[1]);
				free(aux->arg);
			}
		}
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
		free(aux->var);
		free(aux);
	}
}
