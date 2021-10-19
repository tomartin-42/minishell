/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:27:59 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/18 19:25:25 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

int	ft_pwd(t_env *env)
{
	t_env	*p_env;
	int		n;

	p_env = env;
	n = 0;
	if (!p_env->var[0] && !p_env->var[1])
		return (1);
	while (p_env)
	{
		if (p_env->var[0] && p_env->var[1])
		{
			if (p_env->var[0][0] == 'P' && p_env->var[0][1] == 'W'
				&& p_env->var[0][2] == 'D')
			{
				while (p_env->var[1][n] != '\0')
				{
					write (1, &p_env->var[1][n], 1);
					n++;
				}
				write(1, "\n", 1);
			}
		}
		p_env = p_env->next;
	}
	return (0);
}
/*	int	pos;
	int	n;

	pos = 0;
	n = 4;
	if (!envs)
		return (1);
	while (envs[pos]
		&& (envs[pos][0] != 'P' && envs[pos][1] != 'W' && envs[pos][2] != 'D'))
	{
		pos++;
	}
	if (envs[pos])
	{
		if (envs[pos][0] == 'P' && envs[pos][1] == 'W' && envs[pos][2] == 'D')
		{
			while (envs[pos][n] != '\0')
			{
				write (1, &envs[pos][n], 1);
				n++;
			}
			write(1, "\n", 1);
		}
	}
	return (0);
}*/