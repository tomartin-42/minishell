/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 08:34:15 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/13 14:34:20 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

//Separate the env var in doble pointer name and value
char	**separate_env_var(char *var)
{
	char	**var_dual;
	int		i;
	char	*aux;

	i = 0;
	var_dual = malloc(sizeof(char *) * 2);
	while (var[i] != '=' && var[i] != '\0')
		i++;
	var_dual[0] = ft_substr(var, 0, i);
	aux = ft_strchr(var, '=');
	aux++;
	if (*aux == '\0')
		var_dual[1] = NULL;
	else
		var_dual[1] = ft_strdup(aux);
	return (var_dual);
}

void	print_env_vars(t_env *env)
{
	t_env	*aux;

	aux = env;
	while (aux)
	{
		printf("%s", aux->var[0]);
		printf("%s\n", aux->var[1]);
		aux = aux->next;
	}
}
