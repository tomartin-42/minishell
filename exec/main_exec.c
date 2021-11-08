/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:22:59 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/08 09:44:54 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "hered.h"

void	start_hered(t_element *element, t_env *env, int sig)
{
	t_element	*aux_ele;

	aux_ele = element; 
	while(aux_ele)
	{
		if (aux_ele->type == 'H')
		{
			main_hered(aux_ele, env, sig);
		}
		aux_ele = aux_ele->next;
	}
}

static void	open_to_read(t_element *element)
{
	element->fd = open(element->arg[1], O_RDONLY);
	if (element->fd < 0)
	{
		g_state = errno;
		printf("**%d**\n", errno);
		perror("Error");
		ft_putstr_fd(element->arg[1], 2);
		exit (g_state);
	}
	else
		dup2(element->fd, STDIN_FILENO);
	close(element->fd);
}

static void	open_to_write(t_element *element)
{
	element->fd = open(element->arg[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);	 
	if (element->fd < 0)
	{
		g_state = errno;
		printf("**%d**\n", errno);
		perror("Error");
		ft_putstr_fd(element->arg[1], 2);
		exit (g_state);
	}
	else
		dup2(element->fd, STDOUT_FILENO);
	close(element->fd);
}

static void	open_to_trunk(t_element *element)
{
	element->fd = open(element->arg[1], O_APPEND | O_RDWR | O_CREAT, 0644);
	if (element->fd < 0)
	{
		g_state = errno;
		printf("**%d**\n", errno);
		perror("Error");
		ft_putstr_fd(element->arg[1], 2);
		exit (g_state);
	}
	else
		dup2(element->fd, STDOUT_FILENO);
	close(element->fd);
}

static void redir_hered(t_element *element)
{
	dup2(element->fd, STDIN_FILENO);
	close(element->fd);
}

void	redir_files(t_command *command)
{
	t_element	*p_elem;

	p_elem = command->multi_cmd[0];
	while (p_elem != command->multi_cmd[1])
	{
		if (p_elem->type == 'I')
			open_to_read(p_elem);
		else if (p_elem->type == 'O')
			open_to_write(p_elem);
		else if (p_elem->type == 'T')
			open_to_trunk(p_elem);
		else if (p_elem->type == 'H')
			redir_hered(p_elem);
		p_elem = p_elem->next;
	}
}

/*void  get_fd_pipes(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem)
	{
		if (p_elem->type == 'P')
			pipe(p_elem->p_fd);
		p_elem = p_elem->next;
	}
}*/

static void	get_special_pipes(t_element *element, t_command *command)
{
	t_element	*aux_elem;

	aux_elem = element;
	while (aux_elem)
	{
		if (aux_elem->type == 'P')
		{
			command->special_cmd[0] = aux_elem;
			break ;
		}
		aux_elem = aux_elem->next;
	}
	aux_elem = ft_lstlast(element);
	while (aux_elem)
	{
		if (aux_elem->type == 'P')
		{
			command->special_cmd[1] = aux_elem;
			break ;
		}
		aux_elem = aux_elem->prev;
	}
}

void	main_exec(t_element *element, t_env *env)
{
	t_command	command;
	t_element	*next_elem;

//	print_list(element);
//	print_arg_list(element);
	command.p_elem = element;
	command.m_env = env;
	next_elem = element->next;
//	get_fd_pipes(next_elem);
	get_special_pipes(next_elem, &command);
	command.multi_cmd[0] = next_elem;
	command.fd_stdin = dup(0);
	command.fd_stdout = dup(1);
	command.pid_num = 0;
	rutine_command(next_elem, env, &command);
	close_hered(element);
//	free_element(element);
}

