/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:48:42 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 13:53:00 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

//clean up spaces of element
void	clean_element(t_element *element)
{
	t_element	*p_elem;
	char		*aux;

	p_elem = element;
	while (p_elem)
	{
		aux = ft_strtrim(p_elem->str, " ");
		free(p_elem->str);
		p_elem->str = ft_strdup(aux);
		free(aux);
		p_elem = p_elem->next;
	}
}

void	change_heredoc(t_element *p_elem)
{
	if (p_elem->next->str[0] == '<')
	{
		free(p_elem->str);
		p_elem->str = ft_strdup("<<");
		p_elem->type = 'H';
		p_elem->next->type = 'X';
	}			
	else
		p_elem->type = 'I';
}

void	change_truck(t_element *p_elem)
{
	if (p_elem->next->str[0] == '>')
	{	
		free(p_elem->str);
		p_elem->str = ft_strdup(">>");
		p_elem->type = 'T';
		p_elem->next->type = 'X';
	}
	else
		p_elem->type = 'O';
}

//Asig type string to nodes of element, if not S add ? to type
void	get_string(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem)
	{
		if (p_elem->str[0] == '"')
			p_elem->type = 'S';
		else if (p_elem->str[0] == 39)
			p_elem->type = 'S';
		else
			p_elem->type = '?';
		p_elem = p_elem->next;
	}
}

//Asig the cmd_num for each pipe and asig P to the pipes
void	get_pipes_and_cmd_num(t_element *element)
{
	t_element	*p_elem;
	int			cmd;

	cmd = 1;
	p_elem = element;
	p_elem->type = 'G';
	p_elem = p_elem->next;
	while (p_elem)
	{
		if (p_elem->str[0] == '|' && p_elem->type == '?')
		{
			p_elem->type = 'P';
			p_elem->cmd_num = cmd;
			cmd++;
		}
		else
			p_elem->cmd_num = cmd;
		p_elem = p_elem->next;
	}
}
