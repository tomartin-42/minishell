/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:07:52 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/10 16:55:17 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "hered.h"

static void	finish_pid(pid_t pid, t_command *command)
{
	while (command->pid_num != 0)
	{
		waitpid(pid, null, -1);
		command->pid_num -= 1;
	}
	dup2(0, command->fd_stdin);
	dup2(0, command->fd_stdout);
	close(command->fd_stdin);
	close(command->fd_stdout);
}

static void	extraxt_cmd_and_arg(t_element *element, t_command *command)
{
	
}

void	rutine_command(t_element *element, t_env *env, t_command *command)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		printf("error de fork\n");
	else if (pid == 0)
	{
		start_hered(element);
		redir_files(element);
		command->env = extract_all_env_list(env);	
		extract_cmd_and_arg(t_element, command);
	}
	else
		finish_pid(pid, command);
}

