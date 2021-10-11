/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:07:52 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/11 23:47:20 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "build.h"

// create dp with comand and all arg. Return the dp 
static char	**create_command_dp(t_element *element, int i)
{
	char		**cmd;
	int			j;
	t_element	*p_elem;

	j = 1;
	cmd = malloc((sizeof(char *) * (i + 1)));
	p_elem = element;
	while (p_elem && p_elem->type != 'P')
	{
		if (p_elem->type == 'C')
			cmd[0] = ft_strdup(p_elem->str);
		else if (p_elem->type == 'A')
		{
			cmd[j] = ft_strdup(p_elem->str);
			j++;
		}
		p_elem = p_elem->next;
	}
	cmd[j] = NULL;
	return (cmd);
}

static void	extract_cmd_and_arg(t_element *element, t_command *command)
{
	t_element	*p_elem;
	int			i;

	i = 1;
	p_elem = element;
	while (p_elem && p_elem->type != 'P')
	{
		if (p_elem->type == 'A')
			i++;
		p_elem = p_elem->next;
	}	
	command->command = create_command_dp(element, i);
}

static void	execut_cmd(char **cmd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd[0], cmd, env) == -1)
		{
			printf("Error N= %d\n", errno);
			exit(errno);
		}
	}
	waitpid(pid, NULL, 0);
}

void	rutine_command(t_element *element, t_env *env, t_command *command)
{
	int not_build;/////borrar

	not_build = 0;/////borrar
	redir_files(element);
	command->env = extract_all_env_list(env);
	extract_cmd_and_arg(element, command);
	//add compare to builds
	///////////////////////
	not_build = is_build(element, command);
	command->command[0] = find_exec_path(command->command, command->env);
	for (int i = 0; command->command[i]; i++)
		printf("%s\n", command->command[i]);
	if (not_build == 0)/////borrar
	{
		printf("HOLA");
		execut_cmd(command->command, command->env);
	}
	/////////////////////////
}
/*
desde is_build hasta el final, meter en funcion.
-	recorrer todo element->str , identificar cuales son commands
si son build cambiar a B
(cambiar command->... a element->str y a element->arg)
-	funcion para poder ejecutar execut_cmd si no es build y si no accede
a funcion para ejecutar build
*/
