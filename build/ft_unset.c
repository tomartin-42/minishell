/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:26:09 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/29 11:45:37 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"
#include "errorlib.h"

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

static void	clean_up_env_list(t_env *env)
{
	t_env	*p_env;
	t_env	*aux;
	t_env	*prev;

	p_env = env;
	prev = p_env;
	while (p_env)
	{
		if (p_env->visible == false)
		{
			aux = p_env;
			prev->next = aux->next;
			free (aux->v_env);
			free (aux->var[0]);
			free (aux->var[1]);
			free (aux);
			p_env = prev;
		}
		else
		{
			prev = p_env;
			p_env = p_env->next;
		}
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
			dell_var_t_env(env, command->cmd->arg[i]);
		i++;
	}
	clean_up_env_list(env);
	return (ret);
}

