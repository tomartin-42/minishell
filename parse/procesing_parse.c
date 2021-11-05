/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procesing_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:07:23 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/05 08:37:04 by tomartin         ###   ########.fr       */
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
		p_elem->next->arg = malloc (sizeof(char *));
		p_elem->next->arg[0] = ft_strdup("");
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
		p_elem->next->arg = malloc (sizeof(char *));
		p_elem->next->arg[0] = ft_strdup("");
	}
	else
		p_elem->type = 'O';
}

static void	change_position_list(t_element *e_move, t_element *p1)
{
	t_element	*aux;

	aux = e_move;
	while (aux->next != p1)
	{
		aux = aux->next;
	}
	if (p1 && p1->type == 'P')
	{
		aux->prev->next = e_move;
		e_move->next = aux;
  		e_move->prev = aux->prev;
		aux->prev = e_move;
	}
	else
	{
		e_move->next = NULL;
		e_move->prev = aux;
		aux->next = e_move;
	}
}

static int	need_order_cmd(t_element *p0, t_element *p1)
{
	t_element	*p_elem;
	
	p_elem = p0;
	while (p_elem->next != p1)
	{
		if ((p_elem->type == 'I' || p_elem->type == 'O' || p_elem->type == 'T'
			|| p_elem->type == 'H' || p_elem->type == 'F')
			 && (p_elem->next->type == 'C' || p_elem->next->type == 'A'))
			return (1);
		p_elem = p_elem->next;
	}
	return (0);
}

static	int check_order_list(t_element *p0, t_element *p1)
{
	int	cmd;
	int	resp;	

	resp = 0;
	cmd = need_order_cmd(p0, p1);
	printf("cmd %d\n", cmd);
	resp = cmd;
	return (resp);
}

// Receive the start point to order and search the next point to order
static t_element	*get_next_pipe(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem && p_elem->type != 'P')
		p_elem = p_elem->next;
	return (p_elem);
}

static void	order_element_list(t_element *element)
{
	t_element	*p_elem;
	t_element	*aux;
	t_element	*point[2];

	p_elem = element;
	point[0] = p_elem;
	point[1] = point[0];
	while (point[0] != NULL)
	{
		point[1] = get_next_pipe(point[0]);
		while (check_order_list(point[0], point[1]))
		{
			if (p_elem->type == 'I' || p_elem->type == 'O' 
				|| p_elem->type == 'T' || p_elem->type == 'H' 
				|| p_elem->type == 'F')
			{
				p_elem->next->prev = p_elem->prev;
				p_elem->prev->next = p_elem->next;
				aux = p_elem;
				p_elem = point[0];
				change_position_list(aux, point[1]);
			}
			p_elem = p_elem->next;
		}
		point[0] = point[1];
		if (point[0])
			point[0] = point[0]->next;
	}
}
//asig value to t_element->type in function of type bash's element
//need reevaluate list because some type depend of previos valude in the list
//(ej. <,< <<)
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
void	pre_procesing(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	print_list(element);
	printf("*****************************************\n");
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
		else if (p_elem->str[0] != '<' && p_elem->str[0] != '>')
			p_elem->type = 'C';
		sec_procesing(p_elem);
		check_env(p_elem);
		p_elem = p_elem->next;
	}
	ft_lst_del_all_x(element);
//	order_element_list(element);
	print_list(element);
	add_args(element);
	//is_direct(element);
	//expand_all(element);
}
