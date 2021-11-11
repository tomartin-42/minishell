/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 07:34:51 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/11 19:23:24 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*expand_str(char *str, t_env *env)
{
	t_element	str_elem;

	str_elem.next = NULL;
	str_elem.str = ft_strdup(str);
	free(str);
	expand_all(&str_elem, env, 1);
	str = ft_strdup(str_elem.str);
	free(str_elem.str);
	return (str);
}

//Generate and asing hered and fd (EXPAND). 
//The fd is add to the elelment list
static void	hered_expand(t_element *element, t_env *env)
{
	char	*h_str;
	int		h_fd[2];

	pipe (h_fd);
	while (1)
	{
		h_str = readline("> ");
		if (h_str == NULL)
			break ;
		if (!ft_strncmp(element->arg[1], h_str, ft_strlen(element->arg[1]))
			&& ft_strlen(element->arg[1]) == ft_strlen(h_str))
		{
			free(h_str);
			break ;
		}
		else
			hered_expand_loop_else(h_fd, h_str, env);
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
		if (h_str == NULL)
			break ;
		if (!ft_strncmp(element->arg[1], h_str, ft_strlen(element->arg[1]))
			&& ft_strlen(element->arg[1]) == ft_strlen(h_str))
		{
			free(h_str);
			break ;
		}
		else
			hered_no_expand_loop_else(h_fd, h_str);
	}
	close(h_fd[1]);
	element->fd = dup(h_fd[0]);
	close(h_fd[0]);
}

void	main_hered(t_element *element, t_env *env)
{
	signal_hered();
	if (element->hd_expand == false)
		hered_no_expand(element);
	else
		hered_expand(element, env);
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
