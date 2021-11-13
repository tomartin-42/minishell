/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:07:52 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/13 16:41:29 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "build.h"
#include "hered.h"

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
		signal_in_proces();
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

static void	execut_cmd_pid0(char **env, t_command *command)
{
	signal_in_proces();
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
	{
		execut_cmd_pid0(env, command);
	}
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
	while (command->multi_cmd[0])
	{
		command->multi_cmd[1] = get_last_pipe(command);
		if (command->multi_cmd[1] != NULL)
			pipe(command->multi_cmd[1]->p_fd);
		command->env = extract_env_list(env);
		extract_cmd_and_arg(command);
		main_build_filt(element);
		signal_ignorate();
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
