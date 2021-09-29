/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:14:34 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/29 11:42:52 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_env *env, t_element *element)
{
	env = env;

	if (ft_strlen(element->arg[0]))
		printf(" "); // codigo para pasar una variable statica a global
	else
		printf(" ");

}
