/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:26:09 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/13 14:35:02 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"
#include "errorlib.h"

static void	clean_up_env_list(t_env *env)
{
	t_env	*prev;
	t_env	*aux;

	aux = env;
	prev = aux;
	aux = aux->next;
	while (aux != NULL && aux->visible == true)
	{
		prev = aux;
		aux = aux->next;
	}
	if (aux != NULL)
	{
		prev->next = aux->next;
		free(aux->v_env);
		free(aux->var[0]);
		free(aux->var[1]);
		free(aux->var);
		free(aux);
	}
}

static void	dell_var_t_env(t_env *env, char *var)
{
	t_env	*p_env;

	p_env = env;
	while (p_env)
	{
		if (ft_strcmp(p_env->var[0], var) == 0)
			p_env->visible = false;
		p_env = p_env->next;
	}
}

int	ft_unset(t_command *command, t_env *env)
{
	int	i;
	int	ret;

	i = 1;
	ret = 0;
	if (command->cmd->arg[1] == NULL)
		return (error_unset_no_arg());
	while (command->cmd->arg[i])
	{
		if (ft_strchr(command->cmd->arg[i], '=') && ret == 0)
			ret = error_unset_invalid_param(command->cmd->arg[i]);
		else
		{
			dell_var_t_env(env, command->cmd->arg[i]);
			clean_up_env_list(env);
		}
		i++;
	}
	return (ret);
}
