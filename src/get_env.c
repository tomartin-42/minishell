/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:32:38 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 18:28:20 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	errno_dollar(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] == '$' && str[pos + 1]
			&& str[pos + 1] == '?')
			return (0);
		pos++;
	}
	return (1);
}

char	*get_t_env(t_env *env, char *var)
{
	t_env	*p_env;

	p_env = env;
	while (p_env)
	{
		if (!ft_strcmp(var, p_env->var[0]))
			return (p_env->var[1]);
		p_env = p_env->next;
	}
	return (NULL);
}

char	*env_content(char **envs, int pos, int w_p)
{
	int		len_env;
	char	*ret_var;

	len_env = 0;
	w_p++;
	while (envs[pos][w_p] != '\0')
	{
		len_env++;
		w_p++;
	}
	ret_var = malloc(sizeof(char) * len_env + 1);
	w_p = w_p - len_env;
	len_env = 0;
	while (envs[pos][w_p] != '\0')
	{
		ret_var[len_env] = envs[pos][w_p];
		len_env++;
		w_p++;
	}
	ret_var[len_env] = '\0';
	return (ret_var);
}

char	*get_env(char **envs, char *var)
{
	int		pos;
	int		w_p;

	pos = 0;
	w_p = 0;
	while (envs[pos])
	{
		w_p = 0;
		while (envs[pos][w_p] && var[w_p]
			&& envs[pos][w_p] != '=' && envs[pos][w_p] == var[w_p])
		{
			w_p++;
		}
		if (envs[pos][w_p] == '=')
		{
			return (env_content(envs, pos, w_p));
		}
		pos++;
	}
	return (NULL);
}
