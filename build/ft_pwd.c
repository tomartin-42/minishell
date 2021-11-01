/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:27:59 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/01 10:31:48 by davyd11          ###   ########.fr       */
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
		exit (1);
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
