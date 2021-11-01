/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 07:34:51 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/01 12:27:09 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hered.h"

//Generate and asing hered and fd (EXPAND). 
//The fd is add to the elelment list
static void	hered_expand(t_element *element)
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
	close(h_fd[0]);
}

//Generate and asing hered and fd (NO EXPAND). 
//The fd is add to the elelment list
static void	hered_no_expand(t_element *element)
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
	close(h_fd[0]);
}

void	main_hered(t_element *element)
{
	char	*aux;

	if (element->arg[1][0] == '"' || element->arg[1][0] == 39)
	{	
		aux = ft_strtrim(element->arg[1], "\"\'");
		free(element->arg[1]);
		element->arg[1] = ft_strdup(aux);
		free(aux);
		hered_no_expand(element);
	}
	else
		hered_expand(element);
}

void	close_hered(t_element *element)
{
	t_element	*aux;

	aux = element;
	while (aux)
	{
		if (aux->type == 'H')
			close (aux->fd);
		aux = aux->next;
	}
}
