/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:07:52 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/29 16:25:20 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "build.h"
#include "hered.h"

void	exec_cmd_pid0(char **env, t_command *command)
{
	if (command->multi_cmd[1] && command->multi_cmd[1]->type == 'P')
	{
		dup2(command->multi_cmd[1]->p_fd[1], STDOUT_FILENO);
		close(command->multi_cmd[1]->p_fd[0]);
	}
	command->cmd->arg[0] = find_exec_path(command->cmd->arg, command->env);
	redir_files(command);
	if (execve(command->cmd->arg[0], command->cmd->arg, env) == -1)
	{
		perror("Error");
		g_state = errno;
		exit(g_state);
	}
}
//The motor of execut comand (No Buildings)

void	execut_cmd(char **env, t_command *command)
{
	pid_t	pid;

	if (command->multi_cmd[0]->type == 'P')
	{
		dup2(command->multi_cmd[0]->p_fd[0], STDIN_FILENO);
		close(command->multi_cmd[0]->p_fd[1]);
	}
	pid = fork();
	if (pid == 0)
		exec_cmd_pid0(env, command);
	else
		close(command->multi_cmd[0]->p_fd[0]);
}

static t_element	*get_last_pipe(t_command *command)
{
	t_element	*aux_elem;

	aux_elem = command->multi_cmd[0];
	aux_elem = aux_elem->next;
	while (aux_elem && aux_elem->type != 'P')
	{
		aux_elem = aux_elem->next;
	}
	return (aux_elem);
}

void	rutine_command(t_element *element, t_env *env, t_command *command)
{
	start_hered(element);
	while (command->multi_cmd[0])
	{
		command->multi_cmd[1] = get_last_pipe(command);
		if (command->multi_cmd[1] != NULL)
			pipe(command->multi_cmd[1]->p_fd);
		command->env = extract_all_env_list(env);
		extract_cmd_and_arg(command);
		main_build_filt(element);
		ft_lst_del_all_x(element);
		cmd_execution(element, command, env);
		command->multi_cmd[0] = command->multi_cmd[1];
		ft_free_dp(command->env);
	}
	dup2(command->fd_stdin, STDIN_FILENO);
	dup2(command->fd_stdout, STDOUT_FILENO);
	if (check_pipes_or_cmd(element))
		close_forks(element);
	close(command->fd_stdin);
	close(command->fd_stdout);
}
