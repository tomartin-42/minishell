/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read_write_trunk_np.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:25:09 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/13 13:54:49 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "hered.h"

void	open_to_read_np(t_element *element)
{
	element->fd = open(element->arg[1], O_RDONLY);
	if (element->fd < 0)
	{
		g_state = errno;
		ft_putstr_fd("SFH: ", 2);
		ft_putstr_fd(element->arg[1], 2);
		ft_putstr_fd(": ", 2);
		perror("");
	}
	else
		dup2(element->fd, STDIN_FILENO);
	close(element->fd);
}

void	open_to_write_np(t_element *element)
{
	element->fd = open(element->arg[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (element->fd < 0)
	{
		g_state = errno;
		ft_putstr_fd("SFH: ", 2);
		ft_putstr_fd(element->arg[1], 2);
		ft_putstr_fd(": ", 2);
		perror("");
	}
	else
		dup2(element->fd, STDOUT_FILENO);
	close(element->fd);
}

void	open_to_trunk_np(t_element *element)
{
	element->fd = open(element->arg[1], O_APPEND | O_RDWR | O_CREAT, 0644);
	if (element->fd < 0)
	{
		g_state = errno;
		ft_putstr_fd("SFH: ", 2);
		ft_putstr_fd(element->arg[1], 2);
		ft_putstr_fd(": ", 2);
		perror("");
	}
	else
		dup2(element->fd, STDOUT_FILENO);
	close(element->fd);
}

void	redir_files_np(t_command *command)
{
	t_element	*p_elem;

	p_elem = command->multi_cmd[0];
	while (p_elem != command->multi_cmd[1])
	{
		if (p_elem->type == 'I')
			open_to_read_np(p_elem);
		else if (p_elem->type == 'O')
			open_to_write_np(p_elem);
		else if (p_elem->type == 'T')
			open_to_trunk_np(p_elem);
		else if (p_elem->type == 'H')
			redir_hered(p_elem);
		p_elem = p_elem->next;
	}
}
