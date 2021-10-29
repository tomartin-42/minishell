/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_args_add_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:36:21 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/29 15:46:28 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	yes_C_B(int size_arg, t_element	*p_elem)
{
	size_arg = count_args(p_elem);
	if (size_arg > 0)
	{
		p_elem->arg = malloc(sizeof(char *) * (size_arg + 2));
		arg_input(p_elem, size_arg);
	}
	else
	{
		p_elem->arg = malloc(sizeof(char *) * 2);
		p_elem->arg[0] = ft_strdup(p_elem->str);
		p_elem->arg[1] = NULL;
	}
}
