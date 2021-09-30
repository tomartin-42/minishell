/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_parse_proc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:19:00 by dpuente-          #+#    #+#             */
/*   Updated: 2021/09/30 17:28:51 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_env(t_element *element)
{
	int	n;
	int	value;

	value = 0;
	n = 0;
	if (element->prev != NULL)
	{
		while (element->str[n] != '\0')
		{
			if (element->str[n] == '$' || element->str[n] == '=')
				value = 1;
			if ((element->type != 'A' || element->type != 'S'
					|| element->type != 'G') && value == 1)
			{
				if (element->prev->type != 'G')
					element->type = 'E';
			}
			n++;
		}	
	}
}

void	arg_token(t_element *element)
{
	if (element->type != 'T' && element->type != 'O' && element->type != 'I'
		&& element->type != 'H')
	{
		element->type = 'A';
	}
}

void	sec_procesing(t_element *element)
{
	if (element->prev != NULL)
	{
		if (element->prev->type == 'O' && element->type == 'C')
			element->type = 'F';
		else if (element->prev->type == 'O' && element->type == 'S')
			element->type = 'F';
		else if (element->prev->type == 'G' && element->type != 'C')
			element->type = 'C';
		else if (element->prev->type == 'C' || element->prev->type == 'A'
			|| element->prev->type == 'E')
		{
			arg_token(element);
		}
		else if ((element->prev->type == 'T' && element->type == 'C')
			|| element->prev->type == 'X')
		{
			element->type = 'F';
		}
	}
}
