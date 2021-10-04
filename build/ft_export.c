/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommy <tommy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:45:05 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/04 19:45:57 by tommy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

char	**extract_env_list(t_env *env)
{
	t_env	*p_env;
	int		i;
	char	**list;

	i = 0;
	p_env = env;
	while (p_env)
	{
		if (p_env->global == true)
			i++;
		p_env = p_env->next;
	}
	list = malloc (sizeof(char *) * (i + 1));
	list[i] = NULL;
	i = 0;
	p_env = env;
	while (p_env)
	{
		if (p_env->global == true)
			list[i++] = ft_strdup(p_env->v_env);
		p_env = p_env->next;
	}
	return (list);
}
