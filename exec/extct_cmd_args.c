/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extct_cmd_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:07:17 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/29 16:16:57 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "build.h"
#include "hered.h"

void	extract_cmd_and_arg(t_command *command)
{
	t_element	*p_elem;

	p_elem = command->multi_cmd[0];
	while (p_elem != command->multi_cmd[1])
	{
		if (p_elem->type == 'C' || p_elem->type == 'B')
		{
			command->cmd = p_elem;
			break ;
		}
		p_elem = p_elem->next;
	}	
}
