/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procesing_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:07:23 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/02 20:15:08 by davyd11          ###   ########.fr       */
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

static void	change_heredoc(t_element *p_elem)
{
	if (p_elem->next != NULL && p_elem->next->str[0] == '<')
	{
		free(p_elem->str);
		p_elem->str = ft_strdup("<<");
		p_elem->type = 'H';
		p_elem->next->type = 'X';
	}			
	else
		p_elem->type = 'I';
}

static void	change_truck(t_element *p_elem)
{
	if (p_elem->next != NULL && p_elem->next->str[0] == '>')
	{	
		free(p_elem->str);
		p_elem->str = ft_strdup(">>");
		p_elem->type = 'T';
		p_elem->next->type = 'X';
	}
	else
		p_elem->type = 'O';
}

//asig value to t_element->type in function of type bash's element
//need reevaluate list because some type depend of previos valude in the list
//(ej. <,< <<)
///////////////////////////////////////////////////////////////
/*void	expand_str(t_element * p_elem)
{
	
}*/

void	arg_input(t_element *p_elem, int	size_arg)
{
	int n;
	t_element *p_elem_arg;

	n = 0;
	p_elem_arg = p_elem;
	while(n < size_arg)
	{
		if (p_elem_arg != NULL)
			p_elem_arg = p_elem_arg->next;
		p_elem->arg[n] = p_elem_arg->str;
		n++;
	}
}

int	count_args(t_element *p_elem)
{
	int	n;

	n = 0;
	if (p_elem)
		p_elem = p_elem->next;
	while (p_elem && (p_elem->type == 'A' || p_elem->type == 'E'
			|| p_elem->type == '$'))
	{
		p_elem = p_elem->next;
		n++;
	}
	return (n);
}

void	add_args(t_element *element)
{
	t_element	*p_elem;
	int			size_arg;

	p_elem = element;
	size_arg = 0;
	while (p_elem)
	{
		if (p_elem->type == 'C')
		{
			size_arg = count_args(p_elem);
			if (size_arg > 0)
			{
				//printf("|-%d-|", size_arg);
				p_elem->arg = malloc(sizeof(char *) * size_arg);
				arg_input(p_elem, size_arg);
				//printf("%s", p_elem->arg[0]);
			}
		}
		p_elem = p_elem->next;
	}
}
///////////////////////////////////////////////////////////////
void	pre_procesing(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem)
	{
		if (p_elem->type == 'X' || p_elem->type == 'G')
			;
		else if (p_elem->str[0] == '"')
			p_elem->type = 'S';
		else if (p_elem->str[0] == 39)
			p_elem->type = 'S';
		else if (p_elem->str[0] == '<')
			change_heredoc(p_elem);
		else if (p_elem->str[0] == '>')
			change_truck(p_elem);
		else if (p_elem->str[0] == '|')
			p_elem->type = 'P';
		else
			p_elem->type = 'C';
		sec_procesing(p_elem);
		check_env(p_elem);
		p_elem = p_elem->next;
	}
	add_args(element); ///////move to oder function, just temporal
}
