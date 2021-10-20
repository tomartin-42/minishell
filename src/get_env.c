/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:32:38 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/20 17:51:10 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	*get_env(char **envs, char *var)
{
	int		pos;
	int		w_p;
	int		len_env;
	char	*ret_var;

	pos = 0;
	w_p = 0;
	len_env = 0;
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
		pos++;
	}
	return (NULL);
	//free(ret_var);//no liberar aqui pero si fuera donde se utilice.
}
