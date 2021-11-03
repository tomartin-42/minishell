/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_parse_proc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:19:00 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/03 15:23:41 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	is_direct(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem)
	{
		if (p_elem->type == 'C')
		{
			if (p_elem->str[0] == '/')
				printf("🔥ShellFromHell🔥: > %s: is a directory\n", p_elem->str);
		}
		p_elem = p_elem->next;
	}
}

void	check_env(t_element *p_elem)
{
	int	n;
	int	value;

	value = 0;
	n = 0;
	if (p_elem->prev != NULL)
	{
		while (p_elem->str[n] != '\0')
		{
			if (p_elem->str[n] == '$')
				value = 1;
			if (p_elem->str[n] == '=')
				value = 2;
			if ((p_elem->type != 'A' || p_elem->type != 'S'
					|| p_elem->type != 'G') && value > 0)
			{
				if (p_elem->prev->type != 'G' && value == 2)
					p_elem->type = 'E';
				if (p_elem->prev->type != 'G' && value == 1)
					p_elem->type = '$';
			}
			n++;
		}	
	}
}
///////////////////////////////////////
///////////////////////////////////////
///////////////////////////////////////

int	thereis_command(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	//printf("Entra->%s[%c]\n", p_elem->str, p_elem->type);
	while (p_elem->prev != NULL)
		p_elem = p_elem->prev;
	while (p_elem && p_elem->type != 'P')
	{
		//printf("->%s<-\n", p_elem->str);
		if (p_elem->type == 'C')
			return (1);
		p_elem = p_elem->next;
	}
	return (0);
}

///////////////////////////////////////
///////////////////////////////////////
///////////////////////////////////////
void	arg_token(t_element *p_elem)
{
	if (p_elem->type != 'T' && p_elem->type != 'O' && p_elem->type != 'I'
		&& p_elem->type != 'H' && p_elem->type != 'P')
	{
		//printf("[%d]\n", thereis_command(p_elem));
		if (p_elem->prev && p_elem->prev->type == 'F'
			&& !thereis_command(p_elem))
			p_elem->type = 'C';
		else
			p_elem->type = 'A';
		//	print_list(p_elem);
	}
}

void	sec_procesing(t_element *p_elem)
{
	if (p_elem->prev != NULL)
	{
		if (p_elem->prev->type == 'O' && p_elem->type == 'A')
			p_elem->type = 'F';
		else if (p_elem->prev->type == 'O' && p_elem->type == 'S')
			p_elem->type = 'F';
		else if (p_elem->prev->type == 'G' && p_elem->type != 'C'
			&& p_elem->str[0] != '<' && p_elem->str[0] != '>')
		{
			p_elem->type = 'C';
		}
		else if (p_elem->prev->type == 'C' || p_elem->prev->type == 'A'
			|| p_elem->prev->type == 'E' || p_elem->prev->type == '$'
			|| p_elem->prev->type == 'F')
		{
			arg_token(p_elem);
		}
		else if ((p_elem->prev->type == 'T' && p_elem->type == 'C')
			|| p_elem->prev->type == 'X' || p_elem->prev->type == 'I')
		{
			p_elem->type = 'F';
		}
	}
}
