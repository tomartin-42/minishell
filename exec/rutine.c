/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:07:52 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/26 11:41:52 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "build.h"
#include "hered.h"

static void	extract_cmd_and_arg(t_command *command)
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

static void	close_forks(t_element *element)
{
	int			i;
	t_element	*p_elem;
	int			error;

	p_elem = element;
	i = 1;
	while (p_elem)
	{
		if (p_elem->type == 'P')
			i++;
		p_elem = p_elem->next;
	}
	while (i != 0)
	{
		waitpid(-1, &error, 0);
		g_state = WEXITSTATUS(error);
		i--;
	}
}

void	execut_cmd_build_np(t_env *env, t_command *command)
{
	redir_files(command);
	build_filt(command, env);
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
		errno = build_filt(command, env);
		exit (errno);
	}
	else
		close(command->multi_cmd[0]->p_fd[0]);
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
		if (command->multi_cmd[1] && command->multi_cmd[1]->type == 'P')
		{
			dup2(command->multi_cmd[1]->p_fd[1], STDOUT_FILENO);
			close(command->multi_cmd[1]->p_fd[0]);
		}
		command->cmd->arg[0] = find_exec_path(command->cmd->arg, command->env);
		redir_files(command);
		if (execve(command->cmd->arg[0],command->cmd->arg, env) == -1)
		{
			perror("Error"); 
			g_state = errno;
			exit(g_state);
		}
	}
	else
		close(command->multi_cmd[0]->p_fd[0]);
}

static t_element *get_last_pipe(t_command *command)
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
	while(command->multi_cmd[0])
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
