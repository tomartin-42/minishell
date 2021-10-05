/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_ex2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:41:22 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/05 21:24:30 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	find_env(t_env *p_env)
{
	int n;

	n = 0;
	//printf("HOLA ESTOS ES env_ex2.c\n");
	while (p_env[n].end != true)
	{
		printf("%s", p_env[n].var[0]);
		printf("=");
		printf("%s\n", p_env[n].var[1]);
		n++;
	}
	//printf("\n\n%s\n\n", p_env->var[0]);
}
