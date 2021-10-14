/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:32:38 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/14 19:17:32 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
