/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:06:47 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/11 13:49:23 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	copy_to_word(char *str, int *i, int *j, t_element *element)
{
	t_element	*new;
	int			aux_i;

	aux_i = 0;
	new = malloc(sizeof(t_element));
	new->str = malloc(*i - *j + 2);
	while (*j <= *i)
	{
		new->str[aux_i] = str[*j];
		aux_i++;
		*j = *j + 1;
	}
	new->str[aux_i] = '\0';
	new->next = NULL;
	if (new->str[0] == '"' || new->str[0] == 39)
		new->hd_expand = false;
	else
		new->hd_expand = true;
	ft_lstadd_back(&element, new);
}

void	check_open_mark(char *str, bool *mark_s, bool *mark_d, int *i)
{
	if (*mark_d == false && *mark_s == false && str[*i] == '"')
		*mark_d = true;
	if ((*mark_s == false && *mark_d == false) && str[*i] == 39)
		*mark_s = true;
}

void	check_close_mark(char *str, bool *mark_s, bool *mark_d, int *i)
{
	if (*mark_d == true && *mark_s == false && str[*i] == '"')
	{
		*mark_d = false;
		*i += 1;
	}
	if (*mark_s == true && *mark_d == false && str[*i] == 39)
	{	
		*mark_s = false;
		*i += 1;
	}
}

void	ini_var(t_mark *mark)
{
	mark->mark_s = false;
	mark->mark_d = false;
	mark->i = 0;
	mark->j = 0;
}
