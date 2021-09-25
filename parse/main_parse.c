/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 15:12:24 by tommy             #+#    #+#             */
/*   Updated: 2021/09/25 20:19:12 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	copy_to_word(char *str, int *i, int *j, t_element *element)
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
	if (new->str[0] != ' ')
	{
		if (ft_strlen(new->str) != 0)
			ft_lstadd_back(&element, new);
		else
		{
			free(new->next);
			free(new);
		}
	}
}

static void	check_open_mark(char *str, bool *mark_s, bool *mark_d, int *i)
{
	if (*mark_d == false && *mark_s == false && str[*i] == '"')
		*mark_d = true;
	if ((*mark_s == false && *mark_d == false) && str[*i] == 39)
		*mark_s = true;
}

static void	check_close_mark(char *str, bool *mark_s, bool *mark_d, int *i)
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
/*
static void	add_trunc(t_element *element, int *i, int *j)
{	
	t_element	*new;

	new = malloc(sizeof(t_element));
	new->str = malloc(sizeof(char) * 3);
	new->str[0] = '<';
	new->str[1] = '<';
	new->str[2] = '\0';
	new->next = NULL;
	*j += 2;
	*i += 2;
	ft_lstadd_back(&element, new);
}

static void	add_herd(t_element *element, int *i, int *j)
{	
	t_element	*new;

	new = malloc(sizeof(t_element));
	new->str = malloc(sizeof(char) * 3);
	new->str[0] = '>';
	new->str[1] = '>';
	new->str[2] = '\0';
	new->next = NULL;
	*j += 2;
	*i += 2;
	ft_lstadd_back(&element, new);
}*/

static void	ini_var(t_mark *mark)
{
	mark->mark_s = false;
	mark->mark_d = false;
	mark->i = 0;
	mark->j = 0;
}

void	main_parse(char *str, t_element *element)
{
	t_mark	mk;

	ini_var(&mk);
	while (str[mk.i])
	{
		check_open_mark(str, &mk.mark_s, &mk.mark_d, &mk.i);
		if (ft_strchr("|<> ", str[mk.i]) && mk.mark_d == false
			&& mk.mark_s == false)
		{	
			if (ft_strchr("|<>", str[mk.i]))
			{
			/*	if (str[mk.i + 1] != '\0' && str[mk.i] == '<' && str[mk.i + 1] == '<')
				{
					copy_to_word(str, &mk.i, &mk.j, element);
					add_trunc(element, &mk.i, &mk.j);//añade <<
				}
				if (str[mk.i + 1] != '\0' && str[mk.i] == '>' && str[mk.i + 1] == '>')
				{
					copy_to_word(str, &mk.i, &mk.j, element);
					add_herd(element, &mk.i, &mk.j);
				}*/
				mk.i--;
				copy_to_word(str, &mk.i, &mk.j, element);
				mk.i++;
			}
			copy_to_word(str, &mk.i, &mk.j, element);
		}
		if (str[mk.i] != '\0')
			mk.i++;
		check_close_mark(str, &mk.mark_s, &mk.mark_d, &mk.i);
		if (str[mk.i] == '\0')
			copy_to_word(str, &mk.i, &mk.j, element);
	}
	clean_element(element);
	pre_procesing(element);
	post_procesing(element);
}
