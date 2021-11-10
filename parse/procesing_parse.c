/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procesing_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:07:23 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/10 12:49:20 by tomartin         ###   ########.fr       */
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
	if (p_elem->next->str[0] == '<')
	{
		free(p_elem->str);
		p_elem->str = ft_strdup("<<");
		p_elem->type = 'H';
		p_elem->next->type = 'X';
	//	p_elem->next->arg = malloc (sizeof(char *));
	//	p_elem->next->arg[0] = ft_strdup("");
	}			
	else
		p_elem->type = 'I';
}

static void	change_truck(t_element *p_elem)
{
	if (p_elem->next->str[0] == '>')
	{	
		free(p_elem->str);
		p_elem->str = ft_strdup(">>");
		p_elem->type = 'T';
		p_elem->next->type = 'X';
	//	p_elem->next->arg = malloc (sizeof(char *));
	//	p_elem->next->arg[0] = ft_strdup("");
	}
	else
		p_elem->type = 'O';
}

//Asig type string to nodes of element, if not S add ? to type
static void get_string(t_element *element)
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
static void	get_pipes_and_cmd_num(t_element *element)
{
	t_element	*p_elem;
	int			cmd;

	cmd = 1;
	p_elem = element;
	p_elem->type = 'G';
	p_elem = p_elem->next;
	while(p_elem)
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

//Asig Trunc or output file to the nodes
static void get_trunk_file(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem)
	{
		if (p_elem->str[0] == '>' && p_elem->type == '?')
		{
			change_truck(p_elem);
			ft_lst_del_all_x(element);
			if (p_elem->next != NULL)
				p_elem->next->type = 'F';
		}
		p_elem = p_elem->next;
	}
}

//Asig Hered or input file to the nodes
static void get_hered_file(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem)
	{
		if (p_elem->str[0] == '<' && p_elem->type == '?')
		{	
			change_heredoc(p_elem);
			ft_lst_del_all_x(element);
			if (p_elem->next != NULL)
				p_elem->next->type = 'F';
		}
		p_elem = p_elem->next;
	}
}

//Asit cmd and arg in the nodes
static void	get_cmd_and_args(t_element *element)
{
	t_element	*p_elem;
	bool		cmd_state;

	cmd_state = false;
	p_elem = element;
	while (p_elem)
	{
		if (p_elem->type == 'P')
			cmd_state = false;
		if ((p_elem->type == '?' || p_elem->type == 'S') 
			&& cmd_state == false)
		{
			p_elem->type = 'C';
			cmd_state = true;
		}
		else if ((p_elem->type == '?' || p_elem->type == 'S') 
			&& cmd_state == true)
			p_elem->type = 'A';
		p_elem = p_elem->next;
	}
}


static void	clean_spaces_in_str(t_element *element)
{
	t_element	*p_elem;
	char		*aux;

	p_elem = element;
	while (p_elem)
	{
		aux = ft_strtrim(p_elem->str, " \t");
		free (p_elem->str);
		p_elem->str = ft_strdup(aux);
		free(aux);
		p_elem = p_elem->next;
	}
}

static t_element *add_do_nothing_node(void)
{
	t_element *new;

	new = malloc(sizeof(t_element));
	new->str = ft_strdup("do_nothing");
	new->arg = malloc(sizeof(char *) * 2);
	new->arg[0] = ft_strdup("do_nothing");
	new->arg[1] = NULL; 
	new->type = 'C';
	new->cmd_num = 1;
	new->next = NULL;
	return (new);
	//ft_lstadd_back(&element, new);
}

static void	add_do_nothing(t_element *p_elem)
{
	t_element	*new;

	new = add_do_nothing_node();
	new->next = p_elem;
	new->prev = p_elem->prev;
	p_elem->prev->next = new;
	p_elem->prev = new;
}

void	check_if_add_do_nothing(t_element *element)
{
	t_element	*p_elem;
	bool		cmd;
	t_element	*new;

	p_elem = element;
	cmd = false;
	while (p_elem)
	{
		if (p_elem->type == 'C')
			cmd = true;
		if (p_elem->type == 'P') 
		{
			if (cmd == false) 
				add_do_nothing(p_elem);
			else
				cmd = false;
		}
		p_elem = p_elem->next;
	}
	if (!p_elem && cmd == false)
	{
		new = add_do_nothing_node();
		ft_lstadd_back(&element, new);
	}
}


//asig value to t_element->type in function of type bash's element
//need reevaluate list because some type depend of previos valude in the list
//(ej. <,< <<)
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
void	pre_procesing(t_element *element)
{
	str_ex(element);
	clean_spaces_in_str(element);
	get_string(element);
	get_pipes_and_cmd_num(element);
	get_trunk_file(element);
	get_hered_file(element);
	get_cmd_and_args(element);
//	print_list(element);
//	ft_lst_del_all_x(element);
//	order_element_list(element);
	add_args(element);
	check_if_add_do_nothing(element);
//	print_arg_list(element);
	//is_direct(element);
	//expand_all(element);
}
