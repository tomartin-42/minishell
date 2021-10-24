/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:31:56 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/24 16:45:18 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

int	ft_exit(t_command *command, t_env *env)
{
	int ret_error;
	
	ret_error = 0;
	if (command && env)
	;
	if (command->cmd->arg[1])
		ret_error = ft_atoi(command->cmd->arg[1]);

	exit (ret_error);
}
