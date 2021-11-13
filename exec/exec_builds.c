/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:13:19 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/13 13:54:38 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "build.h"
#include "hered.h"

void	execut_cmd_build_np(t_env *env, t_command *command)
{
	redir_files_np(command);
	g_state = build_filt(command, env);
}

//The motor of execut comand (Buildings)
void	execut_cmd_build(t_env *env, t_command *command)
{
	pid_t	pid;

	if (command->multi_cmd[0]->type == 'P')
	{
		dup2(command->multi_cmd[0]->p_fd[0], STDIN_FILENO);
		close(command->multi_cmd[0]->p_fd[1]);
	}
	pid = fork();
	if (pid == 0)
	{
		if (command->multi_cmd[1] && command->multi_cmd[1]->type == 'P')
		{
			dup2(command->multi_cmd[1]->p_fd[1], STDOUT_FILENO);
			close(command->multi_cmd[1]->p_fd[0]);
		}
		redir_files(command);
		g_state = build_filt(command, env);
		exit (g_state);
	}
	else
		close(command->multi_cmd[0]->p_fd[0]);
}
