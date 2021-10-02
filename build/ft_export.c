/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:45:05 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/02 19:45:49 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

static void	order_env(char **env_lst)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	while (env_lst[i])
	{
		j = i + 1;
		while (env_lst[j])
		{
			if (ft_strcmp(env_lst[i], env_lst[j]) < 0)
			{
				aux = env_lst[i];
				env_lst[i] = env_lst[j];
				env_lst[j] = aux;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (env_lst[i])
		printf("%s\n", env_lst[i++]);
}

void	ft_export(t_env *m_env, char **args)
{
	char	**env_lst;

	if (!args)
	{
		env_lst = copy_env_to_double_pointer(m_env);
		order_env(env_lst);
	}
}
