/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:07:52 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/14 11:49:38 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "build.h"

static void	extract_cmd_and_arg(t_command *command)
{
	t_element	*p_elem;

	p_elem = command->multi_cmd[0];
	while (p_elem != command->multi_cmd[1])
	{
		if (p_elem->type == 'C')
		{
			command->cmd = p_elem;
			break ;
		}
		p_elem = p_elem->next;
	}	
}

static void	execut_cmd(char **cmd, char **env, t_command *command)
{
	pid_t	pid;

	if (command->multi_cmd[0]->type == 'P')
	{
		printf("HOLA1\n");
		close(command->multi_cmd[0]->p_fd[1]);
		dup2(command->multi_cmd[0]->p_fd[0], STDIN_FILENO);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd[0], cmd, env) == -1)
		{
			printf("Error N= %d\n", errno);
			exit(errno);
			if (command->multi_cmd[1]->type == 'P')
			{
				printf("HOLA2\n");
				dup2(command->multi_cmd[1]->p_fd[1], STDOUT_FILENO);
				close(command->multi_cmd[1]->p_fd[0]);
			}
		}
		
	}
	else
	{
	}
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
	/// EMPIEZA LA FIESTA ///////////////////////////////////////////////
		command->multi_cmd[1] = get_last_pipe(command);
		command->env = extract_all_env_list(env);
	
		extract_cmd_and_arg(command);
	////////////////
		main_build_filt(element);//filtra si es build y marca los args a borrar
		ft_lst_del_all_x(element);//elimina 'X' arg
	//////////////////////////////////////////////////////////////
	//ft_pwd(command->env);//////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////
		command->cmd->arg[0] = find_exec_path(command->cmd->arg, command->env);
		for (int i = 0; command->cmd->arg[i]; i++)//print a todos los args y command// borrar despues
			printf("%s\n", command->cmd->arg[i]);
		redir_files(command);
		execut_cmd(command->cmd->arg, command->env, command);//TO DO:filtrar con la lista y ver si comand is 'B'
		command->multi_cmd[0] = command->multi_cmd[1];
	}
		waitpid(-1, NULL, 0);
		waitpid(-1, NULL, 0);
		waitpid(-1, NULL, 0);
	dup2(command->fd_stdin, STDIN_FILENO);
	dup2(command->fd_stdout, STDOUT_FILENO);
	close(command->fd_stdin);
	close(command->fd_stdout);
}
