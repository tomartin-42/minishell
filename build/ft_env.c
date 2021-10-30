/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:57:35 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/29 10:15:59 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

int	ft_env(t_env *env)
{
	if (!env)
		return (-1);
	while (env)
	{
		if (env->visible == true)
		{
			ft_putstr_fd(env->var[0], 1);
			write (1, "=", 1);
			ft_putstr_fd(env->var[1], 1);
			write (1, "\n", 1);
		}
		env = env->next;
	}
	return (0);
}
	//exit (0);
