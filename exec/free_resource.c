/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resource.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:08:03 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/04 19:07:31 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_aux(char **aux_path)
{
	int	i;

	i = 0;
	while (aux_path[i])
		free(aux_path[i++]);
	free(aux_path);
}

void	free_param(t_param *param)
{
	free(param->file[0]);
	free(param->file[1]);
	free(param->cmd[0]);
	free(param->cmd[1]);
	free_aux(param->cmd1);
	free_aux(param->cmd2);
}
