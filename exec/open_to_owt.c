/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_to_owt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:32:10 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/29 17:01:11 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "hered.h"

void	open_to_read(t_element *element)
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

void	open_to_write(t_element *element)
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

void	open_to_trunk(t_element *element)
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
