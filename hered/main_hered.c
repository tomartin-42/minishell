/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommy <tommy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 08:12:14 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/29 07:34:51 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hered.h"

//Generate and asing hered and fd. The fd is add to the elelment list
void	main_hered(t_element *element)
{
	char	*h_str;
	int		h_fd[2];

	pipe (h_fd);
	while (1)
	{
		h_str = readline("> ");
		if (!ft_strncmp(element->arg[1], h_str, ft_strlen(element->arg[1]))
			&& ft_strlen(element->arg[1]) == ft_strlen(h_str))
		{
			free(h_str);
			break ;
		}
		else
		{
			write (h_fd[1], h_str, ft_strlen(h_str));
			write (h_fd[1], "\n", 1);
			free(h_str);
		}
	}
	close(h_fd[1]);
	element->fd = dup(h_fd[0]);
}
